#include "KeyMotorMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

namespace
{
    const int M_0_ALIVE = 1;
    const int M_0_SET_CURRENT = 2;
    const int M_0_SET_VELOCITY = 6;
    const int M_0_BUS_CURRENT = 10;
    const int M_0_BUS_VOLTAGE = 14;
    const int M_0_VEHICLE_VELOCITY = 18;
    const int M_1_ALIVE = 22;
    const int M_1_SET_CURRENT = 23;
    const int M_1_SET_VELOCITY = 27;
    const int M_1_BUS_CURRENT = 31;
    const int M_1_BUS_VOLTAGE = 35;
    const int M_1_VEHICLE_VELOCITY = 39;
}

KeyMotorMessage::KeyMotorMessage(const QByteArray& messageData)
: messageData_(messageData)
{
}

bool KeyMotorMessage::m0Alive() const
{
    return static_cast<bool>(messageData_.at(M_0_ALIVE));
}

float KeyMotorMessage::m0SetCurrent() const
{
    return MessageDecodingHelpers::getFloat(messageData_, M_0_SET_CURRENT);
}

float KeyMotorMessage::m0SetVelocity() const
{
    return MessageDecodingHelpers::getFloat(messageData_, M_0_SET_VELOCITY);
}

float KeyMotorMessage::m0BusCurrent() const
{
    return MessageDecodingHelpers::getFloat(messageData_, M_0_BUS_CURRENT);
}

float KeyMotorMessage::m0BusVoltage() const
{
    return MessageDecodingHelpers::getFloat(messageData_, M_0_BUS_VOLTAGE);
}

float KeyMotorMessage::m0VehicleVelocity() const
{
    return MessageDecodingHelpers::getFloat(messageData_, M_0_VEHICLE_VELOCITY);
}

bool KeyMotorMessage::m1Alive() const
{
    return static_cast<bool>(messageData_.at(M_1_ALIVE));
}

float KeyMotorMessage::m1SetCurrent() const
{
    return MessageDecodingHelpers::getFloat(messageData_, M_1_SET_CURRENT);
}

float KeyMotorMessage::m1SetVelocity() const
{
    return MessageDecodingHelpers::getFloat(messageData_, M_1_SET_VELOCITY);
}

float KeyMotorMessage::m1BusCurrent() const
{
    return MessageDecodingHelpers::getFloat(messageData_, M_1_BUS_CURRENT);
}

float KeyMotorMessage::m1BusVoltage() const
{
    return MessageDecodingHelpers::getFloat(messageData_, M_1_BUS_VOLTAGE);
}

float KeyMotorMessage::m1VehicleVelocity() const
{
    return MessageDecodingHelpers::getFloat(messageData_, M_1_VEHICLE_VELOCITY);
}

QString KeyMotorMessage::toString() const
{
    QString messageString;
    messageString += QString::number(MessageDefines::KeyMotor) + ", ";
    messageString += QString::number(m0Alive()) + ", ";
    messageString += QString::number(m0SetCurrent()) + ", ";
    messageString += QString::number(m0SetVelocity()) + ", ";
    messageString += QString::number(m0BusCurrent()) + ", ";
    messageString += QString::number(m0BusVoltage()) + ", ";
    messageString += QString::number(m0VehicleVelocity()) + ", ";
    messageString += QString::number(m1Alive()) + ", ";
    messageString += QString::number(m1SetCurrent()) + ", ";
    messageString += QString::number(m1SetVelocity()) + ", ";
    messageString += QString::number(m1BusCurrent()) + ", ";
    messageString += QString::number(m1BusVoltage()) + ", ";
    messageString += QString::number(m1VehicleVelocity()) + ", ";
    return messageString;
}
