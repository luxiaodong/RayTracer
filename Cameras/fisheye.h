#ifndef FISHEYE_H
#define FISHEYE_H

#include "camera.h"
#include <QSize>

class Fisheye : public Camera
{
public:
    Fisheye();

public:
    void setViewSize(QSize size);
    virtual Ray ray(QVector2D pt);
    virtual bool isValidRay();

private:
    QSize m_size;
    float m_maxAngle;
    bool m_isVaildRay;
};

#endif // FISHEYE_H
