#include "BatteryFaultsPopulator.h"

BatteryFaultsPopulator::BatteryFaultsPopulator(I_PacketDecoder& packetDecoder, I_BatteryFaultsData& batteryFaultsData)
    : packetDecoder_(packetDecoder)
    , batteryFaultsData_(batteryFaultsData)
{
    connect(&packetDecoder_, SIGNAL(packetDecoded(const BatteryFaultsMessage)), this, SLOT(populateData(const BatteryFaultsMessage)));
}

void BatteryFaultsPopulator::populateData(const BatteryFaultsMessage message)
{
    batteryFaultsData_.setErrorFlags(message.errorFlags());
    batteryFaultsData_.setLimitFlags(message.limitFlags());
}
