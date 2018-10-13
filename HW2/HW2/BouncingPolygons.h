#include <FL/Fl.H>
#include <FL/Fl_Gl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>

#include <glut.h>
//#include <gl.h>
//#include <gl/GLAux.h>

#include <math.h>


#define FPS (1.0/24.0)

class BouncingPolygons : public Fl_Gl_Window 
{
public:

	float x1,x2,y1,y2;
	int sum;
	int shape;
	float p[1000][5];
	int ee;
	int c;
	bool check;



    static void Timer_CB(void *userdata);

	BouncingPolygons(int x,int y,int w,int h,const char *l=0);

    void ReshapeViewport();
	 
    void GlInit();

    void draw();

	int handle(int event);

	int checkPoint(float a,float b);
};