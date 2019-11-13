#include "orthographic.h"

Orthographic::Orthographic()
{

}

Ray Orthographic::ray(QVector2D pt)
{
    Ray ray;
    ray.m_origin = QVector3D(pt.x(), pt.y(), 100);
    ray.m_direction = QVector3D(0,0,-1);
    return ray;
}
