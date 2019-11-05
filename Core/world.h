#ifndef WORLD_H
#define WORLD_H

#include <QList>
#include "abstractobject.h"
#include "fragment.h"

class World
{
public:
    World();

public:
    void build();
    bool hit(Ray ray);
    Fragment* fragment(){return m_fragment;}

private:
    void buildSingleSphere();
    void buildMultipleObjects();
    void buildBBCoverPic();
    void buildCheckboard();

private:
    QList<AbstractObject*> m_objects;
    Fragment* m_fragment;
};

#endif // WORLD_H
