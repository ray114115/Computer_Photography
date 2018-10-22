
#include "Draw.h"





Penguin::Penguin(Angle angleinput, MoveA moveinput, Color colorinput)
{
	angle = angleinput;
	move = moveinput;
	acolor = colorinput;

	glPushMatrix();

	this->Move();
	this->Draw();


	glPopMatrix();
}

void Penguin::Move()
{
	glTranslatef(move.x,move.y,move.z);
}

void Penguin::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	this->Body();

	glPushMatrix();
	glRotatef(angle.wing, 0, 0, 1);
	this->Wing();
	glPopMatrix();

	glPushMatrix();

	glTranslatef(0, PENGUIN_BODY, 0);
	glRotatef(angle.head, 0, 0, 1);

	this->Head();
	this->Eye();

	glPushMatrix();
	glTranslatef(PENGUIN_HEAD *0.9, PENGUIN_HEAD*0.7, 0);
	this->Mouth();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(PENGUIN_LEG * 0.2, -PENGUIN_BODY, 0);
	
	this->LeftLeg();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-PENGUIN_LEG * 0.2, -PENGUIN_BODY, 0);
	this->RightLeg();
	glPopMatrix();

}

void Penguin::Body() {
	glPushMatrix();

	int n = 100;
	GLfloat Pi = 3.14;

	glBegin(GL_POLYGON); //酶籹よΑ

	for (int i = 0; i < n; i++)
	{
		//glColor3f(0., 0., 1.0); //砞竚肅︹3f把计疊翴计
		glColor3f(acolor.R, acolor.G, acolor.B); //砞竚肅︹3f把计疊翴计
		glVertex2f(PENGUIN_BODY*0.7*cos(2 * Pi / n*i), PENGUIN_BODY*sin(2 * Pi / n*i));//璸衡Г夹
	}


	glEnd();

	glPopMatrix();
}

void Penguin::Wing()
{
	glPushMatrix();
	glTranslatef(0, -PENGUIN_WING / 3, 0);
	int n = 100;
	GLfloat Pi = 3.14;

	glBegin(GL_POLYGON); //酶籹よΑ

	for (int i = 0; i < n; i++)
	{
		//glColor3f(0.3, 0.3, 1.0); //砞竚肅︹3f把计疊翴计
		glColor3f(acolor.G - 0.3 , acolor.B + 0.1, acolor.R + 0.2); //砞竚肅︹3f把计疊翴计
		glVertex2f(PENGUIN_WING*0.6*cos(2 * Pi / n*i), PENGUIN_WING*sin(2 * Pi / n*i));//璸衡Г夹
	}

	glEnd();

	glPushMatrix();
	glTranslatef(0, PENGUIN_WING / 3, 0);
	glBegin(GL_POLYGON); //礶厚翴
	for (int i = 0; i < n; i++)
	{
		glColor3f(0, 1, 0.0); //砞竚肅︹3f把计疊翴计
		glVertex2f(PENGUIN_POINT*cos(2 * Pi / n*i), PENGUIN_POINT*sin(2 * Pi / n*i));//璸衡Г夹
	}
	glEnd();
	glPopMatrix();

	glPopMatrix();
}

void Penguin::Head()
{
	glPushMatrix();
	int n = 100;
	GLfloat Pi = 3.14;
	
	glTranslatef(0, PENGUIN_HEAD - PENGUIN_BODY / 5, 0);
	//int n = 100;
	//GLfloat Pi = 3.14;

	glBegin(GL_POLYGON); //酶籹よΑ

	for (int i = 0; i < n; i++)
	{
		glColor3f(acolor.R, acolor.G, acolor.B); //砞竚肅︹3f把计疊翴计
		//glColor3f(0, 0, 1.0); //砞竚肅︹3f把计疊翴计
		glVertex2f(PENGUIN_HEAD*cos(2 * Pi / n*i), PENGUIN_HEAD*sin(2 * Pi / n*i));//璸衡Г夹
	}
	glEnd();

	glPushMatrix();
	glTranslatef(0, -PENGUIN_HEAD + PENGUIN_BODY / 5, 0);
	glBegin(GL_POLYGON); //礶厚翴
	for (int i = 0; i < n; i++)
	{
		glColor3f(0, 1, 0.0); //砞竚肅︹3f把计疊翴计
		glVertex2f(PENGUIN_POINT*cos(2 * Pi / n*i), PENGUIN_POINT*sin(2 * Pi / n*i));//璸衡Г夹
	}
	glEnd();
	glPopMatrix();

	glPopMatrix();
}

void Penguin::LeftLeg()
{
	glPushMatrix();

	glTranslatef(0, PENGUIN_BODY / 5, 0);
	glRotatef(angle.leftleg, 0, 0, 1);

	glPushMatrix();
	

	glBegin(GL_POLYGON);
	//glColor3f(0., 0., 1.0); //砞竚肅︹3f把计疊翴计
	glColor3f(acolor.R, acolor.G, acolor.B); //砞竚肅︹3f把计疊翴计
	glVertex2f(PENGUIN_LEG * -0.25, 0);//璸衡Г夹
	glVertex2f(PENGUIN_LEG * -0.25, -PENGUIN_LEG);//璸衡Г夹
	glVertex2f(PENGUIN_LEG * 0.25, -PENGUIN_LEG);
	glVertex2f(PENGUIN_LEG * 0.25, 0);
	glEnd();

	/*礶厚翴*/
	glPushMatrix();
	glTranslatef(0, 0, 0);
	int n = 100;
	GLfloat Pi = 3.14;
	glBegin(GL_POLYGON); //礶厚翴
	for (int i = 0; i < n; i++)
	{
		glColor3f(0, 1, 0.0); //砞竚肅︹3f把计疊翴计
		glVertex2f(PENGUIN_POINT*cos(2 * Pi / n*i), PENGUIN_POINT*sin(2 * Pi / n*i));//璸衡Г夹
	}
	glEnd();
	glPopMatrix();

	//draw foot
	glTranslatef(0, -PENGUIN_LEG * 4 / 5, 0);
	glRotatef(angle.leftfoot, 0, 0, 1);
	
	glPushMatrix();
	//glTranslatef(PENGUIN_LEG * 0.25, PENGUIN_LEG * 0.1, 0);

	glBegin(GL_POLYGON);
	glColor3f(acolor.G + 0.3, acolor.B + 0.1, acolor.R - 0.2); //砞竚肅︹3f把计疊翴计
	//glColor3f(0.6, 0.6, 0.0); //砞竚肅︹3f把计疊翴计
	glVertex2f(-PENGUIN_FOOT , -PENGUIN_FOOT);//璸衡Г夹
	glVertex2f(0, 0);//璸衡Г夹
	glVertex2f(PENGUIN_FOOT , -PENGUIN_FOOT);//璸衡Г夹
	glEnd();

	glBegin(GL_POLYGON); //礶厚翴
	for (int i = 0; i < n; i++)
	{
		glColor3f(0, 1, 0.0); //砞竚肅︹3f把计疊翴计
		glVertex2f(PENGUIN_POINT*cos(2 * Pi / n*i), PENGUIN_POINT*sin(2 * Pi / n*i));//璸衡Г夹
	}
	glEnd();
	glPopMatrix();


	glPopMatrix();
	glPopMatrix();
}

void Penguin::Mouth()
{

	glPushMatrix();

	//糒瓸
	glBegin(GL_POLYGON);
	//glColor3f(0.6, 0.6, 0.0); //砞竚肅︹3f把计疊翴计
	glColor3f(acolor.G + 0.3, acolor.B + 0.1, acolor.R - 0.2); //砞竚肅︹3f把计疊翴计
	glVertex2f(PENGUIN_MOUTH, 0);//璸衡Г夹
	glVertex2f(0, 0);//璸衡Г夹
	glVertex2f(0, PENGUIN_MOUTH * 0.5);//璸衡Г夹
	glEnd();

	//糒瓸
	glTranslatef(0, move.mouth, 0);

	glBegin(GL_POLYGON);
	//glColor3f(0.6, 0.6, 0.0); //砞竚肅︹3f把计疊翴计
	glColor3f(acolor.G + 0.3, acolor.B + 0.1, acolor.R - 0.2); //砞竚肅︹3f把计疊翴计
	glVertex2f(PENGUIN_MOUTH, 0 - PENGUIN_MOUTH / 8);//璸衡Г夹
	glVertex2f(0, -PENGUIN_MOUTH / 8);//璸衡Г夹
	glVertex2f(0, -PENGUIN_MOUTH * 0.5 - PENGUIN_MOUTH / 8);//璸衡Г夹
	glEnd();

	glPopMatrix();
}

void Penguin::Eye()
{

	glPushMatrix();
	glTranslatef(PENGUIN_HEAD*0.6, PENGUIN_HEAD *0.9, 0);
	int n = 100;
	GLfloat Pi = 3.14;


	glBegin(GL_POLYGON); //酶籹よΑ

						 //フ泊痌
	for (int i = 0; i < n; i++)
	{
		glColor3f(1, 1, 1.0); //砞竚肅︹3f把计疊翴计
		glVertex2f(PENGUIN_EYE*cos(2 * Pi / n*i), PENGUIN_EYE*sin(2 * Pi / n*i));//璸衡Г夹
	}
	glEnd();

	glBegin(GL_POLYGON); //酶籹よΑ
						 //堵泊痌
	for (int i = 0; i < n; i++)
	{
		glColor3f(0, 0, 0.0); //砞竚肅︹3f把计疊翴计
		glVertex2f(PENGUIN_EYE * 0.5*cos(2 * Pi / n*i), PENGUIN_EYE*0.5*sin(2 * Pi / n*i));//璸衡Г夹
	}

	glEnd();
	glPopMatrix();
}


void Penguin::RightLeg()
{

	glPushMatrix();

	glTranslatef(0, PENGUIN_BODY / 5, 0);
	glRotatef(angle.rightleg, 0, 0, 1);

	glPushMatrix();

	glBegin(GL_POLYGON);
	//glColor3f(0., 0., 1.0); //砞竚肅︹3f把计疊翴计
	glColor3f(acolor.R, acolor.G, acolor.B); //砞竚肅︹3f把计疊翴计
	glVertex2f(-PENGUIN_LEG * 0.25, 0);//璸衡Г夹
	glVertex2f(-PENGUIN_LEG * 0.25, -PENGUIN_LEG);//璸衡Г夹
	glVertex2f(PENGUIN_LEG * 0.25, -PENGUIN_LEG);
	glVertex2f(PENGUIN_LEG * 0.25, 0);
	glEnd();

	/*礶厚翴*/
	glPushMatrix();
	glTranslatef(0, 0, 0);
	int n = 100;
	GLfloat Pi = 3.14;
	glBegin(GL_POLYGON); //礶厚翴
	for (int i = 0; i < n; i++)
	{
		glColor3f(0, 1, 0.0); //砞竚肅︹3f把计疊翴计
		glVertex2f(PENGUIN_POINT*cos(2 * Pi / n*i), PENGUIN_POINT*sin(2 * Pi / n*i));//璸衡Г夹
	}
	glEnd();
	glPopMatrix();

	glTranslatef(0, -PENGUIN_LEG * 4 / 5, 0);
	glRotatef(angle.rightfoot, 0, 0, 1);

	/*厚翴*/
	glPushMatrix();
	//glTranslatef(PENGUIN_LEG * 0.25, PENGUIN_LEG * 0.1, 0);
	glBegin(GL_POLYGON); //礶厚翴
	for (int i = 0; i < n; i++)
	{
		glColor3f(0, 1, 0.0); //砞竚肅︹3f把计疊翴计
		glVertex2f(PENGUIN_POINT*cos(2 * Pi / n*i), PENGUIN_POINT*sin(2 * Pi / n*i));//璸衡Г夹
	}
	glEnd();
	glPopMatrix();

	
	glBegin(GL_POLYGON);
	//glColor3f(0.6, 0.6, 0.0); //砞竚肅︹3f把计疊翴计
	glColor3f(acolor.G + 0.3, acolor.B + 0.1, acolor.R - 0.2); //砞竚肅︹3f把计疊翴计
	glVertex2f(-PENGUIN_FOOT, -PENGUIN_FOOT);//璸衡Г夹
	glVertex2f(0, 0);//璸衡Г夹
	glVertex2f(PENGUIN_FOOT, -PENGUIN_FOOT);//璸衡Г夹
	glEnd();

	glPopMatrix();
	glPopMatrix();
}

