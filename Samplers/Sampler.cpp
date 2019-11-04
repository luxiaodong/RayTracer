#include "sampler.h"

Sampler::Sampler()
{

}

void Sampler::generate()
{
    m_samplers.clear();
    m_samplers.append(QPointF(0.5,0.5));
}
