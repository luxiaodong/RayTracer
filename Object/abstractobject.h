#ifndef ABSTRACTOBJECT_H
#define ABSTRACTOBJECT_H

#include <QColor>
#include <QtMath>

#include "ray.h"
#include "define.h"
#include "fragment.h"

class AbstractObject
{
public:
    AbstractObject();
    virtual ~AbstractObject();

    virtual bool hit(const Ray& ray);
    Fragment* fragment();
    void setColor(QColor r);

    Fragment* m_fragment;
    QColor m_color;
};

#endif // ABSTRACTOBJECT_H
