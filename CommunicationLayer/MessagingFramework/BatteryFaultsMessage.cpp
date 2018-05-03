#include "BatteryFaultsMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
const int ERROR_FLAGS_OFFSET = 1;
const int LIMIT_FLAGS_OFFSET = 4;
}

BatteryFaultsMessage::BatteryFaultsMessage(QByteArray& messageData)
    : messageData_(messageData)
{
    // Initialize messageData
}

unsigned int BatteryFaultsMessage::errorFlags() const
{
    return getUnsignedInt(messageData_, ERROR_FLAGS_OFFSET);
}

unsigned short BatteryFaultsMessage::limitFlags() const
{
    return getUnsignedShort(messageData_, LIMIT_FLAGS_OFFSET);
}

QString BatteryFaultsMessage::toString() const
{
    QString messageString;
    messageString += QString::number(MessageDefines::BATTERY_FAULTS) + ", ";
    messageString += QString::number(errorFlags()) + ", ";
    messageString += QString::number(limitFlags()) + ", ";
    return messageString;
}
