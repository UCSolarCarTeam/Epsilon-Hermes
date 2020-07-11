
QT += serialport widgets network svg
CONFIG += c++11 debug console static

INCLUDEPATH += ..

OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc
UI_DIR = .ui

LIBS += -lSimpleAmqpClient -lrabbitmq
