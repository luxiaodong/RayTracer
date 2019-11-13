#ifndef CAMERA_H
#define CAMERA_H

#include <QVector2D>
#include "ray.h"

class Camera
{
public:
    Camera();
    void setEye(float eye);
    float eye();
    virtual Ray ray(QVector2D pt) = 0;

protected:
    float m_eye;
};

#endif // CAMERA_H
