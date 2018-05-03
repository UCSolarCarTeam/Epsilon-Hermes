#pragma once
#include <gmock/gmock.h>

#include "InfrastructureLayer/Settings/I_Settings.h"

class MockSettings : public I_Settings
{
public:
    MOCK_CONST_METHOD0(forwardPeriod, int());

    // UnitNumbers
    MOCK_CONST_METHOD0(numberOfMotors, int());
    MOCK_CONST_METHOD0(numberOfMppts, int());

    // SerialPort
    MOCK_CONST_METHOD0(serialPortName, QString());
    MOCK_CONST_METHOD0(baudrate, int());
    MOCK_CONST_METHOD0(ipAddress, QString());

    // Output SerialPort
    MOCK_CONST_METHOD0(outputSerialEnabled, bool());
    MOCK_CONST_METHOD0(outputSerialPortName, QString());
    MOCK_CONST_METHOD0(outputBaudrate, int());

    // RabbitMq
    MOCK_CONST_METHOD0(port, quint16());
    MOCK_CONST_METHOD0(packetTitle, QString());
    MOCK_CONST_METHOD0(exchangeName, QString());

    // Logging
    MOCK_CONST_METHOD0(logLevel, int());
    MOCK_CONST_METHOD0(loggingEnabled, bool());
};
