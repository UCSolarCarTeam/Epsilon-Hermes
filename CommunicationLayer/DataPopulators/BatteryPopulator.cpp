#include "BatteryPopulator.h"

BatteryPopulator::BatteryPopulator(I_PacketDecoder& packetDecoder, I_BatteryData& batteryData)
    : packetDecoder_(packetDecoder)
    , batteryData_(batteryData)
{
    connect(&packetDecoder_, SIGNAL(packetDecoded(const BatteryMessage)), this, SLOT(populateData(const BatteryMessage)));
}

void BatteryPopulator::populateData(const BatteryMessage message)
{
    batteryData_.setAlive(message.alive());
    batteryData_.setBmsRelayStatus(message.bmsRelayStatus());
    batteryData_.setPopulatedCells(message.populatedCells());
    batteryData_.set12VInputVoltage(message.inputVoltage12V());
    batteryData_.setFanVoltage(message.fanVoltage());
    batteryData_.setPackCurrent(message.packCurrent());
    batteryData_.setPackVoltage(message.packVoltage());
    batteryData_.setPackStateOfCharge(message.packStateOfCharge());
    batteryData_.setPackAmphours(message.packAmphorus());
    batteryData_.setPackDepthOfDischarge(message.packDepthOfDischarge());
    batteryData_.setHighTemperature(message.highTemperature());
    batteryData_.setHighThermistorId(message.highThermistorId());
    batteryData_.setLowTemperature(message.lowTemperature());
    batteryData_.setLowThermistorId(message.lowThermistorId());
    batteryData_.setAverageTemperature(message.averageTemperature());
    batteryData_.setInternalTemperature(message.internalTemperature());
    batteryData_.setFanSpeed(message.fanSpeed());
    batteryData_.setRequestedFanSpeed(message.requestedFanSpeed());
    batteryData_.setLowCellVoltage(message.lowCellVoltage());
    batteryData_.setLowCellVoltageId(message.lowCellVoltageId());
    batteryData_.setHighCellVoltage(message.highCellVoltage());
    batteryData_.setHighCellVoltageId(message.highCellVoltageId());
    batteryData_.setAverageCellVoltage(message.averageCellVoltage());
    batteryData_.setPrechargeState(message.prechargeState());
    batteryData_.setAuxVoltage(message.auxVoltage());
    batteryData_.setAuxBmsAlive(message.auxBmsAlive());
}
