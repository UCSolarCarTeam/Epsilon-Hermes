#pragma once

#include <QObject>

class I_CommunicationsMonitoringService : public QObject
{
    Q_OBJECT
public:
    virtual ~I_CommunicationsMonitoringService() {}
    virtual void start() = 0;
    virtual void stop() = 0;
};
