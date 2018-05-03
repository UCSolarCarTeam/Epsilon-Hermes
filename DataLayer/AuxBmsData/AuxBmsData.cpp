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

/*AuxBmsData "Sets"*/
void AuxBmsData::setPrechargeState(const unsigned char& prechargeState)
{
    prechargeState_ = static_cast<PrechargeState>(prechargeState);
    emit prechargeStateReceived(prechargeState_);
}

void AuxBmsData::setAuxVoltage(const unsigned char& auxVoltage)
{
    auxVoltage_ = auxVoltage;
    emit auxVoltageReceived(auxVoltage_);
}

void AuxBmsData::setAuxBmsAlive(const bool& auxBmsAlive)
{
    auxBmsAlive_ = auxBmsAlive;
    emit auxBmsAliveReceived(auxBmsAlive_);
}

void AuxBmsData::setStrobeBmsLight(const bool& strobeBmsLight)
{
    strobeBmsLight_ = strobeBmsLight;
    emit strobeBmsLightRecieved(strobeBmsLight_);
}

void AuxBmsData::setAllowCharge(const bool& allowCharge)
{
    allowCharge_ = allowCharge;
    emit allowChargeRecieved(allowCharge_);
}

void AuxBmsData::setContactorError(const bool& contactorError)
{
    contactorError_ = contactorError;
    emit contactorErrorRecieved(contactorError_);
}
