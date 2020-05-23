#pragma once

#include <QObject>

class I_AuxBmsData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_AuxBmsData() {}

    enum PrechargeState
    {
        OFF = 0,
        COMMON_ENGAGED = 1,
        CHARGE_ENGAGED = 2,
        DISCHARGE_ENGAGED = 3,
        ALL_ENGAGED = 4,
        INVALID_STATE = 5,
    };

    /*Data "Gets"*/
    virtual PrechargeState getPrechargeState() const = 0;
    virtual unsigned char getAuxVoltage() const = 0;
    virtual bool getAuxBmsAlive() const = 0;
    virtual bool getStrobeBmsLight() const = 0;
    virtual bool getAllowCharge() const = 0;
    virtual bool getHighVoltageEnableState() const = 0;
    virtual bool getAllowDischarge() const = 0;

    virtual bool getOrionCANReceivedRecently() const = 0;
    virtual bool getChargeContactorError() const = 0;
    virtual bool getDischargeContactorError() const = 0;
    virtual bool getCommonContactorError() const = 0;
    virtual bool getDischargeShouldTrip() const = 0;
    virtual bool getChargeShouldTrip() const = 0;
    virtual bool getChargeOpenButShouldBeClosed() const = 0;
    virtual bool getDischargeOpenButShouldBeClosed() const = 0;

    virtual bool getChargeTripDueToHighCellVoltage() const = 0;
    virtual bool getChargeTripDueToHighTemperatureAndCurrent() const = 0;
    virtual bool getChargeTripDueToPackCurrent() const = 0;
    virtual bool getDischargeTripDueToLowCellVoltage() const = 0;
    virtual bool getDischargeTripDueToHighTemperatureAndCurrent() const = 0;
    virtual bool getDischargeTripDueToPackCurrent() const = 0;
    virtual bool getProtectionTrip() const = 0;

    /*AuxBmsData "Sets"*/
    virtual void setPrechargeState(const unsigned char&) = 0;
    virtual void setAuxVoltage(const unsigned char&) = 0;
    virtual void setAuxBmsAlive(const bool&) = 0;
    virtual void setStrobeBmsLight(const bool&) = 0;
    virtual void setAllowCharge(const bool&) = 0;
    virtual void setHighVoltageEnableState(const bool&) = 0;
    virtual void setAllowDischarge(const bool&) = 0;

    virtual void setAuxContactor(const unsigned char auxContactor) = 0;
    virtual void setAuxTrip(const unsigned char auxTrip) = 0;
};
