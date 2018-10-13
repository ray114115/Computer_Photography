
#include "BouncingPolygons.h"
#include "ShowImg.h"
#include "READ_BMP.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Choice.H>

Fl_Window *win;

BouncingPolygons *mygl_1;
ShowImg *Img;
Fl_Light_Button *but1,*but2,*but3,*but4,*but5;
Fl_Button *but6;
char* filename;
int state;


void quit(Fl_Widget*, void*) 
{
	exit(0);
}


void button1_cb(Fl_Widget*, void*) 
{
	but1->value(1);
	but2->value(0);
	but3->value(0);
	but4->value(1);
	but5->value(0);
	mygl_1->shape=1;
	mygl_1->ee=1;
}
void button2_cb(Fl_Widget*, void*) 
{
	but1->value(0);
	but2->value(1);
	but3->value(0);
	but4->value(1);
	but5->value(0);
	mygl_1->shape=2;
	mygl_1->ee=1;
}
void button3_cb(Fl_Widget*, void*) 
{
	but1->value(0);
	but2->value(0);
	but3->value(1);
	but4->value(1);
	but5->value(0);
	mygl_1->shape=3;
	mygl_1->ee=1;
}
void button4_cb(Fl_Widget*, void*) 
{
	but1->value(1);
	but2->value(0);
	but3->value(0);
	but4->value(1);
	but5->value(0);
	mygl_1->shape=1;
	mygl_1->ee=1;
}
void button5_cb(Fl_Widget*, void*) 
{
	but1->value(0);
	but2->value(0);
	but3->value(0);
	but4->value(0);
	but5->value(1);
	mygl_1->shape=0;
	mygl_1->ee=2;
}

void button6_cb(Fl_Widget*) 
{
	char *filename = fl_file_chooser("Select file","Image files (*.{bmp})","",!0);
	if( !filename ) return;
	int w,h;
	BYTE *img = (BYTE *)malloc(sizeof(BYTE *));
	BMP_Read(filename,&img,w,h);
	Img->setImgData(img,w,h);
	Img->redraw();
}



Fl_Choice *choice=(Fl_Choice *)0;
Fl_Menu_Item menu_choice[] = {      // Create choice menu
	{"Line", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
	{"Circle", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
	{"Rectangle", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
	{0,0,0,0,0,0,0,0,0}
};

void choice_cb(Fl_Widget *o)    // choice callback function
{
	int temp=int(((Fl_Choice*)o)->value());
	win->redraw();
	switch(temp)
	{
	case 0:
		
		but1->value(1);
		but2->value(0);
		but3->value(0);
		but4->value(1);
		but5->value(0);
		mygl_1->ee=1;
		mygl_1->shape=1;
		break;
	case 1:
	
		but1->value(0);
		but2->value(1);
		but3->value(0);
		but4->value(1);
		but5->value(0);
		mygl_1->ee=1;
		mygl_1->shape=2;
		break;
	case 2:
		
		but1->value(0);
		but2->value(0);
		but3->value(1);
		but4->value(1);
		but5->value(0);
		mygl_1->ee=1;
		mygl_1->shape=3;
		break;
	default:
		printf("Other\n");
		break;
	}
}
//----------------------------------------------

int main(int  argc, char **argv)
{
	state = 1;
	int w,h;
	BYTE *img = (BYTE *)malloc(sizeof(BYTE *));
	BMP_Read("pan.bmp",&img,w,h);

	win = new Fl_Window(900, 550,"HW1");

	Fl_Button *but = new Fl_Button(50, 500, 80, 30, "Quit");
	but->callback(quit);
	
	but1 = new Fl_Light_Button(200, 440, 80, 30, "Line");
	but1->labelsize(12);
	but1->callback(button1_cb);


	but2 = new Fl_Light_Button(200, 470, 80, 30, "Circle");
	but2->labelsize(12);
	but2->callback(button2_cb);

	but3 = new Fl_Light_Button(200, 500,80, 30, "Rectangle");
	but3->labelsize(12);
	but3->callback(button3_cb);

	but4 = new Fl_Light_Button(50, 440, 80, 30, "Draw");
	but4->labelsize(12);
	but4->callback(button4_cb);

	but5 = new Fl_Light_Button(50, 470, 80, 30, "Selection");
	but5->labelsize(12);
	but5->callback(button5_cb);

	but6 = new Fl_Button(500, 440, 120, 30, "Change Image");
	but6->labelsize(12);
	but6->callback(button6_cb);

	choice = new Fl_Choice(350, 450 , 100 , 20);    // Add Choice ui in position (200,450). width=100 height=20  
	choice->down_box(FL_BORDER_BOX);
	choice->menu(menu_choice);
	choice->callback(choice_cb);


	Img = new ShowImg(450,30,400,400);
	Img->setImgData(img,w,h);


	mygl_1 = new BouncingPolygons(30, 30, 400, 400);

	win->end();
	win->show();

	return (Fl::run());
}