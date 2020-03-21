#include "AuxBmsData.h"

namespace
{
    const unsigned char CHARGE_TRIP_DUE_TO_HIGH_CELL_VOLTAGE_MASK              = 0x01;
    const unsigned char CHARGE_TRIP_DUE_TO_HIGH_TEMPERATURE_AND_CURRENT_MASK   = 0x02;
    const unsigned char CHARGE_TRIP_DUE_TO_PACK_CURRENT_MASK                   = 0x04;
    const unsigned char DISCHARGE_TRIP_DUE_TO_LOW_CELL_VOLTAGE_MASK            = 0x08;
    const unsigned char DISCHARGE_TRIP_DUE_TO_HIGH_TEMERATURE_AND_CURRENT_MASK = 0x10;
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

bool AuxBmsData::getChargeTripDueToHighCellVoltage() const
{
    return auxTripBit(CHARGE_TRIP_DUE_TO_HIGH_CELL_VOLTAGE_MASK);
}

bool AuxBmsData::getChargeTripDueToHighTemperatureAndCurrent() const
{
    return auxTripBit(CHARGE_TRIP_DUE_TO_HIGH_TEMPERATURE_AND_CURRENT_MASK);
}

bool AuxBmsData::getChargeTripDueToPackCurrent() const
{
    return auxTripBit(CHARGE_TRIP_DUE_TO_PACK_CURRENT_MASK);
}

bool AuxBmsData::getDischargeTripDueToLowCellVoltage() const
{
    return auxTripBit(DISCHARGE_TRIP_DUE_TO_LOW_CELL_VOLTAGE_MASK);
}

bool AuxBmsData::getDischargeTripDueToHighTemeratureAndCurrent() const
{
    return auxTripBit(DISCHARGE_TRIP_DUE_TO_HIGH_TEMERATURE_AND_CURRENT_MASK);
}

bool AuxBmsData::getDischargeTripDueToPackCurrent() const
{
    return auxTripBit(DISCHARGE_TRIP_DUE_TO_PACK_CURRENT_MASK);
}

bool AuxBmsData::getProtectionTrip() const
{
    return auxTripBit(PROTECTION_TRIP_MASK);
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

void AuxBmsData::setAuxTrip(const unsigned char auxTrip)
{
    auxTrip_ = auxTrip;
}

bool AuxBmsData::auxTripBit(const unsigned char mask) const
{
    return static_cast<bool>(auxTrip_ & mask);
}
