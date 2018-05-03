#include <QDebug>
#include <QSettings>

#include "Settings.h"

namespace
{
const QSettings::Format SETTINGS_FILE_FORMAT = QSettings::IniFormat;
}

Settings::Settings(QString filepath)
    : settings_(filepath, SETTINGS_FILE_FORMAT)
{
}


int Settings::forwardPeriod() const
{
    return settings_.value("forwardPeriod").toInt();
}

// UnitNumbers

int Settings::numberOfMotors() const
{
    return settings_.value("UnitNumbers/numberOfMotors").toInt();
}

int Settings::numberOfMppts() const
{
    return settings_.value("UnitNumbers/numberOfMppts").toInt();
}

// JsonFormat

QString Settings::packetTitle() const
{
    return settings_.value("JsonFormat/packetTitle").toString();
}

// SerialPort

QString Settings::serialPortName() const
{
    return settings_.value("SerialPort/portName").toString();
}

int Settings::baudrate() const
{
    return settings_.value("SerialPort/baudrate").toInt();
}

// Output SerialPort
bool Settings::outputSerialEnabled() const
{
    return settings_.value("OutputSerialPort/outputSerialEnabled").toBool();
}

QString Settings::outputSerialPortName() const
{
    return settings_.value("OutputSerialPort/portName").toString();
}

int Settings::outputBaudrate() const
{
    return settings_.value("OutputSerialPort/baudrate").toInt();
}

// RabbitMq

QString Settings::ipAddress() const
{
    return QString(settings_.value("RabbitMq/ipAddress").toString());
}

quint16 Settings::port() const
{
    return (quint16)settings_.value("RabbitMq/port").toInt();
}

QString Settings::exchangeName() const
{
    return QString(settings_.value("RabbitMq/exchangeName").toString());
}

// Logging

int Settings::logLevel() const
{
    return settings_.value("Logging/logLevel").toInt();
}
bool Settings::loggingEnabled() const
{
    return settings_.value("Logging/loggingEnabled").toBool();
}
