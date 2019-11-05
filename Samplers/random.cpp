#include "random.h"
#include <QTime>
#include <QtMath>

Random::Random()
{
}

void Random::generate()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int n = m_number;
    for (int p = 0; p < n; p++)
    {
        m_samplers.append(QVector2D(randomOne(), randomOne()));
    }
}
