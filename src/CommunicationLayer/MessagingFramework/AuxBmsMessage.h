#pragma once

#include <QByteArray>
#include <QString>

class AuxBmsMessage
{
public:
    AuxBmsMessage(const QByteArray& messageData);

    unsigned char prechargeState() const;
    unsigned char auxVoltage() const;
    bool auxBmsAlive() const;
    bool strobeBmsLight() const;
    bool allowCharge() const;
    bool highVoltageEnableState() const;
    bool allowDischarge() const;
    unsigned char auxContactor() const;
    unsigned char auxTrip() const;

    QString toString() const;

private:
    const QByteArray messageData_;
};
