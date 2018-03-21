#pragma once

#include <QObject>

class I_AuxBMSData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_AuxBMSData() {}

    enum PrechargeState
    {
        IDLE = 0,
        PRECHARGE = 1,
        MEASURE = 2,
        ENABLE_PACK = 3,
        RUN = 4
    };

    /*Data "Gets"*/
    virtual PrechargeState getPrechargeState() const = 0;
    virtual unsigned char getAuxVoltage() const = 0;
    virtual bool getAuxBmsAlive() const = 0;
    virtual bool getStrobeBmsLight() const = 0;
    virtual bool getAllowCharge() const = 0;
    virtual bool getContactorError() const = 0;

    /*AuxBMSData "Sets"*/
    virtual void setPrechargeState(const unsigned char&) = 0;
    virtual void setAuxVoltage(const unsigned char&) = 0;
    virtual void setAuxBmsAlive(const bool&) = 0;
    virtual void setStrobeBmsLight(const bool&) = 0;
    virtual void setAllowCharge(const bool&) = 0;
    virtual void setContactorError(const bool&) = 0;

signals:
    void prechargeStateReceived(const unsigned char&);
    void auxVoltageReceived(const unsigned char&);
    void auxBmsAliveReceived(const bool&);
    void strobeBmsLightRecieved(const bool&);
    void allowChargeRecieved(const bool&);
    void contactorErrorRecieved(const bool&);
};