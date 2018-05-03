#pragma once

#include <QJsonObject>
#include <QJsonArray>

class I_AuxBmsData;
class I_BatteryData;
class I_BatteryFaultsData;
class I_DriverControlsData;
class I_KeyMotorData;
class I_LightsData;
class I_MotorDetailsData;
class I_MotorFaultsData;
class I_MpptData;

class I_JsonMessageBuilder
{
public:
    virtual ~I_JsonMessageBuilder() {}
    virtual QJsonObject buildAuxBmsMessage(const I_AuxBmsData& data) = 0;
    virtual QJsonObject buildBatteryMessage(const I_BatteryData& data) = 0;
    virtual QJsonObject buildBatteryFaultsMessage(const I_BatteryFaultsData& data) = 0;
    virtual QJsonObject buildDriverControlsMessage(const I_DriverControlsData& data) = 0;
    virtual QJsonArray buildKeyMotorMessage(const I_KeyMotorData& data) = 0;
    virtual QJsonObject buildLightsMessage(const I_LightsData& data) = 0;
    virtual QJsonArray buildMotorDetailsMessage(const I_MotorDetailsData& data) = 0;
    virtual QJsonArray buildMotorFaultsMessage(const I_MotorFaultsData& data) = 0;
    virtual QJsonArray buildMpptMessage(const I_MpptData& data) = 0;
};
