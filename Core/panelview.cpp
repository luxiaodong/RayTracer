#include "panelview.h"

PanelView::PanelView()
{
    m_size = QSize(200,200);
    m_pixelSize = 1.0;
    m_backgroundColor = QColor(0,0,0);
}

void PanelView::setSize(QSize size)
{
    m_size = size;
}

void PanelView::setPixelSize(float pixelSize)
{
    m_pixelSize = pixelSize;
}

void PanelView::setBackgroundColor(QColor &c)
{
    m_backgroundColor = c;
}

Ray PanelView::ray(int x, int y)
{
    Ray ray;
    float fx = m_pixelSize*(x*1.0 - m_size.width()/2.0 + 0.5);
    float fy = m_pixelSize*(y*1.0 - m_size.height()/2.0 + 0.5);
    ray.m_origin = QVector3D(fx, fy, 100);
    ray.m_direction = QVector3D(0,0,-1);
    return ray;
}
