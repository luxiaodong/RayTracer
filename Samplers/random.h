#ifndef RANDOM_H
#define RANDOM_H

#include "sampler.h"

class Random : public Sampler
{
public:
    Random();

public:
    virtual void generate();
};

#endif // RANDOM_H
