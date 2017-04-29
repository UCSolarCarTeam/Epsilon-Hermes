#include "BusinessContainer.h"

#include "CommunicationLayer/CommunicationContainer.h"
#include "CommunicationsMonitoringService/CommunicationsMonitoringService.h"
#include "DataLayer/DataContainer.h"
#include "InfrastructureLayer/InfrastructureContainer.h"
#include "JsonForwarder/JsonForwarder.h"
#include "LoggerService/LoggerService.h"

BusinessContainer::BusinessContainer(InfrastructureContainer& infrastructureContainer,
                                     CommunicationContainer& communicationContainer,
                                     bool isGui/*,
                                     DataContainer& dataContainer*/)
    : loggerService_(new LoggerService(communicationContainer.packetSynchronizer(),
                                       communicationContainer.packetDecoder()))
    , communicationsMonitoringService_(new CommunicationsMonitoringService(
                                           communicationContainer.packetChecksumChecker()))
    , jsonForwarder_(new JsonForwarder(/*dataContainer.batteryData(),
                                       dataContainer.batteryFaultsData(),
                                       dataContainer.cmuData(),
                                       dataContainer.driverControlsData(),
                                       dataContainer.keyMotorData(),
                                       dataContainer.lightsData(),
                                       dataContainer.motorDetailsData(),
                                       dataContainer.motorFaultsData(),
                                       dataContainer.mpptData(),
                                       dataContainer.otherData(),*/
                         communicationContainer.udpMessageForwarder(),
                         infrastructureContainer.settings(), isGui))
{
    jsonForwarder_->startForwardingData();
}

BusinessContainer::~BusinessContainer()
{
}

I_CommunicationsMonitoringService& BusinessContainer::communicationsMonitoringService()
{
    return *communicationsMonitoringService_;
}
