#include <QByteArray>
#include <QDebug>
#include <QHostAddress>
#include <QTextCodec>


#include "InfrastructureLayer/Settings/I_Settings.h"
#include "UdpMessageForwarder.h"


namespace
{
    quint32 TIMEOUT = 120;
    quint32 SLEEP_TIME = 2;
}

UdpMessageForwarder::UdpMessageForwarder(I_Settings& settings, Mode::Mode mode)
{
    exchangeName_ = settings.exchangeName();
    ipAddress_ = settings.ipAddress();
    udpPort_ = settings.udpPort();

    if (mode == Mode::Mode::HEADLESS)
    {
        setupChannel();
    }
}

UdpMessageForwarder::~UdpMessageForwarder()
{
}


void UdpMessageForwarder::setupChannel()
{
    quint32 i = 0;

    do
    {
        if (i++)
        {
            qWarning() << "UdpMessageForwarder: Attempting to reconnect";
        }

        try
        {
            channel_ = AmqpClient::Channel::Create(ipAddress_.toStdString(), udpPort_);
        }
        catch (std::exception&)
        {
            if (channel_ == NULL)
            {
                if (i == (TIMEOUT / SLEEP_TIME))
                {
                    qWarning() << "UdpMessageForwarder timed out waiting for connection to broker";
                    throw;
                }

                qWarning() << "UdpMessageForwarder: error creating channel";
                QThread::sleep(SLEEP_TIME);
            }
            else
            {
                throw;
            }
        }
    }
    while (channel_ == NULL);

    channel_->DeclareExchange(exchangeName_.toStdString(), AmqpClient::Channel::EXCHANGE_TYPE_FANOUT);
}

void UdpMessageForwarder::forwardData(QByteArray data)
{
    qDebug() << "UdpMessageForwarder: Forwarding data";
    AmqpClient::BasicMessage::ptr_t mq_msg = AmqpClient::BasicMessage::Create(QTextCodec::codecForMib(106)->toUnicode(data).toStdString());

    try
    {
        channel_->BasicPublish(exchangeName_.toStdString(), "", mq_msg);
    }
    catch (AmqpClient::ChannelException& ex)
    {
        qWarning() << "UdpMessageForwarder: Failed to forward data";
    }
    catch (AmqpClient::ConnectionException& ex)
    {
        qWarning() << "UdpMessageForwarder: Connection to broker terminated";
        setupChannel();
    }
}
