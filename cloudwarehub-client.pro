#-------------------------------------------------
#
# Project created by QtCreator 2016-03-10T15:28:10
#
#-------------------------------------------------

QT       += core gui network 

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cloudwarehub-client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cipclient.cpp \
    cipchannel.cpp \
    cipchannelmaster.cpp \
    cloudwaredialog.cpp \
    cipchannelevent.cpp \
    cipchanneldisplay.cpp

HEADERS  += mainwindow.h \
    cipchannel.h \
    cipchannelmaster.h \
    cipclient.h \
    cip_protocol.h \
    cip_defs.h \
    cloudwaredialog.h \
    cipchannelevent.h \
    cipchanneldisplay.h

FORMS    += mainwindow.ui \
    cloudwaredialog.ui

INCLUDEPATH += /usr/local/include
