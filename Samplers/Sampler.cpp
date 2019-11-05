#include "sampler.h"
#include <QTime>
#include <QtMath>

Sampler::Sampler()
{
    m_number = 1;
}

void Sampler::setNumber(int num)
{
    m_number = num;
}

float Sampler::randomOne()
{
    int a = qrand()%1000;
    return a*1.0/1000;
}

QVector2D Sampler::maptoDisk(QVector2D pt)
{
    float r;
    float phi;
    QVector2D sp;
    sp.setX( 2*pt.x() - 1 );
    sp.setY( 2*pt.y() - 1 );

    if(sp.x() + sp.y() > 0 )
    {
        if(sp.x() > sp.y())
        {
            r = sp.x();
            phi = sp.y()/sp.x();
        }
        else
        {
            r = sp.y();
            phi = 2 - sp.x()/sp.y();
        }
    }
    else
    {
        if(sp.x() < sp.y())
        {
            r = -sp.x();
            phi = 4 + sp.y()/sp.x();
        }
        else
        {
            r = -sp.y();
            phi = 6 - sp.x()/sp.y();
        }
    }

    phi *= M_PI/4.0;
    sp.setX(r*qCos(phi));
    sp.setY(r*qSin(phi));
    return sp;
}


QVector3D Sampler::maptoHemisphere(QVector2D pt, float e)
{
    float cos_phi = qCos(2.0*M_PI*pt.x());
    float sin_phi = qSin(2.0*M_PI*pt.x());
    float cos_theta = qPow(1 - pt.y(), 1/(1+e));
    float sin_theta = qSqrt(1 - cos_theta*cos_theta);
    float pu = sin_theta * cos_phi;
    float pv = sin_theta * sin_phi;
    float pw = cos_theta;
    return QVector3D(pu, pv, pw);
}

void Sampler::generate()
{
    m_samplers.clear();
    m_samplers.append(QVector2D(0.5,0.5));
}
