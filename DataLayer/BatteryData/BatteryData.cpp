#include "BatteryData.h"

namespace
{
    const unsigned char BMS_DISCHARGE_RELAY_OFFSET = 0x1;
    const unsigned char BMS_CHARGE_RELAY_OFFSET = 0x2;
    const unsigned char BMS_CHARGER_SAFETY_OFFSET = 0x4;
    const unsigned char BMS_MALFUNCTION_INDICATOR_OFFSET = 0x8;
    const unsigned char BMS_MULTI_PURPOSE_INPUT_OFFSET = 0x10;
    const unsigned char BMS_ALWAYS_ON_OFFSET = 0x20;
    const unsigned char BMS_IS_READY_OFFSET = 0x40;
    const unsigned char BMS_IS_CHARGING_OFFSET = 0x80;
    const int PERCENTAGE_CONVERSION = 2;
    const int DECI_TO_ONES = 10;
    const int CENTI_TO_ONES = 100;
}

BatteryData::BatteryData()
    : alive_(false)
    , bmsRelayStatus_(0)
    , populatedCells_(0.0f)
    , inputVoltage12_(0.0f)
    , fanVoltage_(0.0f)
    , packCurrent_(0.0f)
    , packVoltage_(0.0f)
    , packStateOfCharge_(0.0f)
    , packAmphours_(0.0f)
    , packDepthOfDischarge_(0.0f)
    , highTemperature_(0)
    , highThermistorId_(0)
    , lowTemperature_(0)
    , lowThermistorId_(0)
    , averageTemperature_(0)
    , internalTemperature_(0)
    , fanSpeed_(0)
    , requestedFanSpeed_(0)
    , lowCellVoltage_(0)
    , lowCellVoltageId_(0)
    , highCellVoltage_(0)
    , highCellVoltageId_(0)
    , averageCellVoltage_(0)
{
    // initialize to 0
}

BatteryData::~BatteryData()
{
}

bool BatteryData::bmsRelayStatusFlagPresent(const unsigned char statusMask) const
{
    return static_cast<bool>(bmsRelayStatus_ & statusMask);
}

/*Data "Gets"*/
bool BatteryData::getAlive() const
{
    return alive_;
}

unsigned char BatteryData::getBmsRelayStatus() const
{
    return bmsRelayStatus_;
}

unsigned char BatteryData::getPopulatedCells() const
{
    return populatedCells_;
}

float BatteryData::get12VInputVoltage() const
{
    return inputVoltage12_;
}

float BatteryData::getFanVoltage() const
{
    return fanVoltage_;
}

float BatteryData::getPackCurrent() const
{
    return packCurrent_;
}

float BatteryData::getPackVoltage() const
{
    return packVoltage_;
}

float BatteryData::getPackStateOfCharge() const
{
    return packStateOfCharge_;
}

float BatteryData::getPackAmphours() const
{
    return packAmphours_;
}

float BatteryData::getPackDepthOfDischarge() const
{
    return packDepthOfDischarge_;
}

unsigned char BatteryData::getHighTemperature() const
{
    return highTemperature_;
}

unsigned char BatteryData::getHighThermistorId() const
{
    return highThermistorId_;
}

unsigned char BatteryData::getLowTemperature() const
{
    return lowTemperature_;
}

unsigned char BatteryData::getLowThermistorId() const
{
    return lowThermistorId_;
}

unsigned char BatteryData::getAverageTemperature() const
{
    return averageTemperature_;
}

unsigned char BatteryData::getInternalTemperature() const
{
    return internalTemperature_;
}

unsigned char BatteryData::getFanSpeed() const
{
    return fanSpeed_;
}

unsigned char BatteryData::getRequestedFanSpeed() const
{
    return requestedFanSpeed_;
}

unsigned short BatteryData::getLowCellVoltage() const
{
    return lowCellVoltage_;
}

unsigned char BatteryData::getLowCellVoltageId() const
{
    return lowCellVoltageId_;
}

unsigned short BatteryData::getHighCellVoltage() const
{
    return highCellVoltage_;
}

unsigned char BatteryData::getHighCellVoltageId() const
{
    return highCellVoltageId_;
}

unsigned short BatteryData::getAverageCellVoltage() const
{
    return averageCellVoltage_;
}

/* BMS relay status getter */
bool BatteryData::bmsDischargeRelayEnabled() const
{
    return bmsRelayStatusFlagPresent(BMS_DISCHARGE_RELAY_OFFSET);
}

bool BatteryData::bmsChargeRelayEnabled() const
{
    return bmsRelayStatusFlagPresent(BMS_CHARGE_RELAY_OFFSET);
}

bool BatteryData::bmsChargerSafetyEnabled() const
{
    return bmsRelayStatusFlagPresent(BMS_CHARGER_SAFETY_OFFSET);
}

bool BatteryData::bmsMalfunctionIndicatorActive() const
{
    return bmsRelayStatusFlagPresent(BMS_MALFUNCTION_INDICATOR_OFFSET);
}

bool BatteryData::bmsGetMultiPurposeInputSignalStatus() const
{
    return bmsRelayStatusFlagPresent(BMS_MULTI_PURPOSE_INPUT_OFFSET);
}

bool BatteryData::bmsGetAlwaysOnSignalStatus() const
{
    return bmsRelayStatusFlagPresent(BMS_ALWAYS_ON_OFFSET);
}

bool BatteryData::bmsGetIsReadySignalStatus() const
{
    return bmsRelayStatusFlagPresent(BMS_IS_READY_OFFSET);
}

bool BatteryData::bmsGetIsChargingSignalStatus() const
{
    return bmsRelayStatusFlagPresent(BMS_IS_CHARGING_OFFSET);
}

/*BatteryData "Sets"*/
void BatteryData::setAlive(const bool& alive)
{
    alive_ = alive;
}

void BatteryData::setBmsRelayStatus(const unsigned char& bmsRelayStatus)
{
    bmsRelayStatus_ = bmsRelayStatus;
}

void BatteryData::setPopulatedCells(const unsigned char& populatedCells)
{
    populatedCells_ = populatedCells;
}

void BatteryData::set12VInputVoltage(const float& inputVoltage12V)
{
    inputVoltage12_ = (inputVoltage12V / DECI_TO_ONES);
}

void BatteryData::setFanVoltage(const float& fanVoltage)
{
    fanVoltage_ = (fanVoltage / CENTI_TO_ONES);
}

void BatteryData::setPackCurrent(const float& packCurrent)
{
    packCurrent_ = (packCurrent / DECI_TO_ONES);
}

void BatteryData::setPackVoltage(const float& packVoltage)
{
    packVoltage_ = (packVoltage / DECI_TO_ONES);
}

void BatteryData::setPackStateOfCharge(const float& packStateOfCharge)
{
    packStateOfCharge_ = (packStateOfCharge / PERCENTAGE_CONVERSION);
}

void BatteryData::setPackAmphours(const float& packAmphours)
{
    packAmphours_ = (packAmphours / DECI_TO_ONES);
}

void BatteryData::setPackDepthOfDischarge(const float& packDepthOfDischarge)
{
    packDepthOfDischarge_ = (packDepthOfDischarge / PERCENTAGE_CONVERSION);
}

void BatteryData::setHighTemperature(const unsigned char& highTemperature)
{
    highTemperature_ = highTemperature;
}

void BatteryData::setHighThermistorId(const unsigned char& highThermistorId)
{
    highThermistorId_ = highThermistorId;
}

void BatteryData::setLowTemperature(const unsigned char& lowTemperature)
{
    lowTemperature_ = lowTemperature;
}

void BatteryData::setLowThermistorId(const unsigned char& lowThermistorId)
{
    lowThermistorId_ = lowThermistorId;
}

void BatteryData::setAverageTemperature(const unsigned char& averageTemperature)
{
    averageTemperature_ = averageTemperature;
}

void BatteryData::setInternalTemperature(const unsigned char& internalTemperature)
{
    internalTemperature_ = internalTemperature;
}

void BatteryData::setFanSpeed(const unsigned char& fanSpeed)
{
    fanSpeed_ = fanSpeed;
}

void BatteryData::setRequestedFanSpeed(const unsigned char& requestedFanSpeed)
{
    requestedFanSpeed_ = requestedFanSpeed;
}

void BatteryData::setLowCellVoltage(const unsigned short& lowCellVoltage)
{
    lowCellVoltage_ = (lowCellVoltage / DECI_TO_ONES);
}

void BatteryData::setLowCellVoltageId(const unsigned char& lowCellVoltageId)
{
    lowCellVoltageId_ = lowCellVoltageId;
}

void BatteryData::setHighCellVoltage(const unsigned short& highCellVoltage)
{
    highCellVoltage_ = (highCellVoltage / DECI_TO_ONES);
}

void BatteryData::setHighCellVoltageId(const unsigned char& highCellVoltageId)
{
    highCellVoltageId_ = highCellVoltageId;
}

void BatteryData::setAverageCellVoltage(const unsigned short& averageCellVoltage)
{
    averageCellVoltage_ = (averageCellVoltage / DECI_TO_ONES);
}
