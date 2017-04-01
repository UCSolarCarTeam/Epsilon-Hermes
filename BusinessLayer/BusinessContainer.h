#pragma once

#include <QScopedPointer>
#include "../SchulichDeltaHermes/Mode.h"

class CommunicationContainer;
class DataContainer;
class I_CommunicationsMonitoringService;
class I_JsonForwarder;
class InfrastructureContainer;
class LoggerService;

class BusinessContainer
{
public:
    explicit BusinessContainer(InfrastructureContainer& infrastructureContainer,
                               CommunicationContainer& communicationContainer,
                               Mode::Mode mode/*,
                               DataContainer& dataContainer*/);
    ~BusinessContainer();

    I_CommunicationsMonitoringService& communicationsMonitoringService();

private:
    QScopedPointer<LoggerService> loggerService_;
    QScopedPointer<I_CommunicationsMonitoringService> communicationsMonitoringService_;
    QScopedPointer<I_JsonForwarder> jsonForwarder_;
};
