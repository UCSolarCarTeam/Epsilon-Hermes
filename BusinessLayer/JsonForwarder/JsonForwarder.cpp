#include <QTimer>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDateTime>

#include "CommunicationLayer/CommDeviceControl/I_MessageForwarder.h"
#include "InfrastructureLayer/Settings/I_Settings.h"
#include "JsonDefines.h"
#include "JsonForwarder.h"
#include "BusinessLayer/JsonMessageBuilder/JsonMessageBuilder.h"

namespace
{
const QString MYSQL_DATE_FORMAT = "yyyy-MM-dd HH:mm:ss";
}

JsonForwarder::JsonForwarder(
    I_JsonMessageBuilder& jsonMessageBuilder,
    I_AuxBmsData& auxBmsData,
    I_BatteryData& batteryData,
    I_BatteryFaultsData& batteryFaultsData,
    I_DriverControlsData& driverControlsData,
    I_KeyMotorData& keyMotorData,
    I_LightsData& lightsData,
    I_MotorDetailsData& motorDetailsData,
    I_MotorFaultsData& motorFaultsData,
    I_MpptData& mpptData,
    I_MessageForwarder& messageForwarder,
    I_Settings& settings)
    : jsonMessageBuilder_(jsonMessageBuilder)
    , auxBmsData_(auxBmsData)
    , batteryData_(batteryData)
    , batteryFaultsData_(batteryFaultsData)
    , driverControlsData_(driverControlsData)
    , keyMotorData_(keyMotorData)
    , lightsData_(lightsData)
    , motorDetailsData_(motorDetailsData)
    , motorFaultsData_(motorFaultsData)
    , mpptData_(mpptData)
    , messageForwarder_(messageForwarder)
    , readTimer_(new QTimer())
    , forwardPeriod_(settings.forwardPeriod())
    , PACKET_TITLE_(settings.packetTitle())
{
    connect(readTimer_.data(), SIGNAL(timeout()), this, SLOT(handleTimeout()));
}

JsonForwarder::~JsonForwarder()
{}

void JsonForwarder::startForwardingData()
{
    readTimer_->setInterval(forwardPeriod_);
    readTimer_->start();
}

void JsonForwarder::handleTimeout()
{
    QDateTime currentTime = QDateTime::currentDateTime();
    forwardData(currentTime);
}

void JsonForwarder::forwardData(QDateTime& currentTime)
{
    QJsonObject baseJson = QJsonObject();
    baseJson[JsonFormat::PACKET_TITLE] = PACKET_TITLE_;
    baseJson[JsonFormat::TIMESTAMP] = currentTime.toUTC().toString(MYSQL_DATE_FORMAT);

    baseJson[JsonFormat::KEY_MOTOR] = jsonMessageBuilder_.buildKeyMotorMessage(keyMotorData_);
    baseJson[JsonFormat::MOTOR_DETAILS] = jsonMessageBuilder_.buildMotorDetailsMessage(motorDetailsData_);
    baseJson[JsonFormat::DRIVER_CONTROLS] = jsonMessageBuilder_.buildDriverControlsMessage(driverControlsData_);
    baseJson[JsonFormat::MOTOR_FAULTS] = jsonMessageBuilder_.buildMotorFaultsMessage(motorFaultsData_);
    baseJson[JsonFormat::BATTERY_FAULTS] = jsonMessageBuilder_.buildBatteryFaultsMessage(batteryFaultsData_);
    baseJson[JsonFormat::BATTERY] = jsonMessageBuilder_.buildBatteryMessage(batteryData_);
    baseJson[JsonFormat::MPPT] = jsonMessageBuilder_.buildMpptMessage(mpptData_);
    baseJson[JsonFormat::LIGHTS] = jsonMessageBuilder_.buildLightsMessage(lightsData_);
    baseJson[JsonFormat::AUX_BMS] = jsonMessageBuilder_.buildAuxBmsMessage(auxBmsData_);
    messageForwarder_.forwardData(QJsonDocument(baseJson).toJson(QJsonDocument::Compact));
}
