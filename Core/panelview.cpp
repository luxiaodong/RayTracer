#include "panelview.h"
#include "regular.h"
#include "random.h"

PanelView::PanelView()
{
    m_size = QSize(200,200);
    m_pixelSize = 1.0;
    m_backgroundColor = QColor(0,0,0);

//    Sampler* s = new Sampler();
    Regular* s = new Regular();
    s->setNumber(4);
//    Random* s = new Random();
//    s->setNumber(1);

    s->generate();
    m_sampler = s;
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

QPointF PanelView::convertPoint(QPointF pt)
{
    float fx = m_pixelSize*(pt.x() - m_size.width()/2.0);
    float fy = m_pixelSize*(pt.y() - m_size.height()/2.0);
    return QPointF(fx, fy);
}

