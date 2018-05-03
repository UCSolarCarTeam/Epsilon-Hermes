#pragma once

#include <QSerialPort>
#include <QString>
#include "I_CommDevice.h"

class I_Settings;

class OutputRadioCommDevice : public I_CommDevice
{
    Q_OBJECT
public:
    OutputRadioCommDevice(I_CommDevice& inputSerialPort, QSerialPort& outputSerialPort, I_Settings& settings);
    virtual ~OutputRadioCommDevice();

private slots:
    void handleSerialDataIncoming(const QByteArray data);
    void forwardSerialData(const QByteArray input);
    bool connectToDataSource();

private:
    void setSerialParameters(QString serialPortName, int baudRate);

private:
    QSerialPort& outputSerialPort_;
    I_CommDevice& inputSerialPort_;
};
