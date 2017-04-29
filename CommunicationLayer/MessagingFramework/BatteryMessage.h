#pragma once

#include <QByteArray>
#include <QString>

class BatteryMessage
{
public:
    BatteryMessage(const QByteArray& messageData);

    bool alive() const;
    unsigned char bmsRelayStatus() const;
    unsigned char populatedCells() const;
    float inputVoltage12V() const;
    float fanVoltage() const;
    float packCurrent() const;
    float packVoltage() const;
    float packStateOfCharge() const;
    float packAmphorus() const;
    float packDepthOfDischarge() const;
    unsigned char highTemperature() const;
    unsigned char highThermistorId() const;
    unsigned char lowTemperature() const;
    unsigned char lowThermistorId() const;
    unsigned char averageTemperature() const;
    unsigned char internalTemperature() const;
    unsigned char fanSpeed() const;
    unsigned char requestedFanSpeed() const;
    unsigned short lowCellVoltage() const;
    unsigned char lowCellVoltageId() const;
    unsigned short highCellVoltage() const;
    unsigned char highCellVoltageId() const;
    unsigned short averageCellVoltage() const;
    unsigned char prechargeState() const;
    unsigned char auxVoltage() const;
    bool auxBmsAlive() const;

    QString toString() const;

private:
    const QByteArray messageData_;
};
