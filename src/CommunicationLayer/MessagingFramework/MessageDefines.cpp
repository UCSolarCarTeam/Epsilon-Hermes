#include "MessageDefines.h"

namespace
{
// Message lengths do not include metadata
    const int AUX_BMS_DATA_LENGTH = 11;
    const int BATTERY_DATA_LENGTH = 48;
    const int BATTERY_FAULTS_DATA_LENGTH = 6;
    const int DRIVER_CONTROLS_DATA_LENGTH = 9;
    const int KEY_MOTOR_DATA_LENGTH = 43;
    const int LIGHTS_DATA_LENGTH = 3;
    const int MOTOR_DETAILS_DATA_LENGTH = 65;
    const int MOTOR_FAULTS_DATA_LENGTH = 9;
    const int MPPT_DATA_LENGTH = 10;
}

int MessageDefines::getLengthForMessage(MessageDefines::Type type)
{
    switch (type)
    {
        case AUX_BMS:
            return AUX_BMS_DATA_LENGTH;

        case BATTERY:
            return BATTERY_DATA_LENGTH;

        case BATTERY_FAULTS:
            return BATTERY_FAULTS_DATA_LENGTH;

        case DRIVER_CONTROLS:
            return DRIVER_CONTROLS_DATA_LENGTH;

        case KEY_MOTOR:
            return KEY_MOTOR_DATA_LENGTH;

        case LIGHTS:
            return LIGHTS_DATA_LENGTH;

        case MOTOR_0_DETAILS:
        case MOTOR_1_DETAILS:
            return MOTOR_DETAILS_DATA_LENGTH;

        case MOTOR_FAULTS:
            return MOTOR_FAULTS_DATA_LENGTH;

        case MPPT:
            return MPPT_DATA_LENGTH;

        default:
            return 0;
    }
}
