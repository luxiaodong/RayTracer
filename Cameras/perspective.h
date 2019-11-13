#ifndef PERSPECTIVE_H
#define PERSPECTIVE_H

#include "camera.h"

class Perspective : public Camera
{
public:
    Perspective();
    virtual Ray ray(QVector2D pt);
};

#endif // PERSPECTIVE_H
