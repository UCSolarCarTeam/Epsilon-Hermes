#include "MotorDetailsMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

#include <QDebug>

namespace
{
    const int PACKAGE_ID_OFFSET = 0;
    const int PHASE_CCURRENT_OFFSET = 1;
    const int PHASE_BCURRENT_OFFSET = 5;
    const int MOTOR_VOLTAGE_REAL_OFFSET = 9;
    const int MOTOR_VOLTAGE_IMAGINARY_OFFSET = 13;
    const int MOTOR_CURRENT_REAL_OFFSET = 17;
    const int MOTOR_CURRENT_IMAGINARY_OFFSET = 21;
    const int BACK_EMF_OFFSET = 25;
    const int VOLTAGE_RAIL_SUPPPLY_15_V_OFFSET = 29;
    const int VOLTAGE_RAIL_SUPPLY_33_V_OFFSET = 33;
    const int VOLTAGE_RAIL_SUPPLY_19_V_OFFSET = 37;
    const int HEAT_SINK_TEMPERATURE_OFFSET = 41;
    const int MOTOR_TEMPERATURE_OFFSET = 45;
    const int DSP_BOARD_TEMPERATURE_OFFSET = 49;
    const int DC_BUS_AMP_HOURS_OFFSET = 53;
    const int ODOMETER_OFFSET = 57;
    const int SLIP_SPEED_OFFSET = 61;
}

MotorDetailsMessage::MotorDetailsMessage(const QByteArray& messageData)
    : messageData_(messageData)
{
}

unsigned char MotorDetailsMessage::motorNumber() const
{
    const unsigned char packageID = getUnsignedChar(messageData_, PACKAGE_ID_OFFSET);
    // ID of motor 0 == 2, ID of motor 1 == 3
    return packageID - 2;
}

float MotorDetailsMessage::phaseCCurrent() const
{
    return MessageDecodingHelpers::getFloat(messageData_, PHASE_CCURRENT_OFFSET);
}

float MotorDetailsMessage::phaseBCurrent() const
{
    return MessageDecodingHelpers::getFloat(messageData_, PHASE_BCURRENT_OFFSET);
}

float MotorDetailsMessage::motorVoltageReal() const
{
    return MessageDecodingHelpers::getFloat(messageData_, MOTOR_VOLTAGE_REAL_OFFSET);
}

float MotorDetailsMessage::motorVoltageImaginary() const
{
    return MessageDecodingHelpers::getFloat(messageData_, MOTOR_VOLTAGE_IMAGINARY_OFFSET);
}

float MotorDetailsMessage::motorCurrentReal() const
{
    return MessageDecodingHelpers::getFloat(messageData_, MOTOR_CURRENT_REAL_OFFSET);
}

float MotorDetailsMessage::motorCurrentImaginary() const
{
    return MessageDecodingHelpers::getFloat(messageData_, MOTOR_CURRENT_IMAGINARY_OFFSET);
}

float MotorDetailsMessage::backEmf() const
{
    return MessageDecodingHelpers::getFloat(messageData_, BACK_EMF_OFFSET);
}

float MotorDetailsMessage::voltageRailSuppply15V() const
{
    return MessageDecodingHelpers::getFloat(messageData_, VOLTAGE_RAIL_SUPPPLY_15_V_OFFSET);
}

float MotorDetailsMessage::voltageRailSupply33V() const
{
    return MessageDecodingHelpers::getFloat(messageData_, VOLTAGE_RAIL_SUPPLY_33_V_OFFSET);
}

float MotorDetailsMessage::voltageRailSupply19V() const
{
    return MessageDecodingHelpers::getFloat(messageData_, VOLTAGE_RAIL_SUPPLY_19_V_OFFSET);
}

float MotorDetailsMessage::heatSinkTemperature() const
{
    return MessageDecodingHelpers::getFloat(messageData_, HEAT_SINK_TEMPERATURE_OFFSET);
}

float MotorDetailsMessage::motorTemperature() const
{
    return MessageDecodingHelpers::getFloat(messageData_, MOTOR_TEMPERATURE_OFFSET);
}

float MotorDetailsMessage::dspBoardTemperature() const
{
    return MessageDecodingHelpers::getFloat(messageData_, DSP_BOARD_TEMPERATURE_OFFSET);
}

float MotorDetailsMessage::dcBusAmpHours() const
{
    return MessageDecodingHelpers::getFloat(messageData_, DC_BUS_AMP_HOURS_OFFSET);
}

float MotorDetailsMessage::odometer() const
{
    return MessageDecodingHelpers::getFloat(messageData_, ODOMETER_OFFSET);
}

float MotorDetailsMessage::slipSpeed() const
{
    return MessageDecodingHelpers::getFloat(messageData_, SLIP_SPEED_OFFSET);
}

QString MotorDetailsMessage::toString() const
{
    QString messageString;

    if ((motorNumber() & 0xe) != 0x0)
    {
        qCritical() << "Invalid motor number, unexpected behaviour likely";
    }

    messageString += QString::number(MessageDefines::MOTOR_0_DETAILS + motorNumber()) + ", ";
    messageString += QString::number(phaseCCurrent()) + ", ";
    messageString += QString::number(phaseBCurrent()) + ", ";
    messageString += QString::number(motorVoltageReal()) + ", ";
    messageString += QString::number(motorVoltageImaginary()) + ", ";
    messageString += QString::number(motorCurrentReal()) + ", ";
    messageString += QString::number(motorCurrentImaginary()) + ", ";
    messageString += QString::number(backEmf()) + ", ";
    messageString += QString::number(voltageRailSuppply15V()) + ", ";
    messageString += QString::number(voltageRailSupply33V()) + ", ";
    messageString += QString::number(voltageRailSupply19V()) + ", ";
    messageString += QString::number(heatSinkTemperature()) + ", ";
    messageString += QString::number(motorTemperature()) + ", ";
    messageString += QString::number(dspBoardTemperature()) + ", ";
    messageString += QString::number(dcBusAmpHours()) + ", ";
    messageString += QString::number(odometer()) + ", ";
    messageString += QString::number(slipSpeed()) + ", ";
    return messageString;
}
