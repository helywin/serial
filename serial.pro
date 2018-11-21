#-------------------------------------------------
#
# Project created by QtCreator 2018-06-09T11:25:15
#
#-------------------------------------------------

#TEMPLATE = subdirs
#SUBDIRS = src
#CONFIG = ordered
QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = serial
QMAKE_LFLAGS = -static
QMAKE_LFLAGS_QT_DLL = -static
DEFINES += QT_NO_DEBUG_OUTPUT
DEFINES += QT_WARNING_DEBUG_OUTPUT
TEMPLATE = app

CONFIG += c++1z

SUBDIRS = src

INCLUDEPATH += ./src \

SOURCES += \
        ./src/main.cpp \
        ./src/Serial.cpp \
        ./src/Window.cpp \
        ./src/Generate.cpp \
        ./src/SerialModel.cpp \
        ./src/SerialSortModel.cpp \
        ./src/SerialView.cpp \


HEADERS += \
        ./src/Serial.hpp \
        ./src/Window.hpp \
        ./src/Generate.hpp \
        ./src/SerialModel.hpp \
        ./src/SerialSortModel.hpp \
        ./src/SerialView.hpp \


RESOURCES += \


RC_FILE += \

TRANSLATIONS += \

