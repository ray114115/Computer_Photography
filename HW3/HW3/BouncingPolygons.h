#include <cmath>
#include "SMFLoader.h"
#include <FL/Fl.H>
#include <FL/Fl_Gl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>

#include <glut.h>
//#include <gl/gl.h>
//#include <gl/GLAux.h>




#define FPS (1.0/24.0)

#define PI 3.1415926


class BouncingPolygons : public Fl_Gl_Window 
{
public:

	int x1,x2,y1,y2;
	int x,y;
	int t;
	
	int g,c,a;
	float degree,degree2,depth;
	float ball_degree;
	float ball_degree2;
	float ball_degree3;
	float ball_x,ball_z;
	
	int see;
	bool shoot;

	float far1;
	float *vertex,*color,*face;
	int *faces;
	SMFLoader *smf;

	float **colorful;



	float tank_z,tank_x,tank_degree,tank_degree2,tank_degree3;

	/*дїио*/
	float train_x, train_y, train_z,train_degree;




    static void Timer_CB(void *userdata);

	BouncingPolygons(int x,int y,int w,int h,const char *l=0);

    void ReshapeViewport();
	void drawDuck(float s);
	 
    void GlInit();

    void draw();
	void oepnLight();
	void closeLight();
	void ground();

	int handle(int event);


	void xyz(void);
	
	void ball(void);

	void train(void);
	void scene(void);
};