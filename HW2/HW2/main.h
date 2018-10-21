#pragma once

#ifndef _MAIN_H_



#include <windows.h>
#include <glut.h>
#include <stdio.h>
#include "Draw.h"

#include <FL/Fl.H>
#include <FL/gl.h>
#include <FL/Fl_Gl_Window.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>

void Display1();
void timerFunction(int p);
void keyboard(unsigned char key, int x, int y);
void rotateFourpart(int x, int y);
float moveing(float x);
int rotating(int angle);

int flag = 0;
MoveA aMove = { 0.5,0.5,0 };
Flag aFlag = { 0 };
Angle aAngle = { 0,30,0,0,0,0 };

#endif // !_MAIN_H_
