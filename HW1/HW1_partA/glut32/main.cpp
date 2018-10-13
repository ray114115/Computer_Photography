//#include <windows.h>
#include <stdlib.h>
#include <glut.h>
#include <cmath>
#include <string.h>



void draw_polygon();
void draw_trian();
void draw_circle();
void draw_ellipse();
void print(float x, float y,float z, char *string);

void reshape(int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(60, 1, -1, 20);//<--------------------here
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef(0,0,-5); //<--------------------here
} 

void Display(void)
{
    glPushMatrix();
	print(-0.8,-0.9,0,"Hello Nurse!");
    draw_circle();
	draw_ellipse();
	draw_trian();
	draw_polygon();

    glPopMatrix();
    glutSwapBuffers();
}




int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(100, 100); // 設定視窗位置 
    glutInitWindowSize(500, 500); // 設定視窗大小 
    glutCreateWindow("Colorful Triangle "); // 設定視窗標題 
    glutDisplayFunc(Display);  // 呼叫函數 
    glutMainLoop();
    return 0;
}

void draw_circle()
{
	glTranslatef(0.7,0.7,0);
	int n = 100;
	GLfloat R = 0.2;
	GLfloat Pi = 3.14;

	glBegin(GL_POLYGON); //繪製方式
	//glColor3f(1.0, 0.0, 0.0); //設置顏色，3f代表參數為三個浮點數
	for (int i = 0; i < n; i++)
	{
		glColor3f(1.0 *i/n , 0.0, 0.0); //設置顏色，3f代表參數為三個浮點數
		glVertex2f(R*cos(2 * Pi / n*i), R*sin(2 * Pi / n*i));//計算坐標
	}
	glEnd();
	glFlush();
	
	glTranslatef(-0.7,-0.7,0);
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


void draw_ellipse()
{
	glTranslatef(-0.7,0.7,0);
	const int n = 100;
	const GLfloat R = 0.2;
	const GLfloat Y = 0.2*0.6;
	const GLfloat Pi = 3.14;
	
	glBegin(GL_POLYGON); 
	glColor3f(1.0, 0.0, 0.0); //設置顏色
	for (int i = 0; i < n; i++)
		glVertex2f(R*cos(2 * Pi / n*i),Y*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	glTranslatef(0.7,-0.7,0);

}

void draw_trian()
{
	glTranslatef(0.0,0.5,0);
	glBegin (GL_TRIANGLES);
        glColor3f (1.0f, 0.0f, 0.0f);         // 設定輸出色為紅色 
        glVertex2f (0.0f, 0.5f);
        glColor3f (0.0f, 0.0f, 1.0f);         // 設定輸出色為藍色 
        glVertex2f (0.25f,  0.0f); 
		glColor3f (0.0f, 1.0f, 0.0f);         // 設定輸出色為綠色 
        glVertex2f (-0.25f, 0.0f); 
    glEnd ();

	glFlush();
	glTranslatef(0.0,-0.5,0);
}

void draw_polygon()
{
	glTranslatef(0,-0.2,0);
	for(float i = 0.0;i<=0.6;i+=0.2)
	{
		glColor3f(1,1,1);
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
	glTranslatef(0,0.2,0);
}