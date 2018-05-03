#pragma once

#include <QObject>
#include "CommunicationLayer/PacketDecoder/I_PacketDecoder.h"
#include "DataLayer/AuxBmsData/I_AuxBmsData.h"

class AuxBmsPopulator : public QObject
{
    Q_OBJECT
public:
    AuxBmsPopulator(I_PacketDecoder& packetDecoder,
                    I_AuxBmsData& auxBmsData);
public slots:
    void populateData(const AuxBmsMessage);

private:
    I_PacketDecoder& packetDecoder_;
    I_AuxBmsData& auxBmsData_;
};
