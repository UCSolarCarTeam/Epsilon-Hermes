#include "InfrastructureLayer/InfrastructureContainer.h"
#include "DataLayer/DataContainer.h"
#include "CommunicationLayer/CommunicationContainer.h"
#include "BusinessLayer/BusinessContainer.h"

#include "SchulichEpsilonHermes.h"

SchulichEpsilonHermes::SchulichEpsilonHermes(int& argc, char** argv)
    : QCoreApplication(argc, argv)
    , infrastructureContainer_(new InfrastructureContainer())
    , dataContainer_(new DataContainer(infrastructureContainer_->settings()))
    , communicationContainer_(new CommunicationContainer(*dataContainer_,
                              *infrastructureContainer_))
    , businessContainer_(new BusinessContainer(*infrastructureContainer_,
                         *communicationContainer_,
                         *dataContainer_))
{
}

SchulichEpsilonHermes::~SchulichEpsilonHermes()
{
}
