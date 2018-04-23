#-------------------------------------------------
#
# Project created by QtCreator 2018-01-29T12:06:51
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11
INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HW1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ray.cpp \
    camera.cpp \
    primitive.cpp \
    shape.cpp \
    transform.cpp \
    intersection.cpp \
    scene.cpp \
    sphere.cpp \
    squareplane.cpp

HEADERS  += mainwindow.h \
    globalincludes.h \
    ray.h \
    camera.h \
    primitive.h \
    shape.h \
    transform.h \
    intersection.h \
    scene.h \
    sphere.h \
    squareplane.h

FORMS    += mainwindow.ui
