#include "nrooks.h"

NRooks::NRooks()
{
}

void NRooks::generate()
{
    int n = m_number;
    for (int p = 0; p < n; p++)
    {
        m_samplers.append( QVector2D( (p + randomOne())/n, (p + randomOne())/n) );
    }

    shuffle_x_coordinates();
    shuffle_y_coordinates();
}

void NRooks::shuffle_x_coordinates()
{
    int n = m_number;
    for (int i = n - 1; i > 0; i--)
    {
        int target = qrand()%i;
        float temp = m_samplers[i].x();
        m_samplers[i].setX( m_samplers[target].x() );
        m_samplers[target].setX(temp);
    }
}

void NRooks::shuffle_y_coordinates()
{
    int n = m_number;
    for (int i = n - 1; i > 0; i--)
    {
        int target = qrand()%i;
        float temp = m_samplers[i].y();
        m_samplers[i].setY( m_samplers[target].y() );
        m_samplers[target].setY(temp);
    }
}



