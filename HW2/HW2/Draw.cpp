
#include "Draw.h"





Penguin::Penguin(float x, float y, float z)
{
	glPushMatrix();

	this->Move(x,y,z);

	this->Body();

	this->Wing();

	glPushMatrix();
	glTranslatef(0, PENGUIN_BODY, 0);



	this->Head();
	
	this->Eye();

	
	glPushMatrix();
	glTranslatef(PENGUIN_HEAD *0.9, PENGUIN_HEAD*0.7, 0);
	this->Mouth();

	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -PENGUIN_BODY, 0);
	this->LeftLeg();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-PENGUIN_LEG * 0.4, -PENGUIN_BODY, 0);
	this->RightLeg();
	glPopMatrix();

	glPopMatrix();
}

void Penguin::Move(float x, float y, float z) 
{
	glTranslatef(x, y, z);
}

void Penguin :: Body() {
	glPushMatrix();


	int n = 100;
	GLfloat Pi = 3.14;

	glBegin(GL_POLYGON); //ø�s�覡

	for (int i = 0; i < n; i++)
	{
		glColor3f(0., 0., 1.0); //�]�m�C��A3f�N��ѼƬ��T�ӯB�I��
		glVertex2f(PENGUIN_BODY*0.7*cos(2 * Pi / n*i), PENGUIN_BODY*sin(2 * Pi / n*i));//�p�⧤��
	}


	glEnd();
	
	glPopMatrix();
}

void Penguin::Wing() 
{
	glPushMatrix();
	int n = 100;
	GLfloat Pi = 3.14;

	glBegin(GL_POLYGON); //ø�s�覡
	
	for (int i = 0; i < n; i++)
	{
		glColor3f(0.3, 0.3, 1.0); //�]�m�C��A3f�N��ѼƬ��T�ӯB�I��
		glVertex2f(PENGUIN_WING*0.6*cos(2 * Pi / n*i), PENGUIN_WING*sin(2 * Pi / n*i));//�p�⧤��
	}

	glEnd();

	


	glPopMatrix();
}

void Penguin::Head()
{
	glPushMatrix();

	/*�e���I*/
	glPushMatrix();
	glTranslatef(0, 0, 1);
	int n = 100;
	GLfloat Pi = 3.14;
	glBegin(GL_POLYGON); //�e���I
	for (int i = 0; i < n; i++)
	{
		glColor3f(0, 1, 0.0); //�]�m�C��A3f�N��ѼƬ��T�ӯB�I��
		glVertex2f(PENGUIN_POINT*cos(2 * Pi / n*i), PENGUIN_POINT*sin(2 * Pi / n*i));//�p�⧤��
	}
	glEnd();
	glPopMatrix();


	glTranslatef(0, PENGUIN_HEAD - PENGUIN_BODY /5, 0);
	//int n = 100;
	//GLfloat Pi = 3.14;

	glBegin(GL_POLYGON); //ø�s�覡

	for (int i = 0; i < n; i++)
	{
		glColor3f(0, 0, 1.0); //�]�m�C��A3f�N��ѼƬ��T�ӯB�I��
		glVertex2f(PENGUIN_HEAD*cos(2 * Pi / n*i), PENGUIN_HEAD*sin(2 * Pi / n*i));//�p�⧤��
	}
	glEnd();

	glPopMatrix();
}

void Penguin::LeftLeg()
{
	glPushMatrix();
	glTranslatef(0, PENGUIN_BODY / 5, 0);

	/*�e���I*/
	glPushMatrix();
	glTranslatef(PENGUIN_LEG * 0.25, PENGUIN_LEG * 0.1, 0);
	int n = 100;
	GLfloat Pi = 3.14;
	glBegin(GL_POLYGON); //�e���I
	for (int i = 0; i < n; i++)
	{
		glColor3f(0, 1, 0.0); //�]�m�C��A3f�N��ѼƬ��T�ӯB�I��
		glVertex2f(PENGUIN_POINT*cos(2 * Pi / n*i), PENGUIN_POINT*sin(2 * Pi / n*i));//�p�⧤��
	}
	glEnd();
	glPopMatrix();


	glBegin(GL_POLYGON);
	glColor3f(0., 0., 1.0); //�]�m�C��A3f�N��ѼƬ��T�ӯB�I��
	glVertex2f(0, 0);//�p�⧤��
	glVertex2f(0, -PENGUIN_LEG);//�p�⧤��
	glVertex2f(PENGUIN_LEG * 0.5, -PENGUIN_LEG);
	glVertex2f(PENGUIN_LEG * 0.5, 0);
	glEnd();

	glTranslatef(PENGUIN_LEG * 0.25, -PENGUIN_LEG * 4 /5, 0);

	/*���I*/
	glPushMatrix();
	//glTranslatef(PENGUIN_LEG * 0.25, PENGUIN_LEG * 0.1, 0);
	glBegin(GL_POLYGON); //�e���I
	for (int i = 0; i < n; i++)
	{
		glColor3f(0, 1, 0.0); //�]�m�C��A3f�N��ѼƬ��T�ӯB�I��
		glVertex2f(PENGUIN_POINT*cos(2 * Pi / n*i), PENGUIN_POINT*sin(2 * Pi / n*i));//�p�⧤��
	}
	glEnd();
	glPopMatrix();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.0); //�]�m�C��A3f�N��ѼƬ��T�ӯB�I��
	glVertex2f(-PENGUIN_FOOT, -PENGUIN_FOOT);//�p�⧤��
	glVertex2f(0, 0);//�p�⧤��
	glVertex2f(PENGUIN_FOOT, -PENGUIN_FOOT);//�p�⧤��
	glEnd();

	
	glPopMatrix();
}

void Penguin::Mouth()
{

	glPushMatrix();

	//�W�L�B
	glBegin(GL_POLYGON); 
	glColor3f(0.6, 0.6, 0.0); //�]�m�C��A3f�N��ѼƬ��T�ӯB�I��
	glVertex2f(PENGUIN_MOUTH,0);//�p�⧤��
	glVertex2f(0, 0);//�p�⧤��
	glVertex2f(0, PENGUIN_MOUTH * 0.5);//�p�⧤��
	glEnd();

	//�U�L�B
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.0); //�]�m�C��A3f�N��ѼƬ��T�ӯB�I��
	glVertex2f(PENGUIN_MOUTH, 0-PENGUIN_MOUTH /8);//�p�⧤��
	glVertex2f(0, -PENGUIN_MOUTH / 8 );//�p�⧤��
	glVertex2f(0, -PENGUIN_MOUTH * 0.5 - PENGUIN_MOUTH / 8);//�p�⧤��
	glEnd();

	glPopMatrix();
}

void Penguin::Eye()
{

	glPushMatrix();
	glTranslatef(PENGUIN_HEAD*0.6, PENGUIN_HEAD *0.9 , 0);
	int n = 100;
	GLfloat Pi = 3.14;


	glBegin(GL_POLYGON); //ø�s�覡
	
	//�ղ��]
	for (int i = 0; i < n; i++)
	{
		glColor3f(1, 1, 1.0); //�]�m�C��A3f�N��ѼƬ��T�ӯB�I��
		glVertex2f(PENGUIN_EYE*cos(2 * Pi / n*i), PENGUIN_EYE*sin(2 * Pi / n*i));//�p�⧤��
	}
	glEnd();

	glBegin(GL_POLYGON); //ø�s�覡
	//�²��]
	for (int i = 0; i < n; i++)
	{
		glColor3f(0, 0, 0.0); //�]�m�C��A3f�N��ѼƬ��T�ӯB�I��
		glVertex2f(PENGUIN_EYE * 0.5*cos(2 * Pi / n*i), PENGUIN_EYE*0.5*sin(2 * Pi / n*i));//�p�⧤��
	}

	glEnd();
	glPopMatrix();
}


void Penguin::RightLeg()
{

	glPushMatrix();
	glTranslatef(0, PENGUIN_BODY / 5, 0);

	/*�e���I*/
	glPushMatrix();
	glTranslatef(PENGUIN_LEG * 0.25, PENGUIN_LEG * 0.1, 0);
	int n = 100;
	GLfloat Pi = 3.14;
	glBegin(GL_POLYGON); //�e���I
	for (int i = 0; i < n; i++)
	{
		glColor3f(0, 1, 0.0); //�]�m�C��A3f�N��ѼƬ��T�ӯB�I��
		glVertex2f(PENGUIN_POINT*cos(2 * Pi / n*i), PENGUIN_POINT*sin(2 * Pi / n*i));//�p�⧤��
	}
	glEnd();
	glPopMatrix();


	glBegin(GL_POLYGON);
	glColor3f(0., 0., 1.0); //�]�m�C��A3f�N��ѼƬ��T�ӯB�I��
	glVertex2f(0, 0);//�p�⧤��
	glVertex2f(0, -PENGUIN_LEG);//�p�⧤��
	glVertex2f(PENGUIN_LEG * 0.5, -PENGUIN_LEG);
	glVertex2f(PENGUIN_LEG * 0.5, 0);
	glEnd();



	glTranslatef(PENGUIN_LEG * 0.25, -PENGUIN_LEG * 4 / 5, 0);

	/*���I*/
	glPushMatrix();
	//glTranslatef(PENGUIN_LEG * 0.25, PENGUIN_LEG * 0.1, 0);
	glBegin(GL_POLYGON); //�e���I
	for (int i = 0; i < n; i++)
	{
		glColor3f(0, 1, 0.0); //�]�m�C��A3f�N��ѼƬ��T�ӯB�I��
		glVertex2f(PENGUIN_POINT*cos(2 * Pi / n*i), PENGUIN_POINT*sin(2 * Pi / n*i));//�p�⧤��
	}
	glEnd();
	glPopMatrix();


	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.0); //�]�m�C��A3f�N��ѼƬ��T�ӯB�I��
	glVertex2f(-PENGUIN_FOOT, -PENGUIN_FOOT);//�p�⧤��
	glVertex2f(0, 0);//�p�⧤��
	glVertex2f(PENGUIN_FOOT, -PENGUIN_FOOT);//�p�⧤��
	glEnd();

	glPopMatrix();
}

