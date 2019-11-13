#include "panelview.h"
#include "regular.h"
#include "random.h"
#include "jittered.h"
#include "nrooks.h"

PanelView::PanelView()
{
    m_size = QSize(200,200);
    m_pixelSize = 1.0;
    m_backgroundColor = QColor(0,0,0);

//    Sampler* s = new Sampler();
//    Regular* s = new Regular();
    Jittered* s = new Jittered();
//    NRooks* s = new NRooks();
//    Random* s = new Random();
//    s->setNumber(1);

    s->setNumber(2);
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

QVector2D PanelView::convertPoint(QVector2D pt)
{
    float fx = m_pixelSize*(pt.x() - m_size.width()/2.0);
    float fy = m_pixelSize*(pt.y() - m_size.height()/2.0);
    return QVector2D(fx, fy);
}

