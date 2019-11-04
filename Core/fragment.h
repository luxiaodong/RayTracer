#ifndef FRAGMENT_H
#define FRAGMENT_H

#include <QColor>
#include <QVector3D>

#include "ray.h"

class Fragment
{
public:
    Fragment(Ray ray);
    void setColor(QColor &c);
    void setNormal(QVector3D &n);

public:
    Ray m_ray;
    float m_t;
    QColor m_color;
    QVector3D m_normal;
};

#endif // FRAGMENT_H
