#pragma once


#ifndef  _GLOBAL_PARAMETER_H_


#include <FL/Fl_Scrollbar.H>
#include <FL/Fl_Output.H>

#define PENGUIN_SIZE 0.6
#define PENGUIN_BODY (PENGUIN_SIZE * 0.5)
#define PENGUIN_WING (PENGUIN_SIZE * 0.2)
#define PENGUIN_HEAD (PENGUIN_SIZE * 0.25)
#define PENGUIN_EYE (PENGUIN_HEAD * 0.2)
#define PENGUIN_MOUTH (PENGUIN_HEAD * 0.8)
#define PENGUIN_LEG (PENGUIN_BODY * 0.7)
#define PENGUIN_FOOT (PENGUIN_LEG * 0.5)
#define PENGUIN_POINT 0.01


#define BAR_SIZE_W 200
#define BAR_SIZE_H 30

#define HEAD_BAR_X 50
#define HEAD_BAR_Y 450
#define WING_BAR_X 300
#define WING_BAR_Y 450

#define RIGHTLEG_BAR_X 50
#define RIGHTLEG_BAR_Y 550
#define RIGHTFOOT_BAR_X 300
#define RIGHTFOOT_BAR_Y 550

#define LEFTLEG_BAR_X 50
#define LEFTLEG_BAR_Y 650
#define LEFTFOOT_BAR_X 300
#define LEFTFOOT_BAR_Y 650

#define POSITIONX_BAR_X 50
#define POSITIONX_BAR_Y 750
#define POSITIONY_BAR_X 300
#define POSITIONY_BAR_Y 750

#define COLORDELTA 0.02

typedef struct
{
	int Auto;
	int Move;
	int Mouth;
	int RotateFlag;
	int Color;
	struct
	{
		int head;
		int rightleg;
		int rightfoot;
		int leftleg;
		int leftfoot;
		int wing;
	}Rotate;

}Flag;

typedef struct
{
	int head;
	int rightleg;
	int rightfoot;
	int leftleg;
	int leftfoot;
	int wing;
}Angle;

typedef struct
{
	float x;
	float y;
	float z;
	float mouth;

} MoveA;

typedef struct
{
	Fl_Scrollbar *head;
	Fl_Scrollbar *rightleg;
	Fl_Scrollbar *rightfoot;
	Fl_Scrollbar *leftleg;
	Fl_Scrollbar *leftfoot;
	Fl_Scrollbar *wing;
	Fl_Scrollbar *positionx;
	Fl_Scrollbar *positiony;
}Penguin_Srcollbar;

typedef struct
{
	Fl_Output *head;
	Fl_Output *rightleg;
	Fl_Output *rightfoot;
	Fl_Output *leftleg;
	Fl_Output *leftfoot;
	Fl_Output *wing;
	Fl_Output *positionx;
	Fl_Output *positiony;
}Penguin_Output;

typedef struct
{
	float R;
	float G;
	float B;
}Color;

//BouncingPolygons *mygl_1;

#endif // ! _GLOBAL_PARAMETER_H_
