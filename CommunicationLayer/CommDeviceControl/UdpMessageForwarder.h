#pragma once

#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <QUdpSocket>
#include <QThread>
#include "CommunicationLayer/CommDeviceControl/I_MessageForwarder.h"

class I_Settings;

class UdpMessageForwarder : public I_MessageForwarder
{
    Q_OBJECT
public:
    UdpMessageForwarder(I_Settings& settings, bool isGui = false);
    virtual ~UdpMessageForwarder();

public slots:
    void forwardData(QByteArray data);

private:
    void setupChannel();
    AmqpClient::Channel::ptr_t channel_;
    QString exchangeName_;
    QString ipAddress_;
    quint16 udpPort_;
};
