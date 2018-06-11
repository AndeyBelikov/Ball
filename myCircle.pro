#-------------------------------------------------
#
# Project created by QtCreator 2018-04-05T16:11:38
#
#-------------------------------------------------

QT      += core gui
QT      += testlib
QT      += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myCircle
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    circle.cpp \
    logic.cpp \
    exampleobject.cpp \
    database.cpp

HEADERS  += mainwindow.h \
    circle.h \
    logic.h \
    exampleobject.h \
    database.h

FORMS    += mainwindow.ui
