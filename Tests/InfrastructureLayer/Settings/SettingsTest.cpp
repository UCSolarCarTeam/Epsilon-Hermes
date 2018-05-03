#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <QScopedPointer>

#include "InfrastructureLayer/Settings/Settings.h"

namespace
{
const QString TEST_FILE_PATH = "testconfig.ini";
}

class SettingsTest : public ::testing::Test
{
protected:
    QScopedPointer<Settings> settings_;

    virtual void SetUp()
    {
        settings_.reset(new Settings(TEST_FILE_PATH));
    }
};

TEST_F(SettingsTest, serialPortName)
{
    EXPECT_EQ(settings_->serialPortName(), "/dev/pts/7");
}

TEST_F(SettingsTest, baudrate)
{
    EXPECT_EQ(settings_->baudrate(), 9600);
}

TEST_F(SettingsTest, ipAddress)
{
    EXPECT_EQ(settings_->ipAddress(), "239.255.43.21");
}

TEST_F(SettingsTest, port)
{
    EXPECT_EQ(settings_->port(), 44550);
}

TEST_F(SettingsTest, forwardPeriod)
{
    EXPECT_EQ(settings_->forwardPeriod(), 500);
}

TEST_F(SettingsTest, packetTitle)
{
    EXPECT_EQ(settings_->packetTitle(), "Gen5");
}

TEST_F(SettingsTest, exchangeName)
{
    EXPECT_EQ(settings_->exchangeName(), "hermesExchange");
}

TEST_F(SettingsTest, logLevel)
{
    EXPECT_EQ(settings_->logLevel(), 4);
}

TEST_F(SettingsTest, loggingEnabled)
{
    EXPECT_EQ(settings_->loggingEnabled(), true);
}
