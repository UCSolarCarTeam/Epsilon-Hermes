#pragma once

#include "I_AuxBMSData.h"

class AuxBMSData : public I_AuxBMSData
{
public:

    AuxBMSData();
    virtual ~AuxBMSData();

    /*Data "Gets"*/
    PrechargeState getPrechargeState() const;
    unsigned char getAuxVoltage() const;
    bool getAuxBmsAlive() const;
    bool getStrobeBmsLight() const;
    bool getAllowCharge() const;
    bool getContactorError() const;

    /*AuxBMSData "Sets"*/
    void setPrechargeState(const unsigned char&);
    void setAuxVoltage(const unsigned char&);
    void setAuxBmsAlive(const bool&);
    void setStrobeBmsLight(const bool&);
    void setAllowCharge(const bool&);
    void setContactorError(const bool&);

private:
    PrechargeState prechargeState_;
    unsigned char auxVoltage_;
    bool auxBmsAlive_;
    bool strobeBmsLight_;
    bool allowCharge_;
    bool contactorError_;
};