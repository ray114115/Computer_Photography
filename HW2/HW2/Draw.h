#pragma once

#include <Windows.h>
#include <glut.h>
#include "Global_parameter.h"
#include <cmath>

class Penguin
{
public:
	Angle angle;
	MoveA move;
	Color acolor;
	Penguin(Angle angleinput, MoveA moveinput,Color colorinput);

	void Move();
	void Draw();

	void Body();
	void Wing();
	void Head();
	void LeftLeg();
	void Mouth();
	void Eye();
	void RightLeg();

};