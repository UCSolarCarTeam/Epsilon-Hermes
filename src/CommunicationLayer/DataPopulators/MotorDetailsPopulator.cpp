#include "MotorDetailsPopulator.h"

MotorDetailsPopulator::MotorDetailsPopulator(I_PacketDecoder& packetDecoder, I_MotorDetailsData& motorDetailsData)
    : packetDecoder_(packetDecoder)
    , motorDetailsData_(motorDetailsData)
{
    connect(&packetDecoder_, SIGNAL(packetDecoded(const MotorDetailsMessage)), this, SLOT(populateData(const MotorDetailsMessage)));
}

void MotorDetailsPopulator::populateData(const MotorDetailsMessage message)
{
    I_MotorDetailsUnit& motorDetailsUnit = motorDetailsData_.getMotorDetailsUnit(message.motorNumber());
    motorDetailsUnit.setPhaseCCurrent(message.phaseCCurrent());
    motorDetailsUnit.setPhaseBCurrent(message.phaseBCurrent());
    motorDetailsUnit.setMotorVoltageReal(message.motorVoltageReal());
    motorDetailsUnit.setMotorVoltageImaginary(message.motorVoltageImaginary());
    motorDetailsUnit.setMotorCurrentReal(message.motorCurrentReal());
    motorDetailsUnit.setMotorCurrentImaginary(message.motorCurrentImaginary());
    motorDetailsUnit.setBackEmf(message.backEmf());
    motorDetailsUnit.setVoltageRailSuppply15V(message.voltageRailSuppply15V());
    motorDetailsUnit.setVoltageRailSupply33V(message.voltageRailSupply33V());
    motorDetailsUnit.setVoltageRailSupply19V(message.voltageRailSupply19V());
    motorDetailsUnit.setHeatSinkTemperature(message.heatSinkTemperature());
    motorDetailsUnit.setMotorTemperature(message.motorTemperature());
    motorDetailsUnit.setDspBoardTemperature(message.dspBoardTemperature());
    motorDetailsUnit.setDcBusAmpHours(message.dcBusAmpHours());
    motorDetailsUnit.setOdometer(message.odometer());
    motorDetailsUnit.setSlipSpeed(message.slipSpeed());
}
