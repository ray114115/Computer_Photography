


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "BouncingPolygons.h"
#include "SMFLoader.h"

#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Choice.H>

Fl_Window *win;

//PolygonDraw *mygl;
BouncingPolygons *mygl_1;
Fl_Light_Button *but1, *but2, *but3, *but4, *but5;
int state;
bool L_sate = true;


void quit(Fl_Widget*, void*)
{
	exit(0);
}


void Change_File(Fl_Widget*, void*)
{
	char *filename = fl_file_chooser("Select file", "Image files (*.{bmp})", "", !0);
	if (!filename) return;
	int w, h;
}

void button1_cb(Fl_Widget*, void*)
{
	but1->value(1);
	but2->value(0);
	but4->value(0);
	but5->value(0);
	mygl_1->see = 1;
}
void button2_cb(Fl_Widget*, void*)
{
	but1->value(0);
	but2->value(1);
	but4->value(0);
	but5->value(0);
	mygl_1->see = 0;

}
void button3_cb(Fl_Widget*, void*)
{
	if (L_sate == true) {

		mygl_1->oepnLight();
		L_sate = false;
	}
	else {
		mygl_1->closeLight();
		L_sate = true;
	}


}
void button4_cb(Fl_Widget*, void*)
{
	but1->value(0);
	but2->value(0);
	but4->value(1);
	but5->value(0);
	mygl_1->see = 2;

}
void button5_cb(Fl_Widget*, void*)
{
	but1->value(0);
	but2->value(0);
	but4->value(0);
	but5->value(1);
	mygl_1->see = 3;
}





int main(int  argc, char **argv)
{
	win = new Fl_Window(900, 900, "HW3");
	mygl_1 = new BouncingPolygons(30, 30, 800, 600);

	win->end();
	win->show();

	return (Fl::run());
	/*
	state = 1;
	int w, h;


	win = new Fl_Window(900, 900, "HW2");

	Fl_Button *but = new Fl_Button(50, 500, 80, 30, "Quit");
	but->callback(quit);

	but1 = new Fl_Light_Button(200, 700, 80, 30, "duck1");
	but1->labelsize(12);
	but1->callback(button1_cb);


	but2 = new Fl_Light_Button(200, 730, 80, 30, "vision");
	but2->labelsize(12);
	but2->callback(button2_cb);

	but3 = new Fl_Light_Button(200, 820, 80, 30, "Light");
	but3->labelsize(12);
	but3->callback(button3_cb);

	but4 = new Fl_Light_Button(200, 790, 80, 30, "duck3");
	but4->labelsize(12);
	but4->callback(button4_cb);

	but5 = new Fl_Light_Button(200, 760, 80, 30, "duck2");
	but5->labelsize(12);
	but5->callback(button5_cb);



	mygl_1 = new BouncingPolygons(30, 30, 800, 600);

	win->end();
	win->show();

	return (Fl::run());
	*/
}