
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
ShowImg *Img,*Img2,*Img3, *Img4;
Fl_Light_Button *but5;
Fl_Button *but1, *but2, *but3,*but6,*but4;
char* filename;
int state;


void quit(Fl_Widget*, void*)
{
	exit(0);
}



void button4_cb(Fl_Widget*)
{
	//char *filename = fl_file_chooser("Select file", "Image files (*.{bmp})", "", !0);
	//if (!filename) return;
	int w, h;
	BYTE *img = (BYTE *)malloc(sizeof(BYTE *));
	//BMP_Read(filename, &img, w, h);
	//Img->setImgData(img, w, h);
	

	unsigned char change = Img2->imageA[0] - Img3->imageA[0];

	for (int i = 0; i < Img->width; i++)
		for (int j = 0; j < Img->height; j++)
		{
			int tmp;
			if (Img->imageA[(j + i*Img->width) * 3 + 0] != 0)
				tmp = Img3->imageA[(j + i*Img3->width) * 3 + 0] + Img3->imageA[(j + i*Img3->width) * 3 + 0] * ((Img2->imageA[(j + i*Img2->width) * 3 + 0] - Img->imageA[(j + i*Img->width) * 3 + 0]) / Img->imageA[(j + i*Img->width) * 3 + 0]);
			else
				tmp = Img3->imageA[(j + i*Img3->width) * 3 + 0] + Img2->imageA[(j + i*Img2->width) * 3 + 0];
			if (tmp > 255) tmp = 255;
			else if (tmp < 0) tmp = 0;
			Img4->imageA[(j + i*Img->width) * 3 + 0] = tmp;
		
			int tmp1;
			if (Img->imageA[(j + i*Img->width) * 3 + 1] != 0)
				tmp1 = Img3->imageA[(j + i*Img3->width) * 3 + 1] + Img3->imageA[(j + i*Img3->width) * 3 + 1] * ((Img2->imageA[(j + i*Img2->width) * 3 + 1] - Img->imageA[(j + i*Img->width) * 3 + 1]) / Img->imageA[(j + i*Img->width) * 3 + 1]);
			else
				tmp1 = Img3->imageA[(j + i*Img3->width) * 3 + 1] + Img2->imageA[(j + i*Img2->width) * 3 + 1];
			if (tmp1 > 255) tmp1 = 255;
			else if (tmp1 < 0) tmp1 = 0;
			Img4->imageA[(j + i*Img->width) * 3 + 1] = tmp1;

			int tmp2;
			if (Img->imageA[(j + i*Img->width) * 3 + 2] != 0)
				tmp2 = Img3->imageA[(j + i*Img3->width) * 3 + 2] + Img3->imageA[(j + i*Img3->width) * 3 + 2] * ((Img2->imageA[(j + i*Img2->width) * 3 + 2] - Img->imageA[(j + i*Img->width) * 3 + 2]) / Img->imageA[(j + i*Img->width) * 3 + 2]);
			else
				tmp2 = Img3->imageA[(j + i*Img3->width) * 3 + 2] + Img2->imageA[(j + i*Img2->width) * 3 + 2];
			if (tmp2 > 255) tmp2 = 255;
			else if (tmp2 < 0) tmp2 = 0;
			Img4->imageA[(j + i*Img->width) * 3 + 2] = tmp2;


		}
	//printf("%d %d\n", Img->height, Img->width);
	printf("%d\n", change);
	
	Img4->redraw();
}

void button1_cb(Fl_Widget*)
{
	char *filename = fl_file_chooser("Select file", "Image files (*.{bmp})", "", !0);
	if (!filename) return;
	int w, h;
	BYTE *img = (BYTE *)malloc(sizeof(BYTE *));
	BMP_Read(filename, &img, w, h);
	Img->setImgData(img, w, h);
	Img->redraw();
}

void button2_cb(Fl_Widget*)
{
	char *filename = fl_file_chooser("Select file", "Image files (*.{bmp})", "", !0);
	if (!filename) return;
	int w, h;
	BYTE *img = (BYTE *)malloc(sizeof(BYTE *));
	BMP_Read(filename, &img, w, h);
	Img2->setImgData(img, w, h);
	Img2->redraw();
}
void button3_cb(Fl_Widget*)
{
	char *filename = fl_file_chooser("Select file", "Image files (*.{bmp})", "", !0);
	if (!filename) return;
	int w, h;
	BYTE *img = (BYTE *)malloc(sizeof(BYTE *));
	BMP_Read(filename, &img, w, h);
	Img3->setImgData(img, w, h);
	Img3->redraw();
}


//----------------------------------------------

int main(int  argc, char **argv)
{
	state = 1;
	int w, h;
	BYTE *img = (BYTE *)malloc(sizeof(BYTE *));
	BYTE *img2 = (BYTE *)malloc(sizeof(BYTE *));
	BYTE *img3 = (BYTE *)malloc(sizeof(BYTE *));
	BYTE *img4 = (BYTE *)malloc(sizeof(BYTE *));

	win = new Fl_Window(1850, 550, "HW1");

	Fl_Button *but = new Fl_Button(50, 500, 80, 30, "Quit");
	but->callback(quit);

	but1 = new Fl_Button(50, 440, 120, 30, "Change Image A");
	but1->labelsize(12);
	but1->callback(button1_cb);


	but2 = new Fl_Button(500, 440, 120, 30, "Change Image A'");
	but2->labelsize(12);
	but2->callback(button2_cb);

	but3 = new Fl_Button(950, 440, 120, 30, "Change Image B");
	but3->labelsize(12);
	but3->callback(button3_cb);

	but4 = new Fl_Button(1400, 440, 120, 30, "Run");
	but4->labelsize(12);
	but4->callback(button4_cb);

	BMP_Read("bird-A1.bmp", &img, w, h);
	Img = new ShowImg(50, 30, 400, 400);
	Img->setImgData(img, w, h);

	BMP_Read("bird-A2.bmp", &img2, w, h);
	Img2 = new ShowImg(500, 30, 400, 400);
	Img2->setImgData(img2, w, h);

	BMP_Read("bird-B1.bmp", &img3, w, h);
	Img3 = new ShowImg(950, 30, 400, 400);
	Img3->setImgData(img3, w, h);

	BMP_Read("bird-B2.bmp", &img4, w, h);
	Img4 = new ShowImg(1400, 30, 400, 400);
	Img4->setImgData(img4, w, h);
	win->end();
	win->show();

	

	return (Fl::run());
}