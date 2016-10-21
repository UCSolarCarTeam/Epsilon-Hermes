#include "BatteryData/BatteryData.h"
#include "DataContainer.h"
#include "FaultsData/FaultsData.h"
#include "PowerData/PowerData.h"
#include "VehicleData/VehicleData.h"

DataContainer::DataContainer()
    : vehicleData_(new VehicleData())
    , powerData_(new PowerData())
    , batteryData_(new BatteryData())
    , faultsData_(new FaultsData())
{
}

DataContainer::~DataContainer()
{
}

I_PowerData& DataContainer::powerData()
{
    return *powerData_;
}

I_VehicleData& DataContainer::vehicleData()
{
    return *vehicleData_;
}

I_BatteryData& DataContainer::batteryData()
{
    return *batteryData_;
}

I_FaultsData& DataContainer::faultsData()
{
    return *faultsData_;
}
