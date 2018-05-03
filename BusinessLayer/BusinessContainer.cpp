#include "BusinessContainer.h"

#include "CommunicationLayer/CommunicationContainer.h"
#include "CommunicationsMonitoringService/CommunicationsMonitoringService.h"
#include "DataLayer/DataContainer.h"
#include "InfrastructureLayer/InfrastructureContainer.h"
#include "JsonForwarder/JsonForwarder.h"
#include "JsonMessageBuilder/JsonMessageBuilder.h"

BusinessContainer::BusinessContainer(InfrastructureContainer& infrastructureContainer,
                                     CommunicationContainer& communicationContainer,
                                     DataContainer& dataContainer)
    : communicationsMonitoringService_(new CommunicationsMonitoringService(
                                           communicationContainer.packetChecksumChecker()))
    , jsonMessageBuilder_(new JsonMessageBuilder())
    , jsonForwarder_(new JsonForwarder(
                         *jsonMessageBuilder_,
                         dataContainer.auxBmsData(),
                         dataContainer.batteryData(),
                         dataContainer.batteryFaultsData(),
                         dataContainer.driverControlsData(),
                         dataContainer.keyMotorData(),
                         dataContainer.lightsData(),
                         dataContainer.motorDetailsData(),
                         dataContainer.motorFaultsData(),
                         dataContainer.mpptData(),
                         communicationContainer.messageForwarder(),
                         infrastructureContainer.settings()))
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
