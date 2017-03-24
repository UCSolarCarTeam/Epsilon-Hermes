#include <QCommandLineOption>
#include <QCommandLineParser>
#include "InfrastructureLayer/InfrastructureContainer.h"
#include "DataLayer/DataContainer.h"
#include "CommunicationLayer/CommunicationContainer.h"
#include "BusinessLayer/BusinessContainer.h"
#include "ViewLayer/ViewContainer.h"

#include "SchulichDeltaHermes.h"

SchulichDeltaHermes::SchulichDeltaHermes(int& argc, char** argv)
    : QApplication(argc, argv)
    , infrastructureContainer_(new InfrastructureContainer())
    , dataContainer_(new DataContainer(infrastructureContainer_->settings()))
    , communicationContainer_(new CommunicationContainer(*dataContainer_,
                              *infrastructureContainer_))
    , businessContainer_(new BusinessContainer(*infrastructureContainer_,
                         *communicationContainer_/*,
                         *dataContainer_*/))
{
    QCommandLineParser parser;
    QCommandLineOption telemetryModeOption("g");
    parser.addOption(telemetryModeOption);
    parser.process(*this);
    Mode mode = Mode::HEADLESS;

    if (parser.isSet(telemetryModeOption))
    {
        mode = Mode::GUI;
    }

    viewContainer_.reset(new ViewContainer(mode));
}

SchulichDeltaHermes::~SchulichDeltaHermes()
{
}
