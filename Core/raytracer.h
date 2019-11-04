#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <QImage>
#include "world.h"
#include "panelview.h"

class RayTracer
{
public:
    RayTracer();
    QImage* image(){return m_image;}
    void build();
    void render();

private:
    void writeToImage(int i, int j, QColor c);

private:
    QImage* m_image;
    World m_world;
    PanelView m_panelView;
};

#endif // RAYTRACER_H
