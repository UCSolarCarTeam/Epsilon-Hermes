#pragma once
#include "I_TelemetryDisplayUi.h"

namespace Ui
{
    class TelemetryDisplayUi;
}

class TelemetryDisplayUi : public I_TelemetryDisplayUi
{
    Q_OBJECT

public:
    explicit TelemetryDisplayUi();
    ~TelemetryDisplayUi();

private:
    Ui::TelemetryDisplayUi* ui_;
};
