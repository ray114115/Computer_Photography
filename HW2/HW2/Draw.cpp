
#include "Draw.h"





Penguin::Penguin(Angle angle, float x, float y, float z)
{
	glPushMatrix();

	this->Move(x,y,z);

	this->Body();

	//this->Wing(angle);
	

	glPushMatrix();
	glTranslatef(0, PENGUIN_BODY, 0);

	//this->Angle(angle, 0, 0, 1);


	this->Head();

	//this->Angle(angle, 0, 0, -1);
	this->GreenPoint(0, -PENGUIN_BODY / 5, 0);
	//this->Angle(angle, 0, 0, 1);

	this->Eye();

	
	glPushMatrix();
	glTranslatef(PENGUIN_HEAD *0.9, PENGUIN_HEAD*0.7, 0);
	//this->Mouth(angle);

	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(PENGUIN_LEG * 0.25, -PENGUIN_BODY, 0);

	//this->LeftLeg(angle);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-PENGUIN_LEG * 0.25, -PENGUIN_BODY, 0);
	
	//this->RightLeg(-angle);
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

	glBegin(GL_POLYGON); //繪製方式

	for (int i = 0; i < n; i++)
	{
		glColor3f(0., 0., 1.0); //設置顏色，3f代表參數為三個浮點數
		glVertex2f(PENGUIN_BODY*0.7*cos(2 * Pi / n*i), PENGUIN_BODY*sin(2 * Pi / n*i));//計算坐標
	}


	glEnd();
	
	glPopMatrix();
}

void Penguin::Wing(int angle)
{
	glPushMatrix();
	int n = 100;
	GLfloat Pi = 3.14;

	glPushMatrix();
	glTranslatef(0, PENGUIN_WING * 0.6, 0);
	
	this->Angle(angle, 0, 0, 1);
	glTranslatef(0, -PENGUIN_WING * 0.6, 0);

	glBegin(GL_POLYGON); //繪製方式
	
	for (int i = 0; i < n; i++)
	{
		glColor3f(0.3, 0.3, 1.0); //設置顏色，3f代表參數為三個浮點數
		glVertex2f(PENGUIN_WING*0.6*cos(2 * Pi / n*i), PENGUIN_WING*sin(2 * Pi / n*i));//計算坐標
	}

	glEnd();

	glPopMatrix();

	this->GreenPoint(0, PENGUIN_WING * 0.6, 0);


	glPopMatrix();
}

void Penguin::Head()
{
	glPushMatrix();

	glTranslatef(0, PENGUIN_HEAD - PENGUIN_BODY /5, 0);
	int n = 100;
	GLfloat Pi = 3.14;

	glBegin(GL_POLYGON); //繪製方式

	for (int i = 0; i < n; i++)
	{
		glColor3f(0, 0, 1.0); //設置顏色，3f代表參數為三個浮點數
		glVertex2f(PENGUIN_HEAD*cos(2 * Pi / n*i), PENGUIN_HEAD*sin(2 * Pi / n*i));//計算坐標
	}
	glEnd();

	glPopMatrix();


	
}

void Penguin::LeftLeg(int angle)
{
	glPushMatrix();
	glTranslatef(0, PENGUIN_BODY / 5, 0);

	
	glPushMatrix();
	this->Angle(angle, 0, 0, 1);
	

	glBegin(GL_POLYGON);
	glColor3f(0., 0., 1.0); //設置顏色，3f代表參數為三個浮點數
	glVertex2f(-PENGUIN_LEG * 0.25, 0);//計算坐標
	glVertex2f(-PENGUIN_LEG * 0.25, -PENGUIN_LEG);//計算坐標
	glVertex2f(PENGUIN_LEG * 0.25, -PENGUIN_LEG);
	glVertex2f(PENGUIN_LEG * 0.25, 0);
	glEnd();

	glPopMatrix();
	this->GreenPoint(0, PENGUIN_LEG * 0.1, 0);
	this->Angle(angle, 0, 0, 1);



	glTranslatef(0, -PENGUIN_LEG * 4 /5, 0);

	this->Angle(angle, 0, 0, 1);
	

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.0); //設置顏色，3f代表參數為三個浮點數
	glVertex2f(-PENGUIN_FOOT, -PENGUIN_FOOT);//計算坐標
	glVertex2f(0, 0);//計算坐標
	glVertex2f(PENGUIN_FOOT, -PENGUIN_FOOT);//計算坐標
	glEnd();

	this->GreenPoint(0, 0, 0);

	glPopMatrix();
}

void Penguin::Mouth(int angle)
{

	glPushMatrix();

	//上嘴唇
	glBegin(GL_POLYGON); 
	glColor3f(0.6, 0.6, 0.0); //設置顏色，3f代表參數為三個浮點數
	glVertex2f(PENGUIN_MOUTH,0);//計算坐標
	glVertex2f(0, 0);//計算坐標
	glVertex2f(0, PENGUIN_MOUTH * 0.5);//計算坐標
	glEnd();

	float temp = angle ;
	temp /= 2000;
	glTranslatef(0,-PENGUIN_MOUTH / 8 -temp ,0);
	//下嘴唇
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.0); //設置顏色，3f代表參數為三個浮點數
	glVertex2f(PENGUIN_MOUTH, 0);//計算坐標
	glVertex2f(0, 0);//計算坐標
	glVertex2f(0, -PENGUIN_MOUTH * 0.5);//計算坐標
	glEnd();

	glPopMatrix();
}

void Penguin::Eye()
{

	glPushMatrix();
	glTranslatef(PENGUIN_HEAD*0.6, PENGUIN_HEAD *0.9 , 0);
	int n = 100;
	GLfloat Pi = 3.14;


	glBegin(GL_POLYGON); //繪製方式
	
	//白眼珠
	for (int i = 0; i < n; i++)
	{
		glColor3f(1, 1, 1.0); //設置顏色，3f代表參數為三個浮點數
		glVertex2f(PENGUIN_EYE*cos(2 * Pi / n*i), PENGUIN_EYE*sin(2 * Pi / n*i));//計算坐標
	}
	glEnd();

	glBegin(GL_POLYGON); //繪製方式
	//黑眼珠
	for (int i = 0; i < n; i++)
	{
		glColor3f(0, 0, 0.0); //設置顏色，3f代表參數為三個浮點數
		glVertex2f(PENGUIN_EYE * 0.5*cos(2 * Pi / n*i), PENGUIN_EYE*0.5*sin(2 * Pi / n*i));//計算坐標
	}

	glEnd();
	glPopMatrix();
}


void Penguin::RightLeg(int angle)
{

	glPushMatrix();
	glTranslatef(0, PENGUIN_BODY / 5, 0);

	glPushMatrix();
	this->Angle(angle, 0, 0, 1);

	glBegin(GL_POLYGON);
	glColor3f(0., 0., 1.0); //設置顏色，3f代表參數為三個浮點數
	glVertex2f(-PENGUIN_LEG * 0.25, 0);//計算坐標
	glVertex2f(-PENGUIN_LEG * 0.25, -PENGUIN_LEG);//計算坐標
	glVertex2f(PENGUIN_LEG * 0.25, -PENGUIN_LEG);
	glVertex2f(PENGUIN_LEG * 0.25, 0);
	glEnd();

	glPopMatrix();
	this->GreenPoint(0, PENGUIN_LEG * 0.1, 0);
	this->Angle(angle, 0, 0, 1);


	glTranslatef(0, -PENGUIN_LEG * 4 / 5, 0);
	this->Angle(angle, 0, 0, 1);


	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.0); //設置顏色，3f代表參數為三個浮點數
	glVertex2f(-PENGUIN_FOOT, -PENGUIN_FOOT);//計算坐標
	glVertex2f(0, 0);//計算坐標
	glVertex2f(PENGUIN_FOOT, -PENGUIN_FOOT);//計算坐標
	glEnd();

	/*綠點*/
	this->GreenPoint(0, 0, 0);

	glPopMatrix();
}

void Penguin::GreenPoint(float x, float y, float z)
{
	/*畫綠點*/
	glPushMatrix();
	glTranslatef(x, y, z);
	int n = 100;
	GLfloat Pi = 3.14;
	glBegin(GL_POLYGON); //畫綠點
	for (int i = 0; i < n; i++)
	{
		glColor3f(0, 1, 0.0); //設置顏色，3f代表參數為三個浮點數
		glVertex2f(PENGUIN_POINT*cos(2 * Pi / n*i), PENGUIN_POINT*sin(2 * Pi / n*i));//計算坐標
	}
	glEnd();
	glPopMatrix();
}

void Penguin::Angle(float angle, float x, float y, float z)
{
	glRotatef(angle, x, y, z);
}

