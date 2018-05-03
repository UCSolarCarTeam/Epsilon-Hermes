#pragma once

#include <QObject>

class I_BatteryData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_BatteryData() {}

    /*Data "Gets"*/
    virtual bool getAlive() const = 0;
    virtual unsigned char getBmsRelayStatus() const = 0;
    virtual unsigned char getPopulatedCells() const = 0;
    virtual float get12VInputVoltage() const = 0;
    virtual float getFanVoltage() const = 0;
    virtual float getPackCurrent() const = 0;
    virtual float getPackVoltage() const = 0;
    virtual float getPackStateOfCharge() const = 0;
    virtual float getPackAmphours() const = 0;
    virtual float getPackDepthOfDischarge() const = 0;
    virtual unsigned char getHighTemperature() const = 0;
    virtual unsigned char getHighThermistorId() const = 0;
    virtual unsigned char getLowTemperature() const = 0;
    virtual unsigned char getLowThermistorId() const = 0;
    virtual unsigned char getAverageTemperature() const = 0;
    virtual unsigned char getInternalTemperature() const = 0;
    virtual unsigned char getFanSpeed() const = 0;
    virtual unsigned char getRequestedFanSpeed() const = 0;
    virtual unsigned short getLowCellVoltage() const = 0;
    virtual unsigned char getLowCellVoltageId() const = 0;
    virtual unsigned short getHighCellVoltage() const = 0;
    virtual unsigned char getHighCellVoltageId() const = 0;
    virtual unsigned short getAverageCellVoltage() const = 0;

    /* BMS relay status getter */
    virtual bool bmsDischargeRelayEnabled() const = 0;
    virtual bool bmsChargeRelayEnabled() const = 0;
    virtual bool bmsChargerSafetyEnabled() const = 0;
    virtual bool bmsMalfunctionIndicatorActive() const = 0;
    virtual bool bmsGetMultiPurposeInputSignalStatus() const = 0;
    virtual bool bmsGetAlwaysOnSignalStatus() const = 0;
    virtual bool bmsGetIsReadySignalStatus() const = 0;
    virtual bool bmsGetIsChargingSignalStatus() const = 0;

    /*BatteryData "Sets"*/
    virtual void setAlive(const bool&) = 0;
    virtual void setBmsRelayStatus(const unsigned char&) = 0;
    virtual void setPopulatedCells(const unsigned char&) = 0;
    virtual void set12VInputVoltage(const float&) = 0;
    virtual void setFanVoltage(const float&) = 0;
    virtual void setPackCurrent(const float&) = 0;
    virtual void setPackVoltage(const float&) = 0;
    virtual void setPackStateOfCharge(const float&) = 0;
    virtual void setPackAmphours(const float&) = 0;
    virtual void setPackDepthOfDischarge(const float&) = 0;
    virtual void setHighTemperature(const unsigned char&) = 0;
    virtual void setHighThermistorId(const unsigned char&) = 0;
    virtual void setLowTemperature(const unsigned char&) = 0;
    virtual void setLowThermistorId(const unsigned char&) = 0;
    virtual void setAverageTemperature(const unsigned char&) = 0;
    virtual void setInternalTemperature(const unsigned char&) = 0;
    virtual void setFanSpeed(const unsigned char&) = 0;
    virtual void setRequestedFanSpeed(const unsigned char&) = 0;
    virtual void setLowCellVoltage(const unsigned short&) = 0;
    virtual void setLowCellVoltageId(const unsigned char&) = 0;
    virtual void setHighCellVoltage(const unsigned short&) = 0;
    virtual void setHighCellVoltageId(const unsigned char&) = 0;
    virtual void setAverageCellVoltage(const unsigned short&) = 0;

signals:
    void aliveReceived(const bool& alive);
    void bmsRelayStatusReceived(const unsigned char&);
    void populatedCellsReceived(const unsigned char&);
    void inputVoltage12VReceived(const float&);
    void fanVoltageReceived(const float&);
    void packCurrentReceived(const float&);
    void packVoltageReceived(const float&);
    void packStateOfChargeReceived(const float&);
    void packAmphoursReceived(const float&);
    void packDepthOfDischargeReceived(const float&);
    void highTemperatureReceived(const unsigned char&);
    void highThermistorIdReceived(const unsigned char&);
    void lowTemperatureReceived(const unsigned char&);
    void lowThermistorIdReceived(const unsigned char&);
    void averageTemperatureReceived(const unsigned char&);
    void internalTemperatureReceived(const unsigned char&);
    void fanSpeedReceived(const unsigned char&);
    void requestedFanSpeedReceived(const unsigned char&);
    void lowCellVoltageReceived(const unsigned short&);
    void lowCellVoltageIdReceived(const unsigned char&);
    void highCellVoltageReceived(const unsigned short&);
    void highCellVoltageIdReceived(const unsigned char&);
    void averageCellVoltageReceived(const unsigned short&);
};
