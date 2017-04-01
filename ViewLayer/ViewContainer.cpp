#include "ViewContainer.h"
#include "TelemetryDisplayUi/TelemetryDisplayUi.h"
#include "OverlordWidget/OverlordWidget.h"

ViewContainer::ViewContainer(Mode::Mode mode)
{
    if (mode == Mode::Mode::GUI)
    {
        telemetryDisplayUi_ = new TelemetryDisplayUi();
        overlordWidget_.reset(new OverlordWidget(*telemetryDisplayUi_));
    }
}

ViewContainer::~ViewContainer()
{
}
