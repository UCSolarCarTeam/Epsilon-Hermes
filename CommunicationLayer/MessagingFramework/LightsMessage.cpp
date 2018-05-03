#include "LightsMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
const int ALIVE_OFFSET = 1;
const int LIGHT_STATUS_OFFSET = 2;
}

LightsMessage::LightsMessage(const QByteArray& messageData)
    : messageData_(messageData)
{
}

bool LightsMessage::alive() const
{
    return static_cast<bool>(messageData_.at(ALIVE_OFFSET));
}

unsigned char LightsMessage::lightStatus() const
{
    return getUnsignedChar(messageData_, LIGHT_STATUS_OFFSET);
}

QString LightsMessage::toString() const
{
    QString messageString;
    messageString += QString::number(MessageDefines::LIGHTS) + ", ";
    messageString += QString::number(alive()) + ", ";
    messageString += QString::number(lightStatus()) + ", ";
    return messageString;
}
