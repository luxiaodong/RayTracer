#ifndef SAMPLER_H
#define SAMPLER_H

#include <QVector3D>
#include <QVector2D>
#include <QList>

class Sampler
{
public:
    Sampler();

public:
    float randomOne();
    void setNumber(int num);
    virtual void generate();

    QVector2D maptoDisk(QVector2D pt);
    QVector3D maptoHemisphere(QVector2D pt, float e);

public:
    QList<QVector2D> m_samplers;

protected:
    int m_number;
};

#endif // SAMPLER_H
