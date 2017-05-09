#pragma once
#include "I_OverlordWidget.h"

class I_TelemetryDisplayUi;

class OverlordWidget : public I_OverlordWidget
{
    Q_OBJECT

public:
    explicit OverlordWidget(I_TelemetryDisplayUi& telemetryDisplayUi);
    ~OverlordWidget();
private:
    I_TelemetryDisplayUi& telemetryDisplayUi_;


};
