#include "JsonMessageBuilder.h"
#include "JsonForwarder/JsonDefines.h"
#include "CommunicationLayer/PacketDecoder/PacketDecoder.h"
#include "CommunicationLayer/PacketChecksumChecker/I_PacketChecksumChecker.h"
#include "DataLayer/KeyMotorData/I_KeyMotorData.h"
#include "DataLayer/MotorDetailsData/I_MotorDetailsData.h"
#include "DataLayer/MotorDetailsData/I_MotorDetailsUnit.h"
#include "DataLayer/DriverControlsData/I_DriverControlsData.h"
#include "DataLayer/MotorFaultsData/I_MotorFaultsData.h"
#include "DataLayer/BatteryFaultsData/I_BatteryFaultsData.h"
#include "DataLayer/BatteryData/I_BatteryData.h"
#include "DataLayer/MpptData/I_MpptData.h"
#include "DataLayer/LightsData/I_LightsData.h"
#include "DataLayer/AuxBmsData/I_AuxBmsData.h"
#include "DataLayer/CcsData/I_CcsData.h"
#include "DataLayer/CcsData/CcsData.h"

JsonMessageBuilder::JsonMessageBuilder()
{

}

QJsonObject JsonMessageBuilder::buildAuxBmsMessage(const I_AuxBmsData& data)
{
    QJsonObject auxBmsJson = QJsonObject();

    switch (data.getPrechargeState())
    {
        case I_AuxBmsData::PrechargeState::OFF:
            auxBmsJson[JsonFormat::PRECHARGE_STATE] = "OFF";
            break;

        case I_AuxBmsData::PrechargeState::COMMON_ENGAGED:
            auxBmsJson[JsonFormat::PRECHARGE_STATE] = "COMMON_ENGAGED";
            break;

        case I_AuxBmsData::PrechargeState::CHARGE_ENGAGED:
            auxBmsJson[JsonFormat::PRECHARGE_STATE] = "CHARGE_ENGAGED";
            break;

        case I_AuxBmsData::PrechargeState::DISCHARGE_ENGAGED:
            auxBmsJson[JsonFormat::PRECHARGE_STATE] = "DISCHARGE_ENGAGED";
            break;

        case I_AuxBmsData::PrechargeState::ALL_ENGAGED:
            auxBmsJson[JsonFormat::PRECHARGE_STATE] = "ALL_ENGAGED";
            break;

        default:
            auxBmsJson[JsonFormat::PRECHARGE_STATE] = "INVALID_STATE";
            break;
    }

    auxBmsJson[JsonFormat::AUX_VOLTAGE] = data.getAuxVoltage();
    auxBmsJson[JsonFormat::AUX_BMS_ALIVE] = data.getAuxBmsAlive();
    auxBmsJson[JsonFormat::STROBE_BMS_LIGHT] = data.getStrobeBmsLight();
    auxBmsJson[JsonFormat::ALLOW_CHARGE] = data.getAllowCharge();
    auxBmsJson[JsonFormat::HIGH_VOLTAGE_ENABLE_STATE] = data.getHighVoltageEnableState();
    auxBmsJson[JsonFormat::ALLOW_DISCHARGE] = data.getAllowDischarge();
    auxBmsJson[JsonFormat::CHARGE_TRIP_DUE_TO_HIGH_CELL_VOLTAGE] = data.getChargeTripDueToHighCellVoltage();
    auxBmsJson[JsonFormat::CHARGE_TRIP_DUE_TO_HIGH_TEMPERATURE_AND_CURRENT] = data.getChargeTripDueToHighTemperatureAndCurrent();
    auxBmsJson[JsonFormat::CHARGE_TRIP_DUE_TO_PACK_CURRENT] = data.getChargeTripDueToPackCurrent();
    auxBmsJson[JsonFormat::DISCHARGE_TRIP_DUE_TO_LOW_CELL_VOLTAGE] = data.getDischargeTripDueToLowCellVoltage();
    auxBmsJson[JsonFormat::DISCHARGE_TRIP_DUE_TO_HIGH_TEMERATURE_AND_CURRENT] = data.getDischargeTripDueToHighTemeratureAndCurrent();
    auxBmsJson[JsonFormat::DISCHARGE_TRIP_DUE_TO_PACK_CURRENT] = data.getDischargeTripDueToPackCurrent();
    auxBmsJson[JsonFormat::PROTECTION_TRIP] = data.getProtectionTrip();
    return auxBmsJson;
}

QJsonObject JsonMessageBuilder::buildCcsMessage(const I_CcsData& data)
{
    QJsonObject ccsJson = QJsonObject();

    ccsJson[JsonFormat::CCS_ALIVE] = data.getCcsAlive();
    return ccsJson;
}

QJsonObject JsonMessageBuilder::buildBatteryMessage(const I_BatteryData& data)
{
    QJsonObject batteryJson = QJsonObject();

    QJsonObject bmsRelayStatusFlagsJson = QJsonObject();
    bmsRelayStatusFlagsJson[JsonFormat::BMS_DISCHARGE_RELAY_ENABLED] = data.bmsDischargeRelayEnabled();
    bmsRelayStatusFlagsJson[JsonFormat::BMS_CHARGE_RELAY_ENABLED] = data.bmsChargeRelayEnabled();
    bmsRelayStatusFlagsJson[JsonFormat::BMS_CHARGER_SAFETY_ENABLED] = data.bmsChargerSafetyEnabled();
    bmsRelayStatusFlagsJson[JsonFormat::BMS_MALFUNCTION_INDICATOR_ACTIVE] = data.bmsMalfunctionIndicatorActive();
    bmsRelayStatusFlagsJson[JsonFormat::BMS_GET_MULTI_PURPOSE_INPUT_SIGNAL_STATUS] = data.bmsGetMultiPurposeInputSignalStatus();
    bmsRelayStatusFlagsJson[JsonFormat::BMS_GET_ALWAYS_ON_SIGNAL_STATUS] = data.bmsGetAlwaysOnSignalStatus();
    bmsRelayStatusFlagsJson[JsonFormat::BMS_GET_IS_READY_SIGNAL_STATUS] = data.bmsGetIsReadySignalStatus();
    bmsRelayStatusFlagsJson[JsonFormat::BMS_GET_IS_CHARGING_SIGNAL_STATUS] = data.bmsGetIsChargingSignalStatus();

    batteryJson[JsonFormat::ALIVE] = data.getAlive();
    batteryJson[JsonFormat::POPULATED_CELLS] = data.getPopulatedCells();
    batteryJson[JsonFormat::INPUT_VOLTAGE_12V] = data.get12VInputVoltage();
    batteryJson[JsonFormat::FAN_VOLTAGE] = data.getFanVoltage();
    batteryJson[JsonFormat::PACK_CURRENT] = data.getPackCurrent();
    batteryJson[JsonFormat::PACK_VOLTAGE] = data.getPackVoltage();
    batteryJson[JsonFormat::PACK_STATE_OF_CHARGE] = data.getPackStateOfCharge();
    batteryJson[JsonFormat::PACK_AMPHOURS] = data.getPackAmphours();
    batteryJson[JsonFormat::PACK_DEPTH_OF_DISCHARGE] = data.getPackDepthOfDischarge();
    batteryJson[JsonFormat::HIGH_TEMPERATURE] = data.getHighTemperature();
    batteryJson[JsonFormat::HIGH_THERMISTOR_ID] = data.getHighThermistorId();
    batteryJson[JsonFormat::LOW_TEMPERATURE] = data.getLowTemperature();
    batteryJson[JsonFormat::LOW_THERMISTOR_ID] = data.getLowThermistorId();
    batteryJson[JsonFormat::AVERAGE_TEMPERATURE] = data.getAverageTemperature();
    batteryJson[JsonFormat::INTERNAL_TEMPERATURE] = data.getInternalTemperature();
    batteryJson[JsonFormat::FAN_SPEED] = data.getFanSpeed();
    batteryJson[JsonFormat::REQUESTED_FAN_SPEED] = data.getRequestedFanSpeed();
    batteryJson[JsonFormat::LOW_CELL_VOLTAGE] = data.getLowCellVoltage();
    batteryJson[JsonFormat::LOW_CELL_VOLTAGE_ID] = data.getLowCellVoltageId();
    batteryJson[JsonFormat::HIGH_CELL_VOLTAGE] = data.getHighCellVoltage();
    batteryJson[JsonFormat::HIGH_CELL_VOLTAGE_ID] = data.getHighCellVoltageId();
    batteryJson[JsonFormat::AVERAGE_CELL_VOLTAGE] = data.getAverageCellVoltage();
    batteryJson[JsonFormat::BMS_RELAY_STATUS_FLAGS] = bmsRelayStatusFlagsJson;
    return batteryJson;
}

QJsonObject JsonMessageBuilder::buildBatteryFaultsMessage(const I_BatteryFaultsData& data)
{
    QJsonObject batteryFaultsJson = QJsonObject();

    QJsonObject errorFlagsJson = QJsonObject();
    errorFlagsJson[JsonFormat::INTERNAL_COMMUNICATION_FAULT] = data.internalCommunicationFault();
    errorFlagsJson[JsonFormat::INTERNAL_CONVERSION_FAULT] = data.internalConversionFault();
    errorFlagsJson[JsonFormat::WEAK_CELL_FAULT] = data.weakCellFault();
    errorFlagsJson[JsonFormat::LOW_CELL_VOLTAGE_FAULT] = data.lowCellVoltageFault();
    errorFlagsJson[JsonFormat::OPEN_WIRING_FAULT] = data.openWiringFault();
    errorFlagsJson[JsonFormat::CURRENT_SENSOR_FAULT] = data.currentSensorFault();
    errorFlagsJson[JsonFormat::PACK_VOLTAGE_SENSOR_FAULT] = data.packVoltageSensorFault();
    errorFlagsJson[JsonFormat::WEAK_PACK_FAULT] = data.weakPackFault();
    errorFlagsJson[JsonFormat::VOLTAGE_REDUNDANCY_FAULT] = data.voltageRedundancyFault();
    errorFlagsJson[JsonFormat::FAN_MONITOR_FAULT] = data.fanMonitorFault();
    errorFlagsJson[JsonFormat::THERMISTOR_FAULT_] = data.thermistorFault();
    errorFlagsJson[JsonFormat::CANBUS_COMMUNICATIONS_FAULT] = data.canbusCommunicationsFault();
    errorFlagsJson[JsonFormat::ALWAYS_ON_SUPPLYFAULT] = data.alwaysOnSupplyFault();
    errorFlagsJson[JsonFormat::HIGH_VOLTAGE_ISOLATION_FAULT] = data.highVoltageIsolationFault();
    errorFlagsJson[JsonFormat::POWER_SUPPLY_12V_FAULT] = data.powerSupply12VFault();
    errorFlagsJson[JsonFormat::CHARGE_LIMIT_ENFORCEMENT_FAULT] = data.chargeLimitEnforcementFault();
    errorFlagsJson[JsonFormat::DISCHARGE_LIMIT_ENFORCEMENT_FAULT] = data.dischargeLimitEnforcementFault();
    errorFlagsJson[JsonFormat::CHARGER_SAFETY_RELAY_FAULT] = data.chargerSafetyRelayFault();
    errorFlagsJson[JsonFormat::INTERNAL_MEMORY_FAULT] = data.internalMemoryFault();
    errorFlagsJson[JsonFormat::INTERNAL_THERMISTOR_FAULT] = data.internalThermistorFault();
    errorFlagsJson[JsonFormat::INTERNAL_LOGIC_FAULT] = data.internalLogicFault();

    QJsonObject limitFlagsJson = QJsonObject();
    limitFlagsJson[JsonFormat::DCL_REDUCED_DUE_TO_LOW_SOC] = data.dclReducedDueToLowSoc();
    limitFlagsJson[JsonFormat::DCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE] = data.dclReducedDueToHighCellResistence();
    limitFlagsJson[JsonFormat::DCL_REDUCED_DUE_TO_TEMPERATURE_] = data.dclReducedDueToTemperature();
    limitFlagsJson[JsonFormat::DCL_REDUCED_DUE_TO_LOW_CELL_VOLTAGE] = data.dclReducedDueToLowCellVoltage();
    limitFlagsJson[JsonFormat::DCL_REDUCED_DUE_TO_LOW_PACK_VOLTAGE] = data.dclReducedDueToLowPackVoltage();
    limitFlagsJson[JsonFormat::DCL_AND_CCL_REDUCED_DUE_TO_VOLTAGE_FAILSAFE] = data.dclAndCclReducedDueToVoltageFailsafe();
    limitFlagsJson[JsonFormat::DCL_AND_CCL_REDUCED_DUE_TO_COMMUNICATION_FAILSAFE] = data.dclAndCclReducedDueToCommunicationFailsafe();
    limitFlagsJson[JsonFormat::CCL_REDUCED_DUE_TO_HIGH_SOC] = data.cclReducedDueToHighSoc();
    limitFlagsJson[JsonFormat::CCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE] = data.cclReducedDueToHighCellResistence();
    limitFlagsJson[JsonFormat::CCL_REDUCED_DUE_TO_TEMPERATURE] = data.cclReducedDueToTemperature();
    limitFlagsJson[JsonFormat::CCL_REDUCED_DUE_TO_HIGH_CELL_VOLTAGE] = data.cclReducedDueToHighCellVoltage();
    limitFlagsJson[JsonFormat::CCL_REDUCED_DUE_TO_HIGH_PACK_VOLTAGE] = data.cclReducedDueToHighPackVoltage();
    limitFlagsJson[JsonFormat::CCL_REDUCED_DUE_TO_CHARGER_LATCH] = data.cclReducedDueToChargerLatch();
    limitFlagsJson[JsonFormat::CCL_REDUCED_DUE_TO_ALTERNATE_CURRENT_LIMIT] = data.cclReducedDueToAlternateCurrentLimit();

    batteryFaultsJson[JsonFormat::ERROR_FLAGS] = errorFlagsJson;
    batteryFaultsJson[JsonFormat::LIMITS_FLAGS] = limitFlagsJson;
    return batteryFaultsJson;
}

QJsonObject JsonMessageBuilder::buildDriverControlsMessage(const I_DriverControlsData& data)
{
    QJsonObject driverControlsJson = QJsonObject();
    driverControlsJson[JsonFormat::ALIVE] = data.getDriverControlsBoardAlive();
    driverControlsJson[JsonFormat::HEADLIGHTS_OFF] = data.getHeadlightsOff();
    driverControlsJson[JsonFormat::HEADLIGHTS_LOW] = data.getHeadlightsLow();
    driverControlsJson[JsonFormat::HEADLIGHTS_HIGH] = data.getHeadlightsHigh();
    driverControlsJson[JsonFormat::SIGNAL_RIGHT] = data.getSignalRight();
    driverControlsJson[JsonFormat::SIGNAL_LEFT] = data.getSignalLeft();
    driverControlsJson[JsonFormat::HAZARD] = data.getHazard();
    driverControlsJson[JsonFormat::INTERIOR] = data.getInterior();
    driverControlsJson[JsonFormat::VOLUME_UP] = data.getVolumeUp();
    driverControlsJson[JsonFormat::VOLUME_DOWN] = data.getVolumeDown();
    driverControlsJson[JsonFormat::NEXT_SONG] = data.getNextSong();
    driverControlsJson[JsonFormat::PREV_SONG] = data.getPreviousSong();
    driverControlsJson[JsonFormat::BRAKES] = data.getBrakes();
    driverControlsJson[JsonFormat::FORWARD] = data.getForward();
    driverControlsJson[JsonFormat::REVERSE] = data.getReverse();
    driverControlsJson[JsonFormat::PUSH_TO_TALK] = data.getPushToTalk();
    driverControlsJson[JsonFormat::HORN] = data.getHorn();
    driverControlsJson[JsonFormat::RESET] = data.getReset();
    driverControlsJson[JsonFormat::AUX] = data.getAux();
    driverControlsJson[JsonFormat::LAP] = data.getLap();
    driverControlsJson[JsonFormat::ACCELERATION] = float(data.getAcceleration());
    driverControlsJson[JsonFormat::REGEN_BRAKING] = float(data.getRegenBraking());
    return driverControlsJson;
}

QJsonArray JsonMessageBuilder::buildKeyMotorMessage(const I_KeyMotorData& data)
{

    QJsonObject keyMotor0Json = QJsonObject();
    keyMotor0Json[JsonFormat::ALIVE] = false;

    if (data.getM0Alive() != 0)
    {
        keyMotor0Json[JsonFormat::ALIVE] = true;

    }

    keyMotor0Json[JsonFormat::SET_CURRENT] = data.getM0SetCurrent();
    keyMotor0Json[JsonFormat::SET_VELOCITY] = data.getM0SetVelocity();
    keyMotor0Json[JsonFormat::BUS_CURRENT] = data.getM0BusCurrent();
    keyMotor0Json[JsonFormat::BUS_VOLTAGE] = data.getM0BusVoltage();
    keyMotor0Json[JsonFormat::VEHICLE_VELOCITY] = data.getM0VehicleVelocity();

    QJsonObject keyMotor1Json = QJsonObject();
    keyMotor1Json[JsonFormat::ALIVE] = false;

    if (data.getM1Alive() != 0)
    {
        keyMotor1Json[JsonFormat::ALIVE] = true;

    }

    keyMotor1Json[JsonFormat::SET_CURRENT] = data.getM1SetCurrent();
    keyMotor1Json[JsonFormat::SET_VELOCITY] = data.getM1SetVelocity();
    keyMotor1Json[JsonFormat::BUS_CURRENT] = data.getM1BusCurrent();
    keyMotor1Json[JsonFormat::BUS_VOLTAGE] = data.getM1BusVoltage();
    keyMotor1Json[JsonFormat::VEHICLE_VELOCITY] = data.getM1VehicleVelocity();

    QJsonArray keyMotorJson =
    {
        keyMotor0Json,
        keyMotor1Json
    };
    return keyMotorJson;
}

QJsonObject JsonMessageBuilder::buildLightsMessage(const I_LightsData& data)
{
    QJsonObject lightsJson = QJsonObject();
    lightsJson[JsonFormat::LIGHTS_ALIVE] = data.getAlive();
    lightsJson[JsonFormat::LIGHTS_LOW_BEAMS] = data.getLowBeams();
    lightsJson[JsonFormat::LIGHTS_HIGH_BEAMS] = data.getHighBeams();
    lightsJson[JsonFormat::LIGHTS_BRAKES] = data.getBrakes();
    lightsJson[JsonFormat::LIGHTS_LEFT_SIGNAL] = data.getLeftSignal();
    lightsJson[JsonFormat::LIGHTS_RIGHT_SIGNAL] = data.getRightSignal();
    lightsJson[JsonFormat::LIGHTS_BMS_STROBE_LIGHT] = data.getBmsStrobeLight();

    return lightsJson;
}

QJsonArray JsonMessageBuilder::buildMotorDetailsMessage(const I_MotorDetailsData& data)
{
    QJsonArray motorDetailsJson = QJsonArray();

    for (int i = 0; i < data.getNumberOfUnits(); i++)
    {
        QJsonObject motorDetailsJsonUnit = QJsonObject();
        const I_MotorDetailsUnit& motorDetailsUnit = data.getMotorDetailsUnit(i);

        motorDetailsJsonUnit[JsonFormat::PHASE_C_CURRENT] = motorDetailsUnit.getPhaseCCurrent();
        motorDetailsJsonUnit[JsonFormat::PHASE_B_CURRENT] = motorDetailsUnit.getPhaseBCurrent();
        motorDetailsJsonUnit[JsonFormat::MOTOR_VOLTAGE_REAL] = motorDetailsUnit.getMotorVoltageReal();
        motorDetailsJsonUnit[JsonFormat::MOTOR_VOLTAGE_IMAGINARY] = motorDetailsUnit.getMotorVoltageImaginary();
        motorDetailsJsonUnit[JsonFormat::MOTOR_CURRENT_REAL] = motorDetailsUnit.getMotorCurrentReal();
        motorDetailsJsonUnit[JsonFormat::MOTOR_CURRENT_IMAGINARY] = motorDetailsUnit.getMotorCurrentImaginary();
        motorDetailsJsonUnit[JsonFormat::BACK_EMF] = motorDetailsUnit.getBackEmf();
        motorDetailsJsonUnit[JsonFormat::VOLTAGE_RAIL_15V_SUPPLY] = motorDetailsUnit.getVoltageRailSuppply15V();
        motorDetailsJsonUnit[JsonFormat::VOLTAGE_RAIL_3V_SUPPLY] = motorDetailsUnit.getVoltageRailSupply33V();
        motorDetailsJsonUnit[JsonFormat::VOLTAGE_RAIL_1V_SUPPLY] = motorDetailsUnit.getVoltageRailSupply19V();
        motorDetailsJsonUnit[JsonFormat::HEAT_SINK_TEMP] = motorDetailsUnit.getHeatSinkTemperature();
        motorDetailsJsonUnit[JsonFormat::MOTOR_TEMP] = motorDetailsUnit.getMotorTemperature();
        motorDetailsJsonUnit[JsonFormat::DSP_BOARD_TEMP] = motorDetailsUnit.getDspBoardTemperature();
        motorDetailsJsonUnit[JsonFormat::DC_BUS_AMP_HOURS] = motorDetailsUnit.getDcBusAmpHours();
        motorDetailsJsonUnit[JsonFormat::ODOMETER_] = motorDetailsUnit.getOdometer();
        motorDetailsJsonUnit[JsonFormat::SLIP_SPEED] = motorDetailsUnit.getSlipSpeed();

        motorDetailsJson.append(motorDetailsJsonUnit);
    }

    return motorDetailsJson;
}

QJsonArray JsonMessageBuilder::buildMotorFaultsMessage(const I_MotorFaultsData& data)
{
    QJsonArray motorFaultsJson = QJsonArray();
    QJsonObject motor0FaultsJson = QJsonObject();
    QJsonObject motor1FaultsJson = QJsonObject();

    QJsonObject m0ErrorFlagsJson = QJsonObject();
    m0ErrorFlagsJson[JsonFormat::MOTOR_OVER_SPEED] = data.m0MotorOverSpeed();
    m0ErrorFlagsJson[JsonFormat::SOFTWARE_OVER_CURRENT] = data.m0SoftwareOverCurrent();
    m0ErrorFlagsJson[JsonFormat::DC_BUS_OVER_VOLTAGE] = data.m0DcBusOverVoltage();
    m0ErrorFlagsJson[JsonFormat::BAD_MOTOR_POSITION_HALL_SEQUENCE] = data.m0BadMotorPositionHallSequence();
    m0ErrorFlagsJson[JsonFormat::WATCHDOG_CAUSED_LAST_RESET] = data.m0WatchdogCausedLastReset();
    m0ErrorFlagsJson[JsonFormat::CONFIG_READ_ERROR] = data.m0ConfigReadError();
    m0ErrorFlagsJson[JsonFormat::RAIL_15V_UNDER_VOLTAGE_LOCK_OUT] = data.m0RailUnderVoltageLockOut();
    m0ErrorFlagsJson[JsonFormat::DESATURATION_FAULT] = data.m0DesaturationFault();
    motor0FaultsJson[JsonFormat::ERROR_FLAGS] = m0ErrorFlagsJson;

    QJsonObject m1ErrorFlagsJson = QJsonObject();
    m1ErrorFlagsJson[JsonFormat::MOTOR_OVER_SPEED] = data.m1MotorOverSpeed();
    m1ErrorFlagsJson[JsonFormat::SOFTWARE_OVER_CURRENT] = data.m1SoftwareOverCurrent();
    m1ErrorFlagsJson[JsonFormat::DC_BUS_OVER_VOLTAGE] = data.m1DcBusOverVoltage();
    m1ErrorFlagsJson[JsonFormat::BAD_MOTOR_POSITION_HALL_SEQUENCE] = data.m1BadMotorPositionHallSequence();
    m1ErrorFlagsJson[JsonFormat::WATCHDOG_CAUSED_LAST_RESET] = data.m1WatchdogCausedLastReset();
    m1ErrorFlagsJson[JsonFormat::CONFIG_READ_ERROR] = data.m1ConfigReadError();
    m1ErrorFlagsJson[JsonFormat::RAIL_15V_UNDER_VOLTAGE_LOCK_OUT] = data.m1RailUnderVoltageLockOut();
    m1ErrorFlagsJson[JsonFormat::DESATURATION_FAULT] = data.m1DesaturationFault();
    motor1FaultsJson[JsonFormat::ERROR_FLAGS] = m1ErrorFlagsJson;

    QJsonObject m0LimitsFlagsJson = QJsonObject();
    m0LimitsFlagsJson[JsonFormat::OUTPUT_VOLTAGE_PWM] = data.m0OutputVoltagePwmLimit();
    m0LimitsFlagsJson[JsonFormat::MOTOR_CURRENT] = data.m0MotorCurrentLimit();
    m0LimitsFlagsJson[JsonFormat::VELOCITY] = data.m0VelocityLimit();
    m0LimitsFlagsJson[JsonFormat::BUS_CURRENT] = data.m0BusCurrentLimit();
    m0LimitsFlagsJson[JsonFormat::BUS_VOLTAGE_UPPER] = data.m0BusVoltageUpperLimit();
    m0LimitsFlagsJson[JsonFormat::BUS_VOLTAGE_LOWER] = data.m0BusVoltageLowerLimit();
    m0LimitsFlagsJson[JsonFormat::IPM_OR_MOTOR_TEMPERATURE] = data.m0IpmOrMotorTemperatureLimit();
    motor0FaultsJson[JsonFormat::LIMITS_FLAGS] = m0LimitsFlagsJson;

    QJsonObject m1LimitsFlagsJson = QJsonObject();
    m1LimitsFlagsJson[JsonFormat::OUTPUT_VOLTAGE_PWM] = data.m1OutputVoltagePwmLimit();
    m1LimitsFlagsJson[JsonFormat::MOTOR_CURRENT] = data.m1MotorCurrentLimit();
    m1LimitsFlagsJson[JsonFormat::VELOCITY] = data.m1VelocityLimit();
    m1LimitsFlagsJson[JsonFormat::BUS_CURRENT] = data.m1BusCurrentLimit();
    m1LimitsFlagsJson[JsonFormat::BUS_VOLTAGE_UPPER] = data.m1BusVoltageUpperLimit();
    m1LimitsFlagsJson[JsonFormat::BUS_VOLTAGE_LOWER] = data.m1BusVoltageLowerLimit();
    m1LimitsFlagsJson[JsonFormat::IPM_OR_MOTOR_TEMPERATURE] = data.m1IpmOrMotorTemperatureLimit();
    motor1FaultsJson[JsonFormat::LIMITS_FLAGS] = m1LimitsFlagsJson;

    motor0FaultsJson[JsonFormat::RX_ERROR_COUNT] = data.getM0CanRxErrorCount();
    motor0FaultsJson[JsonFormat::TX_ERROR_COUNT] = data.getM0CanTxErrorCount();
    motor1FaultsJson[JsonFormat::RX_ERROR_COUNT] = data.getM1CanRxErrorCount();
    motor1FaultsJson[JsonFormat::TX_ERROR_COUNT] = data.getM1CanTxErrorCount();
    motorFaultsJson.append(motor0FaultsJson);
    motorFaultsJson.append(motor1FaultsJson);

    return motorFaultsJson;
}

QJsonArray JsonMessageBuilder::buildMpptMessage(const I_MpptData& data)
{
    QJsonArray mpptJson = QJsonArray();

    for (int i = 0; i < data.getNumberOfUnits(); i++)
    {
        QJsonObject mpptJsonUnit = QJsonObject();
        const I_MpptUnit& mpptUnit = data.getMpptUnit(i);

        if (mpptUnit.getMpptStatus())
        {
            mpptJsonUnit[JsonFormat::ALIVE] = true;
        }
        else
        {
            mpptJsonUnit[JsonFormat::ALIVE] = false;
        }

        mpptJsonUnit[JsonFormat::ARRAY_VOLTAGE] = mpptUnit.getArrayVoltage();
        mpptJsonUnit[JsonFormat::ARRAY_CURRENT] = mpptUnit.getArrayCurrent();
        mpptJsonUnit[JsonFormat::BATTERY_VOLTAGE] = mpptUnit.getBatteryVoltage();
        mpptJsonUnit[JsonFormat::TEMPERATURE] = mpptUnit.getTemperature();

        mpptJson.append(mpptJsonUnit);
    }

    return mpptJson;
}


