#include "sphere.h"
#include <QDebug>

Sphere::Sphere():AbstractObject()
{
    m_origin = QVector3D(0,0,0);
    m_radius = 1.0;
}

Sphere::Sphere(QVector3D o, float r):AbstractObject()
{
    m_origin = o;
    m_radius = r;
}

Sphere::~Sphere()
{}

bool Sphere::hit(const Ray& ray)
{
    double      t;
    QVector3D   temp = ray.m_origin - m_origin;
    double 		a = QVector3D::dotProduct(ray.m_direction, ray.m_direction);
    double 		b = 2.0 * QVector3D::dotProduct(temp, ray.m_direction);
    double 		c = QVector3D::dotProduct(temp, temp) - m_radius * m_radius;
    double 		delta = b * b - 4.0 * a * c;

    if(delta > 0)
    {
        double e = qSqrt(delta);
        double denom = 2.0*a;
        t = (-b - e) / denom;    // smaller root
        if(t > kEpsilon)
        {
            m_fragment = new Fragment(ray);
            m_fragment->m_t = t;
            m_fragment->m_color = m_color;
            return true;
        }

        t = (-b + e) / denom;    // larger root
        if(t > kEpsilon)
        {
            m_fragment = new Fragment(ray);
            m_fragment->m_t = t;
            m_fragment->m_color = m_color;
            return true;
        }
    }

    return false;
}
