#pragma once

#include <QString>
#include <QByteArray>

class BatteryFaultsMessage
{
public:
    BatteryFaultsMessage(QByteArray& messageData);

    unsigned int errorFlags() const;
    unsigned short limitFlags() const;

    QString toString() const;

private:
    const QByteArray messageData_;
};
