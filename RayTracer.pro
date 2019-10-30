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

INCLUDEPATH += Utilities \
    Maths \
    Materials \
    World \
    Tracers \
    GeometricObjects \
    GeometricObjects/Primitives \


SOURCES += main.cpp\
        widget.cpp \
    Maths/Maths.cpp \
    Utilities/RGBColor.cpp \
    Maths/Point2D.cpp \
    Maths/Point3D.cpp \
    Maths/Vector3D.cpp \
    Maths/Matrix.cpp \
    Maths/Normal.cpp \
    GeometricObjects/GeometricObject.cpp \
    Materials/Material.cpp \
    World/ViewPlane.cpp \
    World/World.cpp \
    Tracers/Tracer.cpp \
    Utilities/BBox.cpp \
    GeometricObjects/Primitives/Plane.cpp \
    GeometricObjects/Primitives/Sphere.cpp \
    Utilities/Ray.cpp \
    Utilities/ShadeRec.cpp

HEADERS  += widget.h \
    Maths/Constants.h \
    Maths/Maths.h \
    Utilities/RGBColor.h \
    Maths/Point2D.h \
    Maths/Point3D.h \
    Maths/Vector3D.h \
    Maths/Matrix.h \
    Maths/Normal.h \
    GeometricObjects/GeometricObject.h \
    Materials/Material.h \
    World/ViewPlane.h \
    World/World.h \
    Tracers/Tracer.h \
    Utilities/BBox.h \
    GeometricObjects/Primitives/Plane.h \
    GeometricObjects/Primitives/Sphere.h

FORMS    += widget.ui
