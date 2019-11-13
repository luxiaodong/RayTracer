#include "pinhole.h"

Pinhole::Pinhole()
{
    m_imagePanel = 200;
}

Ray Pinhole::ray(QVector2D pt)
{
    Ray ray;
//    ray.m_origin = QVector3D(pt.x(), pt.y(), m_imagePanel);
    ray.m_origin = QVector3D(0, 0, m_eye);
    ray.m_direction = QVector3D(0 - pt.x(), 0 - pt.y(), m_eye - m_imagePanel).normalized();
    return ray;
}
