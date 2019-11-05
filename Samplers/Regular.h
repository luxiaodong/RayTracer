#ifndef REGULAR_H
#define REGULAR_H

#include "sampler.h"

class Regular : public Sampler
{
public:
    Regular();

public:
    virtual void generate();
};

#endif // REGULAR_H
