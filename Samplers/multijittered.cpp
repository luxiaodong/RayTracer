#include "multijittered.h"

MultiJittered::MultiJittered()
{

}

void MultiJittered::generate()
{
    int n = m_number;
    for (int p = 0; p < n; p++)
    {
        for (int q = 0; q < n; q++)
        {
            m_samplers.append( QVector2D( (q + randomOne())/n, (p + randomOne())/n) );
        }
    }
}
