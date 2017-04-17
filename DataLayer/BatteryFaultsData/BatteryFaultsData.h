#pragma once

#include "I_BatteryFaultsData.h"

class BatteryFaultsData : public I_BatteryFaultsData
{
public:
    BatteryFaultsData();
    virtual ~BatteryFaultsData();

    /* BatteryFaults Gets */
    unsigned int getErrorFlags() const;
    unsigned short getLimitFlags() const;

    /* BatteryFaultsData status (error flags) */
    bool internalCommunicationFault() const;
    bool internalConversionFault() const;
    bool weakCellFault() const;
    bool lowCellVoltageFault() const;
    bool openWiringFault() const;
    bool currentSensorFault() const;
    bool packVoltageSensorFault() const;
    bool weakPackFault() const;
    bool voltageRedundancyFault() const;
    bool fanMonitorFault() const;
    bool thermistorFault() const;
    bool canbusCommunicationsFault() const;
    bool alwaysOnSupplyFault() const;
    bool highVoltageIsolationFault() const;
    bool powerSupply12VFault() const;
    bool chargeLimitEnforcementFault() const;
    bool dischargeLimitEnforcementFault() const;
    bool chargerSafetyRelayFault() const;
    bool internalMemoryFault() const;
    bool internalThermistorFault() const;
    bool internalLogicFault() const;

    /* BatteryFaultsData status (limit flags) */
    bool dclReducedDueToLowSoc() const;
    bool dclReducedDueToHighCellResistence() const;
    bool dclReducedDueToTemperature() const;
    bool dclReducedDueToLowCellVoltage() const;
    bool dclReducedDueToLowPackVoltage() const;
    bool dclAndCclReducedDueToVoltageFailsafe() const;
    bool dclAndCclReducedDueToCommunicationFailsafe() const;
    bool cclReducedDueToHighSoc() const;
    bool cclReducedDueToHighCellResistence() const;
    bool cclReducedDueToTemperature() const;
    bool cclReducedDueToHighCellVoltage() const;
    bool cclReducedDueToHighPackVoltage() const;
    bool cclReducedDueToChargerLatch() const;
    bool cclReducedDueToAlternateCurrentLimit() const;

    bool operator==(const I_BatteryFaultsData& other) const;

    QString toString() const;

    /* BatteryFaults Sets */
    void setErrorFlags(const unsigned int& errorFlags);
    void setLimitFlags(const unsigned short& limitFlags);


protected:
    unsigned int errorFlags_;
    unsigned short limitFlags_;

    inline bool errorFlagPresent(const unsigned int errorMask) const;
    inline bool limitFlagPresent(const unsigned short limitMask) const;
    inline void appendIfPresent(QString& messageString, const unsigned int errorMask, QString errorDescription) const;
    inline void appendIfPresent(QString& messageString, const unsigned short limitMask, QString limitDescription) const;
};
