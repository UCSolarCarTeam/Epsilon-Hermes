#pragma once

#include <QObject>

class I_MotorDetailsUnit : public QObject
{
    Q_OBJECT

public:
    virtual ~I_MotorDetailsUnit() {}

    /*MotorDetailsUnit "Gets"*/
    virtual unsigned char getMotorNumber() const = 0;
    virtual float getPhaseCCurrent() const = 0;
    virtual float getPhaseBCurrent() const = 0;
    virtual float getMotorVoltageReal() const = 0;
    virtual float getMotorVoltageImaginary() const = 0;
    virtual float getMotorCurrentReal() const = 0;
    virtual float getMotorCurrentImaginary() const = 0;
    virtual float getBackEmf() const = 0;
    virtual float getVoltageRailSuppply15V() const = 0;
    virtual float getVoltageRailSupply33V() const = 0;
    virtual float getVoltageRailSupply19V() const = 0;
    virtual float getHeatSinkTemperature() const = 0;
    virtual float getMotorTemperature() const = 0;
    virtual float getDspBoardTemperature() const = 0;
    virtual float getDcBusAmpHours() const = 0;
    virtual float getOdometer() const = 0;
    virtual float getSlipSpeed() const = 0;

    /*MotorDetailsUnit "Sets"*/
    virtual void setPhaseCCurrent(const float& phaseCCurrent) = 0;
    virtual void setPhaseBCurrent(const float& phaseBCurrent) = 0;
    virtual void setMotorVoltageReal(const float& motorVoltageReal) = 0;
    virtual void setMotorVoltageImaginary(const float& motorVoltageImaginary) = 0;
    virtual void setMotorCurrentReal(const float& motorCurrentReal) = 0;
    virtual void setMotorCurrentImaginary(const float& motorCurrentImaginary) = 0;
    virtual void setBackEmf(const float& backEmf) = 0;
    virtual void setVoltageRailSuppply15V(const float& voltageRailSuppply15V) = 0;
    virtual void setVoltageRailSupply33V(const float& voltageRailSupply33V) = 0;
    virtual void setVoltageRailSupply19V(const float& voltageRailSupply19V) = 0;
    virtual void setHeatSinkTemperature(const float& heatSinkTemperature) = 0;
    virtual void setMotorTemperature(const float& motorTemperature) = 0;
    virtual void setDspBoardTemperature(const float& dspBoardTemperature) = 0;
    virtual void setDcBusAmpHours(const float& dcBusAmpHours) = 0;
    virtual void setOdometer(const float& odometer) = 0;
    virtual void setSlipSpeed(const float& slipSpeed) = 0;
};

