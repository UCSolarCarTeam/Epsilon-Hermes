#include "BatteryMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
    const int BMU_ALIVE_OFFSET = 1;
    const int BMS_RELAY_STATUS_OFFSET = 2;
    const int POPULATED_CELLS_OFFSET = 3;
    const int INPUT_VOLTAGE_12V_OFFSET = 4;
    const int FAN_VOLTAGE_OFFSET = 8;
    const int PACK_CURRENT_OFFSET = 12;
    const int PACK_VOLTAGE_OFFSET = 16;
    const int PACK_STATE_OF_CHARGE_OFFSET = 20;
    const int PACK_AMPHOURS_OFFSET = 24;
    const int PACK_DEPTH_OF_DISCHARGE_OFFSET = 28;
    const int HIGH_TEMPERATURE_OFFSET = 32;
    const int HIGH_THERMISTOR_ID_OFFSET = 33;
    const int LOW_TEMPERATURE_OFFSET = 34;
    const int LOW_THERMISTOR_ID_OFFSET = 35;
    const int AVERAGE_TEMPERATURE_OFFSET = 36;
    const int INTERNAL_TEMPERATURE_OFFSET = 37;
    const int FAN_SPEED_OFFSET = 38;
    const int REQUESTED_FAN_SPEED_OFFSET = 39;
    const int LOW_CELL_VOLTAGE_OFFSET = 40;
    const int LOW_CELL_VOLTAGE_ID_OFFSET = 42;
    const int HIGH_CELL_VOLTAGE_OFFSET = 43;
    const int HIGH_CELL_VOLTAGE_ID_OFFSET = 45;
    const int AVERAGE_CELL_VOLTAGE_OFFSET = 46;
    const int PRECHARGE_STATE_OFFSET = 48;
    const int AUX_VOLTAGE_OFFSET = 49;
    const int AUX_BMS_ALIVE_OFFSET = 50;
    const int STROBE_BMS_LIGHT_OFFSET = 51;
    const int ALLOW_CHARGE_OFFSET = 52;
    const int CONTACTOR_ERROR_OFFSET = 53;
}

BatteryMessage::BatteryMessage(const QByteArray& messageData)
    : messageData_(messageData)
{
}

bool BatteryMessage::alive() const
{
    return static_cast<bool>(messageData_.at(BMU_ALIVE_OFFSET));
}

unsigned char BatteryMessage::bmsRelayStatus() const
{
    return getUnsignedChar(messageData_, BMS_RELAY_STATUS_OFFSET);
}

unsigned char BatteryMessage::populatedCells() const
{
    return getUnsignedChar(messageData_, POPULATED_CELLS_OFFSET);
}

float BatteryMessage::inputVoltage12V() const
{
    return getFloat(messageData_, INPUT_VOLTAGE_12V_OFFSET);
}

float BatteryMessage::fanVoltage() const
{
    return getFloat(messageData_, FAN_VOLTAGE_OFFSET);
}

float BatteryMessage::packCurrent() const
{
    return getFloat(messageData_, PACK_CURRENT_OFFSET);
}

float BatteryMessage::packVoltage() const
{
    return getFloat(messageData_, PACK_VOLTAGE_OFFSET);
}

float BatteryMessage::packStateOfCharge() const
{
    return getFloat(messageData_, PACK_STATE_OF_CHARGE_OFFSET);
}

float BatteryMessage::packAmphorus() const
{
    return getFloat(messageData_, PACK_AMPHOURS_OFFSET);
}

float BatteryMessage::packDepthOfDischarge() const
{
    return getFloat(messageData_, PACK_DEPTH_OF_DISCHARGE_OFFSET);
}

unsigned char BatteryMessage::highTemperature() const
{
    return getUnsignedChar(messageData_, HIGH_TEMPERATURE_OFFSET);
}

unsigned char BatteryMessage::highThermistorId() const
{
    return getUnsignedChar(messageData_, HIGH_THERMISTOR_ID_OFFSET);
}

unsigned char BatteryMessage::lowTemperature() const
{
    return getUnsignedChar(messageData_, LOW_TEMPERATURE_OFFSET);
}

unsigned char BatteryMessage::lowThermistorId() const
{
    return getUnsignedChar(messageData_, LOW_THERMISTOR_ID_OFFSET);
}

unsigned char BatteryMessage::averageTemperature() const
{
    return getUnsignedChar(messageData_, AVERAGE_TEMPERATURE_OFFSET);
}

unsigned char BatteryMessage::internalTemperature() const
{
    return getUnsignedChar(messageData_, INTERNAL_TEMPERATURE_OFFSET);
}

unsigned char BatteryMessage::fanSpeed() const
{
    return getUnsignedChar(messageData_, FAN_SPEED_OFFSET);
}
unsigned char BatteryMessage::requestedFanSpeed() const
{
    return getUnsignedChar(messageData_, REQUESTED_FAN_SPEED_OFFSET);
}

unsigned short BatteryMessage::lowCellVoltage() const
{
    return getUnsignedShort(messageData_, LOW_CELL_VOLTAGE_OFFSET);
}

unsigned char BatteryMessage::lowCellVoltageId() const
{
    return getUnsignedChar(messageData_, LOW_CELL_VOLTAGE_ID_OFFSET);
}

unsigned short BatteryMessage::highCellVoltage() const
{
    return getUnsignedShort(messageData_, HIGH_CELL_VOLTAGE_OFFSET);
}

unsigned char BatteryMessage::highCellVoltageId() const
{
    return getUnsignedChar(messageData_, HIGH_CELL_VOLTAGE_ID_OFFSET);
}

unsigned short BatteryMessage::averageCellVoltage() const
{
    return getUnsignedShort(messageData_, AVERAGE_CELL_VOLTAGE_OFFSET);
}

unsigned char BatteryMessage::prechargeState() const
{
    return getUnsignedChar(messageData_, PRECHARGE_STATE_OFFSET);
}
unsigned char BatteryMessage::auxVoltage() const
{
    return getUnsignedChar(messageData_, AUX_VOLTAGE_OFFSET);
}

bool BatteryMessage::auxBmsAlive() const
{
    return static_cast<bool>(messageData_.at(AUX_BMS_ALIVE_OFFSET));
}

bool BatteryMessage::strobeBmsLight() const
{
    return static_cast<bool>(messageData_.at(STROBE_BMS_LIGHT_OFFSET));
}

bool BatteryMessage::allowCharge() const
{
    return static_cast<bool>(messageData_.at(ALLOW_CHARGE_OFFSET));
}

bool BatteryMessage::contactorError() const
{
    return static_cast<bool>(messageData_.at(CONTACTOR_ERROR_OFFSET));
}

QString BatteryMessage::toString() const
{
    QString messageString;
    messageString += QString::number(MessageDefines::BATTERY) + ", ";
    messageString += QString::number(alive()) + ", ";
    messageString += QString::number(bmsRelayStatus()) + ", ";
    messageString += QString::number(populatedCells()) + ", ";
    messageString += QString::number(inputVoltage12V()) + ", ";
    messageString += QString::number(fanVoltage()) + ", ";
    messageString += QString::number(packCurrent()) + ", ";
    messageString += QString::number(packVoltage()) + ", ";
    messageString += QString::number(packStateOfCharge()) + ", ";
    messageString += QString::number(packAmphorus()) + ", ";
    messageString += QString::number(packDepthOfDischarge()) + ", ";
    messageString += QString::number(highTemperature()) + ", ";
    messageString += QString::number(highThermistorId()) + ", ";
    messageString += QString::number(lowTemperature()) + ", ";
    messageString += QString::number(lowThermistorId()) + ", ";
    messageString += QString::number(averageTemperature()) + ", ";
    messageString += QString::number(internalTemperature()) + ", ";
    messageString += QString::number(fanSpeed()) + ", ";
    messageString += QString::number(requestedFanSpeed()) + ", ";
    messageString += QString::number(lowCellVoltage()) + ", ";
    messageString += QString::number(lowCellVoltageId()) + ", ";
    messageString += QString::number(highCellVoltage()) + ", ";
    messageString += QString::number(highCellVoltageId()) + ", ";
    messageString += QString::number(averageCellVoltage()) + ", ";
    messageString += QString::number(prechargeState()) + ", ";
    messageString += QString::number(auxVoltage()) + ", ";
    messageString += QString::number(auxBmsAlive()) + ", ";
    messageString += QString::number(strobeBmsLight()) + ", ";
    messageString += QString::number(allowCharge()) + ", ";
    messageString += QString::number(contactorError()) + ", ";
    return messageString;
}
