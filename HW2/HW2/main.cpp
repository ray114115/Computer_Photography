
#include "Global_parameter.h"
#include "main.h"




int main(int argc, char *argv[])
{


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	//set window1
	glutInitWindowPosition(100, 100); // �]�w������m 
	glutInitWindowSize(500, 500); // �]�w�����j�p 

	int Window1 = glutCreateWindow("Window1"); // �]�w�������D
	
	glutDisplayFunc(Display1);  // �I�s��� 

	//glutTimerFunc(33, timerFunction, 1.0);
	glutKeyboardFunc(keyboard); //��L
	glutMotionFunc(rotateFourpart); //�ƹ�
	

	glutMainLoop();
	return 0;
}

void Display1(void)
{

	//glClearColor(1.0, 1.0, 1.0, 0.0);	//�I���אּ�զ�

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

//���䰵�@��DEMO�Pı
void keyboard(unsigned char key, int x, int y)
{
	/*
	switch (key)//�i�H�Q�Ϋ��䱱��|��
	{
		//�����
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

		//����ڪ��k��
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

		//����ڪ����}
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
		//����k�}
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
		//�^���l
	case 'g':
		val = 0;
		break;
		//�Y�p���R
	case 'y':
		val = 1;
		break;
		//�٭��ۤv���w�����׵M����R
	case 'n':
		val = 2;
		break;

	default:
		break;
	}
	*/
}


//�ƹ����ʧڭn���h���
void rotateFourpart(int x, int y)
{
	/*
	rot1 = x;
	//�Q�n�H����ʧڪ����u
	//for(int i=0;i<rot1;i+=100)
	//{
	shoulder_left = (shoulder_left + 5) % 360;
	shoulder_right = (shoulder_right + 5) % 360;
	glutPostRedisplay();
	//} 
	*/
}


