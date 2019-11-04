#ifndef RAY_H
#define RAY_H

#include <QVector3D>

class Ray
{
public:
    Ray();

public:
    void setOrigin(QVector3D &o);
    void setDirection(QVector3D &d);

public:
    QVector3D m_origin;
    QVector3D m_direction;
};

#endif // RAY_H
