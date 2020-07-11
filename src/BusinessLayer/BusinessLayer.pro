TEMPLATE = lib
CONFIG += staticlib

! include( ../common.pri ) {
   error( "Couldn't find the common.pri file!" )
}

DESTDIR = .lib

HEADERS += \
   BusinessContainer.h \
   JsonForwarder/I_JsonForwarder.h \
   JsonForwarder/JsonForwarder.h \
   JsonMessageBuilder/JsonMessageBuilder.h \
   JsonMessageBuilder/I_JsonMessageBuilder.h \
   JsonForwarder/JsonDefines.h \

SOURCES += \
   BusinessContainer.cpp \
   JsonMessageBuilder/JsonMessageBuilder.cpp \
   JsonForwarder/JsonForwarder.cpp \
