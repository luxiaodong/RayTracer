#include "fisheye.h"
#include <QtMath>
#include <QSize>

Fisheye::Fisheye()
{
    m_maxAngle = 0.5*M_PI;
    m_isVaildRay = true;
    m_size = QSize(200,200);
    //panelview m_pixelSize must 1
}

void Fisheye::setViewSize(QSize size)
{
    m_size = size;
}

Ray Fisheye::ray(QVector2D pt)
{
    QVector2D unitPt;
    unitPt.setX(pt.x()*2/m_size.width());
    unitPt.setY(pt.y()*2/m_size.height());

    float r = unitPt.length();
    if(r > 1)
    {
        m_isVaildRay = false;
        return Ray();
    }

    float psi = r*m_maxAngle;
    float sin_psi = qSin(psi);
    float cos_psi = qCos(psi);
    float sin_alpha = unitPt.y()/r;
    float cos_alpha = unitPt.x()/r;

    Ray ray;
    ray.m_origin = QVector3D(0,0,m_eye);
    ray.m_direction = QVector3D(sin_psi*cos_alpha, sin_psi*sin_alpha, -1.0*cos_psi).normalized(); //-1.0是因为光线朝向z轴负方向
    m_isVaildRay = true;
    return ray;
}

bool Fisheye::isValidRay()
{
    return m_isVaildRay;
}
