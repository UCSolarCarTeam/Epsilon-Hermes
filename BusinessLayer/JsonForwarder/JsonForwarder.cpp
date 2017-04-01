#include <QTimer>
#include <QDebug>
#include <QJsonObject>
#include <QDateTime>

#include "BusinessLayer/JsonForwarder/BatteryJsonForwarder/BatteryJsonForwarder.h"
#include "BusinessLayer/JsonForwarder/FaultsJsonForwarder/FaultsJsonForwarder.h"
#include "BusinessLayer/JsonForwarder/PowerJsonForwarder/PowerJsonForwarder.h"
#include "BusinessLayer/JsonForwarder/VehicleJsonForwarder/VehicleJsonForwarder.h"
#include "CommunicationLayer/CommDeviceControl/I_MessageForwarder.h"
#include "InfrastructureLayer/Settings/I_Settings.h"
#include "JsonDefines.h"
#include "JsonForwarder.h"

namespace
{
    const QString MYSQL_DATE_FORMAT = "yyyy-MM-dd HH:mm:ss";
}

JsonForwarder::JsonForwarder(/*I_BatteryData& batteryData,
                  I_BatteryFaultsData& batteryFaultsData,
                  I_CmuData& cmuData,
                  I_DriverControlsData& driverControlsData,
                  I_KeyMotorData& keyMotorData,
                  I_LightsData& lightsData,
                  I_MotorDetailsData& motorDetailsData,
                  I_MotorFaultsData& motorFaultsData,
                  I_MpptData& mpptData,
                  I_OtherData& otherData,*/
    I_MessageForwarder& messageForwarder,
    I_Settings& settings,
    Mode::Mode mode)
    : batteryJsonForwarder_(new BatteryJsonForwarder(/*batteryData, */messageForwarder))
    , faultsJsonForwarder_(new FaultsJsonForwarder(/*faultsData, */messageForwarder))
    , powerJsonForwarder_(new PowerJsonForwarder(/*powerData, */messageForwarder))
    , vehicleJsonForwarder_(new VehicleJsonForwarder(/*vehicleData, */messageForwarder))
    , readTimer_(new QTimer())
    , dataToReadCount_(0)
    , forwardPeriod_(settings.forwardPeriod())
    , PACKET_TITLE_(settings.packetTitle())
{
    if (mode == Mode::Mode::HEADLESS)
    {
        connect(readTimer_.data(), SIGNAL(timeout()), this, SLOT(forwardData()));
    }
}

JsonForwarder::~JsonForwarder()
{}

void JsonForwarder::startForwardingData()
{
    readTimer_->setInterval(forwardPeriod_);
    readTimer_->start();
}

void JsonForwarder::forwardData()
{
    QJsonObject baseJson = QJsonObject();
    baseJson[JsonFormat::PACKET_TITLE] = PACKET_TITLE_;
    QString currentTime = QDateTime::currentDateTime().toUTC().toString(MYSQL_DATE_FORMAT);
    baseJson[JsonFormat::TIMESTAMP] = currentTime;

    switch (dataToReadCount_)
    {
        case 0:
            qDebug() << "JsonForwarder: Forwarding battery data";
            batteryJsonForwarder_->forwardBatteryData(baseJson);
            break;

        case 1:
            qDebug() << "JsonForwarder: Forwarding faults data";
            faultsJsonForwarder_->forwardFaultsData(baseJson);
            break;

        case 2:
            qDebug() << "JsonForwarder: Forwarding power data";
            powerJsonForwarder_->forwardPowerData(baseJson);
            break;

        case 3 :
            qDebug() << "JsonForwarder: Forwarding vehicle data";
            vehicleJsonForwarder_->forwardVehicleData(baseJson);
            break;
    }

    if (dataToReadCount_ >= 3)
    {
        dataToReadCount_ = 0;
    }
    else
    {
        dataToReadCount_++;
    }
}
