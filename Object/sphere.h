#ifndef SPHERE_H
#define SPHERE_H

#include "abstractobject.h"

class Sphere : public AbstractObject
{
public:
    Sphere();
    Sphere(QVector3D o, float r);
    virtual ~Sphere();
    virtual bool hit(const Ray& ray);

public:
    QVector3D m_origin;
    float m_radius;
};

#endif // SPHERE_H
