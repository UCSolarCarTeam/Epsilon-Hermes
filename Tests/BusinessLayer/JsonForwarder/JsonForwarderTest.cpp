#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <QTest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QScopedPointer>
#include <QDebug>
#include <QDateTime>

#include "BusinessLayer/JsonForwarder/JsonForwarder.h"
#include "BusinessLayer/JsonForwarder/JsonDefines.h"

#include "Tests/InfrastructureLayer/Settings/MockSettings.h"
#include "Tests/CommunicationLayer/CommDeviceControl/MockMessageForwarder.h"
#include "Tests/BusinessLayer/JsonMessageBuilder/MockJsonMessageBuilder.h"
#include "Tests/DataLayer/AuxBmsData/MockAuxBmsData.h"
#include "Tests/DataLayer/BatteryData/MockBatteryData.h"
#include "Tests/DataLayer/BatteryFaultsData/MockBatteryFaultsData.h"
#include "Tests/DataLayer/DriverControlsData/MockDriverControlsData.h"
#include "Tests/DataLayer/KeyMotorData/MockKeyMotorData.h"
#include "Tests/DataLayer/LightsData/MockLightsData.h"
#include "Tests/DataLayer/MotorDetailsData/MockMotorDetailsData.h"
#include "Tests/DataLayer/MotorFaultsData/MockMotorFaultsData.h"
#include "Tests/DataLayer/MpptData/MockMpptData.h"

using ::testing::_;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::NiceMock;

namespace
{
    const int FORWARD_INTERVAL_MSEC = 50;
    const int FORWARD_ITERATIONS = 10;
    const QString PACKET_TITLE = "Gen5";
    const QString MYSQL_DATE_FORMAT = "yyyy-MM-dd HH:mm:ss";
}

class JsonForwarderTest : public ::testing::Test
{
protected:
    QScopedPointer<MockAuxBmsData> auxBmsData_;
    QScopedPointer<MockBatteryData> batteryData_ ;
    QScopedPointer<MockBatteryFaultsData> batteryFaultsData_ ;
    QScopedPointer<MockDriverControlsData> driverControlsData_ ;
    QScopedPointer<MockKeyMotorData> keyMotorData_ ;
    QScopedPointer<MockLightsData> lightsData_ ;
    QScopedPointer<MockMotorDetailsData> motorDetailsData_ ;
    QScopedPointer<MockMotorFaultsData> motorFaultsData_ ;
    QScopedPointer<MockMpptData> mpptData_ ;
    QScopedPointer<NiceMock<MockJsonMessageBuilder>> jsonMessageBuilder_;
    QScopedPointer<MockMessageForwarder> messageForwarder_;
    QScopedPointer<MockSettings> settings_;
    QScopedPointer<JsonForwarder> jsonForwarder_;

    virtual void SetUp()
    {
        auxBmsData_.reset(new MockAuxBmsData());
        batteryData_.reset(new MockBatteryData());
        batteryFaultsData_.reset(new MockBatteryFaultsData());
        driverControlsData_.reset(new MockDriverControlsData());
        keyMotorData_.reset(new MockKeyMotorData());
        lightsData_.reset(new MockLightsData());
        motorDetailsData_.reset(new MockMotorDetailsData());
        motorFaultsData_.reset(new MockMotorFaultsData());
        jsonMessageBuilder_.reset(new NiceMock<MockJsonMessageBuilder>());
        mpptData_.reset(new MockMpptData());
        messageForwarder_.reset(new MockMessageForwarder());
        settings_.reset(new MockSettings());
        EXPECT_CALL(*settings_, forwardPeriod())
        .WillRepeatedly(Return(FORWARD_INTERVAL_MSEC)); // Action must be set before jsonForwarder constructor
        EXPECT_CALL(*settings_, packetTitle())
        .WillRepeatedly(Return(PACKET_TITLE)); // Action must be set before jsonForwarder constructor
        jsonForwarder_.reset(new JsonForwarder(*jsonMessageBuilder_,
                                               *auxBmsData_,
                                               *batteryData_,
                                               *batteryFaultsData_,
                                               *driverControlsData_,
                                               *keyMotorData_,
                                               *lightsData_,
                                               *motorDetailsData_,
                                               *motorFaultsData_,
                                               *mpptData_,
                                               *messageForwarder_,
                                               *settings_));
    }
};


/****** JSON MATCHERS ******/

MATCHER_P2(JsonStringIs, key, value, "")
{
    QJsonObject jsonObj = QJsonDocument::fromJson(arg).object();
    QString actual = jsonObj[key].toString();
    QString expected = value;

    if (actual != expected)
    {
        qDebug() << "Actual is " << actual;
        qDebug() << "Expected is " << expected;
        return false;
    }

    return true;
}

/****** TESTS ******/

TEST_F(JsonForwarderTest, dataForwarded)
{
    EXPECT_CALL(*messageForwarder_, forwardData(_))
    .Times(FORWARD_ITERATIONS);
    jsonForwarder_->startForwardingData();
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS + FORWARD_INTERVAL_MSEC * 0.75);
}

TEST_F(JsonForwarderTest, correctTimeStamp)
{
    QDateTime currentTime = QDateTime::currentDateTime();
    EXPECT_CALL(*messageForwarder_, forwardData(JsonStringIs(JsonFormat::TIMESTAMP, currentTime.toUTC().toString(MYSQL_DATE_FORMAT))))
    .Times(AtLeast(1));
    jsonForwarder_->forwardData(currentTime);
}

TEST_F(JsonForwarderTest, packetTitle)
{
    EXPECT_CALL(*messageForwarder_, forwardData(JsonStringIs(JsonFormat::PACKET_TITLE, PACKET_TITLE)))
    .Times(AtLeast(1));
    jsonForwarder_->startForwardingData();
    QTest::qWait(FORWARD_INTERVAL_MSEC + FORWARD_INTERVAL_MSEC / 2);
}

