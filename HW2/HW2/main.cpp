
#include "Global_parameter.h"
#include "main.h"

class openGL_window : public Fl_Gl_Window { // Create a OpenGL class in FLTK 
	void draw();            // Draw function. 
	//void draw_overlay();    // Draw overlay function. 

public:
	openGL_window(int x, int y, int w, int h, const char *l = 0);  // Class constructor 
	int frame;

};

openGL_window::openGL_window(int x, int y, int w, int h, const char *l) :Fl_Gl_Window(x, y, w, h, l)
{
	mode(FL_RGB | FL_ALPHA | FL_DOUBLE | FL_STENCIL);
	//Fl::add_timeout(1.0 / 24.0, Timer_CB, (void*)this);
	frame = 0;
}

void openGL_window::draw() {
	// the valid() property may be used to avoid reinitializing your
	// GL transformation for each redraw:
	if (!valid()) {
		valid(1);
		glLoadIdentity();
		glViewport(0, 0, w(), h());
	}

	// draw an amazing but slow graphic:--------------
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_QUADS);
	glColor3f(1, 0, 0); glVertex2f(-1, -1);
	glColor3f(1, 1, 0); glVertex2f(-1, 1);
	glColor3f(1, 0, 1); glVertex2f(1, 1);
	glColor3f(1, 1, 1); glVertex2f(1, -1);
	glEnd();

	//--------------------------------------------------
	++frame;
}

int main(int argc, char *argv[])
{
	/*
	Fl_Window window(640, 480);  // Create a FLTK window. Resolution 600*400. 

	openGL_window test(10, 10, 600, 400);
	window.resizable(&test);

	window.end();                  // End of FLTK windows setting. 
	window.show(argc, argv);        // Show the FLTK window
	test.show();
	test.redraw_overlay();

	return Fl::run();
	*/
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	//set window1
	glutInitWindowPosition(100, 100); // 設定視窗位置 
	glutInitWindowSize(500, 500); // 設定視窗大小 

	int Window1 = glutCreateWindow("Window1"); // 設定視窗標題
	
	glutDisplayFunc(Display1);  // 呼叫函數 

	glutTimerFunc(33, timerFunction, 1.0);
	glutKeyboardFunc(keyboard); //鍵盤
	glutMotionFunc(rotateFourpart); //滑鼠
	

	glutMainLoop();
	return 0;
	
}

void Display1(void)
{

	//glClearColor(1.0, 1.0, 1.0, 0.0);	//背景改為白色

	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	

	Penguin a(aAngle,aMove);
	//a.Body();
	//Creat_Penguin(a);
	//PenguinInit(a);

	

	//Penguin aPenguin(aAngle,aMove.x,aMove.y,aMove.z);
	
	glPopMatrix();
	glutSwapBuffers();

}

void timerFunction(int p)
{
	aMove.x = moveing(aMove.x);
	//a.angle = rotating(a.angle);

	//glutPostRedisplay();
	glutTimerFunc(33, timerFunction, 1.0);

}

//按鍵做一些DEMO感覺
void keyboard(unsigned char key, int x, int y)
{
	/*
	switch (key)//可以利用按鍵控制四肢
	{
		//控制左手
	case 'q':
		shoulder_left = (shoulder_left + 5) % 180;
		glutPostRedisplay();
		break;
	case 'w':
		shoulder_left = (shoulder_left - 5) % 180;
		glutPostRedisplay();
		break;
	case 'e':
		elbow_left = (elbow_left + 5) % 360;
		glutPostRedisplay();
		break;
	case 'r':
		elbow_left = (elbow_left - 5) % 360;
		glutPostRedisplay();
		break;

		//控制我的右手
	case 'a':
		shoulder_right = (shoulder_right + 5) % 180;
		glutPostRedisplay();
		break;
	case 's':
		shoulder_right = (shoulder_right - 5) % 180;
		glutPostRedisplay();
		break;
	case 'd':
		elbow_right = (elbow_right + 5) % 360;
		glutPostRedisplay();
		break;
	case 'f':
		elbow_right = (elbow_right - 5) % 360;
		glutPostRedisplay();
		break;

		//控制我的左腳
	case 'z':
		knee_left = (knee_left + 5) % 360;
		glutPostRedisplay();
		break;
	case 'x':
		knee_left = (knee_left - 5) % 360;
		glutPostRedisplay();
		break;
	case 'c':
		foot_left = (foot_left + 5) % 360;
		glutPostRedisplay();
		break;
	case 'v':
		foot_left = (foot_left - 5) % 360;
		glutPostRedisplay();
		break;
		//控制右腳
	case 'u':
		knee_right = (knee_right + 5) % 360;
		glutPostRedisplay();
		break;
	case 'i':
		knee_right = (knee_right - 5) % 360;
		glutPostRedisplay();
		break;
	case 'o':
		foot_right = (foot_right + 5) % 360;
		glutPostRedisplay();
		break;
	case 'p':
		foot_right = (foot_right - 5) % 360;
		glutPostRedisplay();
		break;
		//回到原始
	case 'g':
		val = 0;
		break;
		//縮小跳舞
	case 'y':
		val = 1;
		break;
		//還原到自己喜歡的角度然後跳舞
	case 'n':
		val = 2;
		break;

	default:
		break;
	}
	*/
}


//滑鼠移動我要怎麼去轉動
void rotateFourpart(int x, int y)
{
	/*
	rot1 = x;
	//想要隨機轉動我的手臂
	//for(int i=0;i<rot1;i+=100)
	//{
	shoulder_left = (shoulder_left + 5) % 360;
	shoulder_right = (shoulder_right + 5) % 360;
	glutPostRedisplay();
	//} 
	*/
}

int rotating(int angle)
{
	if (aFlag.Rotate == 0)
		angle += 1;
	else
		angle -= 1;
	if (angle > 40)
		aFlag.Rotate = 1;
	else if (angle < -40)
		aFlag.Rotate = 0;
	return angle;
}

float moveing(float x)
{
	if (aFlag.Move == 0)
	{
		x += 0.01;
	}
	else
	{
		x -= 0.01;
	}
	if (x > 0.5)
		aFlag.Move = 1;
	else if (x < -0.5)
		aFlag.Move = 0;
	return x;
}


