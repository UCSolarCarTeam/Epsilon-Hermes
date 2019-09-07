#pragma once

#include "DataLayer/MpptData/I_MpptUnit.h"

class MockMpptUnit : public I_MpptUnit
{
public:

    /*MpptUnit "Gets"*/
    MOCK_CONST_METHOD0(getMpptStatus, unsigned char());
    MOCK_CONST_METHOD0(getArrayVoltage, float());
    MOCK_CONST_METHOD0(getArrayCurrent, float());
    MOCK_CONST_METHOD0(getBatteryVoltage, float());
    MOCK_CONST_METHOD0(getTemperature, float());


    /*MpptUnit "Gets"*/
    MOCK_METHOD1(setMpptStatus, void(const unsigned char&));
    MOCK_METHOD1(setArrayVoltage, void(const unsigned short&));
    MOCK_METHOD1(setArrayCurrent, void(const unsigned short&));
    MOCK_METHOD1(setBatteryVoltage, void(const unsigned short&));
    MOCK_METHOD1(setTemperature, void(const unsigned short&));
};
