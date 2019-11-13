#include "raytracer.h"
#include "fragment.h"
#include <QDebug>
#include <QVector4D>
#include <QtMath>

#include "orthographic.h"
#include "perspective.h"
#include "pinhole.h"
#include "pinhole.h"
#include "thinlens.h"
#include "fisheye.h"

RayTracer::RayTracer()
{
}

void RayTracer::build()
{
    m_panelView.setSize(QSize(200,200));
    m_panelView.setPixelSize(1);
    m_world.build();
}

void RayTracer::render()
{
    QSize s = m_panelView.size();
    m_image = new QImage(s, QImage::Format_RGBA8888);

//    Perspective* camera = new Perspective();
//    Orthographic* camera = new Orthographic();
//    Pinhole* camera = new Pinhole();
//    ThinLens* camera = new ThinLens();
    Fisheye* camera = new Fisheye();
//    camera->setViewSize( m_panelView.size() );
    camera->setEye(100);
    m_camera = camera;

    for(int j = 0; j < s.height(); ++j)
    {
        for(int i = 0; i < s.width(); ++i)
        {
            QVector4D color(0,0,0,0);
            foreach (QVector2D spt, m_panelView.m_sampler->m_samplers)
            {
                QVector2D pt = m_panelView.convertPoint(QVector2D(i,j) + spt);
                Ray ray = m_camera->ray(pt);
                QColor hitColor = m_panelView.backgroundColor();
                if(m_camera->isValidRay())
                {
                    if(m_world.hit(ray))
                    {
                        hitColor = m_world.fragment()->m_color;
                    }
                }

//                pt = QVector2D(i*1.0/40,j*1.0/40);
//                float c = 0.5*(1+qSin(pt.x()*pt.x()*pt.y()*pt.y()))*255;
//                hitColor = QColor(c,c,c,255);

                color.setX( color.x() + hitColor.red() );
                color.setY( color.y() + hitColor.green() );
                color.setZ( color.z() + hitColor.blue() );
                color.setW( color.w() + hitColor.alpha() );
            }

            int count = m_panelView.m_sampler->m_samplers.count();
            QColor avagerColor = QColor(color.x()/count, color.y()/count,color.z()/count,color.w()/count);
            this->writeToImage(i, j, avagerColor);
        }
    }
}

void RayTracer::writeToImage(int i, int j, QColor color)
{
    m_image->setPixelColor(i, m_panelView.size().height() - j - 1, color);
}
