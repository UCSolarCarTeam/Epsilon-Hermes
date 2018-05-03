#pragma once

#include <QScopedPointer>
#include <QTimer>

#include "I_JsonForwarder.h"

class I_JsonMessageBuilder;
class I_AuxBmsData;
class I_BatteryData;
class I_BatteryFaultsData;
class I_DriverControlsData;
class I_KeyMotorData;
class I_LightsData;
class I_MotorDetailsData;
class I_MotorFaultsData;
class I_MpptData;
class I_MessageForwarder;
class I_Settings;

class JsonForwarder : public I_JsonForwarder
{
    Q_OBJECT
public:
    JsonForwarder(
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
        I_Settings& settings);
    virtual ~JsonForwarder();
    void startForwardingData();
    void forwardData(QDateTime& currentTime);

private slots:
    void handleTimeout();

private:
    I_JsonMessageBuilder& jsonMessageBuilder_;
    I_AuxBmsData& auxBmsData_;
    I_BatteryData& batteryData_;
    I_BatteryFaultsData& batteryFaultsData_;
    I_DriverControlsData& driverControlsData_;
    I_KeyMotorData& keyMotorData_;
    I_LightsData& lightsData_;
    I_MotorDetailsData& motorDetailsData_;
    I_MotorFaultsData& motorFaultsData_;
    I_MpptData& mpptData_;
    I_MessageForwarder& messageForwarder_;
    QScopedPointer<QTimer> readTimer_;
    int forwardPeriod_;
    const QString PACKET_TITLE_;
};
