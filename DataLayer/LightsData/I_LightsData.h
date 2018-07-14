#pragma once

#include <QObject>

class I_LightsData : public QObject
{
    Q_OBJECT
public:
    virtual ~I_LightsData() {}

    /* LightsData Gets */
    virtual bool getAlive() const = 0;
    virtual bool getLowBeams() const = 0;
    virtual bool getHighBeams() const = 0;
    virtual bool getBrakes() const = 0;
    virtual bool getLeftSignal() const = 0;
    virtual bool getRightSignal() const = 0;
    virtual bool getBmsStrobeLight() const = 0;

    /* LightsData Sets */
    virtual void setAlive(const bool&) = 0;
    virtual void setLightStatus(const unsigned char&) = 0;
};
