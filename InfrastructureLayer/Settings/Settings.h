#pragma once

#include <QSettings>

#include "I_Settings.h"

class Settings : public I_Settings
{
public:
    Settings(QString filepath);
    virtual ~Settings() {}

    int forwardPeriod() const;

    // UnitNumbers
    int numberOfMotors() const;
    int numberOfMppts() const;

    // JsonFormat
    QString packetTitle() const;

    // SerialPort
    QString serialPortName() const;
    int baudrate() const;

    // Output SerialPort
    bool outputSerialEnabled() const;
    QString outputSerialPortName() const;
    int outputBaudrate() const;


    // RabbitMq
    QString ipAddress() const;
    quint16 port() const;
    QString exchangeName() const;

    // Logging
    int logLevel() const;
    bool loggingEnabled() const;

private:
    QSettings settings_;
};
