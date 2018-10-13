#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <vector>
#include <glut.h>
#include <string>
#include <sstream>

using namespace std;

void draw_polygon(GLfloat red,GLfloat green,GLfloat blue);
void draw_trian(float x, float y,float z,float R);
void static_circle(void);
void draw_ellipse(float x, float y,float z, float R);

void draw_circle();

void print(float x, float y,float z, char *string);

void delay(float secs);
void reshape(int w, int h);
void TimerFunction(int value);
void TimerFunction2(int value);
void Mouse_Event(int button, int state, int x, int y);
void print_windowsize();

//menu event
void createWINDOW1Menus();
void createSUBWINDOWMenus();
void Window1MenuEvents(int option);
void SubWindowMenuEvents(int option);
void SetPolyColor(int option);

/*Color*/
#define RED		1
#define GREEN	2
#define BLUE	3
#define WHITE	4
#define BLACK	5

/*gobal parameter*/
#define DELTA_R 0.01
#define Animation_Stop 0
#define Animation_Start 1
int Window1;
int Window2;
int SubWindow;
int Animation = 1;


/*set window1 parameter*/
#define R_MAX 0.3
#define R_MIN 0.1
int flag = 1;
int poly_angle = 0;
int poly_R=1,poly_G=1,poly_B=1;
GLfloat circle_r = (R_MAX + R_MIN) / 2;


/*set window2 parameter*/
#define R_MAX2 0.4
#define R_MIN2 0.2
#define TRIAN_ROTATE_ANGLE 10
int trian_angle = 0;
GLfloat R = (R_MAX2 + R_MIN2) / 2;
float trian_R = 0.3;

/* set SubWindow parameter*/
float SubBackColorR = 1;
float SubBackColorG = 1;
float SubBackColorB = 1;

class coor{
    public:
        GLfloat x;
        GLfloat y;
		GLfloat Color[3];
};


GLfloat poly[3];

vector<coor> Mouse_coor;



void Display2()
{
	GLfloat poly[3];
	glClear(GL_COLOR_BUFFER_BIT);


    glPushMatrix();

	print_windowsize();
    static_circle();
	//draw_ellipse();
	draw_trian(-0.3,0,0,trian_R);
	//draw_polygon(0.5,1,1);



    glPopMatrix();
    glutSwapBuffers();
}

void Display1(void)
{
	

	glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

	print(-0.8,-0.9,0,"Hello Nurse!");
	//static_circle(circle_r);
	//draw_ellipse();
	//draw_trian();
	draw_circle();
	draw_polygon(poly_R,poly_G,poly_B);



	//circle 動畫
	if(Animation == 1){
		if(flag == 1)
			circle_r +=DELTA_R;
		else
			circle_r -=DELTA_R;
		if(circle_r > R_MAX)
			flag = 0;
		else if(circle_r < R_MIN)
			flag = 1;

		//正方形 rotatef
		poly_angle += 1;
	}
    glPopMatrix();
    glutSwapBuffers();

}

void Display_SubWindow1()
{
	glClearColor(SubBackColorR,SubBackColorG,SubBackColorB,1);
	glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
	draw_ellipse(0,0,0,0.5);

    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);




	//set window1
    glutInitWindowPosition(100, 100); // 設定視窗位置 
    glutInitWindowSize(500, 500); // 設定視窗大小 
    Window1 = glutCreateWindow("Window1"); // 設定視窗標題
	glutDisplayFunc(Display1);  // 呼叫函數 
	glutMouseFunc(Mouse_Event);
	createWINDOW1Menus();
	//glutReshapeFunc (reshape);

	//set subwindow
	SubWindow = glutCreateSubWindow(1,0,0,200,200);
	glutDisplayFunc(Display_SubWindow1);
	createSUBWINDOWMenus();

	//set window2
	glutInitWindowPosition(600, 100); // 設定視窗位置 
    glutInitWindowSize(400, 150); // 設定視窗大小 
	Window2 = glutCreateWindow("Window2"); // 設定視窗標題 
    glutDisplayFunc(Display2);  // 呼叫函數 
	glutReshapeFunc (reshape);


	
	glutTimerFunc(3, TimerFunction, 1);
	//glutIdleFunc

    glutMainLoop();
    return 0;
}

void static_circle(void)
{
	glTranslatef(0.5,0.,0);
	int n = 100;
	GLfloat Pi = 3.14;
	int WINDOW_WIDTH = glutGet(GLUT_WINDOW_WIDTH);
	int WINDOW_HEIGHT = glutGet(GLUT_WINDOW_HEIGHT);

	glBegin(GL_POLYGON); //繪製方式
	//glColor3f(1.0, 0.0, 0.0); //設置顏色，3f代表參數為三個浮點數

	//circle 動畫
	if(Animation == 1){
		if(flag == 1)
			R += DELTA_R * (R_MAX2-R_MIN2) / (R_MAX-R_MIN);
		else
			R -= DELTA_R * (R_MAX2-R_MIN2) / (R_MAX-R_MIN);
	}
	for (int i = 0; i < n; i++)
	{
		glColor3f(1.0 *i/n , 0.0, 0.0); //設置顏色，3f代表參數為三個浮點數
		glVertex2f(R*WINDOW_HEIGHT/WINDOW_WIDTH*cos(2 * Pi / n*i), R*sin(2 * Pi / n*i));//計算坐標
	}

	glEnd();
	glFlush();
	
	glTranslatef(-0.5,-0.,0);
}


void print(float x, float y,float z, char *string)
{
	glColor3f(1.0f, 1.0f, 1.0f);
	glRasterPos2f(x,y);
	glColor3f(1.0f, 1.0f, 1.0f);
	int len = (int) strlen(string);
	
	for (int i = 0; i < len; i++) 
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,string[i]);
	}
};



void draw_ellipse(float x, float y,float z, float R)
{
	glTranslatef(x,y,z);
	const int n = 100;
//	const GLfloat R = 0.2;
//	const GLfloat Y = 0.2*0.6;
	const GLfloat Pi = 3.14;
	
	glBegin(GL_POLYGON); 
	glColor3f(1.0, 0.0, 0.0); //設置顏色
	for (int i = 0; i < n; i++)
		glVertex2f(R*cos(2 * Pi / n*i),R*0.6*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	glTranslatef(-x,y,z);

}

void draw_trian(float x, float y,float z,float R)
{
	glTranslatef(x,y,z);
	glRotatef(-trian_angle,0,0,1);

	float R_x = R * glutGet(GLUT_WINDOW_WIDTH);
	glBegin (GL_TRIANGLES);
        glColor3f (1.0f, 0.0f, 0.0f);         // 設定輸出色為紅色 
        glVertex2f (0, R);
		glColor3f (0.0f, 1.0f, 0.0f);         // 設定輸出色為綠色 
        glVertex2f (-R,-R); 
        glColor3f (0.0f, 0.0f, 1.0f);         // 設定輸出色為藍色 
        glVertex2f (R,-R); 
    glEnd ();
	if(Animation == 1){
		trian_angle += TRIAN_ROTATE_ANGLE;
	}
	glFlush();
	glRotatef(trian_angle,0,0,1);
	glTranslatef(-x,-y,-z);
}

void draw_polygon(GLfloat red,GLfloat green,GLfloat blue)
{
	glTranslatef(0,-0.2,0);
	glRotatef(poly_angle,0,0,1);
	for(float i = 0.0;i<=0.6;i+=0.2)
	{
		glColor3f(red,green,blue);
		glBegin(GL_POLYGON);			//畫白正方形
			glVertex3f(-(0.6-i),(0.6-i),0.0);
			glVertex3f( (0.6-i),(0.6-i),0.0);
			glVertex3f( (0.6-i),-(0.6-i),0.0);
			glVertex3f(-(0.6-i),-(0.6-i),0.0);
		glEnd();

		glFlush();
		
		glColor3f(0,0,0);
	    glBegin(GL_POLYGON);			//畫黑正方形
        glVertex3f(-(0.5-i),(0.5-i),0.0);
        glVertex3f( (0.5-i),(0.5-i),0.0);
        glVertex3f( (0.5-i),-(0.5-i),0.0);
        glVertex3f(-(0.5-i),-(0.5-i),0.0);
	    glEnd();
	
		
		glFlush();
	}
	glRotatef(-poly_angle,0,0,1);
	glTranslatef(0,0.2,0);
}

void reshape(int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(50.0, (GLfloat) w/(GLfloat) h, 1, 1.0);

}


void TimerFunction(int value)
{
	glutSetWindow(Window1);
	glutPostRedisplay();
	glutSetWindow(Window2);
	glutPostRedisplay();
	glutSetWindow(SubWindow);
	glutPostRedisplay();
	glutTimerFunc(3, TimerFunction, 1);
}


void Mouse_Event(int button, int state, int x, int y)
{
	coor tmp_coor;
	srand(time(NULL));
	if (state == GLUT_DOWN){
        if (button == GLUT_LEFT_BUTTON){
			tmp_coor.x = x;
			tmp_coor.y = y;
			for(int i = 0;i<3;i++){
				tmp_coor.Color[i] = (float)rand()/(float)RAND_MAX;
			}
			Mouse_coor.push_back(tmp_coor);
		}
	}
}




void draw_circle()
{
	float x,y,m_x,m_y;
	x = glutGet(GLUT_WINDOW_WIDTH);
	y = glutGet(GLUT_WINDOW_HEIGHT);

	x /= 2;
	y /= 2;
	for(int j = 0; j< Mouse_coor.size();j++){
		
		m_x = (Mouse_coor[j].x - x) / x;
		m_y = -(Mouse_coor[j].y - y) / y;

		glTranslatef(m_x,m_y,0);
		int n = 100;
		GLfloat Pi = 3.14;

		glBegin(GL_POLYGON); //繪製方式
		//glColor3f(1.0, 0.0, 0.0); //設置顏色，3f代表參數為三個浮點數
		for (int i = 0; i < n; i++)
		{
			glColor3f(Mouse_coor[j].Color[0] *i/n , Mouse_coor[j].Color[1] *i/n, Mouse_coor[j].Color[2] *i/n); //設置顏色，3f代表參數為三個浮點數
			glVertex2f(circle_r*cos(2 * Pi / n*i), circle_r*sin(2 * Pi / n*i));//計算坐標
		}


		glEnd();
		glFlush();
	
		glTranslatef(-m_x,-m_y,0);
	}
	
}

void print_windowsize()
{
	int x = glutGet(GLUT_WINDOW_WIDTH);
	int y = glutGet(GLUT_WINDOW_HEIGHT);
	string s;
    stringstream ss(s);
    ss << x <<" X "<< y;
	string s1(ss.str());
	

	print(-1,-1,0,(char*)s1.c_str());

}

void createWINDOW1Menus()
{
	int menu,Color;
	Color = glutCreateMenu(SetPolyColor);
	glutAddMenuEntry("white",WHITE);
	glutAddMenuEntry("red",RED);
	glutAddMenuEntry("green",GREEN);

	menu = glutCreateMenu(Window1MenuEvents);
	glutAddMenuEntry("Stop Animation",Animation_Stop);
	glutAddMenuEntry("Start Animation",Animation_Start);
	glutAddSubMenu("Square Color",Color);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}



void createSUBWINDOWMenus()
{
	int menu;
	menu = glutCreateMenu(SubWindowMenuEvents);
	glutAddMenuEntry("white",WHITE);
	glutAddMenuEntry("black",BLACK);
	glutAddMenuEntry("red",RED);
	glutAddMenuEntry("green",GREEN);
	glutAddMenuEntry("blue",BLUE);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void Window1MenuEvents(int option)
{
	switch (option){
		case Animation_Stop:
			Animation = 0;
			break;
		case Animation_Start:
			Animation = 1;
			break;
	}
}

void SetPolyColor(int option)
{
	switch (option){
		case WHITE:
			poly_R = 1;
			poly_G = 1;
			poly_B = 1;
			break;
		case RED:
			poly_R = 1;
			poly_G = 0;
			poly_B = 0;
			break;
		case GREEN:
			poly_R = 0;
			poly_G = 1;
			poly_B = 0;
			break;
	}
}

void SubWindowMenuEvents(int option)
{
		switch (option){
		case WHITE:
			SubBackColorR = 1;
			SubBackColorG = 1;
			SubBackColorB = 1;
			break;
		case BLACK:
			SubBackColorR = 0;
			SubBackColorG = 0;
			SubBackColorB = 0;
			break;
		case RED:
			SubBackColorR = 1;
			SubBackColorG = 0;
			SubBackColorB = 0;
			break;
		case GREEN:
			SubBackColorR = 0;
			SubBackColorG = 1;
			SubBackColorB = 0;
			break;
		case BLUE:
			SubBackColorR = 0;
			SubBackColorG = 0;
			SubBackColorB = 1;
			break;
		}
}