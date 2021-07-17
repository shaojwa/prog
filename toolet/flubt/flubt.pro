#-------------------------------------------------
#
# Project created by QtCreator 2016-07-14T23:46:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = flubt
TEMPLATE = app

HEADERS  += \
    include/backuper.h \
    include/config.h \
    include/frame.h \
    include/searcher.h \
    include/statebar.h \
    include/titlebar.h \
    include/toolbar.h \
    include/toolbutton.h \
    include/panelwin.h \
    include/extracter.h

FORMS    +=

SOURCES += \
    src/main.cpp \
    src/backuper.cpp \
    src/config.cpp \
    src/frame.cpp \    
    src/searcher.cpp \
    src/titlebar.cpp \
    src/statebar.cpp \
    src/toolbar.cpp \
    src/toolbutton.cpp \
    src/panelwin.cpp \
    src/extracter.cpp

DISTFILES += \
    scripts/copylog.sh \
    scripts/findlog.sh \
    scripts/findlog.bat

RESOURCES += \
    res.qrc


