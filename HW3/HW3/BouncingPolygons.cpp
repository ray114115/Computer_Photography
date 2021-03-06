#include "BouncingPolygons.h"
#include <time.h>
#include <math.h>
#include "SMFLoader.h"

void train_move(void);

int move = 0;
float train_positionX = 0, train_positionY = 0, train_positionZ = 0, train_Degree = 0, zoom = 1;
int flag = 0;
void BouncingPolygons :: Timer_CB(void *userdata) 
{
	BouncingPolygons *mygl = (BouncingPolygons*)userdata;
	light();
	train_move();
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

		degree=PI/4;
		degree2=PI/4;
		depth=1000;
		see=0;
		
		move = 0;
		cameraX = 0;
		cameraY = 0;
		cameraZ = 0;
		zoom = 1;

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
	


	//glClearColor(0.0, 0.0, 0.0, 0.0);   
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);	

	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluPerspective(45, 1, 1, 5000);	//透視投影  gluPerspective( 視角, rate , 最近邊界 , 最遠邊界 )

	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();

	train_x = train_positionX;
	train_y = train_positionY;
	train_z = train_positionZ;
	train_degree = train_Degree;

	if (see == 0) {
		gluLookAt((depth*cos(degree)*cos(degree2))*zoom, (depth*sin(degree2))*zoom, (depth*sin(degree))*zoom, 0, 0, 0, 0, 1, 0);
	}
	else if (see == 1) {
		gluLookAt(110 + train_x, 50 + train_y, 0 + train_z, 1000 + train_x, 0, 0, 0, 1, 0);
	}
	else if (see == 2){ 
		gluLookAt((1500 + cameraX)*zoom, (500 + cameraY)*zoom, (500 + cameraZ)*zoom, 0 + cameraX, 0 + cameraY, 0 + cameraZ, 0, 1, 0);
	}

	

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
			float x1, y1;
			x1 = Fl::event_x();
			y1 = Fl::event_y();

			printf("Drag(%d,%d)\n", x1, y1);

			degree += x1  *0.00005;
			degree2 += y1 *0.00005;

			return 1;
		case FL_RELEASE:


		return 1;

		case FL_PUSH:
		

		
			return 1;
		case FL_MOUSEWHEEL:
			
			if(Fl::event_dy()>0)
				degree += 0.1;

			else if (Fl::event_dy()<0)
				degree -= 0.1;


			return 1;
		case FL_KEYBOARD:
		case FL_SHORTCUT:
			
			if (Fl::event_key() == 'w') {
				cameraY += 5;
				degree2 += 0.1;
			}
			else if (Fl::event_key() == 'a') {
				cameraZ += 5;
				degree += 0.1;
			}
			else if (Fl::event_key() == 's') {
				cameraY -= 5;
				degree2 -= 0.1;
			}
			else if (Fl::event_key() == 'd') {
				cameraZ -= 5;
				degree -= 0.1;
			}
			else if (Fl::event_key() == 'z') { zoom -= 0.1; }
			else if (Fl::event_key() == 'x') { zoom += 0.1; }
			else if (Fl::event_key() == 65307) {//ESC
				printf("ESC");
				return 0;
			}
			else if (Fl::event_key() == 'o') //
				see = 0;
			else if (Fl::event_key() == 'p') //鴨子視角
				see = 1;
			else if (Fl::event_key() == 32)
				move = ~move;
			else if (Fl::event_key() == 'm')
			{
				flag = ~flag;
			}
			else if (Fl::event_key() == 't')
			{
				see++;
				if (see == 3)
					see = 0;
			}
			
			printf("%d\n", (Fl::event_key()));
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
void train_move(void)
{
	if (flag == 0) {
		if (move == 0) {
			train_Degree += 10;
			train_positionX += 10;
		}
		else if (move == -1) {
			train_Degree -= 10;
			train_positionX -= 10;
		}
		if (train_positionX > 600) move = -1;
		else if (train_positionX < -100) move = 0;
	}
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
