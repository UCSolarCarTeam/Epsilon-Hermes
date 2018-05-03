TEMPLATE = lib
CONFIG += staticlib

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

DESTDIR = ../../build/.lib

HEADERS += \
   CommDeviceControl/I_CommDevice.h \
   CommDeviceControl/I_ConnectionService.h \
   CommDeviceControl/RadioCommDevice.h \
   CommDeviceControl/RabbitMqMessageForwarder.h \
   CommDeviceControl/I_MessageForwarder.h \
   CommunicationContainer.h \
   DataPopulators/AuxBmsPopulator.h \
   DataPopulators/BatteryFaultsPopulator.h \
   DataPopulators/BatteryPopulator.h \
   DataPopulators/DriverControlsPopulator.h \
   DataPopulators/KeyMotorPopulator.h \
   DataPopulators/LightsPopulator.h \
   DataPopulators/MotorDetailsPopulator.h \
   DataPopulators/MotorFaultsPopulator.h \
   DataPopulators/MpptPopulator.h \
   MessagingFramework/AuxBmsMessage.h \
   MessagingFramework/BatteryFaultsMessage.h \
   MessagingFramework/BatteryMessage.h \
   MessagingFramework/DriverControlsMessage.h \
   MessagingFramework/KeyMotorMessage.h \
   MessagingFramework/LightsMessage.h \
   MessagingFramework/MotorDetailsMessage.h \
   MessagingFramework/MotorFaultsMessage.h \
   MessagingFramework/MpptMessage.h \
   MessagingFramework/MessageDecodingHelpers.h \
   MessagingFramework/MessageDefines.h \
   PacketChecksumChecker/I_PacketChecksumChecker.h \
   PacketChecksumChecker/PacketChecksumChecker.h \
   PacketDecoder/I_PacketDecoder.h \
   PacketDecoder/PacketDecoder.h \
   PacketSynchronizer/I_PacketSynchronizer.h \
   PacketSynchronizer/PacketSynchronizer.h \
   PacketUnstuffer/I_DataInjectionService.h \
   PacketUnstuffer/I_PacketUnstuffer.h \
   PacketUnstuffer/PacketUnstuffer.h \
    CommDeviceControl/OutputRadioCommDevice.h

SOURCES += \
   CommDeviceControl/RadioCommDevice.cpp \
   CommDeviceControl/RabbitMqMessageForwarder.cpp \
   CommunicationContainer.cpp \
   DataPopulators/AuxBmsPopulator.cpp \
   DataPopulators/BatteryFaultsPopulator.cpp \
   DataPopulators/BatteryPopulator.cpp \
   DataPopulators/DriverControlsPopulator.cpp \
   DataPopulators/KeyMotorPopulator.cpp \
   DataPopulators/LightsPopulator.cpp \
   DataPopulators/MotorDetailsPopulator.cpp \
   DataPopulators/MotorFaultsPopulator.cpp \
   DataPopulators/MpptPopulator.cpp \
   MessagingFramework/AuxBmsMessage.cpp \
   MessagingFramework/BatteryFaultsMessage.cpp \
   MessagingFramework/BatteryMessage.cpp \
   MessagingFramework/DriverControlsMessage.cpp \
   MessagingFramework/KeyMotorMessage.cpp \
   MessagingFramework/LightsMessage.cpp \
   MessagingFramework/MotorDetailsMessage.cpp \
   MessagingFramework/MotorFaultsMessage.cpp \
   MessagingFramework/MpptMessage.cpp \
   MessagingFramework/MessageDecodingHelpers.cpp \
   MessagingFramework/MessageDefines.cpp \
   PacketChecksumChecker/PacketChecksumChecker.cpp \
   PacketDecoder/PacketDecoder.cpp \
   PacketSynchronizer/PacketSynchronizer.cpp \
   PacketUnstuffer/PacketUnstuffer.cpp \
    CommDeviceControl/OutputRadioCommDevice.cpp
