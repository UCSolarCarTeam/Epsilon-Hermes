#pragma once

#include <QObject>
#include <QString>

class I_MotorFaultsData : public QObject
{
    Q_OBJECT
public:
    virtual ~I_MotorFaultsData() {}

    virtual QString toString() const = 0;

    /* MotorFaults Gets */
    virtual unsigned char getM0ErrorFlags() const = 0;
    virtual unsigned char getM1ErrorFlags() const = 0;
    virtual unsigned char getM0LimitFlags() const = 0;
    virtual unsigned char getM1LimitFlags() const = 0;
    virtual unsigned char getM0CanRxErrorCount() const = 0;
    virtual unsigned char getM0CanTxErrorCount() const = 0;
    virtual unsigned char getM1CanRxErrorCount() const = 0;
    virtual unsigned char getM1CanTxErrorCount() const = 0;

    // Errors
    virtual bool m0MotorOverSpeed() const = 0;
    virtual bool m0SoftwareOverCurrent() const = 0;
    virtual bool m0DcBusOverVoltage() const = 0;
    virtual bool m0BadMotorPositionHallSequence() const = 0;
    virtual bool m0WatchdogCausedLastReset() const = 0;
    virtual bool m0ConfigReadError() const = 0;
    virtual bool m0RailUnderVoltageLockOut() const = 0;
    virtual bool m0DesaturationFault() const = 0;
    virtual bool m1MotorOverSpeed() const = 0;
    virtual bool m1SoftwareOverCurrent() const = 0;
    virtual bool m1DcBusOverVoltage() const = 0;
    virtual bool m1BadMotorPositionHallSequence() const = 0;
    virtual bool m1WatchdogCausedLastReset() const = 0;
    virtual bool m1ConfigReadError() const = 0;
    virtual bool m1RailUnderVoltageLockOut() const = 0;
    virtual bool m1DesaturationFault() const = 0;

    // Limits
    virtual bool m0OutputVoltagePwmLimit() const = 0;
    virtual bool m0MotorCurrentLimit() const = 0;
    virtual bool m0VelocityLimit() const = 0;
    virtual bool m0BusCurrentLimit() const = 0;
    virtual bool m0BusVoltageUpperLimit() const = 0;
    virtual bool m0BusVoltageLowerLimit() const = 0;
    virtual bool m0IpmOrMotorTemperatureLimit() const = 0;
    virtual bool m1OutputVoltagePwmLimit() const = 0;
    virtual bool m1MotorCurrentLimit() const = 0;
    virtual bool m1VelocityLimit() const = 0;
    virtual bool m1BusCurrentLimit() const = 0;
    virtual bool m1BusVoltageUpperLimit() const = 0;
    virtual bool m1BusVoltageLowerLimit() const = 0;
    virtual bool m1IpmOrMotorTemperatureLimit() const = 0;

    /* MotorFaults Sets */
    virtual void setM0ErrorFlags(const unsigned char& m0ErrorFlags) = 0;
    virtual void setM1ErrorFlags(const unsigned char& m1ErrorFlags) = 0;
    virtual void setM0LimitFlags(const unsigned char& m0LimitFlags) = 0;
    virtual void setM1LimitFlags(const unsigned char& m1LimitFlags) = 0;
    virtual void setM0CanRxErrorCount(const unsigned char& m0CanRxErrorCount) = 0;
    virtual void setM0CanTxErrorCount(const unsigned char& m0CanTxErrorCount) = 0;
    virtual void setM1CanRxErrorCount(const unsigned char& m1CanRxErrorCount) = 0;
    virtual void setM1CanTxErrorCount(const unsigned char& m1CanTxErrorCount) = 0;
};
