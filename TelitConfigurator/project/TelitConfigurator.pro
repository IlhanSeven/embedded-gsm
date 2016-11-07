#-------------------------------------------------
#
# Project created by Ilhan Seven on 21/10/2015
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = TelitConfugirator
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

MOC_DIR =       ../output/moc
OBJECTS_DIR =   ../output/objects
DESTDIR =       ../output/binary

SOURCES += \
    ../sources/main.cpp \
    ../sources/SerialPortHandler.cpp \
    ../sources/telitconfigurator.cpp

HEADERS += \
    ../sources/SerialPortHandler.h \
    ../sources/telitconfigurator.h
