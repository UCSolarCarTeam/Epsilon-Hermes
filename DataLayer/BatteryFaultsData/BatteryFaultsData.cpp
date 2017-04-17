#include "BatteryFaultsData.h"

#include <QString>

namespace
{
    // error flag masks
    const unsigned int INTERNAL_COMMUNICATION_FAULT_MASK      = 0x00000001;
    const unsigned int INTERNAL_CONVERSION_FAULT_MASK         = 0x00000002;
    const unsigned int WEAK_CELL_FAULT_MASK                   = 0x00000004;
    const unsigned int LOW_CELL_VOLTAGE_FAULT_MASK            = 0x00000008;
    const unsigned int OPEN_WIRING_FAULT_MASK                 = 0x00000010;
    const unsigned int CURRENT_SENSOR_FAULT_MASK              = 0x00000020;
    const unsigned int PACK_VOLTAGE_SENSOR_FAULT_MASK         = 0x00000040;
    const unsigned int WEAK_PACK_FAULT_MASK                   = 0x00000080;
    const unsigned int VOLTAGE_REDUNDANCY_FAULT_MASK          = 0x00000100;
    const unsigned int FAN_MONITOR_FAULT_MASK                 = 0x00000200;
    const unsigned int THERMISTOR_FAULT_MASK                  = 0x00000400;
    const unsigned int CANBUS_COMMUNICATIONS_FAULT_MASK       = 0x00000800;
    const unsigned int ALWAYS_ON_SUPPLY_FAULT_MASK            = 0x00001000;
    const unsigned int HIGH_VOLTAGE_ISOLATION_FAULT_MASK      = 0x00002000;
    const unsigned int POWER_SUPPLY_12V_FAULT_MASK            = 0x00004000;
    const unsigned int CHARGE_LIMIT_ENFORCEMENT_FAULT_MASK    = 0x00008000;
    const unsigned int DISCHARGE_LIMIT_ENFORCEMENT_FAULT_MASK = 0x00010000;
    const unsigned int CHARGER_SAFETY_RELAY_FAULT_MASK        = 0x00020000;
    const unsigned int INTERNAL_MEMORY_FAULT_MASK             = 0x00040000;
    const unsigned int INTERNAL_THERMISTOR_FAULT_MASK         = 0x00080000;
    const unsigned int INTERNAL_LOGIC_FAULT_MASK              = 0x00100000;

    // limit flag masks
    const unsigned short DCL_REDUCED_DUE_TO_LOW_SOC_MASK              = 0x0001;
    const unsigned short DCL_REDUCED_DUE_TO_HIGH_CELL_RESISTENCE_MASK = 0x0002;
    const unsigned short DCL_REDUCED_DUE_TO_TEMPERATURE_MASK          = 0x0004;
    const unsigned short DCL_REDUCED_DUE_TO_LOW_CELL_VOLTAGE_MASK     = 0x0008;
    const unsigned short DCL_REDUCED_DUE_TO_LOW_PACK_VOLTAGE_MASK     = 0x0010;
    // 0x0020 N/A
    const unsigned short DCL_AND_CCL_REDUCED_DUE_TO_VOLTAGE_FAILSAFE_MASK       = 0x0040;
    const unsigned short DCL_AND_CCL_REDUCED_DUE_TO_COMMUNICATION_FAILSAFE_MASK = 0x0080;
    // 0x0100 N/A
    const unsigned short CCL_REDUCED_DUE_TO_HIGH_SOC_MASK                = 0x0200;
    const unsigned short CCL_REDUCED_DUE_TO_HIGH_CELL_RESISTENCE_MASK    = 0x0400;
    const unsigned short CCL_REDUCED_DUE_TO_TEMPERATURE_MASK             = 0x0800;
    const unsigned short CCL_REDUCED_DUE_TO_HIGH_CELL_VOLTAGE_MASK       = 0x1000;
    const unsigned short CCL_REDUCED_DUE_TO_HIGH_PACK_VOLTAGE_MASK       = 0x2000;
    const unsigned short CCL_REDUCED_DUE_TO_CHARGER_LATCH_MASK           = 0x4000;
    const unsigned short CCL_REDUCED_DUE_TO_ALTERNATE_CURRENT_LIMIT_MASK = 0x8000;
}

BatteryFaultsData::BatteryFaultsData()
    : errorFlags_(0), limitFlags_(0)
{
    // Initialize to 0
}
BatteryFaultsData::~BatteryFaultsData()
{
}

/* BatteryFaults Gets */
unsigned int BatteryFaultsData::getErrorFlags() const
{
    return errorFlags_;
}

unsigned short BatteryFaultsData::getLimitFlags() const
{
    return limitFlags_;
}


bool BatteryFaultsData::errorFlagPresent(const unsigned int errorMask) const
{
    return static_cast<bool>(errorFlags_ & errorMask);
}

bool BatteryFaultsData::limitFlagPresent(const unsigned short limitMask) const
{
    return static_cast<bool>(limitFlags_ & limitMask);
}

/* BatteryFaults status (error flags) */
bool BatteryFaultsData::internalCommunicationFault() const
{
    return errorFlagPresent(INTERNAL_COMMUNICATION_FAULT_MASK);
}

bool BatteryFaultsData::internalConversionFault() const
{
    return errorFlagPresent(INTERNAL_CONVERSION_FAULT_MASK);
}

bool BatteryFaultsData::weakCellFault() const
{
    return errorFlagPresent(WEAK_CELL_FAULT_MASK);
}

bool BatteryFaultsData::lowCellVoltageFault() const
{
    return errorFlagPresent(LOW_CELL_VOLTAGE_FAULT_MASK);
}

bool BatteryFaultsData::openWiringFault() const
{
    return errorFlagPresent(OPEN_WIRING_FAULT_MASK);
}

bool BatteryFaultsData::currentSensorFault() const
{
    return errorFlagPresent(CURRENT_SENSOR_FAULT_MASK);
}

bool BatteryFaultsData::packVoltageSensorFault() const
{
    return errorFlagPresent(PACK_VOLTAGE_SENSOR_FAULT_MASK);
}

bool BatteryFaultsData::weakPackFault() const
{
    return errorFlagPresent(WEAK_PACK_FAULT_MASK);
}

bool BatteryFaultsData::voltageRedundancyFault() const
{
    return errorFlagPresent(VOLTAGE_REDUNDANCY_FAULT_MASK);
}

bool BatteryFaultsData::fanMonitorFault() const
{
    return errorFlagPresent(FAN_MONITOR_FAULT_MASK);
}

bool BatteryFaultsData::thermistorFault() const
{
    return errorFlagPresent(THERMISTOR_FAULT_MASK);
}

bool BatteryFaultsData::canbusCommunicationsFault() const
{
    return errorFlagPresent(CANBUS_COMMUNICATIONS_FAULT_MASK);
}

bool BatteryFaultsData::alwaysOnSupplyFault() const
{
    return errorFlagPresent(ALWAYS_ON_SUPPLY_FAULT_MASK);
}

bool BatteryFaultsData::highVoltageIsolationFault() const
{
    return errorFlagPresent(HIGH_VOLTAGE_ISOLATION_FAULT_MASK);
}

bool BatteryFaultsData::powerSupply12VFault() const
{
    return errorFlagPresent(POWER_SUPPLY_12V_FAULT_MASK);
}

bool BatteryFaultsData::chargeLimitEnforcementFault() const
{
    return errorFlagPresent(CHARGE_LIMIT_ENFORCEMENT_FAULT_MASK);
}

bool BatteryFaultsData::dischargeLimitEnforcementFault() const
{
    return errorFlagPresent(DISCHARGE_LIMIT_ENFORCEMENT_FAULT_MASK);
}

bool BatteryFaultsData::chargerSafetyRelayFault() const
{
    return errorFlagPresent(CHARGER_SAFETY_RELAY_FAULT_MASK);
}

bool BatteryFaultsData::internalMemoryFault() const
{
    return errorFlagPresent(INTERNAL_MEMORY_FAULT_MASK);
}

bool BatteryFaultsData::internalThermistorFault() const
{
    return errorFlagPresent(INTERNAL_THERMISTOR_FAULT_MASK);
}

bool BatteryFaultsData::internalLogicFault() const
{
    return errorFlagPresent(INTERNAL_LOGIC_FAULT_MASK);
}

/* BatteryFaultsData status (limit flags) */
bool BatteryFaultsData::dclReducedDueToLowSoc() const
{
    return limitFlagPresent(DCL_REDUCED_DUE_TO_LOW_SOC_MASK);
}

bool BatteryFaultsData::dclReducedDueToHighCellResistence() const
{
    return limitFlagPresent(DCL_REDUCED_DUE_TO_HIGH_CELL_RESISTENCE_MASK);
}

bool BatteryFaultsData::dclReducedDueToTemperature() const
{
    return limitFlagPresent(DCL_REDUCED_DUE_TO_TEMPERATURE_MASK);
}

bool BatteryFaultsData::dclReducedDueToLowCellVoltage() const
{
    return limitFlagPresent(DCL_REDUCED_DUE_TO_LOW_CELL_VOLTAGE_MASK);
}

bool BatteryFaultsData::dclReducedDueToLowPackVoltage() const
{
    return limitFlagPresent(DCL_REDUCED_DUE_TO_LOW_PACK_VOLTAGE_MASK);
}

bool BatteryFaultsData::dclAndCclReducedDueToVoltageFailsafe() const
{
    return limitFlagPresent(DCL_AND_CCL_REDUCED_DUE_TO_VOLTAGE_FAILSAFE_MASK);
}

bool BatteryFaultsData::dclAndCclReducedDueToCommunicationFailsafe() const
{
    return limitFlagPresent(DCL_AND_CCL_REDUCED_DUE_TO_COMMUNICATION_FAILSAFE_MASK);
}

bool BatteryFaultsData::cclReducedDueToHighSoc() const
{
    return limitFlagPresent(CCL_REDUCED_DUE_TO_HIGH_SOC_MASK);
}

bool BatteryFaultsData::cclReducedDueToHighCellResistence() const
{
    return limitFlagPresent(CCL_REDUCED_DUE_TO_HIGH_CELL_RESISTENCE_MASK);
}

bool BatteryFaultsData::cclReducedDueToTemperature() const
{
    return limitFlagPresent(CCL_REDUCED_DUE_TO_TEMPERATURE_MASK);
}

bool BatteryFaultsData::cclReducedDueToHighCellVoltage() const
{
    return limitFlagPresent(CCL_REDUCED_DUE_TO_HIGH_CELL_VOLTAGE_MASK);
}

bool BatteryFaultsData::cclReducedDueToHighPackVoltage() const
{
    return limitFlagPresent(CCL_REDUCED_DUE_TO_HIGH_PACK_VOLTAGE_MASK);
}

bool BatteryFaultsData::cclReducedDueToChargerLatch() const
{
    return limitFlagPresent(CCL_REDUCED_DUE_TO_CHARGER_LATCH_MASK);
}

bool BatteryFaultsData::cclReducedDueToAlternateCurrentLimit() const
{
    return limitFlagPresent(CCL_REDUCED_DUE_TO_ALTERNATE_CURRENT_LIMIT_MASK);
}

bool BatteryFaultsData::operator==(const I_BatteryFaultsData& other) const
{
    return errorFlags_ == other.getErrorFlags() && limitFlags_ == other.getLimitFlags();
}

/* BatteryFaults Sets */
void BatteryFaultsData::setErrorFlags(const unsigned int& errorFlags)
{
    errorFlags_ = errorFlags;
    emit errorFlagsRecieved(errorFlags_);
}

void BatteryFaultsData::setLimitFlags(const unsigned short& limitFlags)
{
    limitFlags_ = limitFlags;
    emit limitFlagsRecieved(limitFlags_);
}

void BatteryFaultsData::appendIfPresent(QString& messageString, const unsigned int errorMask, QString errorDescription) const
{
    if (errorFlagPresent(errorMask))
    {
        messageString.append(errorDescription);
    }
}

void BatteryFaultsData::appendIfPresent(QString& messageString, const unsigned short limitMask, QString limitDescription) const
{
    if (errorFlagPresent(limitMask))
    {
        messageString.append(limitDescription);
    }
}

QString BatteryFaultsData::toString() const
{
    QString messageString;

    if (!static_cast<bool>(errorFlags_))
    {
        messageString += "NO_ERROR";
    }
    else
    {
        appendIfPresent(messageString, INTERNAL_COMMUNICATION_FAULT_MASK, "INTERNAL_COMMUNICATION_FAULT ");
        appendIfPresent(messageString, INTERNAL_CONVERSION_FAULT_MASK, "INTERNAL_CONVERSION_FAULT_MASK ");
        appendIfPresent(messageString, WEAK_CELL_FAULT_MASK, "WEAK_CELL_FAULT_MASK ");
        appendIfPresent(messageString, LOW_CELL_VOLTAGE_FAULT_MASK, "LOW_CELL_VOLTAGE_FAULT_MASK ");
        appendIfPresent(messageString, OPEN_WIRING_FAULT_MASK, "OPEN_WIRING_FAULT_MASK ");
        appendIfPresent(messageString, CURRENT_SENSOR_FAULT_MASK, "CURRENT_SENSOR_FAULT_MASK ");
        appendIfPresent(messageString, PACK_VOLTAGE_SENSOR_FAULT_MASK, "PACK_VOLTAGE_SENSOR_FAULT_MASK ");
        appendIfPresent(messageString, WEAK_PACK_FAULT_MASK, "WEAK_PACK_FAULT_MASK ");
        appendIfPresent(messageString, VOLTAGE_REDUNDANCY_FAULT_MASK, "VOLTAGE_REDUNDANCY_FAULT_MASK ");
        appendIfPresent(messageString, FAN_MONITOR_FAULT_MASK, "FAN_MONITOR_FAULT_MASK ");
        appendIfPresent(messageString, THERMISTOR_FAULT_MASK, "THERMISTOR_FAULT_MASK ");
        appendIfPresent(messageString, CANBUS_COMMUNICATIONS_FAULT_MASK, "CANBUS_COMMUNICATIONS_FAULT_MASK ");
        appendIfPresent(messageString, ALWAYS_ON_SUPPLY_FAULT_MASK, "ALWAYS_ON_SUPPLY_FAULT_MASK ");
        appendIfPresent(messageString, HIGH_VOLTAGE_ISOLATION_FAULT_MASK, "HIGH_VOLTAGE_ISOLATION_FAULT_MASK ");
        appendIfPresent(messageString, POWER_SUPPLY_12V_FAULT_MASK, "POWER_SUPPLY_12V_FAULT_MASK ");
        appendIfPresent(messageString, CHARGE_LIMIT_ENFORCEMENT_FAULT_MASK, "CHARGE_LIMIT_ENFORCEMENT_FAULT_MASK ");
        appendIfPresent(messageString, DISCHARGE_LIMIT_ENFORCEMENT_FAULT_MASK, "DISCHARGE_LIMIT_ENFORCEMENT_FAULT_MASK ");
        appendIfPresent(messageString, CHARGER_SAFETY_RELAY_FAULT_MASK, "CHARGER_SAFETY_RELAY_FAULT_MASK ");
        appendIfPresent(messageString, INTERNAL_MEMORY_FAULT_MASK, "INTERNAL_MEMORY_FAULT_MASK ");
        appendIfPresent(messageString, INTERNAL_THERMISTOR_FAULT_MASK, "INTERNAL_THERMISTOR_FAULT_MASK ");
        appendIfPresent(messageString, INTERNAL_LOGIC_FAULT_MASK, "INTERNAL_LOGIC_FAULT_MASK ");
    }

    if (!static_cast<bool>(limitFlags_))
    {
        messageString += "NO_LIMIT_FLAGS_PRESENT";
    }
    else
    {
        appendIfPresent(messageString, DCL_REDUCED_DUE_TO_LOW_SOC_MASK,
                        "DCL_REDUCED_DUE_TO_LOW_SOC_MASK ");
        appendIfPresent(messageString, DCL_REDUCED_DUE_TO_HIGH_CELL_RESISTENCE_MASK,
                        "DCL_REDUCED_DUE_TO_HIGH_CELL_RESISTENCE_MASK ");
        appendIfPresent(messageString, DCL_REDUCED_DUE_TO_TEMPERATURE_MASK,
                        "DCL_REDUCED_DUE_TO_TEMPERATURE_MASK ");
        appendIfPresent(messageString, DCL_REDUCED_DUE_TO_LOW_CELL_VOLTAGE_MASK,
                        "DCL_REDUCED_DUE_TO_LOW_CELL_VOLTAGE_MASK ");
        appendIfPresent(messageString, DCL_REDUCED_DUE_TO_LOW_PACK_VOLTAGE_MASK,
                        "DCL_REDUCED_DUE_TO_LOW_PACK_VOLTAGE_MASK ");

        appendIfPresent(messageString, DCL_AND_CCL_REDUCED_DUE_TO_VOLTAGE_FAILSAFE_MASK,
                        "DCL_AND_CCL_REDUCED_DUE_TO_VOLTAGE_FAILSAFE_MASK ");
        appendIfPresent(messageString, DCL_AND_CCL_REDUCED_DUE_TO_COMMUNICATION_FAILSAFE_MASK,
                        "DCL_AND_CCL_REDUCED_DUE_TO_COMMUNICATION_FAILSAFE_MASK ");

        appendIfPresent(messageString, CCL_REDUCED_DUE_TO_HIGH_SOC_MASK,
                        "CCL_REDUCED_DUE_TO_HIGH_SOC_MASK ");
        appendIfPresent(messageString, CCL_REDUCED_DUE_TO_HIGH_CELL_RESISTENCE_MASK,
                        "CCL_REDUCED_DUE_TO_HIGH_CELL_RESISTENCE_MASK ");
        appendIfPresent(messageString, CCL_REDUCED_DUE_TO_TEMPERATURE_MASK,
                        "CCL_REDUCED_DUE_TO_TEMPERATURE_MASK ");
        appendIfPresent(messageString, CCL_REDUCED_DUE_TO_HIGH_CELL_VOLTAGE_MASK,
                        "CCL_REDUCED_DUE_TO_HIGH_CELL_VOLTAGE_MASK ");
        appendIfPresent(messageString, CCL_REDUCED_DUE_TO_HIGH_PACK_VOLTAGE_MASK,
                        "CCL_REDUCED_DUE_TO_HIGH_PACK_VOLTAGE_MASK ");
        appendIfPresent(messageString, CCL_REDUCED_DUE_TO_CHARGER_LATCH_MASK,
                        "CCL_REDUCED_DUE_TO_CHARGER_LATCH_MASK ");
        appendIfPresent(messageString, CCL_REDUCED_DUE_TO_ALTERNATE_CURRENT_LIMIT_MASK,
                        "CCL_REDUCED_DUE_TO_ALTERNATE_CURRENT_LIMIT_MASK ");
    }

    return messageString;
}
