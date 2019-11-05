#ifndef PANELVIEW_H
#define PANELVIEW_H

#include <QSize>
#include <QColor>
#include <QVector3D>
#include <QVector2D>

#include "ray.h"
#include "sampler.h"

class PanelView
{
public:
    PanelView();

public:
    void setSize(QSize size);
    void setPixelSize(float pixelSize);
    void setBackgroundColor(QColor &c);
    float eye(){return m_eye;}

public:
    QSize size(){return m_size;}
    float pixelSize(){return m_pixelSize;}
    QColor backgroundColor(){return m_backgroundColor;}
    QVector2D convertPoint(QVector2D pt);

public:
    Sampler* m_sampler;

private:
    QColor m_backgroundColor;
    QSize m_size;
    float m_pixelSize;
    float m_eye;
};

#endif // PANELVIEW_H
