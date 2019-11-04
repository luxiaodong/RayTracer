#ifndef PLANE_H
#define PLANE_H

#include "abstractobject.h"
#include <QVector3D>

class Plane : public AbstractObject
{
public:
    Plane();
    Plane(QVector3D o, QVector3D n);
    virtual ~Plane();
    virtual bool hit(const Ray& ray);

public:
    QVector3D m_origin;
    QVector3D m_normal;
};

#endif // PLANE_H
