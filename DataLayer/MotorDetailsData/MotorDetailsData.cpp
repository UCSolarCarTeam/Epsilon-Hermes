/**
 *  Schulich Delta Hermes
 *  Copyright (C) 2015 University of Calgary Solar Car Team
 *
 *  This file is part of Schulich Delta Hermes
 *
 *  Schulich Delta Hermes is free software:
 *  you can redistribute it and/or modify it under the terms
 *  of the GNU Affero General Public License as published by
 *  the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  Schulich Delta Hermes is distributed
 *  in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General
 *  Public License along with Schulich Delta Hermes.
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 *  For further contact, email <software@calgarysolarcar.ca>
 */

#include "VehicleData.h"

VehicleData::VehicleData()
: driverSetSpeedMetersPerSecond_(-1)
, driverSetCurrent_(-1)
, vehicleVelocityMetersPerSecond_(-1)
, motorVelocityRpm_(-1)
, ipmHeatSinkTemp_(-1)
, dspBoardTemp_(-1)
, receivedErrorCount_(-1)
, transmittedErrorCount_(-1)
{
   // initialize to -1
}

VehicleData::~VehicleData()
{
}

double VehicleData::driverSetSpeedMetersPerSecond() const
{
   return driverSetSpeedMetersPerSecond_;
}

double VehicleData::driverSetCurrent() const
{
   return driverSetCurrent_;
}

double VehicleData::vehicleVelocityMetersPerSecond() const
{
   return vehicleVelocityMetersPerSecond_;
}

double VehicleData::motorVelocityRpm() const
{
   return motorVelocityRpm_;
}

double VehicleData::ipmHeatSinkTemp() const
{
   return ipmHeatSinkTemp_;
}
double VehicleData::dspBoardTemp() const
{
   return dspBoardTemp_;
}

double VehicleData::receivedErrorCount() const
{
   return receivedErrorCount_;
}
double VehicleData::transmittedErrorCount() const
{
   return transmittedErrorCount_;
}

void VehicleData::setDriverSetSpeedMetersPerSecond(double driverSetSpeedMetersPerSecond)
{
   driverSetSpeedMetersPerSecond_ = driverSetSpeedMetersPerSecond;
   emit driverSetSpeedMetersPerSecondReceived(driverSetSpeedMetersPerSecond_);
}
void VehicleData::setDriverSetCurrent(double driverSetCurrent)
{
   driverSetCurrent_ = driverSetCurrent;
   emit driverSetCurrentReceived(driverSetCurrent_);
}

void VehicleData::setVehicleVelocityMetersPerSecond(double vehicleVelocityMetersPerSecond)
{
   vehicleVelocityMetersPerSecond_ = vehicleVelocityMetersPerSecond;
   emit vehicleVelocityMetersPerSecondReceived(vehicleVelocityMetersPerSecond_);
}

void VehicleData::setMotorVelocityRpm(double motorVelocityRpm)
{
   motorVelocityRpm_ = motorVelocityRpm;
   emit motorVelocityRpmReceived(motorVelocityRpm_);
}

void VehicleData::setIpmHeatSinkTemp(double ipmHeatSinkTemp)
{
   ipmHeatSinkTemp_ = ipmHeatSinkTemp;
   emit ipmHeatSinkTempReceived(ipmHeatSinkTemp_);
}
void VehicleData::setDspBoardTemp(double dspBoardTemp)
{
   dspBoardTemp_ = dspBoardTemp;
   emit dspBoardTempReceived(dspBoardTemp_);
}

void VehicleData::setReceivedErrorCount(double receivedErrorCount)
{
   receivedErrorCount_ = receivedErrorCount;
   emit receivedErrorCountReceived(receivedErrorCount_);
}
void VehicleData::setTransmittedErrorCount(double transmittedErrorCount)
{
   transmittedErrorCount_ = transmittedErrorCount;
   emit transmittedErrorCountReceived(transmittedErrorCount_);
}
