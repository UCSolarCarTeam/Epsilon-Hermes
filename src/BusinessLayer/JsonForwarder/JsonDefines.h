#pragma once

namespace JsonFormat
{
    const int DECIMAL_PRECISION = 2;
    const QString PACKET_TITLE = "PacketTitle";
    const QString TIMESTAMP = "TimeStamp";

    /* Multi-use */
    const QString ALIVE = "Alive";
    const QString ERROR_FLAGS = "ErrorFlags";
    const QString LIMITS_FLAGS = "LimitFlags";

    /* KeyMotor */
    const QString KEY_MOTOR = "KeyMotor";
    const QString SET_CURRENT = "SetCurrent";
    const QString SET_VELOCITY = "SetVelocity";
    const QString BUS_CURRENT = "BusCurrent";
    const QString BUS_VOLTAGE = "BusVoltage";
    const QString VEHICLE_VELOCITY = "VehicleVelocity";

    /* MotorDetails */
    const QString MOTOR_DETAILS = "MotorDetails";
    const QString PHASE_C_CURRENT = "PhaseCCurrent";
    const QString PHASE_B_CURRENT = "PhaseBCurrent";
    const QString MOTOR_VOLTAGE_REAL = "MotorVoltageReal";
    const QString MOTOR_VOLTAGE_IMAGINARY = "MotorVoltageImaginary";
    const QString MOTOR_CURRENT_REAL = "MotorCurrentReal";
    const QString MOTOR_CURRENT_IMAGINARY = "MotorCurrentImaginary";
    const QString BACK_EMF = "BackEmf";
    const QString VOLTAGE_RAIL_15V_SUPPLY = "VoltageRail15VSupply";
    const QString VOLTAGE_RAIL_3V_SUPPLY = "VoltageRail3VSupply";
    const QString VOLTAGE_RAIL_1V_SUPPLY = "VoltageRail1VSupply";
    const QString HEAT_SINK_TEMP = "HeatSinkTemp";
    const QString MOTOR_TEMP = "MotorTemp";
    const QString DSP_BOARD_TEMP = "DspBoardTemp";
    const QString DC_BUS_AMP_HOURS = "DcBusAmpHours";
    const QString ODOMETER_ = "Odometer";
    const QString SLIP_SPEED = "SlipSpeed";

    /* DriverControls */
    const QString DRIVER_CONTROLS = "DriverControls";
    const QString HEADLIGHTS_OFF = "HeadlightsOff";
    const QString HEADLIGHTS_LOW = "HeadlightsLow";
    const QString HEADLIGHTS_HIGH = "HeadlightsHigh";
    const QString SIGNAL_RIGHT = "SignalRight";
    const QString SIGNAL_LEFT = "SignalLeft";
    const QString HAZARD = "Hazard";
    const QString INTERIOR = "Interior";
    const QString VOLUME_UP = "VolumeUp";
    const QString VOLUME_DOWN = "VolumeDown";
    const QString NEXT_SONG = "NextSong";
    const QString PREV_SONG = "PrevSong";
    const QString BRAKES = "Brakes";
    const QString FORWARD = "Forward";
    const QString REVERSE = "Reverse";
    const QString PUSH_TO_TALK = "PushToTalk";
    const QString HORN = "Horn";
    const QString RESET = "Reset";
    const QString AUX = "Aux";
    const QString LAP = "Lap";
    const QString ACCELERATION = "Acceleration";
    const QString REGEN_BRAKING = "RegenBraking";

    /* MotorFaults */
    const QString MOTOR_FAULTS = "MotorFaults";
    const QString RX_ERROR_COUNT = "RxErrorCount";
    const QString TX_ERROR_COUNT = "TxErrorCount";
    const QString MOTOR_OVER_SPEED = "MotorOverSpeed";
    const QString SOFTWARE_OVER_CURRENT = "SoftwareOverCurrent";
    const QString DC_BUS_OVER_VOLTAGE = "DcBusOverVoltage";
    const QString BAD_MOTOR_POSITION_HALL_SEQUENCE = "BadMotorPositionHallSequence";
    const QString WATCHDOG_CAUSED_LAST_RESET = "WatchdogCausedLastReset";
    const QString CONFIG_READ_ERROR = "ConfigReadError";
    const QString RAIL_15V_UNDER_VOLTAGE_LOCK_OUT = "Rail15VUnderVoltageLockOut";
    const QString DESATURATION_FAULT = "DesaturationFault";
    const QString OUTPUT_VOLTAGE_PWM = "OutputVoltagePwm";
    const QString MOTOR_CURRENT = "MotorCurrent";
    const QString VELOCITY = "Velocity";
// const QString BUS_CURRENT = "BusCurrent"; // Defined at keymotor already
    const QString BUS_VOLTAGE_UPPER = "BusVoltageUpper";
    const QString BUS_VOLTAGE_LOWER = "BusVoltageLower";
    const QString IPM_OR_MOTOR_TEMPERATURE = "IpmOrMotorTemperature";

    /* BatteryFaults */
    const QString BATTERY_FAULTS = "BatteryFaults";
    const QString INTERNAL_COMMUNICATION_FAULT = "InternalCommunicationFault";
    const QString INTERNAL_CONVERSION_FAULT = "InternalConversionFault";
    const QString WEAK_CELL_FAULT = "WeakCellFault";
    const QString LOW_CELL_VOLTAGE_FAULT = "LowCellVoltageFault";
    const QString OPEN_WIRING_FAULT = "OpenWiringFault";
    const QString CURRENT_SENSOR_FAULT = "CurrentSensorFault";
    const QString PACK_VOLTAGE_SENSOR_FAULT = "PackVoltageSensorFault";
    const QString WEAK_PACK_FAULT = "WeakPackFault";
    const QString VOLTAGE_REDUNDANCY_FAULT = "VoltageRedundancyFault";
    const QString FAN_MONITOR_FAULT = "FanMonitorFault";
    const QString THERMISTOR_FAULT_ = "ThermistorFault";
    const QString CANBUS_COMMUNICATIONS_FAULT = "CANBUSCommunicationsFault";
    const QString ALWAYS_ON_SUPPLYFAULT = "AlwaysOnSupplyFault";
    const QString HIGH_VOLTAGE_ISOLATION_FAULT = "HighVoltageIsolationFault";
    const QString POWER_SUPPLY_12V_FAULT = "12vPowerSupplyFault";
    const QString CHARGE_LIMIT_ENFORCEMENT_FAULT = "ChargeLimitEnforcementFault";
    const QString DISCHARGE_LIMIT_ENFORCEMENT_FAULT = "DischargeLimitEnforcementFault";
    const QString CHARGER_SAFETY_RELAY_FAULT = "ChargerSafetyRelayFault";
    const QString INTERNAL_MEMORY_FAULT = "InternalMemoryFault";
    const QString INTERNAL_THERMISTOR_FAULT = "InternalThermistorFault";
    const QString INTERNAL_LOGIC_FAULT = "InternalLogicFault";
    const QString DCL_REDUCED_DUE_TO_LOW_SOC = "DclReducedDueToLowSoc";
    const QString DCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE = "DclReducedDueToHighCellResistance";
    const QString DCL_REDUCED_DUE_TO_TEMPERATURE_ = "DclReducedDueToTemperature";
    const QString DCL_REDUCED_DUE_TO_LOW_CELL_VOLTAGE = "DclReducedDueToLowCellVoltage";
    const QString DCL_REDUCED_DUE_TO_LOW_PACK_VOLTAGE = "DclReducedDueToLowPackVoltage";
    const QString DCL_AND_CCL_REDUCED_DUE_TO_VOLTAGE_FAILSAFE = "DclandCclReducedDueToVoltageFailsafe";
    const QString DCL_AND_CCL_REDUCED_DUE_TO_COMMUNICATION_FAILSAFE = "DclandCclReducedDueToCommunicationFailsafe";
    const QString CCL_REDUCED_DUE_TO_HIGH_SOC = "CclReducedDueToHighSoc";
    const QString CCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE = "CclReducedDueToHighCellResistance";
    const QString CCL_REDUCED_DUE_TO_TEMPERATURE = "CclReducedDueToTemperature";
    const QString CCL_REDUCED_DUE_TO_HIGH_CELL_VOLTAGE = "CclReducedDueToHighCellVoltage";
    const QString CCL_REDUCED_DUE_TO_HIGH_PACK_VOLTAGE = "CclReducedDueToHighPackVoltage";
    const QString CCL_REDUCED_DUE_TO_CHARGER_LATCH = "CclReducedDueToChargerLatch";
    const QString CCL_REDUCED_DUE_TO_ALTERNATE_CURRENT_LIMIT = "CclReducedDueToAlternateCurrentLimit";

    /* Battery */
    const QString BATTERY = "Battery";
    const QString BMS_RELAY_STATUS_FLAGS = "BMSRelayStatusFlags";
    const QString BMS_DISCHARGE_RELAY_ENABLED = "DischargeRelayEnabled";
    const QString BMS_CHARGE_RELAY_ENABLED = "ChargeRelayEnabled";
    const QString BMS_CHARGER_SAFETY_ENABLED = "ChargerSafetyEnabled";
    const QString BMS_MALFUNCTION_INDICATOR_ACTIVE = "MalfunctionIndicatorActive";
    const QString BMS_GET_MULTI_PURPOSE_INPUT_SIGNAL_STATUS = "MultiPurposeInputSignalStatus";
    const QString BMS_GET_ALWAYS_ON_SIGNAL_STATUS = "AlwaysOnSignalStatus";
    const QString BMS_GET_IS_READY_SIGNAL_STATUS = "IsReadySignalStatus";
    const QString BMS_GET_IS_CHARGING_SIGNAL_STATUS = "IsChargingSignalStatus";
    const QString POPULATED_CELLS = "PopulatedCells";
    const QString INPUT_VOLTAGE_12V = "12vInputVoltage";
    const QString FAN_VOLTAGE = "FanVoltage";
    const QString PACK_CURRENT = "PackCurrent";
    const QString PACK_VOLTAGE = "PackVoltage";
    const QString PACK_STATE_OF_CHARGE = "PackStateOfCharge";
    const QString PACK_AMPHOURS = "PackAmphours";
    const QString PACK_DEPTH_OF_DISCHARGE = "PackDepthOfDischarge";
    const QString HIGH_TEMPERATURE = "HighTemperature";
    const QString HIGH_THERMISTOR_ID = "HighThermistorId";
    const QString LOW_TEMPERATURE = "LowTemperature";
    const QString LOW_THERMISTOR_ID = "LowThermistorId";
    const QString AVERAGE_TEMPERATURE = "AverageTemperature";
    const QString INTERNAL_TEMPERATURE = "InternalTemperature";
    const QString FAN_SPEED = "FanSpeed";
    const QString REQUESTED_FAN_SPEED = "RequestedFanSpeed";
    const QString LOW_CELL_VOLTAGE = "LowCellVoltage";
    const QString LOW_CELL_VOLTAGE_ID = "LowCellVoltageId";
    const QString HIGH_CELL_VOLTAGE = "HighCellVoltage";
    const QString HIGH_CELL_VOLTAGE_ID = "HighCellVoltageId";
    const QString AVERAGE_CELL_VOLTAGE = "AverageCellVoltage";

    /* Mppt */
    const QString MPPT = "MPPT";
    const QString ARRAY_VOLTAGE = "ArrayVoltage";
    const QString ARRAY_CURRENT = "ArrayCurrent";
    const QString BATTERY_VOLTAGE = "BatteryVoltage";
    const QString TEMPERATURE = "Temperature";

    /* Lights */
    const QString LIGHTS = "Lights";
    const QString LIGHTS_LOW_BEAMS = "LowBeams";
    const QString LIGHTS_HIGH_BEAMS = "HighBeams";
    const QString LIGHTS_BRAKES = "Brakes";
    const QString LIGHTS_LEFT_SIGNAL = "LeftSignal";
    const QString LIGHTS_RIGHT_SIGNAL = "RightSignal";
    const QString LIGHTS_BMS_STROBE_LIGHT = "BmsStrobeLight";
    const QString LIGHTS_ALIVE = "Alive";

    /* AuxBms */
    const QString AUX_BMS = "AuxBms";
    const QString PRECHARGE_STATE = "PrechargeState";
    const QString AUX_VOLTAGE = "AuxVoltage";
    const QString AUX_BMS_ALIVE = "AuxBmsAlive";
    const QString STROBE_BMS_LIGHT = "StrobeBmsLight";
    const QString ALLOW_CHARGE = "AllowCharge";
    const QString HIGH_VOLTAGE_ENABLE_STATE = "HighVoltageEnableState";
    const QString ALLOW_DISCHARGE = "AllowDischarge";
    const QString ORION_CAN_RECEIVED_RECENTLY = "OrionCANReceivedRecently";
    const QString CHARGE_CONTACTOR_ERROR = "ChargeContactorError";
    const QString DISCHARGE_CONTACTOR_ERROR = "DischargeContactorError";
    const QString COMMON_CONTACTOR_ERROR = "CommonContactorError";
    const QString DISCHARGE_SHOULD_TRIP = "DischargeShouldTrip";
    const QString CHARGE_SHOULD_TRIP = "ChargeShouldTrip";
    const QString CHARGE_OPEN_BUT_SHOULD_BE_CLOSED = "ChargeOpenButShouldBeClosed";
    const QString DISCHARGE_OPEN_BUT_SHOULD_BE_CLOSED = "DischargeOpenButShouldBeClosed";
    const QString CHARGE_TRIP_DUE_TO_HIGH_CELL_VOLTAGE = "ChargeTripDueToHighCellVoltage";
    const QString CHARGE_TRIP_DUE_TO_HIGH_TEMPERATURE_AND_CURRENT = "ChargeTripDueToHighTemperatureAndCurrent";
    const QString CHARGE_TRIP_DUE_TO_PACK_CURRENT = "ChargeTripDueToPackCurrent";
    const QString DISCHARGE_TRIP_DUE_TO_LOW_CELL_VOLTAGE = "DischargeTripDueToLowCellVoltage";
    const QString DISCHARGE_TRIP_DUE_TO_HIGH_TEMERATURE_AND_CURRENT = "DischargeTripDueToHighTemeratureAndCurrent";
    const QString DISCHARGE_TRIP_DUE_TO_PACK_CURRENT = "DischargeTripDueToPackCurrent";
    const QString PROTECTION_TRIP = "ProtectionTrip";

    /* Ccs */
    const QString CCS = "Ccs";
    const QString CCS_ALIVE = "CcsAlive";
}
