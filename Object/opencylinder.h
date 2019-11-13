#ifndef OPENCYLINDER_H
#define OPENCYLINDER_H

#include "abstractobject.h"

class OpenCylinder : public AbstractObject
{
public:
    OpenCylinder();
    OpenCylinder(QVector3D o, float h, float r);
    virtual ~OpenCylinder();
    virtual bool hit(const Ray& ray);

private:
    QVector3D m_origin;
    QVector3D m_normal;
    float m_height;
    float m_radius;
};

#endif // OPENCYLINDER_H
