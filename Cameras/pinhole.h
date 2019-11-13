#ifndef PINHOLE_H
#define PINHOLE_H

#include "camera.h"

class Pinhole : public Camera
{
public:
    Pinhole();
    virtual Ray ray(QVector2D pt);

protected:
    float m_imagePanel;
};

#endif // PINHOLE_H
