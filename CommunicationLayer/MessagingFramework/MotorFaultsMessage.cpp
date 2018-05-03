#include "MotorFaultsMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
    const int M0_ERROR_FLAGS = 1;
    const int M1_ERROR_FLAGS = 2;
    const int M0_LIMIT_FLAGS = 3;
    const int M1_LIMIT_FLAGS = 4;
    const int M0_CAN_RX_ERROR_COUNT = 5;
    const int M0_CAN_TX_ERROR_COUNT = 6;
    const int M1_CAN_RX_ERROR_COUNT = 7;
    const int M1_CAN_TX_ERROR_COUNT = 8;
}

MotorFaultsMessage::MotorFaultsMessage(QByteArray& messageData)
    : messageData_(messageData)
{
}

unsigned char MotorFaultsMessage::M0ErrorFlags() const
{
    return getUnsignedChar(messageData_, M0_ERROR_FLAGS);
}

unsigned char MotorFaultsMessage::M1ErrorFlags() const
{
    return getUnsignedChar(messageData_, M1_ERROR_FLAGS);
}

unsigned char MotorFaultsMessage::M0LimitFlags() const
{
    return getUnsignedChar(messageData_, M0_LIMIT_FLAGS);
}

unsigned char MotorFaultsMessage::M1LimitFlags() const
{
    return getUnsignedChar(messageData_, M1_LIMIT_FLAGS);
}

unsigned char MotorFaultsMessage::M0CanRxErrorCount() const
{
    return getUnsignedChar(messageData_, M0_CAN_RX_ERROR_COUNT);
}

unsigned char MotorFaultsMessage::M0CanTxErrorCount() const
{
    return getUnsignedChar(messageData_, M0_CAN_TX_ERROR_COUNT);
}

unsigned char MotorFaultsMessage::M1CanRxErrorCount() const
{
    return getUnsignedChar(messageData_, M1_CAN_RX_ERROR_COUNT);
}

unsigned char MotorFaultsMessage::M1CanTxErrorCount() const
{
    return getUnsignedChar(messageData_, M1_CAN_TX_ERROR_COUNT);
}


QString MotorFaultsMessage::toString() const
{
    QString messageString;
    messageString += QString::number(MessageDefines::MOTOR_FAULTS) + ", ";
    messageString += QString::number(M0ErrorFlags()) + ", ";
    messageString += QString::number(M1ErrorFlags()) + ", ";
    messageString += QString::number(M0LimitFlags()) + ", ";
    messageString += QString::number(M1LimitFlags()) + ", ";
    messageString += QString::number(M0CanRxErrorCount()) + ", ";
    messageString += QString::number(M0CanTxErrorCount()) + ", ";
    messageString += QString::number(M1CanRxErrorCount()) + ", ";
    messageString += QString::number(M1CanTxErrorCount()) + ", ";
    return messageString;
}
