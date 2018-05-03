#include "LightsData.h"

namespace
{
    const unsigned char LOW_BEAMS_OFFSET = 0x1;
    const unsigned char HIGH_BEAMS_OFFSET = 0x2;
    const unsigned char BRAKES_OFFSET = 0x4;
    const unsigned char LEFT_SIGNAL_OFFSET = 0x8;
    const unsigned char RIGHT_SIGNAL_OFFSET = 0x10;
    const unsigned char BMS_STROBE_LIGHT_OFFSET = 0x20;
}

LightsData::LightsData()
    : alive_(false)
    , lightStatus_(0)
{
//    Initialize to 0
}

LightsData::~LightsData()
{
}

/* LightsData Gets */
bool LightsData::getAlive() const
{
    return alive_;
}

bool LightsData::getLowBeams() const
{
    return static_cast<bool>(lightStatus_ & LOW_BEAMS_OFFSET);
}

bool LightsData::getHighBeams() const
{
    return static_cast<bool>(lightStatus_ & HIGH_BEAMS_OFFSET);
}

bool LightsData::getBrakes() const
{
    return static_cast<bool>(lightStatus_ & BRAKES_OFFSET);
}

bool LightsData::getLeftSignal() const
{
    return static_cast<bool>(lightStatus_ & LEFT_SIGNAL_OFFSET);
}

bool LightsData::getRightSignal() const
{
    return static_cast<bool>(lightStatus_ & RIGHT_SIGNAL_OFFSET);
}

bool LightsData::getBmsStrobeLight() const
{
    return static_cast<bool>(lightStatus_ & BMS_STROBE_LIGHT_OFFSET);
}

/* LightsData Sets */
void LightsData::setAlive(const bool& alive)
{
    alive_ = alive;
    emit aliveReceived(alive_);
}

void LightsData::setLightStatus(const unsigned char& lightStatus)
{
    lightStatus_ = lightStatus;
    emit lightStatusReceived(lightStatus_);
}
