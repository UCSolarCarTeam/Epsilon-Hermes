#pragma once

namespace MessageDefines
{
    enum Type
    {
        KEY_MOTOR = 1,
        MOTOR_0_DETAILS = 2,
        MOTOR_1_DETAILS = 3,
        DRIVER_CONTROLS = 4,
        MOTOR_FAULTS = 5,
        BATTERY_FAULTS = 6,
        BATTERY = 7,
        MPPT = 9,
        LIGHTS = 10
    };

    int getLengthForMessage(Type type);
}
