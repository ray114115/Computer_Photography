#pragma once
#include <cmath>
#include "SMFLoader.h"
#include <FL/Fl.H>
#include <FL/Fl_Gl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>

#include <glut.h>
#include "Global.h";



#define FPS (1.0/24.0)

#define PI 3.1415926



class BouncingPolygons : public Fl_Gl_Window 
{
public:

	//int x1,x2,y1,y2;
	//int x,y;
	//int t;

	float degree,degree2,depth;

	
	int see;

	float *vertex,*color,*face;
	int *faces;
	SMFLoader *smf;




	/*дїио*/
	float train_x, train_y, train_z,train_degree,train_r,train_g,train_b;
	int cameraX, cameraY, cameraZ;



    static void Timer_CB(void *userdata);

	BouncingPolygons(int x,int y,int w,int h,const char *l);

    void ReshapeViewport();
	void drawDuck(float s);
	 
    void GlInit();

    void draw();
	void oepnLight();
	void closeLight();
	void ground();

	int handle(int event);


	void xyz(void);
	void train(void);
	void scene(void);
};

