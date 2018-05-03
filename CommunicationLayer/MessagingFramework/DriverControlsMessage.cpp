#include "DriverControlsMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
const int DRIVER_CONTROLS_BOARD_ALIVE_OFFSET = 1;
const int LIGHTS_INPUTS_OFFSET = 2;
const int MUSIC_INPUTS_OFFSET = 3;
const int ACCELERATION_OFFSET = 4;
const int REGEN_BRAKING_OFFSET = 6;
const int DRIVER_INPUTS_OFFSET = 8;
}

DriverControlsMessage::DriverControlsMessage(const QByteArray& messageData)
    : messageData_(messageData)
{
}

unsigned char DriverControlsMessage::driverControlsBoardAlive() const
{
    return static_cast<bool>(messageData_.at(DRIVER_CONTROLS_BOARD_ALIVE_OFFSET));
}

unsigned char DriverControlsMessage::lightsInputs() const
{
    return getUnsignedChar(messageData_, LIGHTS_INPUTS_OFFSET);
}

unsigned char DriverControlsMessage::musicInputs() const
{
    return getUnsignedChar(messageData_, MUSIC_INPUTS_OFFSET);
}

unsigned short DriverControlsMessage::acceleration() const
{
    return MessageDecodingHelpers::getUnsignedShort(messageData_, ACCELERATION_OFFSET);
}

unsigned short DriverControlsMessage::regenBraking() const
{
    return MessageDecodingHelpers::getUnsignedShort(messageData_, REGEN_BRAKING_OFFSET);
}

unsigned char DriverControlsMessage::driverInputs() const
{
    return getUnsignedChar(messageData_, DRIVER_INPUTS_OFFSET);
}

QString DriverControlsMessage::toString() const
{
    QString messageString;
    messageString += QString::number(MessageDefines::DRIVER_CONTROLS) + ", ";
    messageString += QString::number(driverControlsBoardAlive()) + ", ";
    messageString += QString::number(lightsInputs()) + ", ";
    messageString += QString::number(musicInputs()) + ", ";
    messageString += QString::number(acceleration()) + ", ";
    messageString += QString::number(regenBraking()) + ", ";
    messageString += QString::number(driverInputs()) + ", ";
    return messageString;
}

