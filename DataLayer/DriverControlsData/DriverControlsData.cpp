#include "DriverControlsData.h"

namespace
{
    const unsigned char HEADLIGHTS_OFF_OFFSET = 0x1;
    const unsigned char HEADLIGHTS_LOW_OFFSET = 0x2;
    const unsigned char HEADLIGHTS_HIGH_OFFSET = 0x4;
    const unsigned char SIGNAL_RIGHT_OFFSET = 0x8;
    const unsigned char SIGNAL_LEFT_OFFSET = 0x10;
    const unsigned char HAZARD_OFFSET = 0x20;
    const unsigned char INTERIOR_OFFSET = 0x40;

    const unsigned char VOLUME_UP_OFFSET = 0x1;
    const unsigned char VOLUME_DOWN_OFFSET = 0x2;
    const unsigned char NEXT_SONG_OFFSET = 0x4;
    const unsigned char PREVIOUS_SONG_OFFSET = 0x8;

    const unsigned char BRAKES_OFFSET = 0x1;
    const unsigned char FORWARD_OFFSET = 0x2;
    const unsigned char REVERSE_OFFSET = 0x4;
    const unsigned char PUSH_TO_TALK_OFFSET = 0x8;
    const unsigned char HORN_OFFSET = 0x10;
    const unsigned char RESET_OFFSET = 0x20;
    const unsigned char AUX_OFFSET = 0x40;

}

DriverControlsData::DriverControlsData()
    : driverControlsBoardAlive_(0)
    , lightsInputs_(0)
    , musicInputs_(0)
    , acceleration_(0)
    , regenBraking_(0)
    , driverInputs_(0)
{
    // initialize to 0
}

DriverControlsData::~DriverControlsData()
{
}

/*Data "Gets"*/
bool DriverControlsData::getDriverControlsBoardAlive() const
{
    return static_cast<bool>(driverControlsBoardAlive_);
}

bool DriverControlsData::getHeadlightsOff() const
{
    return static_cast<bool>(lightsInputs_ & HEADLIGHTS_OFF_OFFSET);
}

bool DriverControlsData::getHeadlightsLow() const
{
    return static_cast<bool>(lightsInputs_ & HEADLIGHTS_LOW_OFFSET);
}

bool DriverControlsData::getHeadlightsHigh() const
{
    return static_cast<bool>(lightsInputs_ & HEADLIGHTS_HIGH_OFFSET);
}

bool DriverControlsData::getSignalRight() const
{
    return static_cast<bool>(lightsInputs_ & SIGNAL_RIGHT_OFFSET);
}

bool DriverControlsData::getSignalLeft() const
{
    return static_cast<bool>(lightsInputs_ & SIGNAL_LEFT_OFFSET);
}

bool DriverControlsData::getHazard() const
{
    return static_cast<bool>(lightsInputs_ & HAZARD_OFFSET);
}

bool DriverControlsData::getInterior() const
{
    return static_cast<bool>(lightsInputs_ & INTERIOR_OFFSET);
}

bool DriverControlsData::getVolumeUp() const
{
    return static_cast<bool>(musicInputs_ & VOLUME_UP_OFFSET);
}

bool DriverControlsData::getVolumeDown() const
{
    return static_cast<bool>(musicInputs_ & VOLUME_DOWN_OFFSET);
}

bool DriverControlsData::getNextSong() const
{
    return static_cast<bool>(musicInputs_ & NEXT_SONG_OFFSET);
}

bool DriverControlsData::getPreviousSong() const
{
    return static_cast<bool>(musicInputs_ & PREVIOUS_SONG_OFFSET);
}

bool DriverControlsData::getBrakes() const
{
    return static_cast<bool>(driverInputs_ & BRAKES_OFFSET);
}

bool DriverControlsData::getForward() const
{
    return static_cast<bool>(driverInputs_ & FORWARD_OFFSET);
}

bool DriverControlsData::getReverse() const
{
    return static_cast<bool>(driverInputs_ & REVERSE_OFFSET);
}

bool DriverControlsData::getPushToTalk() const
{
    return static_cast<bool>(driverInputs_ & PUSH_TO_TALK_OFFSET);
}

bool DriverControlsData::getHorn() const
{
    return static_cast<bool>(driverInputs_ & HORN_OFFSET);
}

bool DriverControlsData::getReset() const
{
    return static_cast<bool>(driverInputs_ & RESET_OFFSET);
}
bool DriverControlsData::getAux() const
{
    return static_cast<bool>(driverInputs_ & AUX_OFFSET);
}

unsigned short DriverControlsData::getAcceleration() const
{
    return acceleration_;
}

unsigned short DriverControlsData::getRegenBraking() const
{
    return regenBraking_;
}


/*DriverControlsData "Sets"*/
void DriverControlsData::setDriverControlsBoardAlive(const unsigned char& driverControlsBoardAlive)
{
    driverControlsBoardAlive_ = driverControlsBoardAlive;
}

void DriverControlsData::setLightsInputs(const unsigned char& lightsInputs)
{
    lightsInputs_ = lightsInputs;
}

void DriverControlsData::setMusicInputs(const unsigned char& musicInputs)
{
    musicInputs_ = musicInputs;
}

void DriverControlsData::setAcceleration(const unsigned short& acceleration)
{
    acceleration_ = acceleration;
}

void DriverControlsData::setRegenBraking(const unsigned short& regenBraking)
{
    regenBraking_ = regenBraking;
}

void DriverControlsData::setDriverInputs(const unsigned char& driverInputs)
{
    driverInputs_ = driverInputs;
}
