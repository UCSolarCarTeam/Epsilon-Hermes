TEMPLATE = app

LIBS += \
    -L../BusinessLayer/.lib -lBusinessLayer \
    -L../CommunicationLayer/.lib -lCommunicationLayer \
    -L../DataLayer/.lib -lDataLayer \
    -L../InfrastructureLayer/.lib -lInfrastructureLayer

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

PRE_TARGETDEPS += \
    ../BusinessLayer/.lib/* \
    ../CommunicationLayer/.lib/* \
    ../DataLayer/.lib/* \
    ../InfrastructureLayer/.lib/*

TARGET = SchulichEpsilonHermes
DESTDIR = ../bin

HEADERS += \
   SchulichEpsilonHermes.h

SOURCES += \
   main.cpp \
   SchulichEpsilonHermes.cpp

copyconfigfile.commands = cp $$PWD/../config.ini.example ../bin/config.ini
QMAKE_EXTRA_TARGETS += copyconfigfile
POST_TARGETDEPS += copyconfigfile
