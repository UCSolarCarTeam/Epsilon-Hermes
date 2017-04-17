#include <QCommandLineOption>
#include <QCommandLineParser>
#include "InfrastructureLayer/InfrastructureContainer.h"
#include "DataLayer/DataContainer.h"
#include "CommunicationLayer/CommunicationContainer.h"
#include "BusinessLayer/BusinessContainer.h"
#include "ViewLayer/ViewContainer.h"
#include "Mode.h"

#include "SchulichEpsilonHermes.h"

SchulichEpsilonHermes::SchulichEpsilonHermes(int& argc, char** argv)
    : QApplication(argc, argv)
    , infrastructureContainer_(new InfrastructureContainer())
    , dataContainer_(new DataContainer(infrastructureContainer_->settings()))
{
    QCommandLineParser parser;
    QCommandLineOption telemetryModeOption("g");
    parser.addOption(telemetryModeOption);
    parser.process(*this);
    Mode::Mode mode = Mode::Mode::HEADLESS;

    if (parser.isSet(telemetryModeOption))
    {
        mode = Mode::Mode::GUI;
    }

    viewContainer_.reset(new ViewContainer(mode));
    communicationContainer_.reset(new CommunicationContainer(*dataContainer_, *infrastructureContainer_, mode));
    businessContainer_.reset(new BusinessContainer(*infrastructureContainer_, *communicationContainer_, mode));
}

SchulichEpsilonHermes::~SchulichEpsilonHermes()
{
}
