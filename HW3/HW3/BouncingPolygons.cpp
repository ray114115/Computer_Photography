#include "BouncingPolygons.h"
#include <time.h>
#include <math.h>
#include "SMFLoader.h"

void BouncingPolygons :: Timer_CB(void *userdata) 
{
	BouncingPolygons *mygl = (BouncingPolygons*)userdata;
    mygl->redraw();
    Fl::repeat_timeout(FPS, Timer_CB, userdata);
}

BouncingPolygons :: BouncingPolygons(int x,int y,int w,int h,const char *l) : Fl_Gl_Window(x,y,w,h,l) 
{
	srand(time(NULL));

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
		x=0;
		y=0;
		degree=PI/4;
		degree2=PI/4;
		depth=1000;
		see=0;
		train_x = 0;
		train_y = 0;
		train_z = 0;
		train_degree = 0;

		smf = new SMFLoader();
		smf->load("rubber_duck.smf");
		vertex = smf->getVertices();
		faces = smf->getFaces();
		color = smf->getColors();
		face = smf->getFace(0);
		float *n = smf->getFaceColor(0);

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
	
	
	GLfloat light_ambient[] = {0.6, 0.6, 0.6, 1.0};
	GLfloat light_diffuse[] = {0.2, 0.2, 0.2, 1.0};
	GLfloat light_specular[] ={0.5, 0.5, 0.5, 1.0};
	GLfloat light_position[] = {depth*cos(degree)*cos(degree2),depth*sin(degree2), depth*sin(degree), 1.0};

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);

	//glClearColor(0.0, 0.0, 0.0, 0.0);   
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);	

	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluPerspective(45, 1, 1, 5000);	//透視投影  gluPerspective( 視角, rate , 最近邊界 , 最遠邊界 )

	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	
	
	gluLookAt(depth*cos(degree)*cos(degree2),depth*sin(degree2), depth*sin(degree),0,0,0,0,1,0);

	xyz();
	ground();
	scene();
	train();
	
}






int BouncingPolygons :: handle(int event)
{
	switch(event) 
	{
		case FL_DRAG:
			//printf("Drag(%d,%d)\n",Fl::event_x(),Fl::event_y());
			x2 = Fl::event_x();
			y2 = Fl::event_y();
		
			printf("Drag(%d,%d)\n",x2,y2);
			
			degree+=(x2-x1)*0.0005;
			degree2+=(y2-y1)*0.0005;

			return 1;
		case FL_RELEASE:


		return 1;

		case FL_PUSH:
		
			x1 = Fl::event_x();
			y1 = Fl::event_y();
			printf("Drag(%d,%d)\n",x1,y1);
		
			return 1;
		case FL_MOUSEWHEEL:
			
			if(Fl::event_dy()>0)
				depth=depth+10;

			else if (Fl::event_dy()<0)
				depth=depth-10;


			return 1;
		case FL_KEYBOARD:
		case FL_SHORTCUT:
			if( Fl::event_key() == 'q' ){
				train_degree += 10;
				train_x ++;
				
			}
			if( Fl::event_key() == 'w' ){
				train_degree -= 10;
				train_x --;											
			}
			if( Fl::event_key() == 's' ){
			}
			if( Fl::event_key() == 'e' )
				tank_degree++;

			if( Fl::event_key() == 'a' ){
				tank_degree2--;
				if(abs(tank_degree2)>60)
					tank_degree2++;

			}
			if( Fl::event_key() == 'd' ){
				tank_degree2++;
				if(abs(tank_degree2)>60)
					tank_degree2--;

			}

			if( Fl::event_key() == 'z' ){
			tank_degree3++;
			if(tank_degree3>-10)
				tank_degree3--;
			}

			if( Fl::event_key() == 'c' ){
				tank_degree3--;
				if(abs(tank_degree3)>20)
					tank_degree3++;
			}
			if( shoot==false){
				if( Fl::event_key() == 'x' )
				{
					ball_degree3=tank_degree/180*PI;
					ball_degree=tank_degree2/180*PI;
					ball_x=tank_x;
					ball_z=tank_z;
					ball_degree2=tank_degree3/180*PI;
					shoot=true;
					t=0;
					g=5;
				}
			}
			
				
		return 1;


			

	
		default:
			return Fl_Gl_Window::handle(event);
	}
}


void BouncingPolygons :: xyz(void)
{
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2000.0, 0.0, 0.0);
	glVertex3f(-2000.0, 0.0, 0.0);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0, 2000.0, 0.0);
	glVertex3f(0.0, -2000.0, 0.0);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0, 0.0, 2000.0);
	glVertex3f(0.0, 0.0, -2000.0);
	glEnd();
}
void BouncingPolygons :: ground(void){
glColor3f(0.3, 0.7, 0.5); 
glBegin(GL_POLYGON);  
glVertex3f(-500, -30,-300); 
glVertex3f(-500, -30,300);  
glVertex3f(1000, -30,300);
glVertex3f(1000, -30,-300); 
glEnd();
			}



void BouncingPolygons :: ball(void)
{
	
	glTranslatef(t*sin(ball_degree+ball_degree3),t/10*g-0.2*t/10*t/10,t*cos(ball_degree+ball_degree3));
	glColor3f(0.8, 0.8, 0.5);
	
	t=t+10;
	glutSolidSphere(3,10,10); //(X,前半徑,後半徑,長度,形狀,X)

	if((t/10*g-0.2*t/10*t/10)==0)
		shoot=false;
	
	


}

void  BouncingPolygons :: drawDuck(float s)
{
	glPushMatrix();
	for(int i = 0 ; i < smf->getFaceSize() ; i++ )
	{
		face = smf->getFace(i);
		glPushMatrix();
		glScalef(s,s,s);
		glColor3f(255.0/256,201.0/256,14.0/256);

		glBegin(GL_TRIANGLES);
		glNormal3f(1,0,0);
		glVertex3f(face[0],face[1],face[2]);
		glNormal3f(1,0,0);
		glVertex3f(face[3],face[4],face[5]);
		glNormal3f(1,0,0);
		glVertex3f(face[6],face[7],face[8]);
		glEnd();
		glPopMatrix();
	}
	glPopMatrix();

}

void BouncingPolygons :: oepnLight()
{
	glEnable(GL_LIGHTING);
}
void BouncingPolygons :: closeLight()
{
	glDisable(GL_LIGHTING);
}

void BouncingPolygons::train() 
{
	//glTranslatef(tank_x, 5, tank_z);
	//glRotatef(tank_degree, 0, 1, 0);		//(角度,x,y,z)
	/* 車身 */
	glColor3f(1, 0.5, 0.);	
	glPushMatrix();
	glTranslatef(train_x, 0 + train_y, 0 + train_z);
	glScalef(2, 0.5, 0.5);
	glutSolidCube(80);
	glPopMatrix();

	/* 駕駛艙 */
	glColor3f(0, 1, 1);	
	glPushMatrix();
	glTranslatef(100 + train_x, 0 + train_y, 0 + train_z);
	glScalef(0.5, 0.5, 0.5);
	glutSolidCube(80);
	glPopMatrix();

	/* 輪子 */
	for (int i = 0; i < 4; i++) {
		glColor3f(0, 0, 0);
		/*左邊*/
		glPushMatrix();
		glTranslatef(-40 + i * 40 + train_x, -15 + train_y, 20 + train_z);
		glRotatef(-train_degree, 0, 0, 1);
		GLUquadricObj *quadratic;
		quadratic = gluNewQuadric();
		gluCylinder(quadratic, 10, 10, 5, 32, 5); //(X,前半徑,後半徑,長度,形狀,X)
		glScalef(2, 0.1, 0.5);
		glutSolidCube(10);
		glPopMatrix();
		/*右邊*/
		glPushMatrix();
		glTranslatef(-40 + i * 40 + train_x, -15 + train_y, -20 + train_z);
		glRotatef(-train_degree, 0, 0, 1);
		GLUquadricObj *quadratic2;
		quadratic2 = gluNewQuadric();
		glTranslatef(0, 0, -5);
		gluCylinder(quadratic2, 10, 10, 5, 32, 5); //(X,前半徑,後半徑,長度,形狀,X)
		glTranslatef(0, 0, 5);
		glScalef(2, 0.1, 0.5);
		glutSolidCube(10);
		glPopMatrix();
	}

	/* 煙囪 */
	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(50 + train_x, 60 + train_y, 0 + train_z);
	glRotatef(90, 1, 0, 0);
	GLUquadricObj *quadratic3;
	quadratic3 = gluNewQuadric();
	gluCylinder(quadratic3, 20, 10, 20, 32, 5); //(X,前半徑,後半徑,長度,形狀,X)
	glTranslatef(0, 0, 20);
	gluCylinder(quadratic3, 10, 10, 20, 32, 5);
	glPopMatrix();

	/* 鴨子 */
	glTranslatef(100 + train_x, 30 + train_y, 0 + train_z);
	glRotatef(90, 0, 1, 0);
	drawDuck(0.1);
}

void BouncingPolygons::scene(void)
{

	/* 枕木 x=-200~800 */
	for (int i = 0; i < 50; i++) {
		glColor3f(0.4, 0.3, 0.1);
		glPushMatrix();
		glTranslatef(-200 + 20*i, -30, 0);
		glScalef(0.4, 0.25, 4);
		glutSolidCube(20);
		glPopMatrix();
	}
	/* 鐵軌 */
	glColor3f(0.8, 0.8, 0.8);
	glPushMatrix();
	glTranslatef(300 , -25, 25);
	glScalef(50, 0.2, 0.25);
	glutSolidCube(20);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(300, -25, -25);
	glScalef(50, 0.2, 0.25);
	glutSolidCube(20);
	glPopMatrix();

	/*鐵軌終點障礙物*/
	for (int i = 0; i < 3; i++) {
		glColor3f(0.4 + i *0.2, 0.4 +i*0.2, 1-i*0.2);
		glPushMatrix();
		glTranslatef(850, 0+i*80, 0);
		glScalef(1, 1, 1);
		glutSolidCube(80);
		glPopMatrix();
	}

}
