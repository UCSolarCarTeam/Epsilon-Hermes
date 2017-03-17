#include "ViewContainer.h"
#include "TelemetryDisplayUi/TelemetryDisplayUi.h"
#include "OverlordWidget/OverlordWidget.h"

ViewContainer::ViewContainer()
    : telemetryDisplayUi_(new TelemetryDisplayUi())
    , overlordWidget_(new OverlordWidget(*telemetryDisplayUi_))
{

}

ViewContainer::~ViewContainer()
{
}
