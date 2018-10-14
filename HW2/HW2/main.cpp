
#include "Global_parameter.h"
#include "main.h"




int main(int argc, char *argv[])
{


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	//set window1
	glutInitWindowPosition(100, 100); // 設定視窗位置 
	glutInitWindowSize(500, 500); // 設定視窗大小 

	int Window1 = glutCreateWindow("Window1"); // 設定視窗標題
	
	glutDisplayFunc(Display1);  // 呼叫函數 

	//glutTimerFunc(33, timerFunction, 1.0);
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
	
	Penguin a(0.0,0.0,0);
	//a.Body();
	//Creat_Penguin(a);
	//PenguinInit(a);
	
	//a.head();
	//a.leg();
	//draw_penguin();
	
	glPopMatrix();
	glutSwapBuffers();

}

void timerFunction(int p)
{
	//angle += 10;
	glutPostRedisplay();
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


