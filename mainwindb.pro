#-------------------------------------------------
#
# Project created by QtCreator 2015-09-24T18:59:50
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mainwindb
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    dialogupdate.cpp \
    dialogsearch.cpp \
    dialoglogin.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    dialogupdate.h \
    dialogsearch.h \
    dialoglogin.h

FORMS    += mainwindow.ui \
    dialog.ui \
    dialogupdate.ui \
    dialogsearch.ui \
    dialoglogin.ui
