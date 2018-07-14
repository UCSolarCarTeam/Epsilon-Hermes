#include "AuxBmsData.h"

namespace name
{

}

AuxBmsData::AuxBmsData()
    : prechargeState_(AuxBmsData::PrechargeState::OFF)
    , auxVoltage_()
    , auxBmsAlive_(false)
    , strobeBmsLight_(false)
    , allowCharge_(false)
    , contactorError_(false)
    , highVoltageEnable_(false)
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

bool AuxBmsData::getContactorError() const
{
    return contactorError_;
}

bool AuxBmsData::getHighVoltageEnable() const
{
    return highVoltageEnable_;
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

void AuxBmsData::setContactorError(const bool& contactorError)
{
    contactorError_ = contactorError;
}

void AuxBmsData::setHighVoltageEnable(const bool& highVoltageEnable)
{
    highVoltageEnable_ = highVoltageEnable;
}
