#ifndef REGULAR_H
#define REGULAR_H

#include "sampler.h"

class Regular : public Sampler
{
public:
    Regular();

public:
    void setNumber(int num);
    virtual void generate();

private:
    int m_number;
};

#endif // REGULAR_H
