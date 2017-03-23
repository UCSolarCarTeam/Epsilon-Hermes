#include "ViewContainer.h"
#include "TelemetryDisplayUi/TelemetryDisplayUi.h"
#include "OverlordWidget/OverlordWidget.h"

ViewContainer::ViewContainer(Mode mode)
{
    if(mode == Mode::TELEMETRY)
    {
        telemetryDisplayUi_ = new TelemetryDisplayUi();
        overlordWidget_.reset(new OverlordWidget(*telemetryDisplayUi_));
    }
}

ViewContainer::~ViewContainer()
{
}
