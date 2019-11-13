#include "perspective.h"

Perspective::Perspective()
{

}

Ray Perspective::ray(QVector2D pt)
{
    Ray ray;
    ray.m_origin = QVector3D(0, 0, m_eye);
    ray.m_direction = QVector3D(pt.x(), pt.y(), -m_eye).normalized();
    return ray;
}
