#pragma once

#include <QObject>

class I_BatteryFaultsData : public QObject
{
    Q_OBJECT
public:
    virtual ~I_BatteryFaultsData() {}

    /* BatteryFaultsData Gets */
    virtual unsigned int getErrorFlags() const = 0;
    virtual unsigned short getLimitFlags() const = 0;

    /* BatteryFaultsData status (error flags) */
    virtual bool internalCommunicationFault() const = 0;
    virtual bool internalConversionFault() const = 0;
    virtual bool weakCellFault() const = 0;
    virtual bool lowCellVoltageFault() const = 0;
    virtual bool openWiringFault() const = 0;
    virtual bool currentSensorFault() const = 0;
    virtual bool packVoltageSensorFault() const = 0;
    virtual bool weakPackFault() const = 0;
    virtual bool voltageRedundancyFault() const = 0;
    virtual bool fanMonitorFault() const = 0;
    virtual bool thermistorFault() const = 0;
    virtual bool canbusCommunicationsFault() const = 0;
    virtual bool alwaysOnSupplyFault() const = 0;
    virtual bool highVoltageIsolationFault() const = 0;
    virtual bool powerSupply12VFault() const = 0;
    virtual bool chargeLimitEnforcementFault() const = 0;
    virtual bool dischargeLimitEnforcementFault() const = 0;
    virtual bool chargerSafetyRelayFault() const = 0;
    virtual bool internalMemoryFault() const = 0;
    virtual bool internalThermistorFault() const = 0;
    virtual bool internalLogicFault() const = 0;

    /* BatteryFaultsData status (limit flags) */
    virtual bool dclReducedDueToLowSoc() const = 0;
    virtual bool dclReducedDueToHighCellResistence() const = 0;
    virtual bool dclReducedDueToTemperature() const = 0;
    virtual bool dclReducedDueToLowCellVoltage() const = 0;
    virtual bool dclReducedDueToLowPackVoltage() const = 0;
    virtual bool dclAndCclReducedDueToVoltageFailsafe() const = 0;
    virtual bool dclAndCclReducedDueToCommunicationFailsafe() const = 0;
    virtual bool cclReducedDueToHighSoc() const = 0;
    virtual bool cclReducedDueToHighCellResistence() const = 0;
    virtual bool cclReducedDueToTemperature() const = 0;
    virtual bool cclReducedDueToHighCellVoltage() const = 0;
    virtual bool cclReducedDueToHighPackVoltage() const = 0;
    virtual bool cclReducedDueToChargerLatch() const = 0;
    virtual bool cclReducedDueToAlternateCurrentLimit() const = 0;

    virtual bool operator==(const I_BatteryFaultsData& other) const = 0;

    /* BatteryFaults Sets */
    virtual void setErrorFlags(const unsigned int& errorFlags) = 0;
    virtual void setLimitFlags(const unsigned short& limitFlags) = 0;
};
