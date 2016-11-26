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
    virtual float getBackEmfReal() const = 0;
    virtual float getBackEmfImaginary() const = 0;
    virtual float getVoltageRailSuppply15V() const = 0;
    virtual float getVoltageRailSupply33V() const = 0;
    virtual float getVoltageRailSupply19V() const = 0;
    virtual float getHeatSinkTemperature() const = 0;
    virtual float getMotorTempterature() const = 0;
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
    virtual void setBackEmfReal(const float& backEmfReal) = 0;
    virtual void setBackEmfImaginary(const float& backEmfImaginary) = 0;
    virtual void setVoltageRailSuppply15V(const float& voltageRailSuppply15V) = 0;
    virtual void setVoltageRailSupply33V(const float& voltageRailSupply33V) = 0;
    virtual void setVoltageRailSupply19V(const float& voltageRailSupply19V) = 0;
    virtual void setHeatSinkTemperature(const float& heatSinkTemperature) = 0;
    virtual void setMotorTempterature(const float& motorTempterature) = 0;
    virtual void setDspBoardTemperature(const float& dspBoardTemperature) = 0;
    virtual void setDcBusAmpHours(const float& dcBusAmpHours) = 0;
    virtual void setOdometer(const float& odometer) = 0;
    virtual void setSlipSpeed(const float& slipSpeed) = 0;

signals:
    void phaseCCurrentReceived(const float& phaseCCurrent);
    void phaseBCurrentReceived(const float& phaseBCurrent);
    void motorVoltageRealReceived(const float& motorVoltageReal);
    void motorVoltageImaginaryReceived(const float& motorVoltageImaginary);
    void motorCurrentRealReceived(const float& motorCurrentReal);
    void motorCurrentImaginaryReceived(const float& motorCurrentImaginary);
    void backEmfRealReceived(const float& backEmfReal);
    void backEmfImaginaryReceived(const float& backEmfImaginary);
    void voltageRailSuppply15VReceived(const float& voltageRailSuppply15V);
    void voltageRailSupply33VReceived(const float& voltageRailSupply33V);
    void voltageRailSupply19VReceived(const float& voltageRailSupply19V);
    void heatSinkTemperatureReceived(const float& heatSinkTemperature);
    void motorTempteratureReceived(const float& motorTempterature);
    void dspBoardTemperatureReceived(const float& dspBoardTemperature);
    void dcBusAmpHoursReceived(const float& dcBusAmpHours);
    void odometerReceived(const float& odometer);
    void slipSpeedReceived(const float& slipSpeed);
};

