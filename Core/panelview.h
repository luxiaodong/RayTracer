#ifndef PANELVIEW_H
#define PANELVIEW_H

#include <QSize>
#include <QColor>
#include <QVector3D>
#include <QPointF>

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

public:
    QSize size(){return m_size;}
    float pixelSize(){return m_pixelSize;}
    QColor backgroundColor(){return m_backgroundColor;}
    QPointF convertPoint(QPointF pt);

public:
    Sampler* m_sampler;

private:
    QColor m_backgroundColor;
    QSize m_size;
    float m_pixelSize;
};

#endif // PANELVIEW_H
