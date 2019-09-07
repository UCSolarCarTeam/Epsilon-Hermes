#include "MpptUnit.h"

namespace
{
    const int CENTI_TO_ONES = 100.0;
    const int MILLI_TO_ONES = 1000.0;
}

MpptUnit::MpptUnit()
    : mpptStatus_(0)
    , arrayVoltage_(0)
    , arrayCurrent_(0)
    , batteryVoltage_(0)
    , temperature_(0)
{
    //  Initialize to 0
}

MpptUnit::~MpptUnit()
{
}

/* MpptUnit Gets */
unsigned char MpptUnit::getMpptStatus() const
{
    return mpptStatus_;
}

float MpptUnit::getArrayVoltage() const
{
    return arrayVoltage_;
}

float MpptUnit::getArrayCurrent() const
{
    return arrayCurrent_;
}

float MpptUnit::getBatteryVoltage() const
{
    return batteryVoltage_;
}

float MpptUnit::getTemperature() const
{
    return temperature_;
}


/* MpptUnit Sets */
void MpptUnit::setMpptStatus(const unsigned char& mpptStatus)
{
    mpptStatus_ = mpptStatus;
}

void MpptUnit::setArrayVoltage(const unsigned short& arrayVoltage)
{
    arrayVoltage_ = (arrayVoltage / CENTI_TO_ONES);
}

void MpptUnit::setArrayCurrent(const unsigned short& arrayCurrent)
{
    arrayCurrent_ = (arrayCurrent / MILLI_TO_ONES);
}

void MpptUnit::setBatteryVoltage(const unsigned short& batteryVoltage)
{
    batteryVoltage_ = (batteryVoltage / CENTI_TO_ONES);
}

void MpptUnit::setTemperature(const unsigned short& temperature)
{
    temperature_ = (temperature / CENTI_TO_ONES);
}


