#include "MessageDefines.h"

namespace
{
    const int BATTERY_DATA_LENGTH = 64;
    const int BATTERY_FAULTS_DATA_LENGTH = 7;
    const int CMU_DATA_LENGTH = 54;
    const int DRIVER_CONTROLS_DATA_LENGTH = 14;
    const int KEY_MOTOR_DATA_LENGTH = 47;
    const int LIGHTS_DATA_LENGTH = 6;
    const int MOTOR_DETAILS_DATA_LENGTH = 73;
    const int MOTOR_FAULTS_DATA_LENGTH = 13;
    const int MPPT_DATA_LENGTH = 14;
}

int MessageDefines::getLengthForMessage(MessageDefines::Type type)
{
    switch (type)
    {
        case BATTERY:
            return BATTERY_DATA_LENGTH;

        case BATTERY_FAULTS:
            return BATTERY_FAULTS_DATA_LENGTH;

        case CMU:
            return CMU_DATA_LENGTH;

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
