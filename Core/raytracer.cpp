#include "raytracer.h"
#include "fragment.h"
#include <QDebug>

RayTracer::RayTracer()
{

}

void RayTracer::build()
{
    m_panelView.setSize(QSize(400,400));
    m_panelView.setPixelSize(0.5);
    m_world.build();
}

void RayTracer::render()
{
    QSize s = m_panelView.size();
    m_image = new QImage(s, QImage::Format_RGBA8888);

    for(int j = 0; j < s.height(); ++j)
    {
        for(int i = 0; i < s.width(); ++i)
        {
            Ray ray = m_panelView.ray(i,j);
            if(m_world.hit(ray))
            {
                this->writeToImage(i, j, m_world.fragment()->m_color);
            }
            else
            {
                this->writeToImage(i, j, m_panelView.backgroundColor());
            }
        }
    }
}

void RayTracer::writeToImage(int i, int j, QColor color)
{
    m_image->setPixelColor(i, m_panelView.size().height() - j - 1, color);
}
