#ifndef ORTHOGRAPHIC_H
#define ORTHOGRAPHIC_H

#include "camera.h"

class Orthographic : public Camera
{
public:
    Orthographic();
    virtual Ray ray(QVector2D pt);
};

#endif // ORTHOGRAPHIC_H
