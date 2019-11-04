#ifndef RANDOM_H
#define RANDOM_H

#include "sampler.h"

class Random : public Sampler
{
public:
    Random();

public:
    float randomOne();
    void setNumber(int num);
    virtual void generate();

private:
    int m_number;
};

#endif // RANDOM_H
