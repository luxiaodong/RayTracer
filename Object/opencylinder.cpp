#include "opencylinder.h"

OpenCylinder::OpenCylinder()
{
    m_origin = QVector3D(0,0,0);
    m_normal = QVector3D(0,1,0);
    m_height = 2;
    m_radius = 1;
}

OpenCylinder::OpenCylinder(QVector3D o, float h, float r)
{
    m_origin = o;
    m_normal = QVector3D(0,0,1);
    m_height = h;
    m_radius = r;
}

OpenCylinder::~OpenCylinder()
{
}

bool OpenCylinder::hit(const Ray& ray)
{
    double      t;
    QVector3D   temp = ray.m_origin - m_origin;
    double      a = ray.m_direction.x()*ray.m_direction.x() + ray.m_direction.z()*ray.m_direction.z();
    double      b = 2.0*(ray.m_direction.x()*temp.x() + ray.m_direction.z()*temp.z());
    double      c = temp.x()*temp.x() + temp.z()*temp.z() - m_radius * m_radius;
    double 		delta = b * b - 4.0 * a * c;

    if(delta > 0)
    {
        double e = qSqrt(delta);
        double denom = 2.0*a;
        t = (-b - e) / denom;    // smaller root
        if(t > kEpsilon)
        {
            double y = ray.m_origin.y() + ray.m_direction.y()*t;
            if(y > m_origin.y() && y < m_origin.y() + m_height)
            {
                m_fragment = new Fragment(ray);
                m_fragment->m_t = t;
                m_fragment->m_color = m_color;
                return true;
            }
        }

        t = (-b + e) / denom;    // larger root
        if(t > kEpsilon)
        {
            double y = ray.m_origin.y() + ray.m_direction.y()*t;
            if(y > m_origin.y() && y < m_origin.y() + m_height)
            {
                m_fragment = new Fragment(ray);
                m_fragment->m_t = t;
                m_fragment->m_color = m_color;
                return true;
            }
        }
    }

    return false;




    return false;
}
