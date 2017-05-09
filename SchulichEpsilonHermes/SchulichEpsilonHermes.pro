TEMPLATE = app

LIBS += -L../../build/.lib -lBusinessLayer -lCommunicationLayer -lDataLayer -lInfrastructureLayer -lViewLayer

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

PRE_TARGETDEPS += \
   ../../build/.lib/*

TARGET = SchulichEpsilonHermes
DESTDIR = ../../build

HEADERS += \
   SchulichEpsilonHermes.h

SOURCES += \
   main.cpp \
   SchulichEpsilonHermes.cpp
