#include <QDebug>
#include <QTimer>

#include "OutputRadioCommDevice.h"
#include "InfrastructureLayer/Settings/I_Settings.h"

OutputRadioCommDevice::OutputRadioCommDevice(I_CommDevice& inputSerialPort, QSerialPort& outputSerialPort, I_Settings& settings)
    : outputSerialPort_(outputSerialPort)
    , inputSerialPort_(inputSerialPort)
{
    // This makes sure that it is connected after everything is created.
    // Only if the config file enables it.
    if (!settings.outputSerialEnabled())
    {
        return;
    }

    setSerialParameters(settings.outputSerialPortName(), settings.outputBaudrate());
    QTimer::singleShot(0, this, SLOT(connectToDataSource()));
    connect(&inputSerialPort_, SIGNAL(dataReceived(QByteArray)),
            this, SLOT(handleSerialDataIncoming(QByteArray)));
    connect(this, SIGNAL(dataReceived(QByteArray)),
            this, SLOT(forwardSerialData(QByteArray)));
}

OutputRadioCommDevice::~OutputRadioCommDevice()
{
}

void OutputRadioCommDevice::setSerialParameters(QString serialPortName, int baudRate)
{
    outputSerialPort_.setPortName(serialPortName);
    outputSerialPort_.setBaudRate(baudRate);
    outputSerialPort_.setParity(QSerialPort::NoParity);
    outputSerialPort_.setStopBits(QSerialPort::OneStop);
    outputSerialPort_.setDataBits(QSerialPort::Data8);
}

bool OutputRadioCommDevice::connectToDataSource()
{
    if (outputSerialPort_.open(QIODevice::ReadWrite))
    {
        connect(&outputSerialPort_, SIGNAL(readyRead()),
                this, SLOT(handleSerialDataIncoming()), Qt::UniqueConnection);
        emit connectionSucceeded();
        return true;
    }
    else
    {
        qWarning() << outputSerialPort_.errorString();
        emit connectionFailed(outputSerialPort_.errorString());
        return false;
    }
}
void OutputRadioCommDevice::handleSerialDataIncoming(QByteArray data)
{
    emit dataReceived(data);
}
void OutputRadioCommDevice::forwardSerialData(QByteArray input)
{
    if (outputSerialPort_.write(input) != -1)
    {
        qDebug() << "Wrote to output port";
    }
    else
    {
        qDebug() << "Could not write to output port";
    }

}
