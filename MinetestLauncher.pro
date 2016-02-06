#-------------------------------------------------
#
# Project created by QtCreator 2016-01-29T18:44:36
#
#-------------------------------------------------

QT       += core gui webkitwidgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MinetestLauncher
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    profile.cpp \
    profilemanager.cpp

HEADERS  += mainwindow.h \
    profile.h \
    profilemanager.h

FORMS    += mainwindow.ui
