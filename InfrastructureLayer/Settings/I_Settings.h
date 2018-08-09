#pragma once

class I_Settings
{
public:
    virtual ~I_Settings() {}

    virtual int forwardPeriod() const = 0;

    // UnitNumbers
    virtual int numberOfMotors() const = 0;
    virtual int numberOfMppts() const = 0;

    // JsonFormat
    virtual QString packetTitle() const = 0;

    // SerialPort
    virtual bool outputSerialEnabled() const = 0;
    virtual QString serialPortName() const = 0;
    virtual int baudrate() const = 0;

    // OutputSerialPort
    virtual QString outputSerialPortName() const = 0;
    virtual int outputBaudrate() const = 0;

    // RabbitMq
    virtual QString ipAddress() const = 0;
    virtual quint16 port() const = 0;
    virtual QString exchangeName() const = 0;

    virtual QString serverIpAddress() const = 0;
    virtual quint16 serverPort() const = 0;
    virtual QString serverExchangeName() const = 0;

    // Logging
    virtual int logLevel() const = 0;
    virtual bool loggingEnabled() const = 0;
};
