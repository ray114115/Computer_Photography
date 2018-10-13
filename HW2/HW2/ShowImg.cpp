#include "ShowImg.h"
#include <math.h>


ShowImg :: ShowImg(int x,int y,int w,int h,const char *l) : Fl_Gl_Window(x,y,w,h,l) 
{
	
	imageA = 0;
	width = 0;
	height = 0;

}


void ShowImg :: setImgData(BYTE *byte,int w,int h)
{
	this->imageA = 0;
	this->imageA = byte;
	this->width = w;
	this->height = h;

}


void ShowImg :: GlInit() 
{
    static int first_time = 1;
    if ( first_time ) 
	{
        first_time = 0;
        glShadeModel(GL_FLAT);
        glEnable(GL_DEPTH_TEST);
    }
}

void ShowImg :: drawPoint(int x, int y, float r, float g, float b)
{
	glColor3f(r,g,b);
	glBegin(GL_POINTS);
	glVertex2f(x-width/2,y-width/2);
	glEnd();
}

void ShowImg :: draw() 
{
	
    if ( !valid() ) 
	{
        valid(1);
        GlInit();
    }
	
	if( width && height  )
	{
		glViewport(0, 0, w(), h());
		glMatrixMode(GL_PROJECTION); 
		glLoadIdentity();
		gluOrtho2D(-this->width/2,this->height/2,-this->width/2,this->height/2);
		
	}

		
	
	

    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if( imageA != 0 )
	{
		for(int i = 0 ; i < width ; i++ )
			for( int j = 0 ; j < height ; j++ )
				drawPoint(i,j, (float)*(imageA+(j+i*width)*3+0)/255, (float)*(imageA+(j+i*width)*3+1)/255, (float)*(imageA+(j+i*width)*3+2)/255 );
	}

    GLenum err = glGetError();
    if ( err != GL_NO_ERROR )
        fprintf(stderr, "GLGETERROR=%d\n", (int)err);
}

