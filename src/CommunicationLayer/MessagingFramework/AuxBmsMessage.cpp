#include "AuxBmsMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
    const int PRECHARGE_STATE_OFFSET = 1;
    const int AUX_VOLTAGE_OFFSET = 2;
    const int AUX_BMS_ALIVE_OFFSET = 3;
    const int STROBE_BMS_LIGHT_OFFSET = 4;
    const int ALLOW_CHARGE_OFFSET = 5;
    const int HIGH_VOLTAGE_ENABLE_STATE_OFFSET = 6;
    const int ALLOW_DISCHARGE_OFFSET = 7;
    const int AUX_CONTACTOR_OFFSET = 8;
    const int AUX_TRIP_OFFSET = 16;
}

AuxBmsMessage::AuxBmsMessage(const QByteArray& messageData)
    : messageData_(messageData)
{
}

unsigned char AuxBmsMessage::prechargeState() const
{
    return getUnsignedChar(messageData_, PRECHARGE_STATE_OFFSET);
}
unsigned char AuxBmsMessage::auxVoltage() const
{
    return getUnsignedChar(messageData_, AUX_VOLTAGE_OFFSET);
}

bool AuxBmsMessage::auxBmsAlive() const
{
    return static_cast<bool>(messageData_.at(AUX_BMS_ALIVE_OFFSET));
}

bool AuxBmsMessage::strobeBmsLight() const
{
    return static_cast<bool>(messageData_.at(STROBE_BMS_LIGHT_OFFSET));
}

bool AuxBmsMessage::allowCharge() const
{
    return static_cast<bool>(messageData_.at(ALLOW_CHARGE_OFFSET));
}

bool AuxBmsMessage::highVoltageEnableState() const
{
    return static_cast<bool>(messageData_.at(HIGH_VOLTAGE_ENABLE_STATE_OFFSET));
}

bool AuxBmsMessage::allowDischarge() const
{
    return static_cast<bool>(messageData_.at(ALLOW_DISCHARGE_OFFSET));
}

unsigned char AuxBmsMessage::auxContactor() const
{
    return getUnsignedChar(messageData_, AUX_CONTACTOR_OFFSET);
}

unsigned char AuxBmsMessage::auxTrip() const
{
    return getUnsignedChar(messageData_, AUX_TRIP_OFFSET);
}

QString AuxBmsMessage::toString() const
{
    QString messageString;
    messageString += QString::number(MessageDefines::AUX_BMS) + ", ";
    messageString += QString::number(prechargeState()) + ", ";
    messageString += QString::number(auxVoltage()) + ", ";
    messageString += QString::number(auxBmsAlive()) + ", ";
    messageString += QString::number(strobeBmsLight()) + ", ";
    messageString += QString::number(allowCharge()) + ", ";
    messageString += QString::number(highVoltageEnableState()) + ", ";
    messageString += QString::number(allowDischarge()) + ", ";
    messageString += QString::number(auxContactor()) + ", ";
    messageString += QString::number(auxTrip()) + ", ";
    return messageString;
}
