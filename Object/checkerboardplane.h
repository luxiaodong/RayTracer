#ifndef CHECKERBOARDPLANE_H
#define CHECKERBOARDPLANE_H

#include "plane.h"

class CheckerboardPlane : public Plane
{
public:
    CheckerboardPlane();
    CheckerboardPlane(QVector3D o, QVector3D n);
    virtual ~CheckerboardPlane();
    virtual bool hit(const Ray& ray);

private:
    QColor color(QVector3D v);
};

#endif // CHECKERBOARDPLANE_H
