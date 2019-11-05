#include "plane.h"

Plane::Plane():AbstractObject()
{
    m_origin = QVector3D(0,0,0);
    m_normal = QVector3D(0,0,1);
}

Plane::Plane(QVector3D o, QVector3D d):AbstractObject()
{
    m_origin = o;
    m_normal = d;
}

Plane::~Plane()
{
}

bool Plane::hit(const Ray& ray)
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
        m_fragment->m_color = m_color;
        return true;
    }

    return false;
}
