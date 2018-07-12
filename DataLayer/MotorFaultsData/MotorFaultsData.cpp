#include "MotorFaultsData.h"

namespace
{
// Error Flags
    const unsigned char MOTOR_OVER_SPEED_FLAG = 0x01;
    const unsigned char SOFTWARE_OVER_CURRENT_FLAG = 0x02;
    const unsigned char DC_BUS_OVER_VOLTAGE_FLAG = 0x04;
    const unsigned char BAD_MOTOR_POSITION_HALL_SEQUENCE_FLAG = 0x08;
    const unsigned char WATCHDOG_CAUSED_LAST_RESET_FLAG = 0x10;
    const unsigned char CONFIG_READ_ERROR_FLAG = 0x20;
    const unsigned char RAIL_UNDER_VOLTAGE_LOCK_OUT_FLAG = 0x40;
    const unsigned char DESATURATION_FAULT_FLAG = 0x80;

// Limit Flags
    const unsigned char OUTPUT_VOLTAGE_PWM_LIMIT_FLAG = 0x01;
    const unsigned char MOTOR_CURRENT_LIMIT_FLAG = 0x02;
    const unsigned char VELOCITY_LIMIT_FLAG = 0x04;
    const unsigned char BUS_CURRENT_LIMIT_FLAG = 0x08;
    const unsigned char BUS_VOLTAGE_UPPER_LIMIT_FLAG = 0x10;
    const unsigned char BUS_VOLTAGE_LOWER_LIMIT_FLAG = 0x20;
    const unsigned char IPM_OR_MOTOR_TELEMETRY_LIMIT_FLAG = 0x40;
}

MotorFaultsData::MotorFaultsData()
    : m0ErrorFlags_(0)
    , m1ErrorFlags_(0)
    , m0LimitFlags_(0)
    , m1LimitFlags_(0)
    , m0CanRxErrorCount_(0)
    , m0CanTxErrorCount_(0)
    , m1CanRxErrorCount_(0)
    , m1CanTxErrorCount_(0)
{
}
MotorFaultsData::~MotorFaultsData()
{
}

/* MotorFaults Gets */
unsigned char MotorFaultsData::getM0ErrorFlags() const
{
    return m0ErrorFlags_;
}

unsigned char MotorFaultsData::getM1ErrorFlags() const
{
    return m1ErrorFlags_;
}

unsigned char MotorFaultsData::getM0LimitFlags() const
{
    return m0LimitFlags_;
}

unsigned char MotorFaultsData::getM1LimitFlags() const
{
    return m1LimitFlags_;
}

unsigned char MotorFaultsData::getM0CanRxErrorCount() const
{
    return m0CanRxErrorCount_;
}

unsigned char MotorFaultsData::getM0CanTxErrorCount() const
{
    return m0CanTxErrorCount_;
}

unsigned char MotorFaultsData::getM1CanRxErrorCount() const
{
    return m1CanRxErrorCount_;
}

unsigned char MotorFaultsData::getM1CanTxErrorCount() const
{
    return m1CanTxErrorCount_;
}


// Errors
bool MotorFaultsData::m0MotorOverSpeed() const
{
    return static_cast<bool>(m0ErrorFlags_ & MOTOR_OVER_SPEED_FLAG);
}

bool MotorFaultsData::m0SoftwareOverCurrent() const
{
    return static_cast<bool>(m0ErrorFlags_ & SOFTWARE_OVER_CURRENT_FLAG);
}

bool MotorFaultsData::m0DcBusOverVoltage() const
{
    return static_cast<bool>(m0ErrorFlags_ & DC_BUS_OVER_VOLTAGE_FLAG);
}

bool MotorFaultsData::m0BadMotorPositionHallSequence() const
{
    return static_cast<bool>(m0ErrorFlags_ & BAD_MOTOR_POSITION_HALL_SEQUENCE_FLAG);
}

bool MotorFaultsData::m0WatchdogCausedLastReset() const
{
    return static_cast<bool>(m0ErrorFlags_ & WATCHDOG_CAUSED_LAST_RESET_FLAG);
}

bool MotorFaultsData::m0ConfigReadError() const
{
    return static_cast<bool>(m0ErrorFlags_ & CONFIG_READ_ERROR_FLAG);
}

bool MotorFaultsData::m0RailUnderVoltageLockOut() const
{
    return static_cast<bool>(m0ErrorFlags_ & RAIL_UNDER_VOLTAGE_LOCK_OUT_FLAG);
}

bool MotorFaultsData::m0DesaturationFault() const
{
    return static_cast<bool>(m0ErrorFlags_ & DESATURATION_FAULT_FLAG);
}

bool MotorFaultsData::m1MotorOverSpeed() const
{
    return static_cast<bool>(m0ErrorFlags_ & MOTOR_OVER_SPEED_FLAG);
}

bool MotorFaultsData::m1SoftwareOverCurrent() const
{
    return static_cast<bool>(m0ErrorFlags_ & SOFTWARE_OVER_CURRENT_FLAG);
}

bool MotorFaultsData::m1DcBusOverVoltage() const
{
    return static_cast<bool>(m0ErrorFlags_ & DC_BUS_OVER_VOLTAGE_FLAG);
}

bool MotorFaultsData::m1BadMotorPositionHallSequence() const
{
    return static_cast<bool>(m0ErrorFlags_ & BAD_MOTOR_POSITION_HALL_SEQUENCE_FLAG);
}

bool MotorFaultsData::m1WatchdogCausedLastReset() const
{
    return static_cast<bool>(m0ErrorFlags_ & WATCHDOG_CAUSED_LAST_RESET_FLAG);
}

bool MotorFaultsData::m1ConfigReadError() const
{
    return static_cast<bool>(m0ErrorFlags_ & CONFIG_READ_ERROR_FLAG);
}

bool MotorFaultsData::m1RailUnderVoltageLockOut() const
{
    return static_cast<bool>(m0ErrorFlags_ & RAIL_UNDER_VOLTAGE_LOCK_OUT_FLAG);
}

bool MotorFaultsData::m1DesaturationFault() const
{
    return static_cast<bool>(m0ErrorFlags_ & DESATURATION_FAULT_FLAG);
}


// Limits
bool MotorFaultsData::m0OutputVoltagePwmLimit() const
{
    return static_cast<bool>(m0LimitFlags_ & OUTPUT_VOLTAGE_PWM_LIMIT_FLAG);
}

bool MotorFaultsData::m0MotorCurrentLimit() const
{
    return static_cast<bool>(m0LimitFlags_ & MOTOR_CURRENT_LIMIT_FLAG);
}

bool MotorFaultsData::m0VelocityLimit() const
{
    return static_cast<bool>(m0LimitFlags_ & VELOCITY_LIMIT_FLAG);
}

bool MotorFaultsData::m0BusCurrentLimit() const
{
    return static_cast<bool>(m0LimitFlags_ & BUS_CURRENT_LIMIT_FLAG);
}

bool MotorFaultsData::m0BusVoltageUpperLimit() const
{
    return static_cast<bool>(m0LimitFlags_ & BUS_VOLTAGE_UPPER_LIMIT_FLAG);
}

bool MotorFaultsData::m0BusVoltageLowerLimit() const
{
    return static_cast<bool>(m0LimitFlags_ & BUS_VOLTAGE_LOWER_LIMIT_FLAG);
}

bool MotorFaultsData::m0IpmOrMotorTemperatureLimit() const
{
    return static_cast<bool>(m0LimitFlags_ & IPM_OR_MOTOR_TELEMETRY_LIMIT_FLAG);
}

bool MotorFaultsData::m1OutputVoltagePwmLimit() const
{
    return static_cast<bool>(m1LimitFlags_ & OUTPUT_VOLTAGE_PWM_LIMIT_FLAG);
}

bool MotorFaultsData::m1MotorCurrentLimit() const
{
    return static_cast<bool>(m1LimitFlags_ & MOTOR_CURRENT_LIMIT_FLAG);
}

bool MotorFaultsData::m1VelocityLimit() const
{
    return static_cast<bool>(m1LimitFlags_ & VELOCITY_LIMIT_FLAG);
}

bool MotorFaultsData::m1BusCurrentLimit() const
{
    return static_cast<bool>(m1LimitFlags_ & BUS_CURRENT_LIMIT_FLAG);
}

bool MotorFaultsData::m1BusVoltageUpperLimit() const
{
    return static_cast<bool>(m1LimitFlags_ & BUS_VOLTAGE_UPPER_LIMIT_FLAG);
}

bool MotorFaultsData::m1BusVoltageLowerLimit() const
{
    return static_cast<bool>(m1LimitFlags_ & BUS_VOLTAGE_LOWER_LIMIT_FLAG);
}

bool MotorFaultsData::m1IpmOrMotorTemperatureLimit() const
{
    return static_cast<bool>(m1LimitFlags_ & IPM_OR_MOTOR_TELEMETRY_LIMIT_FLAG);
}



/* MotorFaults Sets */
void MotorFaultsData::setM0ErrorFlags(const unsigned char& m0ErrorFlags)
{
    m0ErrorFlags_ = m0ErrorFlags;
}

void MotorFaultsData::setM1ErrorFlags(const unsigned char& m1ErrorFlags)
{
    m1ErrorFlags_ = m1ErrorFlags;
}

void MotorFaultsData::setM0LimitFlags(const unsigned char& m0LimitFlags)
{
    m0LimitFlags_ = m0LimitFlags;
}

void MotorFaultsData::setM1LimitFlags(const unsigned char& m1LimitFlags)
{
    m1LimitFlags_ = m1LimitFlags;
}

void MotorFaultsData::setM0CanRxErrorCount(const unsigned char& m0CanRxErrorCount)
{
    m0CanRxErrorCount_ = m0CanRxErrorCount;
}

void MotorFaultsData::setM0CanTxErrorCount(const unsigned char& m0CanTxErrorCount)
{
    m0CanTxErrorCount_ = m0CanTxErrorCount;
}

void MotorFaultsData::setM1CanRxErrorCount(const unsigned char& m1CanRxErrorCount)
{
    m1CanRxErrorCount_ = m1CanRxErrorCount;
}

void MotorFaultsData::setM1CanTxErrorCount(const unsigned char& m1CanTxErrorCount)
{
    m1CanTxErrorCount_ = m1CanTxErrorCount;
}

QString MotorFaultsData::toString() const
{
    return "0x" + QString::number(m0ErrorFlags_, 16) + " 0x" + QString::number(m0LimitFlags_, 16) + " 0x" + QString::number(m1ErrorFlags_, 16) + " 0x" + QString::number(m1LimitFlags_, 16);
}
