TEMPLATE = app
QT += testlib
CONFIG += testcase

LIBS += -L../../build/.lib -lBusinessLayer -lCommunicationLayer -lDataLayer -lInfrastructureLayer -lgmock

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

HEADERS += \
    CommunicationLayer/CommDeviceControl/MockMessageForwarder.h \
    InfrastructureLayer/Settings/MockSettings.h \
    BusinessLayer/JsonMessageBuilder/MockJsonMessageBuilder.h \
    DataLayer/KeyMotorData/MockKeyMotorData.h \
    DataLayer/MotorDetailsData/MockMotorDetailsData.h \
    DataLayer/MotorDetailsData/MockMotorDetailsUnit.h \
    DataLayer/DriverControlsData/MockDriverControlsData.h \
    DataLayer/MotorFaultsData/MockMotorFaultsData.h \
    DataLayer/BatteryFaultsData/MockBatteryFaultsData.h \
    DataLayer/BatteryData/MockBatteryData.h \
    DataLayer/MpptData/MockMpptData.h \
    DataLayer/MpptData/MockMpptUnit.h \
    DataLayer/LightsData/MockLightsData.h \
    DataLayer/BatteryData/MockBatteryData.h \
    DataLayer/BatteryFaultsData/MockBatteryFaultsData.h \
    DataLayer/DriverControlsData/MockDriverControlsData.h \
    DataLayer/KeyMotorData/MockKeyMotorData.h \
    DataLayer/LightsData/MockLightsData.h \
    DataLayer/MotorDetailsData/MockMotorDetailsData.h \
    DataLayer/MotorDetailsData/MockMotorDetailsUnit.h \
    DataLayer/MotorFaultsData/MockMotorFaultsData.h \
    DataLayer/MpptData/MockMpptData.h \
    DataLayer/MpptData/MockMpptUnit.h \
    DataLayer/AuxBmsData/MockAuxBmsData.h

SOURCES += \
    testmain.cpp \
    InfrastructureLayer/Settings/SettingsTest.cpp \
    BusinessLayer/JsonForwarder/JsonForwarderTest.cpp \
    BusinessLayer/JsonMessageBuilder/JsonMessageBuilderTest.cpp \

TRAVIS_DEFINED = $$(TRAVIS)
count(TRAVIS_DEFINED, 0) {
   # rabbit mq message forwarder expects rabbitMQ server located at localhost, not applicable for TravisCI.
   SOURCES += \
      CommunicationLayer/CommDeviceControl/RabbitMqMessageForwarderTest.cpp
} else {
   message(TravisCI build)
}

!win32 {
    QMAKE_CXXFLAGS +=
}

DESTDIR = ../../build/tests

copyfiles.commands = cp testconfig.ini $${DESTDIR}

QMAKE_EXTRA_TARGETS += copyfiles
POST_TARGETDEPS += copyfiles
