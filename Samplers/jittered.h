#ifndef JITTERED_H
#define JITTERED_H

#include "sampler.h"

class Jittered : public Sampler
{
public:
    Jittered();

public:
    virtual void generate();
};

#endif // JITTERED_H
