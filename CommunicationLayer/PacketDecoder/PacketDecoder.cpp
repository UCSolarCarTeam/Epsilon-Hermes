#include <QDebug>

#include "PacketDecoder.h"
#include "../PacketChecksumChecker/I_PacketChecksumChecker.h"
#include "../MessagingFramework/MessageDefines.h"

namespace
{
const int INDEX_OF_PACKET_TYPE = 0;
}

PacketDecoder::PacketDecoder(const I_PacketChecksumChecker& checksumChecker)
{
    connect(&checksumChecker, SIGNAL(validDataReceived(QByteArray)),
            this, SLOT(handleValidData(QByteArray)));
}

PacketDecoder::~PacketDecoder()
{
}

void PacketDecoder::handleValidData(QByteArray messageData)
{
    MessageDefines::Type messageType =
        static_cast<MessageDefines::Type>(messageData.at(INDEX_OF_PACKET_TYPE));

    if (MessageDefines::getLengthForMessage(messageType) == messageData.size())
    {
        switch (messageType)
        {
        case MessageDefines::KEY_MOTOR:
            emit packetDecoded(KeyMotorMessage(messageData));
            return;

        case MessageDefines::MOTOR_0_DETAILS:
        case MessageDefines::MOTOR_1_DETAILS:
            emit packetDecoded(MotorDetailsMessage(messageData));
            return;

        case MessageDefines::DRIVER_CONTROLS:
            emit packetDecoded(DriverControlsMessage(messageData));
            return;

        case MessageDefines::MOTOR_FAULTS:
            emit packetDecoded(MotorFaultsMessage(messageData));
            return;

        case MessageDefines::BATTERY_FAULTS:
            emit packetDecoded(BatteryFaultsMessage(messageData));
            return;

        case MessageDefines::BATTERY:
            emit packetDecoded(BatteryMessage(messageData));
            return;

        case MessageDefines::MPPT:
            emit packetDecoded(MpptMessage(messageData));
            return;

        case MessageDefines::LIGHTS:
            emit packetDecoded(LightsMessage(messageData));
            return;
        }
    }
    else
    {
        qWarning() << "Message length is not correct for type" << static_cast<quint8>(messageType);
        qWarning() << "Actual" << messageData.size() << "Expected" << MessageDefines::getLengthForMessage(messageType);
    }
}
