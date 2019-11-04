#include "ray.h"

Ray::Ray()
{
    m_origin = QVector3D(0,0,0);
    m_direction = QVector3D(0,0,-1);
}

void Ray::setOrigin(QVector3D &o)
{
    m_origin = o;
}

void Ray::setDirection(QVector3D &d)
{
    m_direction = d;
}
