#include "MpptUnit.h"

namespace
{
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

unsigned short MpptUnit::getArrayVoltage() const
{
    return arrayVoltage_;
}

unsigned short MpptUnit::getArrayCurrent() const
{
    return arrayCurrent_;
}

unsigned short MpptUnit::getBatteryVoltage() const
{
    return batteryVoltage_;
}

unsigned short MpptUnit::getTemperature() const
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
    arrayVoltage_ = (arrayVoltage);
}

void MpptUnit::setArrayCurrent(const unsigned short& arrayCurrent)
{
    arrayCurrent_ = (arrayCurrent);
}

void MpptUnit::setBatteryVoltage(const unsigned short& batteryVoltage)
{
    batteryVoltage_ = (batteryVoltage);
}

void MpptUnit::setTemperature(const unsigned short& temperature)
{
    temperature_ = (temperature);
}


