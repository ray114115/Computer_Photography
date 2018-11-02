


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "BouncingPolygons.h"
#include "SMFLoader.h"

#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Choice.H>

#include "Global.h";

Fl_Window *win;

BouncingPolygons *mygl_1;
Fl_Light_Button *but0, *but1, *but2, *but3, *but4, *but5;

float R, G, B;

void quit(Fl_Widget*, void*)
{
	exit(0);
}




void button1_cb(Fl_Widget*, void*)
{
	but1->value(1);
	but2->value(0);
	but3->value(0);
	but4->value(0);
	but5->value(0);
	mygl_1->oepnLight();
	R = 1;
	G = 1;
	B = 1;

}
void button2_cb(Fl_Widget*, void*)
{
	but1->value(0);
	but2->value(1);
	but3->value(0);
	but4->value(0);
	but5->value(0);
	mygl_1->oepnLight();
	R = 1;
	G = 0;
	B = 0;
}
void button3_cb(Fl_Widget*, void*)
{
	but1->value(0);
	but2->value(0);
	but3->value(1);
	but4->value(0);
	but5->value(0);
	mygl_1->oepnLight();
	R = 0;
	G = 1;
	B = 0;
}
void button4_cb(Fl_Widget*, void*)
{
	but1->value(0);
	but2->value(0);
	but3->value(0);
	but4->value(1);
	but5->value(0);
	mygl_1->oepnLight();
	R = 0;
	G = 0;
	B = 1;

}
void button5_cb(Fl_Widget*, void*)
{
	but1->value(0);
	but2->value(0);
	but3->value(0);
	but4->value(0);
	but5->value(1);
	mygl_1->closeLight();
}


int main(int  argc, char **argv)
{
	
	win = new Fl_Window(900, 900, "HW3");
	mygl_1 = new BouncingPolygons(30, 30, 800, 600,0);

	but0 = new Fl_Light_Button(200, 850, 80, 30, "Quit");
	but0->callback(quit);

	but1 = new Fl_Light_Button(200, 700, 80, 30, "White");
	but1->labelsize(12);
	but1->callback(button1_cb);


	but2 = new Fl_Light_Button(200, 730, 80, 30, "Red");
	but2->labelsize(12);
	but2->callback(button2_cb);

	but3 = new Fl_Light_Button(200, 760, 80, 30, "Green");
	but3->labelsize(12);
	but3->callback(button3_cb);

	but4 = new Fl_Light_Button(200, 790, 80, 30, "Blue");
	but4->labelsize(12);
	but4->callback(button4_cb);

	but5 = new Fl_Light_Button(200, 820, 80, 30, "Turn Off");
	but5->labelsize(12);
	but5->callback(button5_cb);

	Fl::focus(win);

	win->end();
	win->show();

	return (Fl::run());
}

void light() 
{
	GLfloat light_ambient[] = { R, G, B, 1.0 };
	GLfloat light_diffuse[] = { R, G, B, 1.0 };
	GLfloat light_specular[] = { R, G, B, 1.0 };


	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);

	/* ¿O¥ú */
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	//GLfloat light_ambient[] = { 1.0, 0.0, 0.0, 1.0 };
	//glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	//glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	//glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHTING);
}

