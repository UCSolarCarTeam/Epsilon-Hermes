#pragma once
#include <QScopedPointer>
#include "../SchulichDeltaHermes/Mode.h"
class TelemetryDisplayUi;
class OverlordWidget;

class ViewContainer
{
public:
    explicit ViewContainer(Mode::Mode mode);
    ~ViewContainer();
private:
    TelemetryDisplayUi* telemetryDisplayUi_;
    QScopedPointer<OverlordWidget> overlordWidget_;
};
