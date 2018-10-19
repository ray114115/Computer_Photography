#pragma once
#ifndef _DRAW_H_

#include <Windows.h>
#include <glut.h>
#include "Global_parameter.h"
#include <cmath>

class Penguin
{
public:

	Penguin(Angle angle, float x,float y,float z);

	void Move(float x, float y, float z);
	void Body();
	void Wing(int angle);
	void Head();
	void LeftLeg(int angle);
	void Mouth(int angle);
	void Eye();
	void RightLeg(int angle);
	void GreenPoint(float x, float y, float z);
	void Angle(float angle,float x,float y,float z);

};

Angle aAngle = { 0 };
#endif // !_DRAW_H_
