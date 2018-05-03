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
    MOCK_CONST_METHOD0(getContactorError, bool());

    /*AuxBmsData "Sets"*/
    MOCK_METHOD1(setPrechargeState, void(const unsigned char&));
    MOCK_METHOD1(setAuxVoltage, void(const unsigned char&));
    MOCK_METHOD1(setAuxBmsAlive, void(const bool&));
    MOCK_METHOD1(setStrobeBmsLight, void(const bool&));
    MOCK_METHOD1(setAllowCharge, void(const bool&));
    MOCK_METHOD1(setContactorError, void(const bool&));
};
