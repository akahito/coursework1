#-------------------------------------------------
#
# Project created by QtCreator 2015-04-30T17:40:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = coursework
TEMPLATE = app


SOURCES +=\
    MainWindow.cpp \
    Main.cpp \
    QuickSort.cpp \
    MergeSort.cpp \
    ShellSort.cpp \
    SortThread.cpp \
    SortAlgorithm.cpp

HEADERS  += \
    MainWindow.h \
    QuickSort.h \
    MergeSort.h \
    ShellSort.h \
    SortThread.h \
    SortAlgorithm.h \
    SortMethod.h \
    SortType.h

#CONFIG  += qt warn_off release
#DEFINES += QT_NO_DEBUG_OUTPUT
#DEFINES += QT_NO_DEBUG

FORMS    += mainwindow.ui
