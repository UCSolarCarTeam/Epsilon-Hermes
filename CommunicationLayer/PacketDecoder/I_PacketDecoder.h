#pragma once

#include <QObject>
#include "../MessagingFramework/AuxBmsMessage.h"
#include "../MessagingFramework/BatteryMessage.h"
#include "../MessagingFramework/BatteryFaultsMessage.h"
#include "../MessagingFramework/DriverControlsMessage.h"
#include "../MessagingFramework/KeyMotorMessage.h"
#include "../MessagingFramework/LightsMessage.h"
#include "../MessagingFramework/MotorDetailsMessage.h"
#include "../MessagingFramework/MotorFaultsMessage.h"
#include "../MessagingFramework/MpptMessage.h"

class I_PacketDecoder : public QObject
{
    Q_OBJECT
public:
    virtual ~I_PacketDecoder() {}

signals:
    void packetDecoded(const AuxBmsMessage);
    void packetDecoded(const BatteryMessage);
    void packetDecoded(const BatteryFaultsMessage);
    void packetDecoded(const DriverControlsMessage);
    void packetDecoded(const KeyMotorMessage);
    void packetDecoded(const LightsMessage);
    void packetDecoded(const MotorDetailsMessage);
    void packetDecoded(const MotorFaultsMessage);
    void packetDecoded(const MpptMessage);
};
