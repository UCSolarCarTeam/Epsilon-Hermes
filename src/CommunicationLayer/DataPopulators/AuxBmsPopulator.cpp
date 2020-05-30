#include "AuxBmsPopulator.h"

AuxBmsPopulator::AuxBmsPopulator(I_PacketDecoder& packetDecoder, I_AuxBmsData& auxBmsData)
    : packetDecoder_(packetDecoder)
    , auxBmsData_(auxBmsData)
{
    connect(&packetDecoder_, SIGNAL(packetDecoded(const AuxBmsMessage)), this, SLOT(populateData(const AuxBmsMessage)));
}

void AuxBmsPopulator::populateData(const AuxBmsMessage message)
{
    auxBmsData_.setPrechargeState(message.prechargeState());
    auxBmsData_.setAuxVoltage(message.auxVoltage());
    auxBmsData_.setAuxBmsAlive(message.auxBmsAlive());
    auxBmsData_.setStrobeBmsLight(message.strobeBmsLight());
    auxBmsData_.setAllowCharge(message.allowCharge());
    auxBmsData_.setHighVoltageEnableState(message.highVoltageEnableState());
    auxBmsData_.setAllowDischarge(message.allowDischarge());
    auxBmsData_.setOrionCanReceivedRecently(message.orionCanReceivedRecently());
    auxBmsData_.setAuxContactorDebug(message.auxContactorDebug());
    auxBmsData_.setAuxTrip(message.auxTrip());
}
