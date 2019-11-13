#ifndef TORUS_H
#define TORUS_H

#include "abstractobject.h"

class Torus : public AbstractObject
{
public:
    Torus();
    Torus(QVector3D o, float r, float tr);
    virtual ~Torus();
    virtual bool hit(const Ray& ray);

private:
    QVector3D m_origin;
    QVector3D m_normal;
    float m_radius;
    float m_tubeRadius;
};

#endif // TORUS_H
