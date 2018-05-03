#include "InfrastructureContainer.h"
#include "Settings/Settings.h"
#include "Logging/Logging.h"
#include <QCoreApplication>

namespace
{
}

InfrastructureContainer::InfrastructureContainer()
    : logging_(Logging::instance())
{
    settings_.reset(new Settings(QCoreApplication::applicationDirPath() + "/config.ini"));
    if (settings_->loggingEnabled())
    {
        logging_.init(settings_->logLevel());
    }
}

InfrastructureContainer::~InfrastructureContainer()
{
}

I_Settings& InfrastructureContainer::settings()
{
    return *settings_;
}
