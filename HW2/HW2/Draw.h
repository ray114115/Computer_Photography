#pragma once

#include <Windows.h>
#include <glut.h>
#include "Global_parameter.h"
#include <cmath>

class Penguin
{
public:

	Penguin(float x,float y,float z);

	void Move(float x, float y, float z);
	void Body();
	void Wing();
	void Head();
	void LeftLeg();
	void Mouth();
	void Eye();
	void RightLeg();

};
