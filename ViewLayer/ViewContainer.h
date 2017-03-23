#pragma once
#include <QScopedPointer>

class TelemetryDisplayUi;
class OverlordWidget;

enum class Mode { HEADLESS, GUI };

class ViewContainer
{
public:
    explicit ViewContainer(Mode mode);
    ~ViewContainer();
private:
    TelemetryDisplayUi* telemetryDisplayUi_;
    QScopedPointer<OverlordWidget> overlordWidget_;
};
