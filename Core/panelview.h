#ifndef PANELVIEW_H
#define PANELVIEW_H

#include <QSize>
#include <QColor>
#include <QVector2D>

#include "ray.h"

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
    Ray  ray(int x, int y);

private:
    QColor m_backgroundColor;
    QSize m_size;
    float m_pixelSize;
};

#endif // PANELVIEW_H
