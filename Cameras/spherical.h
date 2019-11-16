#ifndef SPHERICAL_H
#define SPHERICAL_H

#include <camera.h>
#include <QSize>

class Spherical : public Camera
{
public:
    Spherical();
    void setViewSize(QSize size);
    virtual Ray ray(QVector2D pt);

private:
    QSize m_size;
    float m_maxHAngle;
    float m_maxVAngle;
};

#endif // SPHERICAL_H
