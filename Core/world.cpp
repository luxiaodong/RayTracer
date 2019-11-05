#include "world.h"

#include "plane.h"
#include "sphere.h"
#include "checkerboardplane.h"

World::World()
{
}

void World::build()
{
    m_objects.clear();
    this->buildCheckboard();
    //this->buildSingleSphere();
    //this->buildMultipleObjects();
    //this->buildBBCoverPic();
}

bool World::hit(Ray ray)
{
    m_fragment = NULL;
    foreach (AbstractObject* obj, m_objects)
    {
        if(obj->hit(ray))
        {
            if(m_fragment)
            {
                if(m_fragment->m_t > obj->fragment()->m_t)
                {
                    m_fragment = obj->fragment();
                }
            }
            else
            {
                m_fragment = obj->fragment();
            }
        }
    }

    if(m_fragment)
    {
        return true;
    }

    return false;
}

void World::buildSingleSphere()
{
    AbstractObject* s = new Sphere(QVector3D(0,0,-400), 15);
    s->setColor(QColor(255,0,0));
    m_objects.append(s);
}

void World::buildMultipleObjects()
{
    AbstractObject* s = new Sphere(QVector3D(0,-25,0), 80);
    s->setColor(QColor(255,0,0));
    m_objects.append(s);

    s = new Sphere(QVector3D(0,30,0), 60);
    s->setColor(QColor(255,255,0));
    m_objects.append(s);

    s = new Plane(QVector3D(0,0,0), QVector3D(0,1,1));
    s->setColor(QColor(0,255*0.3,0));
    m_objects.append(s);
}

void World::buildCheckboard()
{
    AbstractObject* s = new CheckerboardPlane(QVector3D(0,0,0), QVector3D(0,1,1));
    m_objects.append(s);
}

void World::buildBBCoverPic()
{
    QColor yellow = QColor(255,255,0);
    QColor brown = QColor(0.71*255, 0.40*255, 0.16*255);
    QColor dark_green = QColor(0.0*255, 0.41*255, 0.41*255);
    QColor orange = QColor(255,0.75*255, 0);
    QColor green = QColor(255,255*0.6,255*0.3);
    QColor light_green = QColor(255*0.65,255,255*0.3);
    QColor dark_yellow = QColor(255*0.61,255*0.61,0);
    QColor light_purple = QColor(255*0.65,255*0.3,255);
    QColor dark_purple = QColor(0.5*255, 0 ,255);

    Sphere*	sphere_ptr1 = new Sphere(QVector3D(5, 3, 0), 30);
    sphere_ptr1->setColor(yellow);	   								// yellow
    m_objects.append(sphere_ptr1);

    Sphere*	sphere_ptr2 = new Sphere(QVector3D(45, -7, -60), 20);
    sphere_ptr2->setColor(brown);									// brown
    m_objects.append(sphere_ptr2);

    Sphere*	sphere_ptr3 = new Sphere(QVector3D(40, 43, -100), 17);
    sphere_ptr3->setColor(dark_green);								// dark green
    m_objects.append(sphere_ptr3);

    Sphere*	sphere_ptr4 = new Sphere(QVector3D(-20, 28, -15), 20);
    sphere_ptr4->setColor(orange);									// orange
    m_objects.append(sphere_ptr4);

    Sphere*	sphere_ptr5 = new Sphere(QVector3D(-25, -7, -35), 27);
    sphere_ptr5->setColor(green);									// green
    m_objects.append(sphere_ptr5);

    Sphere*	sphere_ptr6 = new Sphere(QVector3D(20, -27, -35), 25);
    sphere_ptr6->setColor(light_green);								// light green
    m_objects.append(sphere_ptr6);

    Sphere*	sphere_ptr7 = new Sphere(QVector3D(35, 18, -35), 22);
    sphere_ptr7->setColor(green);   								// green
    m_objects.append(sphere_ptr7);

    Sphere*	sphere_ptr8 = new Sphere(QVector3D(-57, -17, -50), 15);
    sphere_ptr8->setColor(brown);									// brown
    m_objects.append(sphere_ptr8);

    Sphere*	sphere_ptr9 = new Sphere(QVector3D(-47, 16, -80), 23);
    sphere_ptr9->setColor(light_green);								// light green
    m_objects.append(sphere_ptr9);

    Sphere*	sphere_ptr10 = new Sphere(QVector3D(-15, -32, -60), 22);
    sphere_ptr10->setColor(dark_green);     						// dark green
    m_objects.append(sphere_ptr10);

    Sphere*	sphere_ptr11 = new Sphere(QVector3D(-35, -37, -80), 22);
    sphere_ptr11->setColor(dark_yellow);							// dark yellow
    m_objects.append(sphere_ptr11);

    Sphere*	sphere_ptr12 = new Sphere(QVector3D(10, 43, -80), 22);
    sphere_ptr12->setColor(dark_yellow);							// dark yellow
    m_objects.append(sphere_ptr12);

    Sphere*	sphere_ptr13 = new Sphere(QVector3D(30, -7, -80), 10);
    sphere_ptr13->setColor(dark_yellow);
    m_objects.append(sphere_ptr13);										// dark yellow (hidden)

    Sphere*	sphere_ptr14 = new Sphere(QVector3D(-40, 48, -110), 18);
    sphere_ptr14->setColor(dark_green); 							// dark green
    m_objects.append(sphere_ptr14);

    Sphere*	sphere_ptr15 = new Sphere(QVector3D(-10, 53, -120), 18);
    sphere_ptr15->setColor(brown); 								// brown
    m_objects.append(sphere_ptr15);

    Sphere*	sphere_ptr16 = new Sphere(QVector3D(-55, -52, -100), 10);
    sphere_ptr16->setColor(light_purple);							// light purple
    m_objects.append(sphere_ptr16);

    Sphere*	sphere_ptr17 = new Sphere(QVector3D(5, -52, -100), 15);
    sphere_ptr17->setColor(brown);									// browm
    m_objects.append(sphere_ptr17);

    Sphere*	sphere_ptr18 = new Sphere(QVector3D(-20, -57, -120), 15);
    sphere_ptr18->setColor(dark_purple);							// dark purple
    m_objects.append(sphere_ptr18);

    Sphere*	sphere_ptr19 = new Sphere(QVector3D(55, -27, -100), 17);
    sphere_ptr19->setColor(dark_green);								// dark green
    m_objects.append(sphere_ptr19);

    Sphere*	sphere_ptr20 = new Sphere(QVector3D(50, -47, -120), 15);
    sphere_ptr20->setColor(brown);									// browm
    m_objects.append(sphere_ptr20);

    Sphere*	sphere_ptr21 = new Sphere(QVector3D(70, -42, -150), 10);
    sphere_ptr21->setColor(light_purple);							// light purple
    m_objects.append(sphere_ptr21);

    Sphere*	sphere_ptr22 = new Sphere(QVector3D(5, 73, -130), 12);
    sphere_ptr22->setColor(light_purple);							// light purple
    m_objects.append(sphere_ptr22);

    Sphere*	sphere_ptr23 = new Sphere(QVector3D(66, 21, -130), 13);
    sphere_ptr23->setColor(dark_purple);							// dark purple
    m_objects.append(sphere_ptr23);

    Sphere*	sphere_ptr24 = new Sphere(QVector3D(72, -12, -140), 12);
    sphere_ptr24->setColor(light_purple);							// light purple
    m_objects.append(sphere_ptr24);

    Sphere*	sphere_ptr25 = new Sphere(QVector3D(64, 5, -160), 11);
    sphere_ptr25->setColor(green);					 				// green
    m_objects.append(sphere_ptr25);

    Sphere*	sphere_ptr26 = new Sphere(QVector3D(55, 38, -160), 12);
    sphere_ptr26->setColor(light_purple);							// light purple
    m_objects.append(sphere_ptr26);

    Sphere*	sphere_ptr27 = new Sphere(QVector3D(-73, -2, -160), 12);
    sphere_ptr27->setColor(light_purple);							// light purple
    m_objects.append(sphere_ptr27);

    Sphere*	sphere_ptr28 = new Sphere(QVector3D(30, -62, -140), 15);
    sphere_ptr28->setColor(dark_purple); 							// dark purple
    m_objects.append(sphere_ptr28);

    Sphere*	sphere_ptr29 = new Sphere(QVector3D(25, 63, -140), 15);
    sphere_ptr29->setColor(dark_purple);							// dark purple
    m_objects.append(sphere_ptr29);

    Sphere*	sphere_ptr30 = new Sphere(QVector3D(-60, 46, -140), 15);
    sphere_ptr30->setColor(dark_purple); 							// dark purple
    m_objects.append(sphere_ptr30);

    Sphere*	sphere_ptr31 = new Sphere(QVector3D(-30, 68, -130), 12);
    sphere_ptr31->setColor(light_purple); 							// light purple
    m_objects.append(sphere_ptr31);

    Sphere*	sphere_ptr32 = new Sphere(QVector3D(58, 56, -180), 11);
    sphere_ptr32->setColor(green);									//  green
    m_objects.append(sphere_ptr32);

    Sphere*	sphere_ptr33 = new Sphere(QVector3D(-63, -39, -180), 11);
    sphere_ptr33->setColor(green);									// green
    m_objects.append(sphere_ptr33);

    Sphere*	sphere_ptr34 = new Sphere(QVector3D(46, 68, -200), 10);
    sphere_ptr34->setColor(light_purple);							// light purple
    m_objects.append(sphere_ptr34);

    Sphere*	sphere_ptr35 = new Sphere(QVector3D(-3, -72, -130), 12);
    sphere_ptr35->setColor(light_purple);							// light purple
    m_objects.append(sphere_ptr35);

}
