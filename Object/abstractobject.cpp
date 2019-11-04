#include "abstractobject.h"

AbstractObject::AbstractObject()
{
    m_color = QColor(255,0,255);
}

AbstractObject::~AbstractObject()
{}

bool AbstractObject::hit(const Ray& ray)
{
    (void)ray;
    return false;
}

Fragment* AbstractObject::fragment()
{
    return m_fragment;
}

void AbstractObject::setColor(QColor r)
{
    m_color = r;
}

