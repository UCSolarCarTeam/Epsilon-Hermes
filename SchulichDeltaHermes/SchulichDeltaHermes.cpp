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
{
    QCommandLineParser parser;
    QCommandLineOption telemetryModeOption("g");
    parser.addOption(telemetryModeOption);
    parser.process(*this);
    Mode mode = Mode::HEADLESS;
    bool isGui = false;
    if (parser.isSet(telemetryModeOption))
    {
        mode = Mode::GUI;
    }

    if(mode == Mode::GUI)
    {   
        isGui = true;
        viewContainer_.reset(new ViewContainer());   
    }
    communicationContainer_.reset(new CommunicationContainer(*dataContainer_, *infrastructureContainer_, isGui));
    businessContainer_.reset(new BusinessContainer(*infrastructureContainer_, *communicationContainer_, isGui));
}

SchulichDeltaHermes::~SchulichDeltaHermes()
{
}
