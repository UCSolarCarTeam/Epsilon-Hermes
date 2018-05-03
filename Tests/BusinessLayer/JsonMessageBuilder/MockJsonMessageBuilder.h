#pragma once

#include "BusinessLayer/JsonMessageBuilder/I_JsonMessageBuilder.h"

class MockJsonMessageBuilder : public I_JsonMessageBuilder
{
public:
    MOCK_METHOD1(buildAuxBmsMessage, QJsonObject(const I_AuxBmsData&));
    MOCK_METHOD1(buildBatteryMessage, QJsonObject(const I_BatteryData&));
    MOCK_METHOD1(buildBatteryFaultsMessage, QJsonObject(const I_BatteryFaultsData&));
    MOCK_METHOD1(buildDriverControlsMessage, QJsonObject(const I_DriverControlsData&));
    MOCK_METHOD1(buildKeyMotorMessage, QJsonArray(const I_KeyMotorData&));
    MOCK_METHOD1(buildLightsMessage, QJsonObject(const I_LightsData&));
    MOCK_METHOD1(buildMotorDetailsMessage, QJsonArray(const I_MotorDetailsData&));
    MOCK_METHOD1(buildMotorFaultsMessage, QJsonArray(const I_MotorFaultsData&));
    MOCK_METHOD1(buildMpptMessage, QJsonArray(const I_MpptData&));
};
