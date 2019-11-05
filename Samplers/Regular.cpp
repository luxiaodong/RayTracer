#include "regular.h"

Regular::Regular()
{
}

void Regular::generate()
{
    int n = m_number;
    for (int p = 0; p < n; p++)
    {
        for (int q = 0; q < n; q++)
        {
            m_samplers.append( QVector2D( (q + 0.5)/n, (p + 0.5)/n) );
        }
    }
}
