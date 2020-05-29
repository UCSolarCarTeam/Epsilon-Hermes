#pragma once

#include "I_AuxBmsData.h"

class AuxBmsData : public I_AuxBmsData
{
public:

    AuxBmsData();
    virtual ~AuxBmsData();

    /*Data "Gets"*/
    PrechargeState getPrechargeState() const;
    unsigned char getAuxVoltage() const;
    bool getAuxBmsAlive() const;
    bool getStrobeBmsLight() const;
    bool getAllowCharge() const;
    bool getHighVoltageEnableState() const;
    bool getAllowDischarge() const;
    bool getOrionCanReceivedRecently() const;

    bool getChargeContactorError() const;
    bool getDischargeContactorError() const;
    bool getCommonContactorError() const;
    bool getDischargeShouldTrip() const;
    bool getChargeShouldTrip() const;
    bool getChargeOpenButShouldBeClosed() const;
    bool getDischargeOpenButShouldBeClosed() const;

    bool getChargeTripDueToHighCellVoltage() const;
    bool getChargeTripDueToHighTemperatureAndCurrent() const;
    bool getChargeTripDueToPackCurrent() const;
    bool getDischargeTripDueToLowCellVoltage() const;
    bool getDischargeTripDueToHighTemperatureAndCurrent() const;
    bool getDischargeTripDueToPackCurrent() const;
    bool getProtectionTrip() const;

    /*AuxBmsData "Sets"*/
    void setPrechargeState(const unsigned char&);
    void setAuxVoltage(const unsigned char&);
    void setAuxBmsAlive(const bool&);
    void setStrobeBmsLight(const bool&);
    void setAllowCharge(const bool&);
    void setHighVoltageEnableState(const bool&);
    void setAllowDischarge(const bool&);
    void setOrionCanReceivedRecently(const bool&);

    void setAuxContactor(const unsigned char auxContactor);
    void setAuxTrip(const unsigned char auxTrip);

private:
    bool auxMaskedBit(const unsigned char mask, unsigned char bits) const;

    PrechargeState prechargeState_;
    unsigned char auxVoltage_;
    bool auxBmsAlive_;
    bool strobeBmsLight_;
    bool allowCharge_;
    bool highVoltageEnableState_;
    bool allowDischarge_;
    bool orionCanReceivedRecently_;
    unsigned char auxContactor_;
    unsigned char auxTrip_;
};
