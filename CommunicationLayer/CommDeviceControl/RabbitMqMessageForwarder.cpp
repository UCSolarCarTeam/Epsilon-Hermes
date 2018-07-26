#include <QByteArray>
#include <QDebug>
#include <QHostAddress>
#include <QTextCodec>


#include "InfrastructureLayer/Settings/I_Settings.h"
#include "RabbitMqMessageForwarder.h"


namespace
{
    quint32 TIMEOUT = 120;
    quint32 SLEEP_TIME = 2;
}

RabbitMqMessageForwarder::RabbitMqMessageForwarder(I_Settings& settings)
{
    exchangeName_ = settings.exchangeName();
    ipAddress_ = settings.ipAddress();
    port_ = settings.port();
    serverExchangeName_ = settings.serverExchangeName();
    serverIpAddress_  = settings.serverIpAddress();
    serverPort_ = settings.serverPort();
    setupChannel();
    setupServerChannel();
}

RabbitMqMessageForwarder::~RabbitMqMessageForwarder()
{
}


void RabbitMqMessageForwarder::setupChannel()
{
    quint32 i = 0;

    do
    {
        if (i++)
        {
            qInfo() << "RabbitMqMessageForwarder: Attempting to reconnect";
        }

        try
        {
            channel_ = AmqpClient::Channel::Create(ipAddress_.toStdString(), port_);
        }
        catch (std::exception&)
        {
            if (channel_ == NULL)
            {
                if (i == (TIMEOUT / SLEEP_TIME))
                {
                    qWarning() << "RabbitMqMessageForwarder timed out waiting for connection to broker";
                    throw;
                }

                qWarning() << "RabbitMqMessageForwarder: error creating channel";
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

void RabbitMqMessageForwarder::setupServerChannel()
{
    qInfo() << "RabbitMqMessageForwarder: Attempting to reconnect to server";

    try
    {
        serverChannel_ = AmqpClient::Channel::Create(serverIpAddress_.toStdString(), serverPort_);
    }
    catch (std::exception&)
    {
    }

    if (serverChannel_ != NULL)
    {
        serverChannel_->DeclareExchange(serverExchangeName_.toStdString(), AmqpClient::Channel::EXCHANGE_TYPE_FANOUT);
    }
}

void RabbitMqMessageForwarder::forwardData(QByteArray data)
{
    qDebug() << "RabbitMqMessageForwarder: Forwarding data";
    AmqpClient::BasicMessage::ptr_t mq_msg = AmqpClient::BasicMessage::Create(QTextCodec::codecForMib(106)->toUnicode(data).toStdString());

    try
    {
        channel_->BasicPublish(exchangeName_.toStdString(), "", mq_msg);
    }
    catch (AmqpClient::ChannelException& ex)
    {
        qCritical() << "RabbitMqMessageForwarder: Failed to forward data";
    }
    catch (AmqpClient::ConnectionException& ex)
    {
        qWarning() << "RabbitMqMessageForwarder: Connection to broker terminated";
        setupChannel();
    }
}

void RabbitMqMessageForwarder::forwardServerData(QByteArray data)
{
    AmqpClient::BasicMessage::ptr_t mq_msg = AmqpClient::BasicMessage::Create(QTextCodec::codecForMib(106)->toUnicode(data).toStdString());

    try
    {
        serverChannel_->BasicPublish(serverExchangeName_.toStdString(), "", mq_msg);
    }
    catch (AmqpClient::ChannelException& ex)
    {
        qCritical() << "RabbitMqMessageForwarder: Failed to forward data to server";
    }
    catch (AmqpClient::ConnectionException& ex)
    {
        qWarning() << "RabbitMqMessageForwarder: Connection to broker for server terminated";
        setupServerChannel();
    }
}
