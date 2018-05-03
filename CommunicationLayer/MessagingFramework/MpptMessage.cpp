#include "MpptMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
    const int MPPT_STATUS_OFFSET = 1;
    const int ARRAY_VOLTAGE_OFFSET = 2;
    const int ARRAY_CURRENT_OFFSET = 4;
    const int BATTERY_VOLTAGE_OFFSET = 6;
    const int TEMPERATURE_OFFSET = 8;

    const unsigned char NUMBER_MASK = 0x3;
    const unsigned char STATUS_MASK = 0x80;
}

MpptMessage::MpptMessage(const QByteArray& messageData)
    : messageData_(messageData)
{
}

unsigned char MpptMessage::mpptNumber() const
{
    return getUnsignedChar(messageData_, MPPT_STATUS_OFFSET) & NUMBER_MASK;
}

unsigned char MpptMessage::mpptStatus() const
{
    return getUnsignedChar(messageData_, MPPT_STATUS_OFFSET) & STATUS_MASK;
}

unsigned short MpptMessage::arrayVoltage() const
{
    return MessageDecodingHelpers::getUnsignedShort(messageData_, ARRAY_VOLTAGE_OFFSET);
}

unsigned short MpptMessage::arrayCurrent() const
{
    return MessageDecodingHelpers::getUnsignedShort(messageData_, ARRAY_CURRENT_OFFSET);
}

unsigned short MpptMessage::batteryVoltage() const
{
    return MessageDecodingHelpers::getUnsignedShort(messageData_, BATTERY_VOLTAGE_OFFSET);
}

unsigned short MpptMessage::temperature() const
{
    return MessageDecodingHelpers::getUnsignedShort(messageData_, TEMPERATURE_OFFSET);
}

QString MpptMessage::toString() const
{
    QString messageString;
    messageString += QString::number(MessageDefines::MPPT) + ", ";
    messageString += QString::number(mpptStatus()) + ", ";
    messageString += QString::number(arrayVoltage()) + ", ";
    messageString += QString::number(arrayCurrent()) + ", ";
    messageString += QString::number(batteryVoltage()) + ", ";
    messageString += QString::number(temperature()) + ", ";
    return messageString;
}

