#include <FL/Fl.H>
#include <FL/Fl_Gl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>


//#include <gl/GLAux.h>
#include <glut.h>
//#include <gl.h>

#define FPS (1.0/24.0)

typedef unsigned char BYTE;

class ShowImg : public Fl_Gl_Window 
{
public:
	
	BYTE *imageA;
	int width,height;

	void setImgData(BYTE *byte,int w,int h);

	ShowImg(int x,int y,int w,int h,const char *l=0);
	 
	void drawPoint(int x, int y, float r, float g, float b);

    void GlInit();

    void draw();

	
};