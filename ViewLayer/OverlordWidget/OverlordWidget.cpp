#include <QVBoxLayout>

#include "OverlordWidget.h"
#include "../TelemetryDisplayUi/I_TelemetryDisplayUi.h"

OverlordWidget::OverlordWidget(I_TelemetryDisplayUi& telemetryDisplayUi)
    : telemetryDisplayUi_(telemetryDisplayUi)
{
    QVBoxLayout* menu = new QVBoxLayout();
    setLayout(menu);
    show();
}
OverlordWidget::~OverlordWidget()
{

}
