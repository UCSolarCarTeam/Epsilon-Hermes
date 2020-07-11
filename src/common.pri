
QT += serialport widgets network svg
CONFIG += c++11 debug console static

INCLUDEPATH += ..

CONFIG += conan_basic_setup
! include($$OUT_PWD/../conanbuildinfo.pri) {
    error("Could not find conanbuildinfo.pri file!")
}

OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc
UI_DIR = .ui

LIBS += -ldl
