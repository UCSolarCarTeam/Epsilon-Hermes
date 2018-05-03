#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <QScopedPointer>
#include <QDebug>
#include <QByteArray>
#include <string>

#include <SimpleAmqpClient/SimpleAmqpClient.h>

#include "CommunicationLayer/CommDeviceControl/RabbitMqMessageForwarder.h"
#include "InfrastructureLayer/Settings/MockSettings.h"

using ::testing::Return;
using ::testing::NiceMock;

namespace
{
    const QString MOCK_IP = QString("localhost");
    const quint16 MOCK_PORT = 5672;
    const QString MOCK_QUEUE = "test-queue";
    const QString MOCK_EXCHANGE = "testExchange";
    const QString EXPECTED_1 = "Message Test";
    const QString EXPECTED_2 = "Second Message Test";
    const QString EXPECTED_3 = "Sp3c1a1** Ch4r4c74r5__ 7357";
}

class RabbitMqMessageForwarderTest : public ::testing::Test
{
protected:

    QScopedPointer<MockSettings> settings_;
    QScopedPointer<RabbitMqMessageForwarder> forwarder;
    AmqpClient::Channel::ptr_t receiver;


    /**
    * SetUp will set up the receiver to verify messages are being sent, as well as mocking the settings to be used by the RabbitMqMessageForwarder
    */
    virtual void SetUp()
    {
        settings_.reset(new NiceMock<MockSettings>());
        ON_CALL(*settings_, ipAddress())
        .WillByDefault(Return(MOCK_IP));
        ON_CALL(*settings_, exchangeName())
        .WillByDefault(Return(MOCK_EXCHANGE));
        ON_CALL(*settings_, port())
        .WillByDefault(Return(MOCK_PORT));
    }

    virtual void TearDown()
    {
        // Delete exchange
        receiver->DeleteExchange(MOCK_EXCHANGE.toStdString());
        cleanReceiver();
    }

    // Test Methods

    void sendMessage(const QString& message);
    QString receiveMessage(bool setupConsume);
    /**
     * setup the receiver for usage
     */
    void setupReceiver();
    /**
     * reset the receiver (clear and delete queue)
     */
    void cleanReceiver();
};

void RabbitMqMessageForwarderTest::sendMessage(const QString& message)
{
    QByteArray expectedBytes = QByteArray();
    expectedBytes.append(message);
    forwarder->forwardData(expectedBytes);
}

QString RabbitMqMessageForwarderTest::receiveMessage(bool setupConsume)
{
    // Receive message from local server
    if (setupConsume)
    {
        receiver->BasicConsume(MOCK_QUEUE.toStdString());
    }

    return QString::fromStdString(receiver->BasicConsumeMessage()->Message()->Body());
}

void RabbitMqMessageForwarderTest::setupReceiver()
{
    receiver = AmqpClient::Channel::Create(MOCK_IP.toStdString(), MOCK_PORT);
    // passive (false), durable (true), exclusive (false), auto_delete (false)
    receiver->DeclareQueue(MOCK_QUEUE.toStdString(), false, true, false, false);
    receiver->DeclareExchange(MOCK_EXCHANGE.toStdString(), AmqpClient::Channel::EXCHANGE_TYPE_FANOUT);
    receiver->BindQueue(MOCK_QUEUE.toStdString(), MOCK_EXCHANGE.toStdString(), "");
}

void RabbitMqMessageForwarderTest::cleanReceiver()
{
    receiver->PurgeQueue(MOCK_QUEUE.toStdString());
    receiver->DeleteQueue(MOCK_QUEUE.toStdString());
    receiver.reset();
}


/**
 * Send a single message representing a JSON string via RabbitMqMessageForwarder and verify its success
 */
TEST_F(RabbitMqMessageForwarderTest, testSendingMessage)
{
    setupReceiver();
    forwarder.reset(new RabbitMqMessageForwarder(*settings_));
    sendMessage(EXPECTED_1);
    QString ACTUAL = receiveMessage(true);
    EXPECT_EQ(EXPECTED_1.toStdString(), ACTUAL.toStdString());
}

/**
 * Send a message before the receiver has setup
 */
TEST_F(RabbitMqMessageForwarderTest, testSendingNoReceiver)
{
    setupReceiver();
    forwarder.reset(new RabbitMqMessageForwarder(*settings_));
    sendMessage(EXPECTED_1);
    setupReceiver();
    QString ACTUAL = receiveMessage(true);
    EXPECT_EQ(EXPECTED_1.toStdString(), ACTUAL.toStdString());
}

/**
 * Disconnect the receiver during delivery and ensure messages still arrive
 */
TEST_F(RabbitMqMessageForwarderTest, testSendingReceiverDC)
{
    setupReceiver();
    forwarder.reset(new RabbitMqMessageForwarder(*settings_));
    sendMessage(EXPECTED_1);
    QString ACTUAL = receiveMessage(true);
    EXPECT_EQ(EXPECTED_1.toStdString(), ACTUAL.toStdString());
    receiver.reset();
    sendMessage(EXPECTED_2);
    setupReceiver();
    ACTUAL = receiveMessage(true);
    EXPECT_EQ(EXPECTED_2.toStdString(), ACTUAL.toStdString());
}

/**
 * test sending message with special characters
 */
TEST_F(RabbitMqMessageForwarderTest, testSendingSpecialChars)
{
    setupReceiver();
    forwarder.reset(new RabbitMqMessageForwarder(*settings_));
    sendMessage(EXPECTED_3);
    QString ACTUAL = receiveMessage(true);
    EXPECT_EQ(EXPECTED_3.toStdString(), ACTUAL.toStdString());
}
