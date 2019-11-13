#ifndef THINLENS_H
#define THINLENS_H

#include "camera.h"
#include "sampler.h"

class ThinLens : public Camera
{
public:
    ThinLens();
    virtual Ray ray(QVector2D pt);

private:
    float m_focusPanel;
    float m_lensRadius;
    Sampler* m_sampler;
};

#endif // THINLENS_H
