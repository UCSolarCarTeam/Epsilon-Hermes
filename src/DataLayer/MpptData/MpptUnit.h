#pragma once

#include "I_MpptUnit.h"

class MpptUnit : public I_MpptUnit
{
public:
    MpptUnit();
    virtual ~MpptUnit();

    /* MpptUnit Gets */
    unsigned char getMpptStatus() const;
    float getArrayVoltage() const;
    float getArrayCurrent() const;
    float getBatteryVoltage() const;
    float getTemperature() const;

    /* MpptUnit Sets */
    void setMpptStatus(const unsigned char& mpptStatus);
    void setArrayVoltage(const unsigned short& arrayVoltage);
    void setArrayCurrent(const unsigned short& arrayCurrent);
    void setBatteryVoltage(const unsigned short& batteryVoltage);
    void setTemperature(const unsigned short& temperature);


private:
    unsigned char mpptStatus_;
    float arrayVoltage_;
    float arrayCurrent_;
    float batteryVoltage_;
    float temperature_;
};
