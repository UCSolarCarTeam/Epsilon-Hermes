#include "AuxBmsData.h"

namespace
{
    const unsigned char ORION_CAN_RECEIVED_RECENTLY_MASK                       = 0x01;
    const unsigned char CHARGE_CONTACTOR_ERROR_MASK                            = 0x02;
    const unsigned char DISCHARGE_CONTACTOR_ERROR_MASK                         = 0x04;
    const unsigned char COMMON_CONTACTOR_ERROR_MASK                            = 0x08;
    const unsigned char DISCHARGE_SHOULD_TRIP_MASK                             = 0x10;
    const unsigned char CHARGE_SHOULD_TRIP_MASK                                = 0x20;
    const unsigned char CHARGE_OPEN_BUT_SHOULD_BE_CLOSED_MASK                  = 0x40;
    const unsigned char DISCHARGE_OPEN_BUT_SHOULD_BE_CLOSED_MASK               = 0x80;

    const unsigned char CHARGE_TRIP_DUE_TO_HIGH_CELL_VOLTAGE_MASK              = 0x01;
    const unsigned char CHARGE_TRIP_DUE_TO_HIGH_TEMPERATURE_AND_CURRENT_MASK   = 0x02;
    const unsigned char CHARGE_TRIP_DUE_TO_PACK_CURRENT_MASK                   = 0x04;
    const unsigned char DISCHARGE_TRIP_DUE_TO_LOW_CELL_VOLTAGE_MASK            = 0x08;
    const unsigned char DISCHARGE_TRIP_DUE_TO_HIGH_TEMPERATURE_AND_CURRENT_MASK = 0x10;
    const unsigned char DISCHARGE_TRIP_DUE_TO_PACK_CURRENT_MASK                = 0x20;
    const unsigned char PROTECTION_TRIP_MASK                                   = 0x40;
}

AuxBmsData::AuxBmsData()
    : prechargeState_(AuxBmsData::PrechargeState::OFF)
    , auxVoltage_()
    , auxBmsAlive_(false)
    , strobeBmsLight_(false)
    , allowCharge_(false)
    , highVoltageEnableState_(false)
    , allowDischarge_(false)
    , auxContactor_(0x0)
    , auxTrip_(0x0)
{

}

AuxBmsData::~AuxBmsData()
{
}

/*Data "Gets"*/
AuxBmsData::PrechargeState AuxBmsData::getPrechargeState() const
{
    return prechargeState_;
}

unsigned char AuxBmsData::getAuxVoltage() const
{
    return auxVoltage_;
}

bool AuxBmsData::getAuxBmsAlive() const
{
    return auxBmsAlive_;
}

bool AuxBmsData::getStrobeBmsLight() const
{
    return strobeBmsLight_;
}

bool AuxBmsData::getAllowCharge() const
{
    return allowCharge_;
}

bool AuxBmsData::getHighVoltageEnableState() const
{
    return highVoltageEnableState_;
}

bool AuxBmsData::getAllowDischarge() const
{
    return allowDischarge_;
}

bool AuxBmsData::getOrionCANReceivedRecently() const
{
    return auxMaskedBit(ORION_CAN_RECEIVED_RECENTLY_MASK, auxContactor_);
}

bool AuxBmsData::getChargeContactorError() const
{
    return auxMaskedBit(CHARGE_CONTACTOR_ERROR_MASK, auxContactor_);
}

bool AuxBmsData::getDischargeContactorError() const
{
    return auxMaskedBit(DISCHARGE_CONTACTOR_ERROR_MASK, auxContactor_);
}

bool AuxBmsData::getCommonContactorError() const
{
    return auxMaskedBit(COMMON_CONTACTOR_ERROR_MASK, auxContactor_);
}

bool AuxBmsData::getDischargeShouldTrip() const
{
    return auxMaskedBit(DISCHARGE_SHOULD_TRIP_MASK, auxContactor_);
}

bool AuxBmsData::getChargeShouldTrip() const
{
    return auxMaskedBit(CHARGE_SHOULD_TRIP_MASK, auxContactor_);
}

bool AuxBmsData::getChargeOpenButShouldBeClosed() const
{
    return auxMaskedBit(CHARGE_OPEN_BUT_SHOULD_BE_CLOSED_MASK, auxContactor_);
}

bool AuxBmsData::getDischargeOpenButShouldBeClosed() const
{
    return auxMaskedBit(DISCHARGE_OPEN_BUT_SHOULD_BE_CLOSED_MASK, auxContactor_);
}

bool AuxBmsData::getChargeTripDueToHighCellVoltage() const
{
    return auxMaskedBit(CHARGE_TRIP_DUE_TO_HIGH_CELL_VOLTAGE_MASK, auxTrip_);
}

bool AuxBmsData::getChargeTripDueToHighTemperatureAndCurrent() const
{
    return auxMaskedBit(CHARGE_TRIP_DUE_TO_HIGH_TEMPERATURE_AND_CURRENT_MASK, auxTrip_);
}

bool AuxBmsData::getChargeTripDueToPackCurrent() const
{
    return auxMaskedBit(CHARGE_TRIP_DUE_TO_PACK_CURRENT_MASK, auxTrip_);
}

bool AuxBmsData::getDischargeTripDueToLowCellVoltage() const
{
    return auxMaskedBit(DISCHARGE_TRIP_DUE_TO_LOW_CELL_VOLTAGE_MASK, auxTrip_);
}

bool AuxBmsData::getDischargeTripDueToHighTemperatureAndCurrent() const
{
    return auxMaskedBit(DISCHARGE_TRIP_DUE_TO_HIGH_TEMPERATURE_AND_CURRENT_MASK, auxTrip_);
}

bool AuxBmsData::getDischargeTripDueToPackCurrent() const
{
    return auxMaskedBit(DISCHARGE_TRIP_DUE_TO_PACK_CURRENT_MASK, auxTrip_);
}

bool AuxBmsData::getProtectionTrip() const
{
    return auxMaskedBit(PROTECTION_TRIP_MASK, auxTrip_);
}

/*AuxBmsData "Sets"*/
void AuxBmsData::setPrechargeState(const unsigned char& prechargeState)
{
    prechargeState_ = static_cast<PrechargeState>(prechargeState);
}

void AuxBmsData::setAuxVoltage(const unsigned char& auxVoltage)
{
    auxVoltage_ = auxVoltage;
}

void AuxBmsData::setAuxBmsAlive(const bool& auxBmsAlive)
{
    auxBmsAlive_ = auxBmsAlive;
}

void AuxBmsData::setStrobeBmsLight(const bool& strobeBmsLight)
{
    strobeBmsLight_ = strobeBmsLight;
}

void AuxBmsData::setAllowCharge(const bool& allowCharge)
{
    allowCharge_ = allowCharge;
}

void AuxBmsData::setHighVoltageEnableState(const bool& highVoltageEnableState)
{
    highVoltageEnableState_ = highVoltageEnableState;
}

void AuxBmsData::setAllowDischarge(const bool& allowDischarge)
{
    allowDischarge_ = allowDischarge;
}

void AuxBmsData::setAuxContactor(const unsigned char auxContactor)
{
    auxContactor_ = auxContactor;
}

void AuxBmsData::setAuxTrip(const unsigned char auxTrip)
{
    auxTrip_ = auxTrip;
}

bool AuxBmsData::auxMaskedBit(const unsigned char mask, unsigned char bits) const
{
    return static_cast<bool>(bits & mask);
}
