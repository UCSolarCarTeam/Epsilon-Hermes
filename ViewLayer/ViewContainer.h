#pragma once
#include <QScopedPointer>

class TelemetryDisplayUi;
class OverlordWidget;

class ViewContainer
{
public:
    explicit ViewContainer();
    ~ViewContainer();
private:
    TelemetryDisplayUi* telemetryDisplayUi_;
    QScopedPointer<OverlordWidget> overlordWidget_;
};
