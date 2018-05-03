#pragma once

#include "DataLayer/BatteryData/I_BatteryData.h"

class MockBatteryData : public I_BatteryData
{
public:

    /*BatteryData "Gets"*/
    MOCK_CONST_METHOD0(getAlive, bool());
    MOCK_CONST_METHOD0(getBmsRelayStatus, unsigned char());
    MOCK_CONST_METHOD0(getPopulatedCells, unsigned char());
    MOCK_CONST_METHOD0(get12VInputVoltage, float());
    MOCK_CONST_METHOD0(getFanVoltage, float());
    MOCK_CONST_METHOD0(getPackCurrent, float());
    MOCK_CONST_METHOD0(getPackVoltage, float());
    MOCK_CONST_METHOD0(getPackStateOfCharge, float());
    MOCK_CONST_METHOD0(getPackAmphours, float());
    MOCK_CONST_METHOD0(getPackDepthOfDischarge, float());
    MOCK_CONST_METHOD0(getHighTemperature, unsigned char());
    MOCK_CONST_METHOD0(getHighThermistorId, unsigned char());
    MOCK_CONST_METHOD0(getLowTemperature, unsigned char());
    MOCK_CONST_METHOD0(getLowThermistorId, unsigned char());
    MOCK_CONST_METHOD0(getAverageTemperature, unsigned char());
    MOCK_CONST_METHOD0(getInternalTemperature, unsigned char());
    MOCK_CONST_METHOD0(getFanSpeed, unsigned char());
    MOCK_CONST_METHOD0(getRequestedFanSpeed, unsigned char());
    MOCK_CONST_METHOD0(getLowCellVoltage, unsigned short());
    MOCK_CONST_METHOD0(getLowCellVoltageId, unsigned char());
    MOCK_CONST_METHOD0(getHighCellVoltage, unsigned short());
    MOCK_CONST_METHOD0(getHighCellVoltageId, unsigned char());
    MOCK_CONST_METHOD0(getAverageCellVoltage, unsigned short());

    MOCK_CONST_METHOD0(bmsDischargeRelayEnabled, bool());
    MOCK_CONST_METHOD0(bmsChargeRelayEnabled, bool());
    MOCK_CONST_METHOD0(bmsChargerSafetyEnabled, bool());
    MOCK_CONST_METHOD0(bmsMalfunctionIndicatorActive, bool());
    MOCK_CONST_METHOD0(bmsGetMultiPurposeInputSignalStatus, bool());
    MOCK_CONST_METHOD0(bmsGetAlwaysOnSignalStatus, bool());
    MOCK_CONST_METHOD0(bmsGetIsReadySignalStatus, bool());
    MOCK_CONST_METHOD0(bmsGetIsChargingSignalStatus, bool());

    /*BatteryData "Sets"*/
    MOCK_METHOD1(setAlive, void(const bool&));
    MOCK_METHOD1(setBmsRelayStatus, void(const unsigned char&));
    MOCK_METHOD1(setPopulatedCells, void(const unsigned char&));
    MOCK_METHOD1(set12VInputVoltage, void(const float&));
    MOCK_METHOD1(setFanVoltage, void(const float&));
    MOCK_METHOD1(setPackCurrent, void(const float&));
    MOCK_METHOD1(setPackVoltage, void(const float&));
    MOCK_METHOD1(setPackStateOfCharge, void(const float&));
    MOCK_METHOD1(setPackAmphours, void(const float&));
    MOCK_METHOD1(setPackDepthOfDischarge, void(const float&));
    MOCK_METHOD1(setHighTemperature, void(const unsigned char&));
    MOCK_METHOD1(setHighThermistorId, void(const unsigned char&));
    MOCK_METHOD1(setLowTemperature, void(const unsigned char&));
    MOCK_METHOD1(setLowThermistorId, void(const unsigned char&));
    MOCK_METHOD1(setAverageTemperature, void(const unsigned char&));
    MOCK_METHOD1(setInternalTemperature, void(const unsigned char&));
    MOCK_METHOD1(setFanSpeed, void(const unsigned char&));
    MOCK_METHOD1(setRequestedFanSpeed, void(const unsigned char&));
    MOCK_METHOD1(setLowCellVoltage, void(const unsigned short&));
    MOCK_METHOD1(setLowCellVoltageId, void(const unsigned char&));
    MOCK_METHOD1(setHighCellVoltage, void(const unsigned short&));
    MOCK_METHOD1(setHighCellVoltageId, void(const unsigned char&));
    MOCK_METHOD1(setAverageCellVoltage, void(const unsigned short&));
};
