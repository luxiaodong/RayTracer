#ifndef NROOKS_H
#define NROOKS_H

#include "sampler.h"

class NRooks : public Sampler
{
public:
    NRooks();

public:
    virtual void generate();

private:
    void shuffle_x_coordinates();
    void shuffle_y_coordinates();
};

#endif // NROOKS_H
