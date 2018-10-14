
#include "Draw.h"





Penguin::Penguin(float x, float y, float z)
{
	glPushMatrix();

	glTranslatef(x, y,z);
	this->Body();

	glPopMatrix();
}

void Penguin :: Body() {
	glPushMatrix();

	int n = 100;
	GLfloat R = 0.2;
	GLfloat Pi = 3.14;

	glBegin(GL_POLYGON); //酶籹よΑ
	glColor3f(0.0, 0.0, 1.0); //砞竚肅︹3f把计疊翴计

	for (int i = 0; i < n; i++)
	{
		glColor3f(0.0, 0.0, 1.0); //砞竚肅︹3f把计疊翴计
		glVertex2f(R*0.6*cos(2 * Pi / n*i), R*sin(2 * Pi / n*i));//璸衡Г夹
	}

	glEnd();


	glPopMatrix();
}

