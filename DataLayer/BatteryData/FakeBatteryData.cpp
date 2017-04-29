#include "FakeBatteryData.h"

FakeBatteryData::FakeBatteryData()
{
}

FakeBatteryData::~FakeBatteryData()
{
}
/*Data "Gets"*/
bool FakeBatteryData::getAlive() const
{
    return true;
}

unsigned char FakeBatteryData::getBmsRelayStatus() const
{
    return 255; // 255 to make it consistent to the flag getters
}

unsigned char FakeBatteryData::getPopulatedCells() const
{
    return 2;
}

float FakeBatteryData::get12VInputVoltage() const
{
    return 3;
}

float FakeBatteryData::getFanVoltage() const
{
    return 4;
}

float FakeBatteryData::getPackCurrent() const
{
    return 5;
}

float FakeBatteryData::getPackVoltage() const
{
    return 6;
}

float FakeBatteryData::getPackStateOfCharge() const
{
    return 7;
}

float FakeBatteryData::getPackAmphours() const
{
    return 8;
}

float FakeBatteryData::getPackDepthOfDischarge() const
{
    return 9;
}

unsigned char FakeBatteryData::getHighTemperature() const
{
    return 10;
}

unsigned char FakeBatteryData::getHighThermistorId() const
{
    return 11;
}

unsigned char FakeBatteryData::getLowTemperature() const
{
    return 12;
}

unsigned char FakeBatteryData::getLowThermistorId() const
{
    return 13;
}

unsigned char FakeBatteryData::getAverageTemperature() const
{
    return 14;
}

unsigned char FakeBatteryData::getInternalTemperature() const
{
    return 15;
}

unsigned char FakeBatteryData::getFanSpeed() const
{
    return 0; // has to be between 0 and 6
}

unsigned char FakeBatteryData::getRequestedFanSpeed() const
{
    return 1; // has to be between 0 and 6
}

unsigned short FakeBatteryData::getLowCellVoltage() const
{
    return 16;
}

unsigned char FakeBatteryData::getLowCellVoltageId() const
{
    return 17;
}

unsigned short FakeBatteryData::getHighCellVoltage() const
{
    return 18;
}

unsigned char FakeBatteryData::getHighCellVoltageId() const
{
    return 19;
}

unsigned short FakeBatteryData::getAverageCellVoltage() const
{
    return 20;
}

FakeBatteryData::PrechargeState FakeBatteryData::getPrechargeState() const
{
    return PrechargeState::IDLE;
}

unsigned char FakeBatteryData::getAuxVoltage() const
{
    return 21;
}

bool FakeBatteryData::getAuxBmsAlive() const
{
    return true;
}

/* BMS relay status getter */
bool FakeBatteryData::bmsDischargeRelayEnabled() const
{
    return true;
}

bool FakeBatteryData::bmsChargeRelayEnabaled() const
{
    return true;
}

bool FakeBatteryData::bmsChargerSafetyEnabled() const
{
    return true;
}

bool FakeBatteryData::bmsMalfunctionIndicatorActive() const
{
    return true;
}

bool FakeBatteryData::bmsGetMultiPurposeInputSignalStatus() const
{
    return true;
}

bool FakeBatteryData::bmsGetAlwaysOnSignalStatus() const
{
    return true;
}

bool FakeBatteryData::bmsGetIsReadySignalStatus() const
{
    return true;
}

bool FakeBatteryData::bmsGetIsChargingSignalStatus() const
{
    return true;
}

/*BatteryData "Sets"*/
void FakeBatteryData::setAlive(const unsigned char&) {}
void FakeBatteryData::setBmsRelayStatus(const unsigned char&) {}
void FakeBatteryData::setPopulatedCells(const unsigned char&) {}
void FakeBatteryData::set12VInputVoltage(const float&) {}
void FakeBatteryData::setFanVoltage(const float&) {}
void FakeBatteryData::setPackCurrent(const float&) {}
void FakeBatteryData::setPackVoltage(const float&) {}
void FakeBatteryData::setPackStateOfCharge(const float&) {}
void FakeBatteryData::setPackAmphours(const float&) {}
void FakeBatteryData::setPackDepthOfDischarge(const float&) {}
void FakeBatteryData::setHighTemperature(const unsigned char&) {}
void FakeBatteryData::setHighThermistorId(const unsigned char&) {}
void FakeBatteryData::setLowTemperature(const unsigned char&) {}
void FakeBatteryData::setLowThermistorId(const unsigned char&) {}
void FakeBatteryData::setAverageTemperature(const unsigned char&) {}
void FakeBatteryData::setInternalTemperature(const unsigned char&) {}
void FakeBatteryData::setFanSpeed(const unsigned char&) {}
void FakeBatteryData::setRequestedFanSpeed(const unsigned char&) {}
void FakeBatteryData::setLowCellVoltage(const unsigned short&) {}
void FakeBatteryData::setLowCellVoltageId(const unsigned char&) {}
void FakeBatteryData::setHighCellVoltage(const unsigned short&) {}
void FakeBatteryData::setHighCellVoltageId(const unsigned char&) {}
void FakeBatteryData::setAverageCellVoltage(const unsigned short&) {}
void FakeBatteryData::setPrechargeState(const unsigned char&) {}
void FakeBatteryData::setAuxVoltage(const unsigned char&) {}
void FakeBatteryData::setAuxBmsAlive(const unsigned char&) {}
