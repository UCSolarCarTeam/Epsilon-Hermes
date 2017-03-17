#include "TelemetryDisplayUi.h"
#include "ui_TelemetryDisplayUi.h"

TelemetryDisplayUi::TelemetryDisplayUi() :
    ui_(new Ui::TelemetryDisplayUi)
{
    ui_->setupUi(this);
}

TelemetryDisplayUi::~TelemetryDisplayUi()
{
    delete ui_;
}
