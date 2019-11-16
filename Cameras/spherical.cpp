#include "spherical.h"
#include <QtMath>

Spherical::Spherical()
{
    m_maxHAngle = M_PI;
    m_maxVAngle = 0.5*M_PI;
}

void Spherical::setViewSize(QSize size)
{
    m_size = size;
}

Ray Spherical::ray(QVector2D pt)
{
    QVector2D unitPt;
    unitPt.setX(pt.x()*2/m_size.width());
    unitPt.setY(pt.y()*2/m_size.height());

    float psi = M_PI - unitPt.x()*m_maxHAngle;
    float alpha = 0.5*M_PI - unitPt.y()*m_maxVAngle;

    float sin_psi = qSin(psi);
    float cos_psi = qCos(psi);
    float sin_alpha = qSin(alpha);
    float cos_alpha = qCos(alpha);

    Ray ray;
    ray.m_origin = QVector3D(0,0,m_eye);
    ray.m_direction = QVector3D(sin_alpha*sin_psi, cos_alpha, sin_alpha*cos_psi).normalized();
    return ray;
}
