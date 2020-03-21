#pragma once

#include "DataLayer/AuxBmsData/I_AuxBmsData.h"

class MockAuxBmsData : public I_AuxBmsData
{
public:

    /*AuxBmsData "Gets"*/
    MOCK_CONST_METHOD0(getPrechargeState, I_AuxBmsData::PrechargeState());
    MOCK_CONST_METHOD0(getAuxVoltage, unsigned char());
    MOCK_CONST_METHOD0(getAuxBmsAlive, bool());
    MOCK_CONST_METHOD0(getStrobeBmsLight, bool());
    MOCK_CONST_METHOD0(getAllowCharge, bool());
    MOCK_CONST_METHOD0(getHighVoltageEnableState, bool());
    MOCK_CONST_METHOD0(getAllowDischarge, bool());

    MOCK_CONST_METHOD0(getOrionCANReceivedRecently, bool());
    MOCK_CONST_METHOD0(getChargeContactorError, bool());
    MOCK_CONST_METHOD0(getDischargeContactorError, bool());
    MOCK_CONST_METHOD0(getCommonContactorError, bool());
    MOCK_CONST_METHOD0(getDischargeShouldTrip, bool());
    MOCK_CONST_METHOD0(getChargeShouldTrip, bool());
    MOCK_CONST_METHOD0(getChargeOpenButShouldBeClosed, bool());
    MOCK_CONST_METHOD0(getDischargeOpenButShouldBeClosed, bool());

    MOCK_CONST_METHOD0(getChargeTripDueToHighCellVoltage, bool());
    MOCK_CONST_METHOD0(getChargeTripDueToHighTemperatureAndCurrent, bool());
    MOCK_CONST_METHOD0(getChargeTripDueToPackCurrent, bool());
    MOCK_CONST_METHOD0(getDischargeTripDueToLowCellVoltage, bool());
    MOCK_CONST_METHOD0(getDischargeTripDueToHighTemeratureAndCurrent, bool());
    MOCK_CONST_METHOD0(getDischargeTripDueToPackCurrent, bool());
    MOCK_CONST_METHOD0(getProtectionTrip, bool());

    /*AuxBmsData "Sets"*/
    MOCK_METHOD1(setPrechargeState, void(const unsigned char&));
    MOCK_METHOD1(setAuxVoltage, void(const unsigned char&));
    MOCK_METHOD1(setAuxBmsAlive, void(const bool&));
    MOCK_METHOD1(setStrobeBmsLight, void(const bool&));
    MOCK_METHOD1(setAllowCharge, void(const bool&));
    MOCK_METHOD1(setHighVoltageEnableState, void(const bool&));
    MOCK_METHOD1(setAllowDischarge, void(const bool&));

    MOCK_METHOD1(setAuxContactor, void(const unsigned char));
    MOCK_METHOD1(setAuxTrip, void(const unsigned char));
};
