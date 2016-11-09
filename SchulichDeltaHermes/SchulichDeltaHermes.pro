TEMPLATE = app

LIBS += -L../../build/.lib -lBusinessLayer -lCommunicationLayer -lDataLayer -lInfrastructureLayer

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

PRE_TARGETDEPS += \
   ../../build/.lib/*

TARGET = SchulichDeltaHermes
DESTDIR = ../../build

HEADERS += \
   SchulichDeltaHermes.h

SOURCES += \
   main.cpp \
   SchulichDeltaHermes.cpp
