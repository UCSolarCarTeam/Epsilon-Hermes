#include "DataContainer.h"
#include "AuxBmsData/AuxBmsData.h"
#include "BatteryData/BatteryData.h"
#include "BatteryFaultsData/BatteryFaultsData.h"
#include "DriverControlsData/DriverControlsData.h"
#include "KeyMotorData/KeyMotorData.h"
#include "LightsData/LightsData.h"
#include "MotorDetailsData/MotorDetailsData.h"
#include "MotorFaultsData/MotorFaultsData.h"
#include "MpptData/MpptData.h"
#include "InfrastructureLayer/Settings/I_Settings.h"

DataContainer::DataContainer(const I_Settings& settings)
    : auxBmsData_(new AuxBmsData())
    , batteryData_(new BatteryData())
    , batteryFaultsData_(new BatteryFaultsData())
    , driverControlsData_(new DriverControlsData())
    , keyMotorData_(new KeyMotorData())
    , lightsData_(new LightsData())
    , motorFaultsData_(new MotorFaultsData())
{
    QList<I_MotorDetailsUnit*> motorUnits;

    for (int i = 0; i < settings.numberOfMotors(); ++i)
    {
        motorUnits.append(new MotorDetailsUnit());
    }

    motorDetailsData_.reset(new MotorDetailsData(motorUnits));

    QList<I_MpptUnit*> mpptUnits;

    for (int i = 0; i < settings.numberOfMppts(); ++i)
    {
        mpptUnits.append(new MpptUnit());
    }

    mpptData_.reset(new MpptData(mpptUnits));
}

DataContainer::~DataContainer()
{
}

I_AuxBmsData& DataContainer::auxBmsData()
{
    return *auxBmsData_;
}

I_BatteryData& DataContainer::batteryData()
{
    return *batteryData_;
}

I_BatteryFaultsData& DataContainer::batteryFaultsData()
{
    return *batteryFaultsData_;
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
