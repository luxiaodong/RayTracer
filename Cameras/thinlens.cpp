#include "thinlens.h"
#include "random.h"

ThinLens::ThinLens()
{
    m_focusPanel = -100;
    m_lensRadius = 10;

    m_sampler = new Random();
}

Ray ThinLens::ray(QVector2D pt)
{
    float f = m_eye - m_focusPanel;
    float d = m_eye;
    QVector2D focusPt;
    focusPt.setX(pt.x()*f/d);
    focusPt.setY(pt.y()*f/d);

    m_sampler->generate();
    QVector2D lensPt = m_sampler->maptoDisk(m_sampler->m_samplers[0])*m_lensRadius;
    Ray ray;
    ray.m_origin = QVector3D(lensPt.x(), lensPt.y(), m_eye);
    ray.m_direction = QVector3D(focusPt.x() - lensPt.x(), focusPt.y() - lensPt.y(), m_focusPanel - m_eye).normalized();
    return ray;
}
