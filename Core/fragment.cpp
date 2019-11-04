#include "fragment.h"

Fragment::Fragment(Ray ray)
{
    m_ray = ray;
}

void Fragment::setColor(QColor &c)
{
    m_color = c;
}

void Fragment::setNormal(QVector3D &n)
{
    m_normal = n;
}
