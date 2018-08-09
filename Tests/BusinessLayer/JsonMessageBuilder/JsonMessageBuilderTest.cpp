#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <QTest>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QScopedPointer>

#include "BusinessLayer/JsonMessageBuilder/JsonMessageBuilder.h"
#include "BusinessLayer/JsonForwarder/JsonDefines.h"

#include "Tests/DataLayer/KeyMotorData/MockKeyMotorData.h"
#include "Tests/DataLayer/MotorDetailsData/MockMotorDetailsData.h"
#include "Tests/DataLayer/MotorDetailsData/MockMotorDetailsUnit.h"
#include "Tests/DataLayer/DriverControlsData/MockDriverControlsData.h"
#include "Tests/DataLayer/MotorFaultsData/MockMotorFaultsData.h"
#include "Tests/DataLayer/BatteryFaultsData/MockBatteryFaultsData.h"
#include "Tests/DataLayer/BatteryData/MockBatteryData.h"
#include "Tests/DataLayer/MpptData/MockMpptData.h"
#include "Tests/DataLayer/MpptData/MockMpptUnit.h"
#include "Tests/DataLayer/LightsData/MockLightsData.h"
#include "Tests/DataLayer/AuxBmsData/MockAuxBmsData.h"

using ::testing::Return;
using ::testing::ReturnRef;
using ::testing::NiceMock;

class JsonMessageBuilderTest : public ::testing::Test
{
};

TEST(JsonMessageBuilderTest, keyMotor)
{
    JsonMessageBuilder jsonMessageBuilder;

    // *INDENT-OFF*
    QString EXPECTED_JSON_MSG = "\
    [ \
        { \
            \"Alive\":true, \
            \"SetCurrent\":1, \
            \"SetVelocity\":2, \
            \"BusCurrent\":3, \
            \"BusVoltage\":4, \
            \"VehicleVelocity\":5 \
        }, \
        { \
            \"Alive\":false, \
            \"SetCurrent\":6, \
            \"SetVelocity\":7, \
            \"BusCurrent\":8, \
            \"BusVoltage\":9, \
            \"VehicleVelocity\":10 \
        } \
    ]";
    // *INDENT-ON*

    QJsonDocument EXPECTED_JSON_DOC = QJsonDocument::fromJson(EXPECTED_JSON_MSG.toLatin1());
    QJsonArray EXPECTED_JSON_ARRAY = EXPECTED_JSON_DOC.array();

    NiceMock<MockKeyMotorData> mockKeyMotorData;
    const unsigned char M0_ALIVE_VAL = true;
    const float M0_SET_CURRENT_VAL = 1;
    const float M0_SET_VELOCITY_VAL = 2;
    const float M0_BUS_CURRENT_VAL = 3;
    const float M0_BUS_VOLTAGE_VAL = 4;
    const float M0_VEHICLE_VELOCITY_VAL = 5;
    const unsigned char M1_ALIVE_VAL = false;
    const float M1_SET_CURRENT_VAL = 6;
    const float M1_SET_VELOCITY_VAL = 7;
    const float M1_BUS_CURRENT_VAL = 8;
    const float M1_BUS_VOLTAGE_VAL = 9;
    const float M1_VEHICLE_VELOCITY_VAL = 10;

    ON_CALL(mockKeyMotorData, getM0Alive())
    .WillByDefault(Return(M0_ALIVE_VAL));
    ON_CALL(mockKeyMotorData, getM0SetCurrent())
    .WillByDefault(Return(M0_SET_CURRENT_VAL));
    ON_CALL(mockKeyMotorData, getM0SetVelocity())
    .WillByDefault(Return(M0_SET_VELOCITY_VAL));
    ON_CALL(mockKeyMotorData, getM0BusCurrent())
    .WillByDefault(Return(M0_BUS_CURRENT_VAL));
    ON_CALL(mockKeyMotorData, getM0BusVoltage())
    .WillByDefault(Return(M0_BUS_VOLTAGE_VAL));
    ON_CALL(mockKeyMotorData, getM0VehicleVelocity())
    .WillByDefault(Return(M0_VEHICLE_VELOCITY_VAL));

    ON_CALL(mockKeyMotorData, getM1Alive())
    .WillByDefault(Return(M1_ALIVE_VAL));
    ON_CALL(mockKeyMotorData, getM1SetCurrent())
    .WillByDefault(Return(M1_SET_CURRENT_VAL));
    ON_CALL(mockKeyMotorData, getM1SetVelocity())
    .WillByDefault(Return(M1_SET_VELOCITY_VAL));
    ON_CALL(mockKeyMotorData, getM1BusCurrent())
    .WillByDefault(Return(M1_BUS_CURRENT_VAL));
    ON_CALL(mockKeyMotorData, getM1BusVoltage())
    .WillByDefault(Return(M1_BUS_VOLTAGE_VAL));
    ON_CALL(mockKeyMotorData, getM1VehicleVelocity())
    .WillByDefault(Return(M1_VEHICLE_VELOCITY_VAL));

    QJsonArray ACTUAL_JSON_ARRAY =
        jsonMessageBuilder.buildKeyMotorMessage(mockKeyMotorData);

    EXPECT_EQ(EXPECTED_JSON_ARRAY, ACTUAL_JSON_ARRAY);

    if (HasFailure())
    {
        qDebug() << "Actual is " << ACTUAL_JSON_ARRAY;
        qDebug() << "Expected is " << EXPECTED_JSON_ARRAY;
    }
}

TEST(JsonMessageBuilderTest, motorDetails)
{
    JsonMessageBuilder jsonMessageBuilder;

    // *INDENT-OFF*
    QString EXPECTED_JSON_MSG = "\
    [{ \
        \"PhaseCCurrent\": 1, \
        \"PhaseBCurrent\": 2, \
        \"MotorVoltageReal\": 3, \
        \"MotorVoltageImaginary\": 4, \
        \"MotorCurrentReal\": 5, \
        \"MotorCurrentImaginary\": 6, \
        \"BackEmf\": 7, \
        \"VoltageRail15VSupply\": 9, \
        \"VoltageRail3VSupply\": 10, \
        \"VoltageRail1VSupply\": 11, \
        \"HeatSinkTemp\": 12, \
        \"MotorTemp\": 13, \
        \"DspBoardTemp\": 14, \
        \"DcBusAmpHours\": 15, \
        \"Odometer\": 16, \
        \"SlipSpeed\": 17 \
    }, { \
        \"PhaseCCurrent\": 18, \
        \"PhaseBCurrent\": 19, \
        \"MotorVoltageReal\": 20, \
        \"MotorVoltageImaginary\": 21, \
        \"MotorCurrentReal\": 22, \
        \"MotorCurrentImaginary\": 23, \
        \"BackEmf\": 24, \
        \"VoltageRail15VSupply\": 26, \
        \"VoltageRail3VSupply\": 27, \
        \"VoltageRail1VSupply\": 28, \
        \"HeatSinkTemp\": 29, \
        \"MotorTemp\": 30, \
        \"DspBoardTemp\": 31, \
        \"DcBusAmpHours\": 32, \
        \"Odometer\": 33, \
        \"SlipSpeed\": 34 \
    }]";
    // *INDENT-ON*

    QJsonDocument EXPECTED_JSON_DOC = QJsonDocument::fromJson(EXPECTED_JSON_MSG.toLatin1());
    QJsonArray EXPECTED_JSON_ARRAY = EXPECTED_JSON_DOC.array();

    NiceMock<MockMotorDetailsData> mockMotorDetailsData;
    NiceMock<MockMotorDetailsUnit> mockMotorDetailsUnit_0;
    NiceMock<MockMotorDetailsUnit> mockMotorDetailsUnit_1;

    ON_CALL(mockMotorDetailsData, getNumberOfUnits())
    .WillByDefault(Return(2));
    ON_CALL(mockMotorDetailsData, getMotorDetailsUnit(0))
    .WillByDefault(ReturnRef(mockMotorDetailsUnit_0));
    ON_CALL(mockMotorDetailsData, getMotorDetailsUnit(1))
    .WillByDefault(ReturnRef(mockMotorDetailsUnit_1));

    const float M0_PHASE_C_CURRENT_VAL = 1;
    const float M0_PHASE_B_CURRENT_VAL = 2;
    const float M0_MOTOR_VOLTAGE_REAL_VAL = 3;
    const float M0_MOTOR_VOLTAGE_IMAGINARY_VAL = 4;
    const float M0_MOTOR_CURRENT_REAL_VAL = 5;
    const float M0_MOTOR_CURRENT_IMAGINARY_VAL = 6;
    const float M0_BACK_EMF_VAL = 7;
    const float M0_VOLTAGE_RAIL_15V_SUPPLY_VAL = 9;
    const float M0_VOLTAGE_RAIL_3V_SUPPLY_VAL = 10;
    const float M0_VOLTAGE_RAIL_1V_SUPPLY_VAL = 11;
    const float M0_HEAT_SINK_TEMP_VAL = 12;
    const float M0_MOTOR_TEMP__VAL = 13;
    const float M0_DSP_BOARD_TEMP_VAL = 14;
    const float M0_DC_BUS_AMPHOURS_VAL = 15;
    const float M0_ODOMETER_VAL = 16;
    const float M0_SLIP_SPEED_VAL = 17;

    const float M1_PHASE_C_CURRENT_VAL = 18;
    const float M1_PHASE_B_CURRENT_VAL = 19;
    const float M1_MOTOR_VOLTAGE_REAL_VAL = 20;
    const float M1_MOTOR_VOLTAGE_IMAGINARY_VAL = 21;
    const float M1_MOTOR_CURRENT_REAL_VAL = 22;
    const float M1_MOTOR_CURRENT_IMAGINARY_VAL = 23;
    const float M1_BACK_EMF_VAL = 24;
    const float M1_VOLTAGE_RAIL_15V_SUPPLY_VAL = 26;
    const float M1_VOLTAGE_RAIL_3V_SUPPLY_VAL = 27;
    const float M1_VOLTAGE_RAIL_1V_SUPPLY_VAL = 28;
    const float M1_HEAT_SINK_TEMP_VAL = 29;
    const float M1_MOTOR_TEMP_VAL = 30;
    const float M1_DSP_BOARD_TEMP_VAL = 31;
    const float M1_DC_BUS_AMPHOURS_VAL = 32;
    const float M1_ODOMETER_VAL = 33;
    const float M1_SLIP_SPEED_VAL = 34;

    ON_CALL(mockMotorDetailsUnit_0, getMotorNumber())
    .WillByDefault(Return(0));
    ON_CALL(mockMotorDetailsUnit_0, getPhaseCCurrent())
    .WillByDefault(Return(M0_PHASE_C_CURRENT_VAL));
    ON_CALL(mockMotorDetailsUnit_0, getPhaseBCurrent())
    .WillByDefault(Return(M0_PHASE_B_CURRENT_VAL));
    ON_CALL(mockMotorDetailsUnit_0, getMotorVoltageReal())
    .WillByDefault(Return(M0_MOTOR_VOLTAGE_REAL_VAL));
    ON_CALL(mockMotorDetailsUnit_0, getMotorVoltageImaginary())
    .WillByDefault(Return(M0_MOTOR_VOLTAGE_IMAGINARY_VAL));
    ON_CALL(mockMotorDetailsUnit_0, getMotorCurrentReal())
    .WillByDefault(Return(M0_MOTOR_CURRENT_REAL_VAL));
    ON_CALL(mockMotorDetailsUnit_0, getMotorCurrentImaginary())
    .WillByDefault(Return(M0_MOTOR_CURRENT_IMAGINARY_VAL));
    ON_CALL(mockMotorDetailsUnit_0, getBackEmf())
    .WillByDefault(Return(M0_BACK_EMF_VAL));
    ON_CALL(mockMotorDetailsUnit_0, getVoltageRailSuppply15V())
    .WillByDefault(Return(M0_VOLTAGE_RAIL_15V_SUPPLY_VAL));
    ON_CALL(mockMotorDetailsUnit_0, getVoltageRailSupply33V())
    .WillByDefault(Return(M0_VOLTAGE_RAIL_3V_SUPPLY_VAL));
    ON_CALL(mockMotorDetailsUnit_0, getVoltageRailSupply19V())
    .WillByDefault(Return(M0_VOLTAGE_RAIL_1V_SUPPLY_VAL));
    ON_CALL(mockMotorDetailsUnit_0, getHeatSinkTemperature())
    .WillByDefault(Return(M0_HEAT_SINK_TEMP_VAL));
    ON_CALL(mockMotorDetailsUnit_0, getMotorTemperature())
    .WillByDefault(Return(M0_MOTOR_TEMP__VAL));
    ON_CALL(mockMotorDetailsUnit_0, getDspBoardTemperature())
    .WillByDefault(Return(M0_DSP_BOARD_TEMP_VAL));
    ON_CALL(mockMotorDetailsUnit_0, getDcBusAmpHours())
    .WillByDefault(Return(M0_DC_BUS_AMPHOURS_VAL));
    ON_CALL(mockMotorDetailsUnit_0, getOdometer())
    .WillByDefault(Return(M0_ODOMETER_VAL));
    ON_CALL(mockMotorDetailsUnit_0, getSlipSpeed())
    .WillByDefault(Return(M0_SLIP_SPEED_VAL));

    ON_CALL(mockMotorDetailsUnit_1, getMotorNumber())
    .WillByDefault(Return(1));
    ON_CALL(mockMotorDetailsUnit_1, getPhaseCCurrent())
    .WillByDefault(Return(M1_PHASE_C_CURRENT_VAL));
    ON_CALL(mockMotorDetailsUnit_1, getPhaseBCurrent())
    .WillByDefault(Return(M1_PHASE_B_CURRENT_VAL));
    ON_CALL(mockMotorDetailsUnit_1, getMotorVoltageReal())
    .WillByDefault(Return(M1_MOTOR_VOLTAGE_REAL_VAL));
    ON_CALL(mockMotorDetailsUnit_1, getMotorVoltageImaginary())
    .WillByDefault(Return(M1_MOTOR_VOLTAGE_IMAGINARY_VAL));
    ON_CALL(mockMotorDetailsUnit_1, getMotorCurrentReal())
    .WillByDefault(Return(M1_MOTOR_CURRENT_REAL_VAL));
    ON_CALL(mockMotorDetailsUnit_1, getMotorCurrentImaginary())
    .WillByDefault(Return(M1_MOTOR_CURRENT_IMAGINARY_VAL));
    ON_CALL(mockMotorDetailsUnit_1, getBackEmf())
    .WillByDefault(Return(M1_BACK_EMF_VAL));
    ON_CALL(mockMotorDetailsUnit_1, getVoltageRailSuppply15V())
    .WillByDefault(Return(M1_VOLTAGE_RAIL_15V_SUPPLY_VAL));
    ON_CALL(mockMotorDetailsUnit_1, getVoltageRailSupply33V())
    .WillByDefault(Return(M1_VOLTAGE_RAIL_3V_SUPPLY_VAL));
    ON_CALL(mockMotorDetailsUnit_1, getVoltageRailSupply19V())
    .WillByDefault(Return(M1_VOLTAGE_RAIL_1V_SUPPLY_VAL));
    ON_CALL(mockMotorDetailsUnit_1, getHeatSinkTemperature())
    .WillByDefault(Return(M1_HEAT_SINK_TEMP_VAL));
    ON_CALL(mockMotorDetailsUnit_1, getMotorTemperature())
    .WillByDefault(Return(M1_MOTOR_TEMP_VAL));
    ON_CALL(mockMotorDetailsUnit_1, getDspBoardTemperature())
    .WillByDefault(Return(M1_DSP_BOARD_TEMP_VAL));
    ON_CALL(mockMotorDetailsUnit_1, getDcBusAmpHours())
    .WillByDefault(Return(M1_DC_BUS_AMPHOURS_VAL));
    ON_CALL(mockMotorDetailsUnit_1, getOdometer())
    .WillByDefault(Return(M1_ODOMETER_VAL));
    ON_CALL(mockMotorDetailsUnit_1, getSlipSpeed())
    .WillByDefault(Return(M1_SLIP_SPEED_VAL));

    QJsonArray ACTUAL_JSON_ARRAY =
        jsonMessageBuilder.buildMotorDetailsMessage(mockMotorDetailsData);

    EXPECT_EQ(EXPECTED_JSON_ARRAY, ACTUAL_JSON_ARRAY);

    if (HasFailure())
    {
        qDebug() << "Actual is " << ACTUAL_JSON_ARRAY;
        qDebug() << "Expected is " << EXPECTED_JSON_ARRAY;
    }
}

TEST(JsonMessageBuilderTest, driverControls)
{
    JsonMessageBuilder jsonMessageBuilder;

    // *INDENT-OFF*
    QString EXPECTED_JSON_MSG = "\
    { \
        \"Alive\": false, \
        \"HeadlightsOff\": true, \
        \"HeadlightsLow\": false, \
        \"HeadlightsHigh\": true, \
        \"SignalRight\": false, \
        \"SignalLeft\": true, \
        \"Hazard\": false, \
        \"Interior\": true, \
        \"Aux\": true, \
        \"VolumeUp\": false, \
        \"VolumeDown\": true, \
        \"NextSong\": false, \
        \"PrevSong\": true, \
        \"Acceleration\": 5, \
        \"RegenBraking\": 2, \
        \"Brakes\": true, \
        \"Forward\": false, \
        \"Reverse\": true, \
        \"PushToTalk\": false, \
        \"Horn\": true, \
        \"Reset\": false \
    }";
    // *INDENT-ON*

    QJsonDocument EXPECTED_JSON_DOC = QJsonDocument::fromJson(EXPECTED_JSON_MSG.toLatin1());
    QJsonObject EXPECTED_JSON = EXPECTED_JSON_DOC.object();

    NiceMock<MockDriverControlsData> mockDriverControlsData;
    const bool ALIVE_VAL = false;
    const bool HEADLIGHTS_OFF_VAL = true;
    const bool HEADLIGHTS_LOW_VAL = false;
    const bool HEADLIGHTS_HIGH_VAL = true;
    const bool SIGNAL_RIGHT_VAL = false;
    const bool SIGNAL_LEFT_VAL = true;
    const bool HAZARD_VAL = false;
    const bool INTERIOR_VAL = true;
    const bool AUX_VAL = true;
    const bool VOLUME_UP_VAL = false;
    const bool VOLUME_DOWN_VAL = true;
    const bool NEXT_SONG_VAL = false;
    const bool PREV_SONG_VAL = true;
    const bool BRAKES_VAL = true;
    const bool FORWARD_VAL = false;
    const bool REVERSE_VAL = true;
    const bool PUSH_TO_TALK_VAL = false;
    const bool HORN_VAL = true;
    const bool RESET_VAL = false;
    const unsigned short ACCELERATION_VAL = 5;
    const unsigned short REGEN_BRAKING_VAL = 2;

    ON_CALL(mockDriverControlsData, getDriverControlsBoardAlive())
    .WillByDefault(Return(ALIVE_VAL));
    ON_CALL(mockDriverControlsData, getHeadlightsOff())
    .WillByDefault(Return(HEADLIGHTS_OFF_VAL));
    ON_CALL(mockDriverControlsData, getHeadlightsLow())
    .WillByDefault(Return(HEADLIGHTS_LOW_VAL));
    ON_CALL(mockDriverControlsData, getHeadlightsHigh())
    .WillByDefault(Return(HEADLIGHTS_HIGH_VAL));
    ON_CALL(mockDriverControlsData, getSignalRight())
    .WillByDefault(Return(SIGNAL_RIGHT_VAL));
    ON_CALL(mockDriverControlsData, getSignalLeft())
    .WillByDefault(Return(SIGNAL_LEFT_VAL));
    ON_CALL(mockDriverControlsData, getHazard())
    .WillByDefault(Return(HAZARD_VAL));
    ON_CALL(mockDriverControlsData, getInterior())
    .WillByDefault(Return(INTERIOR_VAL));
    ON_CALL(mockDriverControlsData, getAux())
    .WillByDefault(Return(AUX_VAL));
    ON_CALL(mockDriverControlsData, getVolumeUp())
    .WillByDefault(Return(VOLUME_UP_VAL));
    ON_CALL(mockDriverControlsData, getVolumeDown())
    .WillByDefault(Return(VOLUME_DOWN_VAL));
    ON_CALL(mockDriverControlsData, getNextSong())
    .WillByDefault(Return(NEXT_SONG_VAL));
    ON_CALL(mockDriverControlsData, getPreviousSong())
    .WillByDefault(Return(PREV_SONG_VAL));
    ON_CALL(mockDriverControlsData, getBrakes())
    .WillByDefault(Return(BRAKES_VAL));
    ON_CALL(mockDriverControlsData, getForward())
    .WillByDefault(Return(FORWARD_VAL));
    ON_CALL(mockDriverControlsData, getReverse())
    .WillByDefault(Return(REVERSE_VAL));
    ON_CALL(mockDriverControlsData, getPushToTalk())
    .WillByDefault(Return(PUSH_TO_TALK_VAL));
    ON_CALL(mockDriverControlsData, getHorn())
    .WillByDefault(Return(HORN_VAL));
    ON_CALL(mockDriverControlsData, getReset())
    .WillByDefault(Return(RESET_VAL));
    ON_CALL(mockDriverControlsData, getAcceleration())
    .WillByDefault(Return(ACCELERATION_VAL));
    ON_CALL(mockDriverControlsData, getRegenBraking())
    .WillByDefault(Return(REGEN_BRAKING_VAL));

    QJsonObject ACTUAL_JSON =
        jsonMessageBuilder.buildDriverControlsMessage(mockDriverControlsData);

    EXPECT_EQ(EXPECTED_JSON, ACTUAL_JSON);

    if (HasFailure())
    {
        qDebug() << "Actual is " << ACTUAL_JSON;
        qDebug() << "Expected is " << EXPECTED_JSON;
    }
}

TEST(JsonMessageBuilderTest, motorFaults)
{
    JsonMessageBuilder jsonMessageBuilder;

    // *INDENT-OFF*
    QString EXPECTED_JSON_MSG = "\
    [ \
        { \
            \"ErrorFlags\":{ \
                \"MotorOverSpeed\":true, \
                \"SoftwareOverCurrent\":false, \
                \"DcBusOverVoltage\":true, \
                \"BadMotorPositionHallSequence\":false, \
                \"WatchdogCausedLastReset\":true, \
                \"ConfigReadError\":false, \
                \"Rail15VUnderVoltageLockOut\":true, \
                \"DesaturationFault\":false \
            }, \
            \"LimitFlags\":{ \
                \"OutputVoltagePwm\":true, \
                \"MotorCurrent\":false, \
                \"Velocity\":true, \
                \"BusCurrent\":false, \
                \"BusVoltageUpper\":true, \
                \"BusVoltageLower\":false, \
                \"IpmOrMotorTemperature\":true \
            }, \
            \"RxErrorCount\":55, \
            \"TxErrorCount\":82 \
        }, \
        { \
            \"ErrorFlags\":{ \
                \"MotorOverSpeed\":false, \
                \"SoftwareOverCurrent\":true, \
                \"DcBusOverVoltage\":false, \
                \"BadMotorPositionHallSequence\":true, \
                \"WatchdogCausedLastReset\":false, \
                \"ConfigReadError\":true, \
                \"Rail15VUnderVoltageLockOut\":false, \
                \"DesaturationFault\":true \
            }, \
            \"LimitFlags\":{ \
                \"OutputVoltagePwm\":false, \
                \"MotorCurrent\":true, \
                \"Velocity\":false, \
                \"BusCurrent\":true, \
                \"BusVoltageUpper\":false, \
                \"BusVoltageLower\":true, \
                \"IpmOrMotorTemperature\":false \
            }, \
            \"RxErrorCount\":59, \
            \"TxErrorCount\":81 \
        } \
    ]";
    // *INDENT-ON*

    QJsonDocument EXPECTED_JSON_DOC = QJsonDocument::fromJson(EXPECTED_JSON_MSG.toLatin1());
    QJsonArray EXPECTED_JSON_ARRAY = EXPECTED_JSON_DOC.array();

    NiceMock<MockMotorFaultsData> mockMotorFaultsData;

    const unsigned char M0_RX_ERROR_COUNT = 55;
    const unsigned char M0_TX_ERROR_COUNT = 82;
    const unsigned char M1_RX_ERROR_COUNT = 59;
    const unsigned char M1_TX_ERROR_COUNT = 81;

    const bool M0_MOTOR_OVER_SPEED = true;
    const bool M0_SOFTWARE_OVER_CURRENT = false;
    const bool M0_DC_BUS_OVER_VOLTAGE = true;
    const bool M0_BAD_MOTOR_POSITION_HALL_SEQUENCE = false;
    const bool M0_WATCHDOG_CAUSED_LAST_RESET = true;
    const bool M0_CONFIG_READ_ERROR = false;
    const bool M0_RAIL_15V_UNDER_VOLTAGE_LOCK_OUT = true;
    const bool M0_DESATURATION_FAULT = false;

    const bool M1_MOTOR_OVER_SPEED = false;
    const bool M1_SOFTWARE_OVER_CURRENT = true;
    const bool M1_DC_BUS_OVER_VOLTAGE = false;
    const bool M1_BAD_MOTOR_POSITION_HALL_SEQUENCE = true;
    const bool M1_WATCHDOG_CAUSED_LAST_RESET = false;
    const bool M1_CONFIG_READ_ERROR = true;
    const bool M1_RAIL_15V_UNDER_VOLTAGE_LOCK_OUT = false;
    const bool M1_DESATURATION_FAULT = true;

    const bool M0_OUTPUT_VOLTAGE_PWM = true;
    const bool M0_MOTOR_CURRENT = false;
    const bool M0_VELOCITY = true;
    const bool M0_BUS_CURRENT = false;
    const bool M0_BUS_VOLTAGE_UPPER = true;
    const bool M0_BUS_VOLTAGE_LOWER = false;
    const bool M0_IPM_OR_MOTOR_TEMPERATURE = true;

    const bool M1_OUTPUT_VOLTAGE_PWM = false;
    const bool M1_MOTOR_CURRENT = true;
    const bool M1_VELOCITY = false;
    const bool M1_BUS_CURRENT = true;
    const bool M1_BUS_VOLTAGE_UPPER = false;
    const bool M1_BUS_VOLTAGE_LOWER = true;
    const bool M1_IPM_OR_MOTOR_TEMPERATURE = false;

    ON_CALL(mockMotorFaultsData, getM0CanRxErrorCount())
    .WillByDefault(Return(M0_RX_ERROR_COUNT));
    ON_CALL(mockMotorFaultsData, getM0CanTxErrorCount())
    .WillByDefault(Return(M0_TX_ERROR_COUNT));
    ON_CALL(mockMotorFaultsData, getM1CanRxErrorCount())
    .WillByDefault(Return(M1_RX_ERROR_COUNT));
    ON_CALL(mockMotorFaultsData, getM1CanTxErrorCount())
    .WillByDefault(Return(M1_TX_ERROR_COUNT));

    ON_CALL(mockMotorFaultsData, m0MotorOverSpeed())
    .WillByDefault(Return(M0_MOTOR_OVER_SPEED));
    ON_CALL(mockMotorFaultsData, m0SoftwareOverCurrent())
    .WillByDefault(Return(M0_SOFTWARE_OVER_CURRENT));
    ON_CALL(mockMotorFaultsData, m0DcBusOverVoltage())
    .WillByDefault(Return(M0_DC_BUS_OVER_VOLTAGE));
    ON_CALL(mockMotorFaultsData, m0BadMotorPositionHallSequence())
    .WillByDefault(Return(M0_BAD_MOTOR_POSITION_HALL_SEQUENCE));
    ON_CALL(mockMotorFaultsData, m0WatchdogCausedLastReset())
    .WillByDefault(Return(M0_WATCHDOG_CAUSED_LAST_RESET));
    ON_CALL(mockMotorFaultsData, m0ConfigReadError())
    .WillByDefault(Return(M0_CONFIG_READ_ERROR));
    ON_CALL(mockMotorFaultsData, m0RailUnderVoltageLockOut())
    .WillByDefault(Return(M0_RAIL_15V_UNDER_VOLTAGE_LOCK_OUT));
    ON_CALL(mockMotorFaultsData, m0DesaturationFault())
    .WillByDefault(Return(M0_DESATURATION_FAULT));

    ON_CALL(mockMotorFaultsData, m1MotorOverSpeed())
    .WillByDefault(Return(M1_MOTOR_OVER_SPEED));
    ON_CALL(mockMotorFaultsData, m1SoftwareOverCurrent())
    .WillByDefault(Return(M1_SOFTWARE_OVER_CURRENT));
    ON_CALL(mockMotorFaultsData, m1DcBusOverVoltage())
    .WillByDefault(Return(M1_DC_BUS_OVER_VOLTAGE));
    ON_CALL(mockMotorFaultsData, m1BadMotorPositionHallSequence())
    .WillByDefault(Return(M1_BAD_MOTOR_POSITION_HALL_SEQUENCE));
    ON_CALL(mockMotorFaultsData, m1WatchdogCausedLastReset())
    .WillByDefault(Return(M1_WATCHDOG_CAUSED_LAST_RESET));
    ON_CALL(mockMotorFaultsData, m1ConfigReadError())
    .WillByDefault(Return(M1_CONFIG_READ_ERROR));
    ON_CALL(mockMotorFaultsData, m1RailUnderVoltageLockOut())
    .WillByDefault(Return(M1_RAIL_15V_UNDER_VOLTAGE_LOCK_OUT));
    ON_CALL(mockMotorFaultsData, m1DesaturationFault())
    .WillByDefault(Return(M1_DESATURATION_FAULT));

    ON_CALL(mockMotorFaultsData, m0OutputVoltagePwmLimit())
    .WillByDefault(Return(M0_OUTPUT_VOLTAGE_PWM));
    ON_CALL(mockMotorFaultsData, m0MotorCurrentLimit())
    .WillByDefault(Return(M0_MOTOR_CURRENT));
    ON_CALL(mockMotorFaultsData, m0VelocityLimit())
    .WillByDefault(Return(M0_VELOCITY));
    ON_CALL(mockMotorFaultsData, m0BusCurrentLimit())
    .WillByDefault(Return(M0_BUS_CURRENT));
    ON_CALL(mockMotorFaultsData, m0BusVoltageUpperLimit())
    .WillByDefault(Return(M0_BUS_VOLTAGE_UPPER));
    ON_CALL(mockMotorFaultsData, m0BusVoltageLowerLimit())
    .WillByDefault(Return(M0_BUS_VOLTAGE_LOWER));
    ON_CALL(mockMotorFaultsData, m0IpmOrMotorTemperatureLimit())
    .WillByDefault(Return(M0_IPM_OR_MOTOR_TEMPERATURE));

    ON_CALL(mockMotorFaultsData, m1OutputVoltagePwmLimit())
    .WillByDefault(Return(M1_OUTPUT_VOLTAGE_PWM));
    ON_CALL(mockMotorFaultsData, m1MotorCurrentLimit())
    .WillByDefault(Return(M1_MOTOR_CURRENT));
    ON_CALL(mockMotorFaultsData, m1VelocityLimit())
    .WillByDefault(Return(M1_VELOCITY));
    ON_CALL(mockMotorFaultsData, m1BusCurrentLimit())
    .WillByDefault(Return(M1_BUS_CURRENT));
    ON_CALL(mockMotorFaultsData, m1BusVoltageUpperLimit())
    .WillByDefault(Return(M1_BUS_VOLTAGE_UPPER));
    ON_CALL(mockMotorFaultsData, m1BusVoltageLowerLimit())
    .WillByDefault(Return(M1_BUS_VOLTAGE_LOWER));
    ON_CALL(mockMotorFaultsData, m1IpmOrMotorTemperatureLimit())
    .WillByDefault(Return(M1_IPM_OR_MOTOR_TEMPERATURE));

    QJsonArray ACTUAL_JSON_ARRAY =
        jsonMessageBuilder.buildMotorFaultsMessage(mockMotorFaultsData);

    EXPECT_EQ(EXPECTED_JSON_ARRAY, ACTUAL_JSON_ARRAY);

    if (HasFailure())
    {
        qDebug() << "Actual is " << ACTUAL_JSON_ARRAY;
        qDebug() << "Expected is " << EXPECTED_JSON_ARRAY;
    }
}

TEST(JsonMessageBuilderTest, batteryFaults)
{
    JsonMessageBuilder jsonMessageBuilder;

    // *INDENT-OFF*
    QString EXPECTED_JSON_MSG = "\
    { \
        \"ErrorFlags\": { \
            \"InternalCommunicationFault\": false, \
            \"InternalConversionFault\": true, \
            \"WeakCellFault\": false, \
            \"LowCellVoltageFault\": true, \
            \"OpenWiringFault\": false, \
            \"CurrentSensorFault\": true, \
            \"PackVoltageSensorFault\": false, \
            \"WeakPackFault\": true, \
            \"VoltageRedundancyFault\": false, \
            \"FanMonitorFault\": true, \
            \"ThermistorFault\": false, \
            \"CANBUSCommunicationsFault\": true, \
            \"AlwaysOnSupplyFault\": false, \
            \"HighVoltageIsolationFault\": true, \
            \"12vPowerSupplyFault\": false, \
            \"ChargeLimitEnforcementFault\": true, \
            \"DischargeLimitEnforcementFault\": false, \
            \"ChargerSafetyRelayFault\": true, \
            \"InternalMemoryFault\": false, \
            \"InternalThermistorFault\": true, \
            \"InternalLogicFault\": false \
        }, \
        \"LimitFlags\": { \
            \"DclReducedDueToLowSoc\": true, \
            \"DclReducedDueToHighCellResistance\": false, \
            \"DclReducedDueToTemperature\": true, \
            \"DclReducedDueToLowCellVoltage\": false, \
            \"DclReducedDueToLowPackVoltage\": true, \
            \"DclandCclReducedDueToVoltageFailsafe\": false, \
            \"DclandCclReducedDueToCommunicationFailsafe\": true, \
            \"CclReducedDueToHighSoc\": false, \
            \"CclReducedDueToHighCellResistance\": true, \
            \"CclReducedDueToTemperature\": false, \
            \"CclReducedDueToHighCellVoltage\": true, \
            \"CclReducedDueToHighPackVoltage\": false, \
            \"CclReducedDueToChargerLatch\": true, \
            \"CclReducedDueToAlternateCurrentLimit\": false \
        } \
    }";
    // *INDENT-ON*

    QJsonDocument EXPECTED_JSON_DOC = QJsonDocument::fromJson(EXPECTED_JSON_MSG.toLatin1());
    QJsonObject EXPECTED_JSON = EXPECTED_JSON_DOC.object();

    NiceMock<MockBatteryFaultsData> mockBatteryFaultsData;
    const bool INTERNAL_COMMUNICATION_FAULT = false;
    const bool INTERNAL_CONVERSION_FAULT = true;
    const bool WEAK_CELL_FAULT = false;
    const bool LOW_CELL_VOLTAGE_FAULT = true;
    const bool OPEN_WIRING_FAULT = false;
    const bool CURRENT_SENSOR_FAULT = true;
    const bool PACK_VOLTAGE_SENSOR_FAULT = false;
    const bool WEAK_PACK_FAULT = true;
    const bool VOLTAGE_REDUNDANCY_FAULT = false;
    const bool FAN_MONITOR_FAULT = true;
    const bool THERMISTOR_FAULT_ = false;
    const bool CANBUS_COMMUNICATIONS_FAULT = true;
    const bool ALWAYS_ON_SUPPLY_FAULT = false;
    const bool HIGH_VOLTAGE_ISOLATION_FAULT = true;
    const bool POWER_SUPPLY12V_FAULT = false;
    const bool CHARGE_LIMIT_ENFORCEMENT_FAULT = true;
    const bool DISCHARGE_LIMIT_ENFORCEMENT_FAULT = false;
    const bool CHARGER_SAFETY_RELAY_FAULT = true;
    const bool INTERNAL_MEMORY_FAULT = false;
    const bool INTERNAL_THERMISTOR_FAULT = true;
    const bool INTERNAL_LOGIC_FAULT = false;
    const bool DCL_REDUCED_DUE_TO_LOW_SOC = true;
    const bool DCL_REDUCED_DUE_TO_HIGH_CELL_RESISTENCE = false;
    const bool DCL_REDUCED_DUE_TO_TEMPERATURE = true;
    const bool DCL_REDUCED_DUE_TO_LOW_CELL_VOLTAGE = false;
    const bool DCL_REDUCED_DUE_TO_LOW_PACK_VOLTAGE = true;
    const bool DCL_AND_CCL_REDUCED_DUE_TO_VOLTAGE_FAILSAFE = false;
    const bool DCL_AND_CCL_REDUCED_DUE_TO_COMMUNICATION_FAILSAFE = true;
    const bool CCL_REDUCED_DUE_TO_HIGH_SOC = false;
    const bool CCL_REDUCED_DUE_TO_HIGH_CELL_RESISTENCE = true;
    const bool CCL_REDUCED_DUE_TO_TEMPERATURE = false;
    const bool CCL_REDUCED_DUE_TO_HIGH_CELL_VOLTAGE = true;
    const bool CCL_REDUCED_DUE_TO_HIGH_PACK_VOLTAGE = false;
    const bool CCL_REDUCED_DUE_TO_CHARGER_LATCH = true;
    const bool CCL_REDUCED_DUE_TO_ALTERNATE_CURRENT_LIMIT = false;

    ON_CALL(mockBatteryFaultsData, internalCommunicationFault())
    .WillByDefault(Return(INTERNAL_COMMUNICATION_FAULT));
    ON_CALL(mockBatteryFaultsData, internalConversionFault())
    .WillByDefault(Return(INTERNAL_CONVERSION_FAULT));
    ON_CALL(mockBatteryFaultsData, weakCellFault())
    .WillByDefault(Return(WEAK_CELL_FAULT));
    ON_CALL(mockBatteryFaultsData, lowCellVoltageFault())
    .WillByDefault(Return(LOW_CELL_VOLTAGE_FAULT));
    ON_CALL(mockBatteryFaultsData, openWiringFault())
    .WillByDefault(Return(OPEN_WIRING_FAULT));
    ON_CALL(mockBatteryFaultsData, currentSensorFault())
    .WillByDefault(Return(CURRENT_SENSOR_FAULT));
    ON_CALL(mockBatteryFaultsData, packVoltageSensorFault())
    .WillByDefault(Return(PACK_VOLTAGE_SENSOR_FAULT));
    ON_CALL(mockBatteryFaultsData, weakPackFault())
    .WillByDefault(Return(WEAK_PACK_FAULT));
    ON_CALL(mockBatteryFaultsData, voltageRedundancyFault())
    .WillByDefault(Return(VOLTAGE_REDUNDANCY_FAULT));
    ON_CALL(mockBatteryFaultsData, fanMonitorFault())
    .WillByDefault(Return(FAN_MONITOR_FAULT));
    ON_CALL(mockBatteryFaultsData, thermistorFault())
    .WillByDefault(Return(THERMISTOR_FAULT_));
    ON_CALL(mockBatteryFaultsData, canbusCommunicationsFault())
    .WillByDefault(Return(CANBUS_COMMUNICATIONS_FAULT));
    ON_CALL(mockBatteryFaultsData, alwaysOnSupplyFault())
    .WillByDefault(Return(ALWAYS_ON_SUPPLY_FAULT));
    ON_CALL(mockBatteryFaultsData, highVoltageIsolationFault())
    .WillByDefault(Return(HIGH_VOLTAGE_ISOLATION_FAULT));
    ON_CALL(mockBatteryFaultsData, powerSupply12VFault())
    .WillByDefault(Return(POWER_SUPPLY12V_FAULT));
    ON_CALL(mockBatteryFaultsData, chargeLimitEnforcementFault())
    .WillByDefault(Return(CHARGE_LIMIT_ENFORCEMENT_FAULT));
    ON_CALL(mockBatteryFaultsData, dischargeLimitEnforcementFault())
    .WillByDefault(Return(DISCHARGE_LIMIT_ENFORCEMENT_FAULT));
    ON_CALL(mockBatteryFaultsData, chargerSafetyRelayFault())
    .WillByDefault(Return(CHARGER_SAFETY_RELAY_FAULT));
    ON_CALL(mockBatteryFaultsData, internalMemoryFault())
    .WillByDefault(Return(INTERNAL_MEMORY_FAULT));
    ON_CALL(mockBatteryFaultsData, internalThermistorFault())
    .WillByDefault(Return(INTERNAL_THERMISTOR_FAULT));
    ON_CALL(mockBatteryFaultsData, internalLogicFault())
    .WillByDefault(Return(INTERNAL_LOGIC_FAULT));
    ON_CALL(mockBatteryFaultsData, dclReducedDueToLowSoc())
    .WillByDefault(Return(DCL_REDUCED_DUE_TO_LOW_SOC));
    ON_CALL(mockBatteryFaultsData, dclReducedDueToHighCellResistence())
    .WillByDefault(Return(DCL_REDUCED_DUE_TO_HIGH_CELL_RESISTENCE));
    ON_CALL(mockBatteryFaultsData, dclReducedDueToTemperature())
    .WillByDefault(Return(DCL_REDUCED_DUE_TO_TEMPERATURE));
    ON_CALL(mockBatteryFaultsData, dclReducedDueToLowCellVoltage())
    .WillByDefault(Return(DCL_REDUCED_DUE_TO_LOW_CELL_VOLTAGE));
    ON_CALL(mockBatteryFaultsData, dclReducedDueToLowPackVoltage())
    .WillByDefault(Return(DCL_REDUCED_DUE_TO_LOW_PACK_VOLTAGE));
    ON_CALL(mockBatteryFaultsData, dclAndCclReducedDueToVoltageFailsafe())
    .WillByDefault(Return(DCL_AND_CCL_REDUCED_DUE_TO_VOLTAGE_FAILSAFE));
    ON_CALL(mockBatteryFaultsData, dclAndCclReducedDueToCommunicationFailsafe())
    .WillByDefault(Return(DCL_AND_CCL_REDUCED_DUE_TO_COMMUNICATION_FAILSAFE));
    ON_CALL(mockBatteryFaultsData, cclReducedDueToHighSoc())
    .WillByDefault(Return(CCL_REDUCED_DUE_TO_HIGH_SOC));
    ON_CALL(mockBatteryFaultsData, cclReducedDueToHighCellResistence())
    .WillByDefault(Return(CCL_REDUCED_DUE_TO_HIGH_CELL_RESISTENCE));
    ON_CALL(mockBatteryFaultsData, cclReducedDueToTemperature())
    .WillByDefault(Return(CCL_REDUCED_DUE_TO_TEMPERATURE ));
    ON_CALL(mockBatteryFaultsData, cclReducedDueToHighCellVoltage())
    .WillByDefault(Return(CCL_REDUCED_DUE_TO_HIGH_CELL_VOLTAGE));
    ON_CALL(mockBatteryFaultsData, cclReducedDueToHighPackVoltage())
    .WillByDefault(Return(CCL_REDUCED_DUE_TO_HIGH_PACK_VOLTAGE));
    ON_CALL(mockBatteryFaultsData, cclReducedDueToChargerLatch())
    .WillByDefault(Return(CCL_REDUCED_DUE_TO_CHARGER_LATCH));
    ON_CALL(mockBatteryFaultsData, cclReducedDueToAlternateCurrentLimit())
    .WillByDefault(Return(CCL_REDUCED_DUE_TO_ALTERNATE_CURRENT_LIMIT));

    QJsonObject ACTUAL_JSON =
        jsonMessageBuilder.buildBatteryFaultsMessage(mockBatteryFaultsData);

    EXPECT_EQ(EXPECTED_JSON, ACTUAL_JSON);

    if (HasFailure())
    {
        qDebug() << "Actual is " << ACTUAL_JSON;
        qDebug() << "Expected is " << EXPECTED_JSON;
    }
}

TEST(JsonMessageBuilderTest, battery)
{
    JsonMessageBuilder jsonMessageBuilder;

    // *INDENT-OFF*
    QString EXPECTED_JSON_MSG = "\
    { \
        \"Alive\": true, \
        \"BMSRelayStatusFlags\": { \
            \"DischargeRelayEnabled\": false, \
            \"ChargeRelayEnabled\": true, \
            \"ChargerSafetyEnabled\": false, \
            \"MalfunctionIndicatorActive\": true, \
            \"MultiPurposeInputSignalStatus\": false, \
            \"AlwaysOnSignalStatus\": true, \
            \"IsReadySignalStatus\": false, \
            \"IsChargingSignalStatus\": true \
        },\
        \"PopulatedCells\": 1, \
        \"12vInputVoltage\": 2, \
        \"FanVoltage\": 3, \
        \"PackCurrent\": 4, \
        \"PackVoltage\": 5, \
        \"PackStateOfCharge\": 6, \
        \"PackAmphours\": 7, \
        \"PackDepthOfDischarge\": 8, \
        \"HighTemperature\": 9, \
        \"HighThermistorId\": 10, \
        \"LowTemperature\": 11, \
        \"LowThermistorId\": 12, \
        \"AverageTemperature\": 13, \
        \"InternalTemperature\": 14, \
        \"FanSpeed\": 15, \
        \"RequestedFanSpeed\": 16, \
        \"LowCellVoltage\": 17, \
        \"LowCellVoltageId\": 18, \
        \"HighCellVoltage\": 19, \
        \"HighCellVoltageId\": 20, \
        \"AverageCellVoltage\": 21 \
    }";
    // *INDENT-ON*

    QJsonDocument EXPECTED_JSON_DOC = QJsonDocument::fromJson(EXPECTED_JSON_MSG.toLatin1());
    QJsonObject EXPECTED_JSON = EXPECTED_JSON_DOC.object();

    NiceMock<MockBatteryData> mockBatteryData;
    const bool ALIVE_VAL = true;
    const bool BMS_DISCHARGE_RELAY_ENABLED_VAL = false;
    const bool BMS_CHARGE_RELAY_ENABLED_VAL = true;
    const bool BMS_CHARGER_SAFETY_ENABLED_VAL = false;
    const bool BMS_MALFUNCTION_INDICATOR_ACTIVE_VAL = true;
    const bool BMS_GET_MULTI_PURPOSE_INPUT_SIGNAL_STATUS_VAL = false;
    const bool BMS_GET_ALWAYS_ON_SIGNAL_STATUS_VAL = true;
    const bool BMS_GET_IS_READY_SIGNAL_STATUS_VAL = false;
    const bool BMS_GET_IS_CHARGING_SIGNAL_STATUS_VAL = true;
    const unsigned char POPULATED_CELLS_VAL = 1;
    const float INPUT_VOLTAGE_12V_VAL = 2;
    const float FAN_VOLTAGE_VAL = 3;
    const float PACK_CURRENT_VAL = 4;
    const float PACK_VOLTAGE_VAL = 5;
    const float PACK_STATE_OF_CHARGE_VAL = 6;
    const float PACK_AMPHOURS_VAL = 7;
    const float PACK_DEPTH_OF_DISCHARGE_VAL = 8;
    const unsigned char HIGH_TEMPERATURE_VAL = 9;
    const unsigned char HIGH_THERMISTOR_ID_VAL = 10;
    const unsigned char LOW_TEMPERATURE_VAL = 11;
    const unsigned char LOW_THERMISTOR_ID_VAL = 12;
    const unsigned char AVERAGE_TEMPERATURE_VAL = 13;
    const unsigned char INTERNAL_TEMPERATURE_VAL = 14;
    const unsigned char FAN_SPEED_VAL = 15;
    const unsigned char REQUESTED_FAN_SPEED_VAL = 16;
    const unsigned short LOW_CELL_VOLTAGE_VAL = 17;
    const unsigned char LOW_CELL_VOLTAGE_ID_VAL = 18;
    const unsigned short HIGH_CELL_VOLTAGE_VAL = 19;
    const unsigned char HIGH_CELL_VOLTAGE_ID_VAL = 20;
    const unsigned short AVERAGE_CELL_VOLTAGE_VAL = 21;

    ON_CALL(mockBatteryData, getAlive())
    .WillByDefault(Return(ALIVE_VAL));
    ON_CALL(mockBatteryData, bmsDischargeRelayEnabled())
    .WillByDefault(Return(BMS_DISCHARGE_RELAY_ENABLED_VAL));
    ON_CALL(mockBatteryData, bmsChargeRelayEnabled())
    .WillByDefault(Return(BMS_CHARGE_RELAY_ENABLED_VAL));
    ON_CALL(mockBatteryData, bmsChargerSafetyEnabled())
    .WillByDefault(Return(BMS_CHARGER_SAFETY_ENABLED_VAL));
    ON_CALL(mockBatteryData, bmsMalfunctionIndicatorActive())
    .WillByDefault(Return(BMS_MALFUNCTION_INDICATOR_ACTIVE_VAL));
    ON_CALL(mockBatteryData, bmsGetMultiPurposeInputSignalStatus())
    .WillByDefault(Return(BMS_GET_MULTI_PURPOSE_INPUT_SIGNAL_STATUS_VAL));
    ON_CALL(mockBatteryData, bmsGetAlwaysOnSignalStatus())
    .WillByDefault(Return(BMS_GET_ALWAYS_ON_SIGNAL_STATUS_VAL));
    ON_CALL(mockBatteryData, bmsGetIsReadySignalStatus())
    .WillByDefault(Return(BMS_GET_IS_READY_SIGNAL_STATUS_VAL));
    ON_CALL(mockBatteryData, bmsGetIsChargingSignalStatus())
    .WillByDefault(Return(BMS_GET_IS_CHARGING_SIGNAL_STATUS_VAL));
    ON_CALL(mockBatteryData, getPopulatedCells())
    .WillByDefault(Return(POPULATED_CELLS_VAL));
    ON_CALL(mockBatteryData, get12VInputVoltage())
    .WillByDefault(Return(INPUT_VOLTAGE_12V_VAL));
    ON_CALL(mockBatteryData, getFanVoltage())
    .WillByDefault(Return(FAN_VOLTAGE_VAL));
    ON_CALL(mockBatteryData, getPackCurrent())
    .WillByDefault(Return(PACK_CURRENT_VAL));
    ON_CALL(mockBatteryData, getPackVoltage())
    .WillByDefault(Return(PACK_VOLTAGE_VAL));
    ON_CALL(mockBatteryData, getPackStateOfCharge())
    .WillByDefault(Return(PACK_STATE_OF_CHARGE_VAL));
    ON_CALL(mockBatteryData, getPackAmphours())
    .WillByDefault(Return(PACK_AMPHOURS_VAL));
    ON_CALL(mockBatteryData, getPackDepthOfDischarge())
    .WillByDefault(Return(PACK_DEPTH_OF_DISCHARGE_VAL));
    ON_CALL(mockBatteryData, getHighTemperature())
    .WillByDefault(Return(HIGH_TEMPERATURE_VAL));
    ON_CALL(mockBatteryData, getHighThermistorId())
    .WillByDefault(Return(HIGH_THERMISTOR_ID_VAL));
    ON_CALL(mockBatteryData, getLowTemperature())
    .WillByDefault(Return(LOW_TEMPERATURE_VAL));
    ON_CALL(mockBatteryData, getLowThermistorId())
    .WillByDefault(Return(LOW_THERMISTOR_ID_VAL));
    ON_CALL(mockBatteryData, getAverageTemperature())
    .WillByDefault(Return(AVERAGE_TEMPERATURE_VAL));
    ON_CALL(mockBatteryData, getInternalTemperature())
    .WillByDefault(Return(INTERNAL_TEMPERATURE_VAL));
    ON_CALL(mockBatteryData, getFanSpeed())
    .WillByDefault(Return(FAN_SPEED_VAL));
    ON_CALL(mockBatteryData, getRequestedFanSpeed())
    .WillByDefault(Return(REQUESTED_FAN_SPEED_VAL));
    ON_CALL(mockBatteryData, getLowCellVoltage())
    .WillByDefault(Return(LOW_CELL_VOLTAGE_VAL));
    ON_CALL(mockBatteryData, getLowCellVoltageId())
    .WillByDefault(Return(LOW_CELL_VOLTAGE_ID_VAL));
    ON_CALL(mockBatteryData, getHighCellVoltage())
    .WillByDefault(Return(HIGH_CELL_VOLTAGE_VAL));
    ON_CALL(mockBatteryData, getHighCellVoltageId())
    .WillByDefault(Return(HIGH_CELL_VOLTAGE_ID_VAL));
    ON_CALL(mockBatteryData, getAverageCellVoltage())
    .WillByDefault(Return(AVERAGE_CELL_VOLTAGE_VAL));

    QJsonObject ACTUAL_JSON =
        jsonMessageBuilder.buildBatteryMessage(mockBatteryData);

    EXPECT_EQ(EXPECTED_JSON, ACTUAL_JSON);

    if (HasFailure())
    {
        qDebug() << "Actual is " << ACTUAL_JSON;
        qDebug() << "Expected is " << EXPECTED_JSON;
    }
}

TEST(JsonMessageBuilderTest, mppt)
{
    JsonMessageBuilder jsonMessageBuilder;

    // *INDENT-OFF*
    QString EXPECTED_JSON_MSG = "\
    [ \
        { \
            \"Alive\":true, \
            \"ArrayVoltage\": 1, \
            \"ArrayCurrent\": 2, \
            \"BatteryVoltage\": 3, \
            \"Temperature\": 4 \
        }, \
        { \
            \"Alive\":true, \
            \"ArrayVoltage\": 5, \
            \"ArrayCurrent\": 6, \
            \"BatteryVoltage\": 7, \
            \"Temperature\": 8 \
        }, \
        { \
            \"Alive\":true, \
            \"ArrayVoltage\": 9, \
            \"ArrayCurrent\": 10, \
            \"BatteryVoltage\": 11, \
            \"Temperature\": 12 \
        } \
    ]";
    // *INDENT-ON*

    QJsonDocument EXPECTED_JSON_DOC = QJsonDocument::fromJson(EXPECTED_JSON_MSG.toLatin1());
    QJsonArray EXPECTED_JSON_ARRAY = EXPECTED_JSON_DOC.array();

    NiceMock<MockMpptData> mockMpptData;
    NiceMock<MockMpptUnit> mockMpptUnit_0;
    NiceMock<MockMpptUnit> mockMpptUnit_1;
    NiceMock<MockMpptUnit> mockMpptUnit_2;

    ON_CALL(mockMpptData, getNumberOfUnits())
    .WillByDefault(Return(3));
    ON_CALL(mockMpptData, getMpptUnit(0))
    .WillByDefault(ReturnRef(mockMpptUnit_0));
    ON_CALL(mockMpptData, getMpptUnit(1))
    .WillByDefault(ReturnRef(mockMpptUnit_1));
    ON_CALL(mockMpptData, getMpptUnit(2))
    .WillByDefault(ReturnRef(mockMpptUnit_2));

    const unsigned short MPPT0_ALIVE_VAL = true;
    const unsigned short MPPT0_ARRAY_VOLTAGE_VAL = 1;
    const unsigned short MPPT0_ARRAY_CURRENT_VAL = 2;
    const unsigned short MPPT0_BATTERY_VOLTAGE_VAL = 3;
    const unsigned short MPPT0_TEMPERATURE_VAL = 4;

    const unsigned short MPPT1_ALIVE_VAL = true;
    const unsigned short MPPT1_ARRAY_VOLTAGE_VAL = 5;
    const unsigned short MPPT1_ARRAY_CURRENT_VAL = 6;
    const unsigned short MPPT1_BATTERY_VOLTAGE_VAL = 7;
    const unsigned short MPPT1_TEMPERATURE_VAL = 8;

    const unsigned short MPPT2_ALIVE_VAL = true;
    const unsigned short MPPT2_ARRAY_VOLTAGE_VAL = 9;
    const unsigned short MPPT2_ARRAY_CURRENT_VAL = 10;
    const unsigned short MPPT2_BATTERY_VOLTAGE_VAL = 11;
    const unsigned short MPPT2_TEMPERATURE_VAL = 12;

    ON_CALL(mockMpptUnit_0, getMpptStatus())
    .WillByDefault(Return(MPPT0_ALIVE_VAL));
    ON_CALL(mockMpptUnit_0, getArrayVoltage())
    .WillByDefault(Return(MPPT0_ARRAY_VOLTAGE_VAL));
    ON_CALL(mockMpptUnit_0, getArrayCurrent())
    .WillByDefault(Return(MPPT0_ARRAY_CURRENT_VAL));
    ON_CALL(mockMpptUnit_0, getBatteryVoltage())
    .WillByDefault(Return(MPPT0_BATTERY_VOLTAGE_VAL));
    ON_CALL(mockMpptUnit_0, getTemperature())
    .WillByDefault(Return(MPPT0_TEMPERATURE_VAL));

    ON_CALL(mockMpptUnit_1, getMpptStatus())
    .WillByDefault(Return(MPPT1_ALIVE_VAL));
    ON_CALL(mockMpptUnit_1, getArrayVoltage())
    .WillByDefault(Return(MPPT1_ARRAY_VOLTAGE_VAL));
    ON_CALL(mockMpptUnit_1, getArrayCurrent())
    .WillByDefault(Return(MPPT1_ARRAY_CURRENT_VAL));
    ON_CALL(mockMpptUnit_1, getBatteryVoltage())
    .WillByDefault(Return(MPPT1_BATTERY_VOLTAGE_VAL));
    ON_CALL(mockMpptUnit_1, getTemperature())
    .WillByDefault(Return(MPPT1_TEMPERATURE_VAL));

    ON_CALL(mockMpptUnit_2, getMpptStatus())
    .WillByDefault(Return(MPPT2_ALIVE_VAL));
    ON_CALL(mockMpptUnit_2, getArrayVoltage())
    .WillByDefault(Return(MPPT2_ARRAY_VOLTAGE_VAL));
    ON_CALL(mockMpptUnit_2, getArrayCurrent())
    .WillByDefault(Return(MPPT2_ARRAY_CURRENT_VAL));
    ON_CALL(mockMpptUnit_2, getBatteryVoltage())
    .WillByDefault(Return(MPPT2_BATTERY_VOLTAGE_VAL));
    ON_CALL(mockMpptUnit_2, getTemperature())
    .WillByDefault(Return(MPPT2_TEMPERATURE_VAL));


    QJsonArray ACTUAL_JSON_ARRAY =
        jsonMessageBuilder.buildMpptMessage(mockMpptData);

    EXPECT_EQ(EXPECTED_JSON_ARRAY, ACTUAL_JSON_ARRAY);

    if (HasFailure())
    {
        qDebug() << "Actual is " << ACTUAL_JSON_ARRAY;
        qDebug() << "Expected is " << EXPECTED_JSON_ARRAY;
    }
}

TEST(JsonMessageBuilderTest, lights)
{
    JsonMessageBuilder jsonMessageBuilder;

    // *INDENT-OFF*
    QString EXPECTED_JSON_MSG = "\
    { \
        \"LowBeams\":true, \
        \"HighBeams\":false, \
        \"Brakes\":true, \
        \"LeftSignal\":false, \
        \"RightSignal\":true, \
        \"BmsStrobeLight\":false, \
        \"Alive\":false \
    }";
    // *INDENT-ON*

    QJsonDocument EXPECTED_JSON_DOC = QJsonDocument::fromJson(EXPECTED_JSON_MSG.toLatin1());
    QJsonObject EXPECTED_JSON = EXPECTED_JSON_DOC.object();

    NiceMock<MockLightsData> mockLightsData;
    const bool LOW_BEAMS_VAL = true;
    const bool HIGH_BEAMS_VAL = false;
    const bool BRAKES_VAL = true;
    const bool LEFT_SIGNAL_VAL = false;
    const bool RIGHT_SIGNAL_VAL = true;
    const bool BMS_STROBE_LIGHT_VAL = false;
    const bool ALIVE_VAL = false;

    ON_CALL(mockLightsData, getAlive())
    .WillByDefault(Return(ALIVE_VAL));
    ON_CALL(mockLightsData, getLowBeams())
    .WillByDefault(Return(LOW_BEAMS_VAL));
    ON_CALL(mockLightsData, getHighBeams())
    .WillByDefault(Return(HIGH_BEAMS_VAL));
    ON_CALL(mockLightsData, getBrakes())
    .WillByDefault(Return(BRAKES_VAL));
    ON_CALL(mockLightsData, getLeftSignal())
    .WillByDefault(Return(LEFT_SIGNAL_VAL));
    ON_CALL(mockLightsData, getRightSignal())
    .WillByDefault(Return(RIGHT_SIGNAL_VAL));
    ON_CALL(mockLightsData, getBmsStrobeLight())
    .WillByDefault(Return(BMS_STROBE_LIGHT_VAL));

    QJsonObject ACTUAL_JSON =
        jsonMessageBuilder.buildLightsMessage(mockLightsData);

    EXPECT_EQ(EXPECTED_JSON, ACTUAL_JSON);

    if (HasFailure())
    {
        qDebug() << "Actual is " << ACTUAL_JSON;
        qDebug() << "Expected is " << EXPECTED_JSON;
    }
}

TEST(JsonMessageBuilderTest, auxBms)
{
    JsonMessageBuilder jsonMessageBuilder;

    // *INDENT-OFF*
    QString EXPECTED_JSON_MSG = "\
        { \
            \"PrechargeState\": \"OFF\", \
            \"AuxVoltage\": 22, \
            \"AuxBmsAlive\": true, \
            \"StrobeBmsLight\": true, \
            \"AllowCharge\": true, \
            \"ContactorError\": true, \
            \"HighVoltageEnable\": true \
        }";

       //*INDENT-ON*

    QJsonDocument EXPECTED_JSON_DOC = QJsonDocument::fromJson(EXPECTED_JSON_MSG.toLatin1());
    QJsonObject EXPECTED_JSON = EXPECTED_JSON_DOC.object();

    NiceMock<MockAuxBmsData> mockAuxBmsData;
    const I_AuxBmsData::PrechargeState PRECHARGE_STATE_VAL = I_AuxBmsData::PrechargeState::OFF;
    const unsigned char AUX_VOLTAGE_VAL = 22;
    const bool AUX_BMS_ALIVE_VAL = true;
    const bool STROBE_BMS_LIGHT_VAL = true;
    const bool ALLOW_CHARGE_VAL = true;
    const bool CONTACTOR_ERROR_VAL = true;
    const bool HIGH_VOLTAGE_ENABLE_VAL = true;

    ON_CALL(mockAuxBmsData, getPrechargeState())
    .WillByDefault(Return(PRECHARGE_STATE_VAL));
    ON_CALL(mockAuxBmsData, getAuxVoltage())
    .WillByDefault(Return(AUX_VOLTAGE_VAL));
    ON_CALL(mockAuxBmsData, getAuxBmsAlive())
    .WillByDefault(Return(AUX_BMS_ALIVE_VAL));
    ON_CALL(mockAuxBmsData, getStrobeBmsLight())
    .WillByDefault(Return(STROBE_BMS_LIGHT_VAL));
    ON_CALL(mockAuxBmsData, getAllowCharge())
    .WillByDefault(Return(ALLOW_CHARGE_VAL));
    ON_CALL(mockAuxBmsData, getContactorError())
    .WillByDefault(Return(CONTACTOR_ERROR_VAL));
    ON_CALL(mockAuxBmsData, getHighVoltageEnable())
    .WillByDefault(Return(HIGH_VOLTAGE_ENABLE_VAL));

    QJsonObject ACTUAL_JSON =
        jsonMessageBuilder.buildAuxBmsMessage(mockAuxBmsData);

    EXPECT_EQ(EXPECTED_JSON, ACTUAL_JSON);

    if (HasFailure())
    {
        qDebug() << "Actual is " << ACTUAL_JSON;
        qDebug() << "Expected is " << EXPECTED_JSON;
    }
}
