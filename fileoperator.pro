#-------------------------------------------------
#
# Project created by QtCreator 2018-06-09T02:39:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fileoperator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    newfile.cpp \
    openfile.cpp \
    copyfile.cpp \
    deletefile.cpp \
    renamefile.cpp

HEADERS  += mainwindow.h \
    newfile.h \
    openfile.h \
    copyfile.h \
    deletefile.h \
    renamefile.h

FORMS    += mainwindow.ui \
    newfile.ui \
    openfile.ui \
    copyfile.ui \
    deletefile.ui \
    renamefile.ui
