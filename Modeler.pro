#-------------------------------------------------
#
# Project created by QtCreator 2016-08-23T17:08:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    setupsimulation.cpp \
    stackedwidget.cpp \
    selectworkingdirectory.cpp \
    startscreen.cpp \
    setupmap.cpp \
    modeler.cpp \
    heatmap.c \
    lodepng.cpp \
    setupoutput.cpp \
    loadingscreen.cpp \
    postscreen.cpp \
    advancedoptions.cpp

HEADERS  += mainwindow.h \
    setupsimulation.h \
    stackedwidget.h \
    selectworkingdirectory.h \
    startscreen.h \
    setupmap.h \
    modeler.h \
    CImg.h \
    lodepng.h \
    setupoutput.h \
    loadingscreen.h \
    postscreen.h \
    advancedoptions.h


FORMS    += mainwindow.ui \
    setupsimulation.ui \
    stackedwidget.ui \
    selectworkingdirectory.ui \
    startscreen.ui \
    setupmap.ui \
    setupoutput.ui \
    loadingscreen.ui \
    postscreen.ui \
    advancedoptions.ui
