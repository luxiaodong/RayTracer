#-------------------------------------------------
#
# Project created by QtCreator 2019-10-23T11:30:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RayTracer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += Core \
    Object \
    Maths \
    Samplers

SOURCES += main.cpp\
        widget.cpp \
    Core/raytracer.cpp \
    Core/panelview.cpp \
    Core/world.cpp \
    Core/ray.cpp \
    Object/abstractobject.cpp \
    Object/plane.cpp \
    Object/sphere.cpp \
    Core/fragment.cpp \
    Samplers/sampler.cpp \
    Samplers/regular.cpp \
    Samplers/random.cpp

HEADERS  += widget.h \
    Core/raytracer.h \
    Core/panelview.h \
    Core/world.h \
    Core/ray.h \
    Object/abstractobject.h \
    Object/plane.h \
    Object/sphere.h \
    Core/fragment.h \
    Maths/define.h \
    Samplers/sampler.h \
    Samplers/regular.h \
    Samplers/random.h

FORMS    += widget.ui
