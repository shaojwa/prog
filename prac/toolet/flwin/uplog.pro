#-------------------------------------------------
#
# Project created by QtCreator 2016-07-06T14:28:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = uplog
TEMPLATE = app


SOURCES += main.cpp\
        frame.cpp \
    searcher.cpp \
    backuper.cpp \
    config.cpp

HEADERS  += frame.h \
    searcher.h \
    backuper.h \
    config.h

FORMS    += frame.ui
