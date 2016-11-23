#include "MotorDetailsUnit.h"

MotorDetailsUnit::MotorDetailsUnit(unsigned char motorNumber)
: motorNumber_(motorNumber)
, phaseCCurrent_(0)
, phaseBCurrent_(0)
, motorVoltageReal_(0)
, motorVoltageImaginary_(0)
, motorCurrentReal_(0)
, motorCurrentImaginary_(0)
, backEmfReal_(0)
, backEmfImaginary_(0)
, voltageRailSuppply15V_(0)
, voltageRailSupply33V_(0)
, voltageRailSupply19V_(0)
, heatSinkTemperature_(0)
, motorTempterature_(0)
, dspBoardTemperature_(0)
, dcBusAmpHours_(0)
, odometer_(0)
, slipSpeed_(0)
{
    // initialize to 0
}

MotorDetailsUnit::~MotorDetailsUnit()
{
}

/* MotorDetailsUnit Gets*/
unsigned char MotorDetailsUnit::getMotorNumber() const
{
    return motorNumber_;
}

float MotorDetailsUnit::getPhaseCCurrent() const
{
    return phaseCCurrent_;
}

float MotorDetailsUnit::getPhaseBCurrent() const
{
    return phaseBCurrent_;
}

float MotorDetailsUnit::getMotorVoltageReal() const
{
    return motorVoltageReal_;
}

float MotorDetailsUnit::getMotorVoltageImaginary() const
{
    return motorVoltageImaginary_;
}

float MotorDetailsUnit::getMotorCurrentReal() const
{
    return motorCurrentReal_;
}

float MotorDetailsUnit::getMotorCurrentImaginary() const
{
    return motorCurrentImaginary_;
}

float MotorDetailsUnit::getBackEmfReal() const
{
    return backEmfReal_;
}

float MotorDetailsUnit::getBackEmfImaginary() const
{
    return backEmfImaginary_;
}

float MotorDetailsUnit::getVoltageRailSuppply15V() const
{
    return voltageRailSuppply15V_;
}

float MotorDetailsUnit::getVoltageRailSupply33V() const
{
    return voltageRailSupply33V_;
}

float MotorDetailsUnit::getVoltageRailSupply19V() const
{
    return voltageRailSupply19V_;
}

float MotorDetailsUnit::getHeatSinkTemperature() const
{
    return heatSinkTemperature_;
}

float MotorDetailsUnit::getMotorTempterature() const
{
    return motorTempterature_;
}

float MotorDetailsUnit::getDspBoardTemperature() const
{
    return dspBoardTemperature_;
}

float MotorDetailsUnit::getDcBusAmpHours() const
{
    return dcBusAmpHours_;
}

float MotorDetailsUnit::getOdometer() const
{
    return odometer_;
}

float MotorDetailsUnit::getSlipSpeed() const
{
    return slipSpeed_;
}


/* MotorDetailsUnit Sets*/
void MotorDetailsUnit::setPhaseCCurrent(float& phaseCCurrent)
{
    phaseCCurrent_ = phaseCCurrent;
    emit phaseCCurrentReceived(phaseCCurrent_);
}

void MotorDetailsUnit::setPhaseBCurrent(float& phaseBCurrent)
{
    phaseBCurrent_ = phaseBCurrent;
    emit phaseBCurrentReceived(phaseBCurrent_);
}

void MotorDetailsUnit::setMotorVoltageReal(float& motorVoltageReal)
{
    motorVoltageReal_ = motorVoltageReal;
    emit motorVoltageRealReceived(motorVoltageReal_);
}

void MotorDetailsUnit::setMotorVoltageImaginary(float& motorVoltageImaginary)
{
    motorVoltageImaginary_ = motorVoltageImaginary;
    emit motorVoltageImaginaryReceived(motorVoltageImaginary_);
}

void MotorDetailsUnit::setMotorCurrentReal(float& motorCurrentReal)
{
    motorCurrentReal_ = motorCurrentReal;
    emit motorCurrentRealReceived(motorCurrentReal_);
}

void MotorDetailsUnit::setMotorCurrentImaginary(float& motorCurrentImaginary)
{
    motorCurrentImaginary_ = motorCurrentImaginary;
    emit motorCurrentImaginaryReceived(motorCurrentImaginary_);
}

void MotorDetailsUnit::setBackEmfReal(float& backEmfReal)
{
    backEmfReal_ = backEmfReal;
    emit backEmfRealReceived(backEmfReal_);
}

void MotorDetailsUnit::setBackEmfImaginary(float& backEmfImaginary)
{
    backEmfImaginary_ = backEmfImaginary;
    emit backEmfImaginaryReceived(backEmfImaginary_);
}

void MotorDetailsUnit::setVoltageRailSuppply15V(float& voltageRailSuppply15V)
{
    voltageRailSuppply15V_ = voltageRailSuppply15V;
    emit voltageRailSuppply15VReceived(voltageRailSuppply15V_);
}

void MotorDetailsUnit::setVoltageRailSupply33V(float& voltageRailSupply33V)
{
    voltageRailSupply33V_ = voltageRailSupply33V;
    emit voltageRailSupply33VReceived(voltageRailSupply33V_);
}

void MotorDetailsUnit::setVoltageRailSupply19V(float& voltageRailSupply19V)
{
    voltageRailSupply19V_ = voltageRailSupply19V;
    emit voltageRailSupply19VReceived(voltageRailSupply19V_);
}

void MotorDetailsUnit::setHeatSinkTemperature(float& heatSinkTemperature)
{
    heatSinkTemperature_ = heatSinkTemperature;
    emit heatSinkTemperatureReceived(heatSinkTemperature_);
}

void MotorDetailsUnit::setMotorTempterature(float& motorTempterature)
{
    motorTempterature_ = motorTempterature;
    emit motorTempteratureReceived(motorTempterature_);
}

void MotorDetailsUnit::setDspBoardTemperature(float& dspBoardTemperature)
{
    dspBoardTemperature_ = dspBoardTemperature;
    emit dspBoardTemperatureReceived(dspBoardTemperature_);
}

void MotorDetailsUnit::setDcBusAmpHours(float& dcBusAmpHours)
{
    dcBusAmpHours_ = dcBusAmpHours;
    emit dcBusAmpHoursReceived(dcBusAmpHours_);
}

void MotorDetailsUnit::setOdometer(float& odometer)
{
    odometer_ = odometer;
    emit odometerReceived(odometer_);
}

void MotorDetailsUnit::setSlipSpeed(float& slipSpeed)
{
    slipSpeed_ = slipSpeed;
    emit slipSpeedReceived(slipSpeed_);
}