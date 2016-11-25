#include "DataContainer.h"
#include "BatteryData/BatteryData.h"
#include "BatteryFaultsData/BatteryFaultsData.h"
#include "CmuData/CmuData.h"
#include "DriverControlsData/DriverControlsData.h"
#include "KeyMotorData/KeyMotorData.h"
#include "LightsData/LightsData.h"
#include "MotorDetailsData/MotorDetailsData.h"
#include "MotorFaultsData/MotorFaultsData.h"
#include "MpptData/MpptData.h"
#include "OtherData/OtherData.h"

DataContainer::DataContainer()
: batteryData_(new BatteryData())
, batteryFaultsData_(new BatteryFaultsData())
, cmuData_(new CmuData())
, driverControlsData_(new DriverControlsData())
, keyMotorData_(new KeyMotorData())
, lightsData_(new LightsData())
, motorDetailsData_(new MotorDetailsData())
, motorFaultsData_(new MotorFaultsData())
, mpptData_(new MpptData())
, otherData_(new OtherData())
{
}

DataContainer::~DataContainer()
{
}

I_BatteryData& DataContainer::batteryData()
{
    return *batteryData_;
}

I_BatteryFaultsData& DataContainer::batteryFaultsData()
{
    return *batteryFaultsData_;
}

I_CmuData& DataContainer::cmuData()
{
    return *cmuData_;
}

I_DriverControlsData& DataContainer::driverControlsData()
{
    return *driverControlsData_;
}

I_KeyMotorData& DataContainer::keyMotorData()
{
    return *keyMotorData_;
}

I_LightsData& DataContainer::lightsData()
{
    return *lightsData_;
}

I_MotorDetailsData& DataContainer::motorDetailsData()
{
    return *motorDetailsData_;
}

I_MotorFaultsData& DataContainer::motorFaultsData()
{
    return *motorFaultsData_;
}

I_MpptData& DataContainer::mpptData()
{
    return *mpptData_;
}

I_OtherData& DataContainer::otherData()
{
    return *otherData_;
}

