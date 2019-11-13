#include "checkerboardplane.h"
#include <QQuaternion>
#include <QDebug>
#include <QtMath>

CheckerboardPlane::CheckerboardPlane():Plane()
{
}

CheckerboardPlane::CheckerboardPlane(QVector3D o, QVector3D n):Plane(o, n)
{}

CheckerboardPlane::~CheckerboardPlane()
{}

bool CheckerboardPlane::hit(const Ray& ray)
{
    float s = QVector3D::dotProduct(ray.m_direction, m_normal);
    if(qAbs(s) < kEpsilon)
    {
        return false;
    }

    float t =  QVector3D::dotProduct(m_origin - ray.m_origin, m_normal)/s;
    if(t > kEpsilon)
    {
        m_fragment = new Fragment(ray);
        m_fragment->m_t = t;
        m_fragment->m_color = this->color(ray.m_origin + ray.m_direction*t);
        return true;
    }

    return false;
}

QColor CheckerboardPlane::color(QVector3D pos)
{
    int cell = 16;
    QQuaternion q = QQuaternion::rotationTo(m_normal, QVector3D(0,1,0));
    QVector3D out = q.rotatedVector(pos);
    int x = qFloor(out.x()/cell);
    int y = qFloor(out.z()/cell);
//    int x = qFloor( (out.x() + out.z())/cell );
//    int y = qFloor( (out.x() - out.z())/cell );

    if((x+y)%2 == 0)
    {
        return QColor(0,0,0,255);
    }

    return QColor(255,255,255,255);
}
