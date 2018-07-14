#pragma once

#include <QObject>

class I_DriverControlsData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_DriverControlsData() {}

    /*Data "Gets"*/
    virtual bool getDriverControlsBoardAlive() const = 0;
    virtual bool getHeadlightsOff() const = 0;
    virtual bool getHeadlightsLow() const = 0;
    virtual bool getHeadlightsHigh() const = 0;
    virtual bool getSignalRight() const = 0;
    virtual bool getSignalLeft() const = 0;
    virtual bool getHazard() const = 0;
    virtual bool getInterior() const = 0;
    virtual bool getVolumeUp() const = 0;
    virtual bool getVolumeDown() const = 0;
    virtual bool getNextSong() const = 0;
    virtual bool getPreviousSong() const = 0;
    virtual bool getBrakes() const = 0;
    virtual bool getForward() const = 0;
    virtual bool getReverse() const = 0;
    virtual bool getPushToTalk() const = 0;
    virtual bool getHorn() const = 0;
    virtual bool getReset() const = 0;
    virtual bool getAux() const = 0;
    virtual unsigned short getAcceleration() const = 0;
    virtual unsigned short getRegenBraking() const = 0;

    /*DriverControlsData "Sets"*/
    virtual void setDriverControlsBoardAlive(const unsigned char& getDriverControlsBoardAlive) = 0;
    virtual void setLightsInputs(const unsigned char& getLightsInputs) = 0;
    virtual void setMusicInputs(const unsigned char& getMusicInputs) = 0;
    virtual void setAcceleration(const unsigned short& getAcceleration) = 0;
    virtual void setRegenBraking(const unsigned short& getRegenBraking) = 0;
    virtual void setDriverInputs(const unsigned char& getDriverInputs) = 0;
};
