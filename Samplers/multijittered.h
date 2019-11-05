#ifndef MULTIJITTERED_H
#define MULTIJITTERED_H

#include "sampler.h"

class MultiJittered : public Sampler
{
public:
    MultiJittered();

    virtual void generate();
};

#endif // MULTIJITTERED_H
