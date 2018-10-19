#pragma once

#ifndef  _GLOBAL_PARAMETER_H_


#define PENGUIN_SIZE 0.6
#define PENGUIN_BODY (PENGUIN_SIZE * 0.5)
#define PENGUIN_WING (PENGUIN_SIZE * 0.2)
#define PENGUIN_HEAD (PENGUIN_SIZE * 0.25)
#define PENGUIN_EYE (PENGUIN_HEAD * 0.2)
#define PENGUIN_MOUTH (PENGUIN_HEAD * 0.8)
#define PENGUIN_LEG (PENGUIN_BODY * 0.7)
#define PENGUIN_FOOT (PENGUIN_LEG * 0.5)
#define PENGUIN_POINT 0.01

typedef struct
{
	int angle;
	float x;
	float y;
	float z;

} MoveA;

typedef struct
{
	int Move;
	int Rotate;
}Flag;

typedef struct
{
	int head;
	int rightleg;
	int ringtfoot;
	int leftleg;
	int leftfoot;
	int wing;
}Angle;

//BouncingPolygons *mygl_1;

#endif // ! _GLOBAL_PARAMETER_H_
