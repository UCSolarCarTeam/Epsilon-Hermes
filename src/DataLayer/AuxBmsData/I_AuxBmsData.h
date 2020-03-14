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
    virtual bool getContactorError() const = 0;
    virtual bool getHighVoltageEnable() const = 0;

    virtual bool getChargeTripDueToHighCellVoltage() const = 0;
    virtual bool getChargeTripDueToHighTemperatureAndCurrent() const = 0;
    virtual bool getChargeTripDueToPackCurrent() const = 0;
    virtual bool getDischargeTripDueToLowCellVoltage() const = 0;
    virtual bool getDischargeTripDueToHighTemeratureAndCurrent() const = 0;
    virtual bool getDischargeTripDueToPackCurrent() const = 0;
    virtual bool getProtectionTrip() const = 0;

    /*AuxBmsData "Sets"*/
    virtual void setPrechargeState(const unsigned char&) = 0;
    virtual void setAuxVoltage(const unsigned char&) = 0;
    virtual void setAuxBmsAlive(const bool&) = 0;
    virtual void setStrobeBmsLight(const bool&) = 0;
    virtual void setAllowCharge(const bool&) = 0;
    virtual void setContactorError(const bool&) = 0;
    virtual void setHighVoltageEnable(const bool&) = 0;

    virtual void setAuxTrip(const unsigned char auxTrip) = 0;
};
