#pragma once

#include "I_BatteryData.h"

class FakeBatteryData : public I_BatteryData
{
public:
    FakeBatteryData();
    virtual ~FakeBatteryData();

    /*Data "Gets"*/
    bool getAlive() const;
    unsigned char getBmsRelayStatus() const; // will return the complete set of bitflags
    unsigned char getPopulatedCells() const;
    float get12VInputVoltage() const;
    float getFanVoltage() const;
    float getPackCurrent() const;
    float getPackVoltage() const;
    float getPackStateOfCharge() const;
    float getPackAmphours() const;
    float getPackDepthOfDischarge() const;
    unsigned char getHighTemperature() const;
    unsigned char getHighThermistorId() const;
    unsigned char getLowTemperature() const;
    unsigned char getLowThermistorId() const;
    unsigned char getAverageTemperature() const;
    unsigned char getInternalTemperature() const;
    unsigned char getFanSpeed() const;
    unsigned char getRequestedFanSpeed() const;
    unsigned short getLowCellVoltage() const;
    unsigned char getLowCellVoltageId() const;
    unsigned short getHighCellVoltage() const;
    unsigned char getHighCellVoltageId() const;
    unsigned short getAverageCellVoltage() const;
    PrechargeState getPrechargeState() const;
    unsigned char getAuxVoltage() const;
    bool getAuxBmsAlive() const;

    /* BMS relay status getter */
    bool bmsDischargeRelayEnabled() const;
    bool bmsChargeRelayEnabaled() const;
    bool bmsChargerSafetyEnabled() const;
    bool bmsMalfunctionIndicatorActive() const;
    bool bmsGetMultiPurposeInputSignalStatus() const;
    bool bmsGetAlwaysOnSignalStatus() const;
    bool bmsGetIsReadySignalStatus() const;
    bool bmsGetIsChargingSignalStatus() const;

    /*BatteryData "Sets"*/
    void setAlive(const unsigned char&);
    void setBmsRelayStatus(const unsigned char&);
    void setPopulatedCells(const unsigned char&);
    void set12VInputVoltage(const float&);
    void setFanVoltage(const float&);
    void setPackCurrent(const float&);
    void setPackVoltage(const float&);
    void setPackStateOfCharge(const float&);
    void setPackAmphours(const float&);
    void setPackDepthOfDischarge(const float&);
    void setHighTemperature(const unsigned char&);
    void setHighThermistorId(const unsigned char&);
    void setLowTemperature(const unsigned char&);
    void setLowThermistorId(const unsigned char&);
    void setAverageTemperature(const unsigned char&);
    void setInternalTemperature(const unsigned char&);
    void setFanSpeed(const unsigned char&);
    void setRequestedFanSpeed(const unsigned char&);
    void setLowCellVoltage(const unsigned short&);
    void setLowCellVoltageId(const unsigned char&);
    void setHighCellVoltage(const unsigned short&);
    void setHighCellVoltageId(const unsigned char&);
    void setAverageCellVoltage(const unsigned short&);
    void setPrechargeState(const unsigned char&);
    void setAuxVoltage(const unsigned char&);
    void setAuxBmsAlive(const unsigned char&);
};
