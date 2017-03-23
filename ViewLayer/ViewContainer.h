#pragma once
#include <QScopedPointer>

class TelemetryDisplayUi;
class OverlordWidget;

enum class Mode { HERMES, TELEMETRY };

class ViewContainer
{
public:
    explicit ViewContainer(Mode mode);
    ~ViewContainer();
private:
    TelemetryDisplayUi* telemetryDisplayUi_;
    QScopedPointer<OverlordWidget> overlordWidget_;
};
