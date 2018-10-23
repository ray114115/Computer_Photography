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
#include <FL/Fl_Scrollbar.H>
#include <FL/Fl_Output.H>


void Scrollbar();
MoveA moveing(MoveA x);
Angle rotating(Angle angle);
Color changeColor(Color color);


MoveA aMove = { 0.5,0.5,0,0 };
Flag aFlag = { 1,0,0,1,0,{1,1,1,1,1,1} }; //auto,move,rotateflag
Angle aAngle = { 0,0,0,0,0,0 };
Color aColor = { 0.3,0.3,0.3 };





Penguin_Srcollbar     aPenguin_Scrollbar = {0,0,0,0,0,0,0,0};
Penguin_Output        out = { 0,0,0,0,0,0,0,0 };


#endif // !_MAIN_H_
