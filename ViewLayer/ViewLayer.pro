TEMPLATE = lib
CONFIG += staticlib

!include(../common.pri){
    error("Could not find common.pri file!")
}

DESTDIR = ../../build/.lib

HEADERS += \
    TelemetryDisplayUi/TelemetryDisplayUi.h \
    ViewContainer.h \
    TelemetryDisplayUi/I_TelemetryDisplayUi.h \
    OverlordWidget/OverlordWidget.h \
    OverlordWidget/I_OverlordWidget.h

SOURCES += \ 
    TelemetryDisplayUi/TelemetryDisplayUi.cpp \
    ViewContainer.cpp \
    OverlordWidget/OverlordWidget.cpp

FORMS += \
    TelemetryDisplayUi/TelemetryDisplayUi.ui
