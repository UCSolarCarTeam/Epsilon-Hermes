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
    bool contactorError() const;
    bool highVoltageEnable() const;

    QString toString() const;

private:
    const QByteArray messageData_;
};