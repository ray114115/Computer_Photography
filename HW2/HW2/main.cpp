
#include "Global_parameter.h"



int main(int argc, char *argv[])
{


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	//set window1
	glutInitWindowPosition(100, 100); // �]�w������m 
	glutInitWindowSize(1000, 500); // �]�w�����j�p 
	int Window1 = glutCreateWindow("Window1"); // �]�w�������D
	
	glutDisplayFunc(Display1);  // �I�s��� 
	
	

	glutMainLoop();
	return 0;
}

void Display1(void)
{

	glClearColor(1.0, 1.0, 1.0, 1.0);	//�I���אּ�զ�
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();

	

	glPopMatrix();
	glutSwapBuffers();

}