// this file contains the definition of the World class

//#include "wxraytracer.h"

#include "World.h"
#include "Constants.h"

// geometric objects

#include "Plane.h"
#include "Sphere.h"

// tracers

#include "SingleSphere.h"
#include "MultipleObjects.h"

// utilities

#include "Vector3D.h"
#include "Point3D.h"
#include "Normal.h"
#include "ShadeRec.h"
#include "Maths.h"

#include <QImage>
#include <QColor>
#include <qDebug>

// -------------------------------------------------------------------- default constructor

World::World(void)
	:  	background_color(black),
		tracer_ptr(NULL)
{
}



//------------------------------------------------------------------ destructor

World::~World(void) {	
	
	if(tracer_ptr) {
		delete tracer_ptr;
		tracer_ptr = NULL;
	}	
	
	delete_objects();	
}

void World::build()
{
    //buildSingleSphere();
    buildMultipleObjects();
    //buildBBCoverPic();
    image = new QImage(vp.hres, vp.vres, QImage::Format_ARGB32);
    //image->fill(QColor(255,0,0));
}


//------------------------------------------------------------------ render_scene

// This uses orthographic viewing along the zw axis

void 												
World::render_scene(void) const {

	RGBColor	pixel_color;	 	
	Ray			ray;					
	int 		hres 	= vp.hres;
	int 		vres 	= vp.vres;
	float		s		= vp.s;
	float		zw		= 100.0;			// hardwired in

	ray.d = Vector3D(0, 0, -1);
	
	for (int r = 0; r < vres; r++)			// up
        for (int c = 0; c < hres; c++) {	// across
			ray.o = Point3D(s * (c - hres / 2.0 + 0.5), s * (r - vres / 2.0 + 0.5), zw);
			pixel_color = tracer_ptr->trace_ray(ray);
			display_pixel(r, c, pixel_color);
		}	
}  

// ------------------------------------------------------------------ clamp

RGBColor
World::max_to_one(const RGBColor& c) const  {
	float max_value = max(c.r, max(c.g, c.b));
	
	if (max_value > 1.0)
		return (c / max_value);
	else
		return (c);
}


// ------------------------------------------------------------------ clamp_to_color
// Set color to red if any component is greater than one

RGBColor
World::clamp_to_color(const RGBColor& raw_color) const {
	RGBColor c(raw_color);
	
	if (raw_color.r > 1.0 || raw_color.g > 1.0 || raw_color.b > 1.0) {
		c.r = 1.0; c.g = 0.0; c.b = 0.0;
	}
		
	return (c);
}


// ---------------------------------------------------------------------------display_pixel

// raw_color is the pixel color computed by the ray tracer
// its RGB floating point components can be arbitrarily large
// mapped_color has all components in the range [0, 1], but still floating point
// display color has integer components for computer display
// the Mac's components are in the range [0, 65535]
// a PC's components will probably be in the range [0, 255]
// the system-dependent code is in the function convert_to_display_color
// the function SetCPixel is a Mac OS function


void
World::display_pixel(const int row, const int column, const RGBColor& raw_color) const {
	RGBColor mapped_color;

	if (vp.show_out_of_gamut)
		mapped_color = clamp_to_color(raw_color);
	else
		mapped_color = max_to_one(raw_color);
	
	if (vp.gamma != 1.0)
		mapped_color = mapped_color.powc(vp.inv_gamma);
	
   //have to start from max y coordinate to convert to screen coordinates
   int x = column;
   int y = vp.vres - row - 1;

   //image->setPixelColor(x, y, QColor(255, 0, 0, 255) );
   image->setPixelColor(x, y, QColor((int)(mapped_color.r * 255), (int)(mapped_color.g* 255), (int)(mapped_color.b * 255), 255) );

//   paintArea->setPixel(x, y, (int)(mapped_color.r * 255),
//                             (int)(mapped_color.g * 255),
//                             (int)(mapped_color.b * 255));
}



// ----------------------------------------------------------------------------- hit_bare_bones_objects

ShadeRec									
World::hit_bare_bones_objects(const Ray& ray) {
	ShadeRec	sr(*this); 
	double		t; 			
	float		tmin 			= kHugeValue;
	int 		num_objects 	= objects.size();
	
	for (int j = 0; j < num_objects; j++)
		if (objects[j]->hit(ray, t, sr) && (t < tmin)) {
			sr.hit_an_object	= true;
			tmin 				= t; 
			sr.color			= objects[j]->get_color(); 
		}
		
	return (sr);   
}


//------------------------------------------------------------------ delete_objects

// Deletes the objects in the objects array, and erases the array.
// The objects array still exists, because it's an automatic variable, but it's empty 

void
World::delete_objects(void) {
	int num_objects = objects.size();
	
	for (int j = 0; j < num_objects; j++) {
		delete objects[j];
		objects[j] = NULL;
	}	
	
	objects.erase (objects.begin(), objects.end());
}

void World::buildSingleSphere()
{
    vp.set_hres(200);
    vp.set_vres(200);
    vp.set_pixel_size(1.0);
    vp.set_gamma(1.0);
    background_color = white;
    tracer_ptr = new SingleSphere(this);
    sphere.set_center(0.0);
    sphere.set_radius(85);
}

void World::buildMultipleObjects()
{
    vp.set_hres(200);
    vp.set_vres(200);
    vp.set_pixel_size(1.0);

    tracer_ptr = new MultipleObjects(this);

    background_color = RGBColor(black);

    // use access functions to set centre and radius

    Sphere* sphere_ptr = new Sphere;
    sphere_ptr->set_center(0, -25, 0);
    sphere_ptr->set_radius(80);
    sphere_ptr->set_color(1, 0, 0);  // red
    add_object(sphere_ptr);

    // use constructor to set centre and radius

    sphere_ptr = new Sphere(Point3D(0, 30, 0), 60);
    sphere_ptr->set_color(1, 1, 0);	// yellow
    add_object(sphere_ptr);

    Plane* plane_ptr = new Plane(Point3D(0), Normal(0, 1, 1));
    plane_ptr->set_color(0.0, 0.3, 0.0);	// dark green
    add_object(plane_ptr);
}

void World::buildBBCoverPic()
{
    vp.set_hres(400);
        vp.set_vres(400);
        vp.set_pixel_size(0.5);

        background_color = RGBColor(0.0);
        tracer_ptr = new MultipleObjects(this);

        // colours

        RGBColor yellow(1, 1, 0);										// yellow
        RGBColor brown(0.71, 0.40, 0.16);								// brown
        RGBColor dark_green(0.0, 0.41, 0.41);							// dark_green
        RGBColor orange(1, 0.75, 0);									// orange
        RGBColor green(0, 0.6, 0.3);									// green
        RGBColor light_green(0.65, 1, 0.30);							// light green
        RGBColor dark_yellow(0.61, 0.61, 0);							// dark yellow
        RGBColor light_purple(0.65, 0.3, 1);							// light purple
        RGBColor dark_purple(0.5, 0, 1);								// dark purple

        // spheres

        Sphere*	sphere_ptr1 = new Sphere(Point3D(5, 3, 0), 30);
        sphere_ptr1->set_color(yellow);	   								// yellow
        add_object(sphere_ptr1);

        Sphere*	sphere_ptr2 = new Sphere(Point3D(45, -7, -60), 20);
        sphere_ptr2->set_color(brown);									// brown
        add_object(sphere_ptr2);

        Sphere*	sphere_ptr3 = new Sphere(Point3D(40, 43, -100), 17);
        sphere_ptr3->set_color(dark_green);								// dark green
        add_object(sphere_ptr3);

        Sphere*	sphere_ptr4 = new Sphere(Point3D(-20, 28, -15), 20);
        sphere_ptr4->set_color(orange);									// orange
        add_object(sphere_ptr4);

        Sphere*	sphere_ptr5 = new Sphere(Point3D(-25, -7, -35), 27);
        sphere_ptr5->set_color(green);									// green
        add_object(sphere_ptr5);

        Sphere*	sphere_ptr6 = new Sphere(Point3D(20, -27, -35), 25);
        sphere_ptr6->set_color(light_green);								// light green
        add_object(sphere_ptr6);

        Sphere*	sphere_ptr7 = new Sphere(Point3D(35, 18, -35), 22);
        sphere_ptr7->set_color(green);   								// green
        add_object(sphere_ptr7);

        Sphere*	sphere_ptr8 = new Sphere(Point3D(-57, -17, -50), 15);
        sphere_ptr8->set_color(brown);									// brown
        add_object(sphere_ptr8);

        Sphere*	sphere_ptr9 = new Sphere(Point3D(-47, 16, -80), 23);
        sphere_ptr9->set_color(light_green);								// light green
        add_object(sphere_ptr9);

        Sphere*	sphere_ptr10 = new Sphere(Point3D(-15, -32, -60), 22);
        sphere_ptr10->set_color(dark_green);     						// dark green
        add_object(sphere_ptr10);

        Sphere*	sphere_ptr11 = new Sphere(Point3D(-35, -37, -80), 22);
        sphere_ptr11->set_color(dark_yellow);							// dark yellow
        add_object(sphere_ptr11);

        Sphere*	sphere_ptr12 = new Sphere(Point3D(10, 43, -80), 22);
        sphere_ptr12->set_color(dark_yellow);							// dark yellow
        add_object(sphere_ptr12);

        Sphere*	sphere_ptr13 = new Sphere(Point3D(30, -7, -80), 10);
        sphere_ptr13->set_color(dark_yellow);
        add_object(sphere_ptr13);										// dark yellow (hidden)

        Sphere*	sphere_ptr14 = new Sphere(Point3D(-40, 48, -110), 18);
        sphere_ptr14->set_color(dark_green); 							// dark green
        add_object(sphere_ptr14);

        Sphere*	sphere_ptr15 = new Sphere(Point3D(-10, 53, -120), 18);
        sphere_ptr15->set_color(brown); 								// brown
        add_object(sphere_ptr15);

        Sphere*	sphere_ptr16 = new Sphere(Point3D(-55, -52, -100), 10);
        sphere_ptr16->set_color(light_purple);							// light purple
        add_object(sphere_ptr16);

        Sphere*	sphere_ptr17 = new Sphere(Point3D(5, -52, -100), 15);
        sphere_ptr17->set_color(brown);									// browm
        add_object(sphere_ptr17);

        Sphere*	sphere_ptr18 = new Sphere(Point3D(-20, -57, -120), 15);
        sphere_ptr18->set_color(dark_purple);							// dark purple
        add_object(sphere_ptr18);

        Sphere*	sphere_ptr19 = new Sphere(Point3D(55, -27, -100), 17);
        sphere_ptr19->set_color(dark_green);								// dark green
        add_object(sphere_ptr19);

        Sphere*	sphere_ptr20 = new Sphere(Point3D(50, -47, -120), 15);
        sphere_ptr20->set_color(brown);									// browm
        add_object(sphere_ptr20);

        Sphere*	sphere_ptr21 = new Sphere(Point3D(70, -42, -150), 10);
        sphere_ptr21->set_color(light_purple);							// light purple
        add_object(sphere_ptr21);

        Sphere*	sphere_ptr22 = new Sphere(Point3D(5, 73, -130), 12);
        sphere_ptr22->set_color(light_purple);							// light purple
        add_object(sphere_ptr22);

        Sphere*	sphere_ptr23 = new Sphere(Point3D(66, 21, -130), 13);
        sphere_ptr23->set_color(dark_purple);							// dark purple
        add_object(sphere_ptr23);

        Sphere*	sphere_ptr24 = new Sphere(Point3D(72, -12, -140), 12);
        sphere_ptr24->set_color(light_purple);							// light purple
        add_object(sphere_ptr24);

        Sphere*	sphere_ptr25 = new Sphere(Point3D(64, 5, -160), 11);
        sphere_ptr25->set_color(green);					 				// green
        add_object(sphere_ptr25);

        Sphere*	sphere_ptr26 = new Sphere(Point3D(55, 38, -160), 12);
        sphere_ptr26->set_color(light_purple);							// light purple
        add_object(sphere_ptr26);

        Sphere*	sphere_ptr27 = new Sphere(Point3D(-73, -2, -160), 12);
        sphere_ptr27->set_color(light_purple);							// light purple
        add_object(sphere_ptr27);

        Sphere*	sphere_ptr28 = new Sphere(Point3D(30, -62, -140), 15);
        sphere_ptr28->set_color(dark_purple); 							// dark purple
        add_object(sphere_ptr28);

        Sphere*	sphere_ptr29 = new Sphere(Point3D(25, 63, -140), 15);
        sphere_ptr29->set_color(dark_purple);							// dark purple
        add_object(sphere_ptr29);

        Sphere*	sphere_ptr30 = new Sphere(Point3D(-60, 46, -140), 15);
        sphere_ptr30->set_color(dark_purple); 							// dark purple
        add_object(sphere_ptr30);

        Sphere*	sphere_ptr31 = new Sphere(Point3D(-30, 68, -130), 12);
        sphere_ptr31->set_color(light_purple); 							// light purple
        add_object(sphere_ptr31);

        Sphere*	sphere_ptr32 = new Sphere(Point3D(58, 56, -180), 11);
        sphere_ptr32->set_color(green);									//  green
        add_object(sphere_ptr32);

        Sphere*	sphere_ptr33 = new Sphere(Point3D(-63, -39, -180), 11);
        sphere_ptr33->set_color(green);									// green
        add_object(sphere_ptr33);

        Sphere*	sphere_ptr34 = new Sphere(Point3D(46, 68, -200), 10);
        sphere_ptr34->set_color(light_purple);							// light purple
        add_object(sphere_ptr34);

        Sphere*	sphere_ptr35 = new Sphere(Point3D(-3, -72, -130), 12);
        sphere_ptr35->set_color(light_purple);							// light purple
        add_object(sphere_ptr35);
}
