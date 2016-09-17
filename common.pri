#-------------------------------------------------
#
#  Project created by QtCreator 2014-10-13T12:01:32
#
#  Schulich Delta Hermes
#  Copyright (C) 2015 University of Calgary Solar Car Team
#
#  This file is part of Schulich Delta Hermes
#
#  Schulich Delta Hermes is free software:
#  you can redistribute it and/or modify it under the terms
#  of the GNU Affero General Public License as published by
#  the Free Software Foundation, either version 3 of the
#  License, or (at your option) any later version.
#
#  Schulich Delta Hermes is distributed
#  in the hope that it will be useful, but WITHOUT ANY WARRANTY;
#  without even the implied warranty of MERCHANTABILITY or
#  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero
#  General Public License for more details.
#
#  You should have received a copy of the GNU Affero General
#  Public License along with Schulich Delta Hermes.
#  If not, see <http://www.gnu.org/licenses/>.
#
#  For further contact, email <software@calgarysolarcar.ca>
#
#-------------------------------------------------

QT += serialport widgets network svg
CONFIG += c++11 debug console static

!win32 {
   QMAKE_CXXFLAGS += -Werror
}

INCLUDEPATH += ..

OBJECTS_DIR = ../../build/.obj
MOC_DIR = ../../build/.moc
RCC_DIR = ../../build/.rcc
UI_DIR = ../../build/.ui

LIBS += -lSimpleAmqpClient -lrabbitmq
