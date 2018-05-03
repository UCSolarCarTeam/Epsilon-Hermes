#pragma once

#include <QScopedPointer>

class DataContainer;
class InfrastructureContainer;
class CommunicationContainerPrivate;

class I_DataInjectionService;
class I_PacketChecksumChecker;
class I_PacketDecoder;
class I_PacketSynchronizer;
class I_CommDevice;
class I_MessageForwarder;

class CommunicationContainer
{
public:
    explicit CommunicationContainer(DataContainer& dataContainer, InfrastructureContainer& infrastructureContainer);
    ~CommunicationContainer();

    I_PacketSynchronizer& packetSynchronizer();
    I_PacketDecoder& packetDecoder();
    I_PacketChecksumChecker& packetChecksumChecker();
    I_DataInjectionService& dataInjectionService();
    I_CommDevice& commDevice();
    I_CommDevice& outputCommDevice();
    I_MessageForwarder& messageForwarder();

private:
    // This is using the PIMPL design pattern, refer to http://c2.com/cgi/wiki?PimplIdiom
    QScopedPointer<CommunicationContainerPrivate> impl_;
};
