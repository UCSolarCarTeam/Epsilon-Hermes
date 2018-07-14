#pragma once

#include <QObject>

class I_KeyMotorData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_KeyMotorData() {}

    /*Data "Gets"*/
    virtual unsigned char getM0Alive() const = 0;
    virtual float getM0SetCurrent() const = 0;
    virtual float getM0SetVelocity() const = 0;
    virtual float getM0BusCurrent() const = 0;
    virtual float getM0BusVoltage() const = 0;
    virtual float getM0VehicleVelocity() const = 0;
    virtual unsigned char getM1Alive() const = 0;
    virtual float getM1SetCurrent() const = 0;
    virtual float getM1SetVelocity() const = 0;
    virtual float getM1BusCurrent() const = 0;
    virtual float getM1BusVoltage() const = 0;
    virtual float getM1VehicleVelocity() const = 0;


    /*KeyMotorData "Sets"*/
    virtual void setM0Alive(const unsigned char& m0Alive) = 0;
    virtual void setM0SetCurrent(const float& m0SetCurrent) = 0;
    virtual void setM0SetVelocity(const float& m0SetVelocity) = 0;
    virtual void setM0BusCurrent(const float& m0BusCurrent) = 0;
    virtual void setM0BusVoltage(const float& m0BusVoltage) = 0;
    virtual void setM0VehicleVelocity(const float& m0VehicleVelocity) = 0;
    virtual void setM1Alive(const unsigned char& m1Alive) = 0;
    virtual void setM1SetCurrent(const float& m1SetCurrent) = 0;
    virtual void setM1SetVelocity(const float& m1SetVelocity) = 0;
    virtual void setM1BusCurrent(const float& m1BusCurrent) = 0;
    virtual void setM1BusVoltage(const float& m1BusVoltage) = 0;
    virtual void setM1VehicleVelocity(const float& m1VehicleVelocity) = 0;
};
