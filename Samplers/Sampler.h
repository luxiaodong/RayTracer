#ifndef SAMPLER_H
#define SAMPLER_H

#include <QVector3D>
#include <QPointF>
#include <QList>

class Sampler
{
public:
    Sampler();

public:
    virtual void generate();

public:
    QList<QPointF> m_samplers;
};

#endif // SAMPLER_H
