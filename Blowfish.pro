#-------------------------------------------------
#
# Project created by QtCreator 2014-09-07T12:42:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Blowfish
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qblowfish.cpp \
    qxorcipher.cpp

HEADERS  += mainwindow.h \
    HexPi.h \
    qblowfish.h \
    qxorcipher.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
