
#include "Global_parameter.h"



int main(int argc, char *argv[])
{


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	//set window1
	glutInitWindowPosition(100, 100); // 設定視窗位置 
	glutInitWindowSize(1000, 500); // 設定視窗大小 
	int Window1 = glutCreateWindow("Window1"); // 設定視窗標題
	
	glutDisplayFunc(Display1);  // 呼叫函數 
	
	

	glutMainLoop();
	return 0;
}

void Display1(void)
{

	glClearColor(1.0, 1.0, 1.0, 1.0);	//背景改為白色
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();

	

	glPopMatrix();
	glutSwapBuffers();

}