#include "BouncingPolygons.h"
#include <time.h>
#include <math.h>

#define PI 3.1415926

void BouncingPolygons :: Timer_CB(void *userdata) 
{
	BouncingPolygons *mygl = (BouncingPolygons*)userdata;
    mygl->redraw();
    Fl::repeat_timeout(FPS, Timer_CB, userdata);
}

BouncingPolygons :: BouncingPolygons(int x,int y,int w,int h,const char *l) : Fl_Gl_Window(x,y,w,h,l) 
{
	srand(time(NULL));

	sum=0;
	ee=0;
	shape=0;
	check=false;
    Fl::add_timeout(FPS, Timer_CB, (void*)this);
}



void BouncingPolygons :: ReshapeViewport() 
{
    glViewport(0, 0, w(), h());
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	gluOrtho2D(-10,10,-10,10);
}

void BouncingPolygons :: GlInit() 
{
    static int first_time = 1;
    if ( first_time ) 
	{
        first_time = 0;
        glShadeModel(GL_FLAT);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);
    }
}



void BouncingPolygons :: draw() 
{
	
    if ( !valid() ) 
	{
        valid(1);
        GlInit();
        ReshapeViewport();
    }
		

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		for(int i=0;i<sum;i++){

			if(check &&i==c-1)
				glColor3f(1,1,1);
			else
				glColor3f(0,1,1);
			if(p[i][5]==1){glBegin(GL_LINES);
			glVertex3f(p[i][1],p[i][2],0.0);
			glVertex3f(p[i][3],p[i][4],0.0);
			glEnd();}
			else if(p[i][5]==2){
			
		
			GLfloat x, y, angle;
			glBegin(GL_POINTS);
			for(angle = 0; angle <2*PI; angle +=0.001)
			{
				x = (abs(p[i][1]-p[i][3])/2*sin(angle)+(p[i][1]+p[i][3])/2);
				y =(abs(p[i][2]-p[i][4])/2*cos(angle)+(p[i][2]+p[i][4])/2);
				glVertex3d(x, y, 0.0);
			}
			glEnd();

			}
		
			else if(p[i][5]==3){
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);   
			glBegin(GL_POLYGON);  
			glVertex2f(p[i][1], p[i][4]); 
			glVertex2f(p[i][1], p[i][2]);  
			glVertex2f(p[i][3], p[i][2]);
			glVertex2f(p[i][3], p[i][4]); 
			glEnd();
			}
	}

	glFlush();

    GLenum err = glGetError();
    if ( err != GL_NO_ERROR )
        fprintf(stderr, "GLGETERROR=%d\n", (int)err);
}





int BouncingPolygons :: handle(int event)
{
	switch(event) 
	{
		case FL_DRAG:
			//printf("Drag(%d,%d)\n",Fl::event_x(),Fl::event_y());
			x2 = Fl::event_x();
			y2 = Fl::event_y();
			x2=(x2-200)/20;
			y2=-(y2-200)/20;
			//printf("Drag(%f,%f)\n",x2,y2);
			if(ee==1){
				p[sum-1][3]=x2;
				p[sum-1][4]=y2;
			}
			if(check && ee==2){
				
				p[c-1][1]+=x2-x1;
				p[c-1][2]+=y2-y1;
				p[c-1][3]+=x2-x1;
				p[c-1][4]+=y2-y1;
				
				x1=x2;
				y1=y2;


			}

		
			return 1;
		case FL_RELEASE:
			check=false;
		return 1;

		case FL_PUSH:
		
			x1 = Fl::event_x();
			y1 = Fl::event_y();
			x1=(x1-200)/20;
			y1=-(y1-200)/20;
			//printf("Click(%f,%f)\n",x1,y1);
			if(ee==1){
				sum++;
				p[sum-1][5]=shape;
				//printf("%d\n",sum);
				p[sum-1][1]=x1;
				p[sum-1][2]=y1;
				p[sum-1][3]=x1;
				p[sum-1][4]=y1;
			}
			else{
				
				if(checkPoint(x1,y1)!=0){
					c=checkPoint(x1,y1);
					check=true;
				}

			}
			return 1;

	
		default:
			return Fl_Gl_Window::handle(event);
	}
}

int BouncingPolygons ::checkPoint(float a,float b)
{

	float v1,b1,v2,b2;
	float m,d;
	float k;
	for(int i=0;i<sum;i++){
		if(p[i][5]==1){
		
				
				bool change=true;
				v1=p[i][1];
				b1=p[i][2];
				v2=p[i][3];
				b2=p[i][4];
					
				if(v1>v2){
					if(a>v1+0.3||a<v2-0.3)
						change=false;
				}
				else {
					if(a>v2+0.3||a<v1-0.3)
						change=false;
				}

				if(b1>b2){
					if(b>b1+0.3||b<b2-0.3)
						change=false;
				}


				else {
					if(b>b2+0.3||b<b1-0.3)
						change=false;
				}

				if(change==true){
				m=(b2-b1)/(v2-v1);
				k=b1-v1*m;
				
				//printf("i=%d\n",i);
				d=abs(m*a-b+k)/sqrt(m*m+1);
				//printf("距離=%f\n",d);
				if(d<=0.3)
					return i+1;}
	
		}

		else if(p[i][5]==2){
			float l,s,f,r,z,n,m;
			z=0;
			
				l=abs(p[i][1]-p[i][3])/2;
				s=abs(p[i][2]-p[i][4])/2;
				if(s>l)
				{
					s=abs(p[i][1]-p[i][3])/2;
					l=abs(p[i][2]-p[i][4])/2;
					z=1;
					
				}
					f=sqrt(l*l-s*s);

					n=a-(p[i][1]+p[i][3])/2;
					m=b-(p[i][2]+p[i][4])/2;

		
					if(z==0)
					r=sqrt((n+f)*(n+f)+m*m)+sqrt((n-f)*(n-f)+m*m);
					else
					r=sqrt(n*n+(m+f)*(m+f))+sqrt(n*n+(m-f)*(m-f));

				
					if(2*l-0.5<r && r<2*l+0.5){
						return i+1;
					

					}
		

		}
		else if(p[i][5]==3){
			
			bool change=true;

			v1=p[i][1];
			v2=p[i][3];
			b1=p[i][2];
			b2=p[i][4];


			if(v1>v2){
				if(a>v1+0.3||a<v2-0.3)
					change=false;

			}
			else {
				if(a>v2+0.3||a<v1-0.3)
					change=false;
			}

			if(b1>b2){
				if(b>b1+0.3||b<b2-0.3)
					change=false;
			}


			else {
				if(b>b2+0.3||b<b1-0.3)
					change=false;
			}
			
			if(change==true){
			
			
			d=abs(a-v1);
			if(d<=0.3)
				return i+1;

			
			d=abs(a-v2);
			if(d<=0.3)
				return i+1;


			
			d=abs(b-b1);
			if(d<=0.3)
				return i+1;


		
			d=abs(b-b2);
			if(d<=0.3)
				return i+1;
			}


		}

		}
	
	
		return 0;
}