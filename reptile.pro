#-------------------------------------------------
#
# Project created by QtCreator 2018-09-17T13:26:02
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = reptile
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    abstract_reptile.cpp \
    reptile.cpp

HEADERS  += mainwindow.h \
    abstract_reptile.h \
    reptile.h

FORMS    += mainwindow.ui

CONFIG +=c++11
