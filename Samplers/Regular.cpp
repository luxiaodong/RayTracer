#include "regular.h"

Regular::Regular()
{
    m_number = 1;
}

void Regular::setNumber(int num)
{
    m_number = num;
}

void Regular::generate()
{
    int n = m_number;
    for (int p = 0; p < n; p++)
    {
        for (int q = 0; q < n; q++)
        {
            m_samplers.append( QPointF( (q + 0.5)/n, (p + 0.5)/n) );
        }
    }
}
