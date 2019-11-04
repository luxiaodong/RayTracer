#include "random.h"
#include <QTime>

Random::Random()
{
    m_number = 1;
}

void Random::setNumber(int num)
{
    m_number = num;
}

void Random::generate()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int n = m_number;
    for (int p = 0; p < n; p++)
    {
        m_samplers.append(QPointF(randomOne(), randomOne()));
    }
}

float Random::randomOne()
{
    int a = qrand()%1000;
    return a*1.0/1000;
}
