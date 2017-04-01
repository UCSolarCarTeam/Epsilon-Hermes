#pragma once

#include <QScopedPointer>
#include <QTimer>

#include "I_JsonForwarder.h"
#include "../SchulichDeltaHermes/Mode.h"

class BatteryJsonForwarder;
class FaultsJsonForwarder;
class PowerJsonForwarder;
class VehicleJsonForwarder;

class I_BatteryData;
class I_BatteryFaultsData;
class I_CmuData;
class I_DriverControlsData;
class I_KeyMotorData;
class I_LightsData;
class I_MotorDetailsData;
class I_MotorFaultsData;
class I_MpptData;
class I_MessageForwarder;
class I_Settings;

class JsonForwarder : public I_JsonForwarder
{
    Q_OBJECT
public:
    JsonForwarder(/*I_BatteryData& batteryData,
                  I_BatteryFaultsData& batteryFaultsData,
                  I_CmuData& cmuData,
                  I_DriverControlsData& driverControlsData,
                  I_KeyMotorData& keyMotorData,
                  I_LightsData& lightsData,
                  I_MotorDetailsData& motorDetailsData,
                  I_MotorFaultsData& motorFaultsData,
                  I_MpptData& mpptData,
                  I_OtherData& otherData,*/
        I_MessageForwarder& messageForwarder,
        I_Settings& settings,
        Mode::Mode mode);
    virtual ~JsonForwarder();
    void startForwardingData();

private slots:
    void forwardData();

private:
    QScopedPointer<BatteryJsonForwarder> batteryJsonForwarder_;
    QScopedPointer<FaultsJsonForwarder> faultsJsonForwarder_;
    QScopedPointer<PowerJsonForwarder> powerJsonForwarder_;
    QScopedPointer<VehicleJsonForwarder> vehicleJsonForwarder_;
    QScopedPointer<QTimer> readTimer_;
    int dataToReadCount_;
    int forwardPeriod_;
    const QString PACKET_TITLE_;
};
