
#include "Global_parameter.h"
#include "main.h"


class penguin_window : public Fl_Gl_Window { // Create a OpenGL class in FLTK 
	void draw();            // Draw function. 
	void draw_overlay();    // Draw overlay function. 
	static void Timer_CB(void *userdata) {
		penguin_window *pb = (penguin_window*)userdata;
		aMove = moveing(aMove);
		aAngle = rotating(aAngle);
		aColor = changeColor(aColor);
		pb->redraw();
		Fl::repeat_timeout(1.0 / 24.0, Timer_CB, userdata);
	}

public:
	penguin_window(int x, int y, int w, int h, const char *l = 0);  // Class constructor 
	int frame;

};

penguin_window::penguin_window(int x, int y, int w, int h, const char *l) :Fl_Gl_Window(x, y, w, h, l)
{
	mode(FL_RGB | FL_ALPHA | FL_DOUBLE | FL_STENCIL);
	Fl::add_timeout(1.0 / 24.0, Timer_CB, (void*)this);
	frame = 0;
}

void penguin_window::draw() {
	// the valid() property may be used to avoid reinitializing your
	// GL transformation for each redraw:
	if (!valid()) {
		valid(1);
		glLoadIdentity();
		glViewport(0, 0, w(), h());
	}

	// draw an amazing but slow graphic:--------------
	Penguin a(aAngle, aMove,aColor);

	//--------------------------------------------------
	++frame;
}



void penguin_window::draw_overlay() {
	// the valid() property may be used to avoid reinitializing your
	// GL transformation for each redraw:
	if (
		!valid()) {
		valid(1);
		glLoadIdentity();
		glViewport(0, 0, w(), h());
	}
	// draw an amazing graphic:-------------
	//---------------------------------------
}


void ScrollbarHEAD_CB(Fl_Widget*, void * ) {
	char s[20];
	sprintf(s, "%d", aPenguin_Scrollbar.head->value());
	out.head->value(s);
}
void ScrollbarRIGHTLEG_CB(Fl_Widget*, void *) {
	char s[20];
	sprintf(s, "%d", aPenguin_Scrollbar.rightleg->value());
	out.rightleg->value(s);
}
void ScrollbarRIGHTFOOT_CB(Fl_Widget*, void *) {
	char s[20];
	sprintf(s, "%d", aPenguin_Scrollbar.rightfoot->value());
	out.rightfoot->value(s);
}
void ScrollbarLEFTLEG_CB(Fl_Widget*, void *) {
	char s[20];
	sprintf(s, "%d", aPenguin_Scrollbar.leftleg->value());
	out.leftleg->value(s);
}
void ScrollbarLEFTFOOT_CB(Fl_Widget*, void *) {
	char s[20];
	sprintf(s, "%d", aPenguin_Scrollbar.leftfoot->value());
	out.leftfoot->value(s);
}
void ScrollbarWING_CB(Fl_Widget*, void *) {
	char s[20];
	sprintf(s, "%d", aPenguin_Scrollbar.wing->value());
	out.wing->value(s);
}
void ScrollbarY_CB(Fl_Widget*, void *) {
	char s[20];
	sprintf(s, "%d", aPenguin_Scrollbar.positiony->value());
	out.positiony->value(s);
}
void ScrollbarX_CB(Fl_Widget*, void *) {
	char s[20];
	sprintf(s, "%d", aPenguin_Scrollbar.positionx->value());
	out.positionx->value(s);
}

//--------Setting FL Choice function here
Fl_Choice *choice1 = (Fl_Choice *)0;
Fl_Menu_Item menu_choice1[] = {  // Create choice menu
	{ "Auto Mode (with initial)", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0 },
	{ "Auto Mode", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0 },
	{ "User Mode", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0 },
	{ 0,0,0,0,0,0,0,0,0 }
};

void choice1_cb(Fl_Widget *o, void *p)   // choice callback function
{
	int temp = int(((Fl_Choice*)o)->value());
	penguin_window *gl_win = (penguin_window *)p;
	gl_win->redraw();
	gl_win->redraw_overlay();
	switch (temp)
	{
	case 0:
		aAngle = { 0,0,0,0,0,0 };
		//aMove = { 0.5,0.5,0,0 };
		//aColor = { float(0.3),float(0.3),float(0.3) };
		aFlag.Auto = 1;
		break;
	case 1:
		aFlag.Auto = 1;
		break;
	case 2:
		aFlag.Auto = 0;
		break;
	default:
		printf("Other\n");
		break;
	}
}

int main(int argc, char *argv[])
{
	
	Fl_Window window(640, 880);  // Create a FLTK window. Resolution 600*400. 

	penguin_window aPenguin(10, 10, 600, 400);
	window.resizable(&aPenguin);


	Scrollbar();
	
	choice1 = new Fl_Choice(530, 450, 100, 20);    // Add Choice ui in position (200,420). width=100 height=20  
	choice1->down_box(FL_BORDER_BOX);
	choice1->menu(menu_choice1);
	choice1->callback(choice1_cb, &aPenguin);


	window.end();                  // End of FLTK windows setting. 
	window.show(argc, argv);        // Show the FLTK window
	aPenguin.show();
	aPenguin.redraw_overlay();

	

	return Fl::run();
	
}

void Scrollbar() 
{
	// Create scrollbarHead
	aPenguin_Scrollbar.head = new Fl_Scrollbar(HEAD_BAR_X, HEAD_BAR_Y, BAR_SIZE_W, BAR_SIZE_H, "Head Angle");
	aPenguin_Scrollbar.head->type(FL_HORIZONTAL);
	aPenguin_Scrollbar.head->bounds(0, 400);              // min/max value of the slider's positions
	((Fl_Valuator*)aPenguin_Scrollbar.head)->value(0); // the initial value (in fltk1.3+ you can use scrollbarHead->value(150); 
	aPenguin_Scrollbar.head->step(1);
	aPenguin_Scrollbar.head->callback(ScrollbarHEAD_CB, (void*)&out.head);
	// Create output to show scrollbar's value
	out.head = new Fl_Output(HEAD_BAR_X + 100, HEAD_BAR_Y + 50, 80, 30, "Scrollbar Value:");
	out.head->textsize(24);

	// Create scrollbarHead
	aPenguin_Scrollbar.wing = new Fl_Scrollbar(WING_BAR_X, WING_BAR_Y, BAR_SIZE_W, BAR_SIZE_H, "Wing Angle");
	aPenguin_Scrollbar.wing->type(FL_HORIZONTAL);
	aPenguin_Scrollbar.wing->bounds(0, 400);              // min/max value of the slider's positions
	((Fl_Valuator*)aPenguin_Scrollbar.wing)->value(0); // the initial value (in fltk1.3+ you can use scrollbarHead->value(150); 
	aPenguin_Scrollbar.wing->step(1);
	aPenguin_Scrollbar.wing->callback(ScrollbarWING_CB, (void*)&out.wing);
	// Create output to show scrollbar's value
	out.wing = new Fl_Output(WING_BAR_X + 100, WING_BAR_Y + 50, 80, 30, "Scrollbar Value:");
	out.wing->textsize(24);

	// Create scrollbarrightleg
	aPenguin_Scrollbar.rightleg = new Fl_Scrollbar(RIGHTLEG_BAR_X, RIGHTLEG_BAR_Y, BAR_SIZE_W, BAR_SIZE_H, "Left Leg Angle");
	aPenguin_Scrollbar.rightleg->type(FL_HORIZONTAL);
	aPenguin_Scrollbar.rightleg->bounds(0, 400);              // min/max value of the slider's positions
	((Fl_Valuator*)aPenguin_Scrollbar.rightleg)->value(0); // the initial value (in fltk1.3+ you can use scrollbarHead->value(150); 
	aPenguin_Scrollbar.rightleg->step(1);
	aPenguin_Scrollbar.rightleg->callback(ScrollbarRIGHTLEG_CB, (void*)&out.rightleg);
	// Create output to show scrollbar's value
	out.rightleg = new Fl_Output(RIGHTLEG_BAR_X + 100, RIGHTLEG_BAR_Y + 50, 80, 30, "Scrollbar Value:");
	out.rightleg->textsize(24);

	// Create scrollbarrightleg
	aPenguin_Scrollbar.rightfoot = new Fl_Scrollbar(RIGHTFOOT_BAR_X, RIGHTFOOT_BAR_Y, BAR_SIZE_W, BAR_SIZE_H, "Left Foot Angle");
	aPenguin_Scrollbar.rightfoot->type(FL_HORIZONTAL);
	aPenguin_Scrollbar.rightfoot->bounds(0, 400);              // min/max value of the slider's positions
	((Fl_Valuator*)aPenguin_Scrollbar.rightfoot)->value(0); // the initial value (in fltk1.3+ you can use scrollbarHead->value(150); 
	aPenguin_Scrollbar.rightfoot->step(1);
	aPenguin_Scrollbar.rightfoot->callback(ScrollbarRIGHTFOOT_CB, (void*)&out.rightfoot);
	// Create output to show scrollbar's value
	out.rightfoot = new Fl_Output(RIGHTFOOT_BAR_X + 100, RIGHTLEG_BAR_Y + 50, 80, 30, "Scrollbar Value:");
	out.rightfoot->textsize(24);
	
	// Create scrollbarleftleg
	aPenguin_Scrollbar.leftleg = new Fl_Scrollbar(LEFTLEG_BAR_X, LEFTLEG_BAR_Y, BAR_SIZE_W, BAR_SIZE_H, "Right Leg Angle");
	aPenguin_Scrollbar.leftleg->type(FL_HORIZONTAL);
	aPenguin_Scrollbar.leftleg->bounds(0, 400);              // min/max value of the slider's positions
	((Fl_Valuator*)aPenguin_Scrollbar.leftleg)->value(0); // the initial value (in fltk1.3+ you can use scrollbarHead->value(150); 
	aPenguin_Scrollbar.leftleg->step(1);
	aPenguin_Scrollbar.leftleg->callback(ScrollbarLEFTLEG_CB, (void*)&out.leftleg);
	// Create output to show scrollbar's value
	out.leftleg = new Fl_Output(LEFTLEG_BAR_X + 100, LEFTLEG_BAR_Y + 50, 80, 30, "Scrollbar Value:");
	out.leftleg->textsize(24);

	// Create scrollbarleftleg
	aPenguin_Scrollbar.leftfoot = new Fl_Scrollbar(LEFTFOOT_BAR_X, LEFTFOOT_BAR_Y, BAR_SIZE_W, BAR_SIZE_H, "Right Foot Angle");
	aPenguin_Scrollbar.leftfoot->type(FL_HORIZONTAL);
	aPenguin_Scrollbar.leftfoot->bounds(0, 400);              // min/max value of the slider's positions
	((Fl_Valuator*)aPenguin_Scrollbar.leftfoot)->value(0); // the initial value (in fltk1.3+ you can use scrollbarHead->value(150); 
	aPenguin_Scrollbar.leftfoot->step(1);
	aPenguin_Scrollbar.leftfoot->callback(ScrollbarLEFTFOOT_CB, (void*)&out.leftfoot);
	// Create output to show scrollbar's value
	out.leftfoot = new Fl_Output(LEFTFOOT_BAR_X + 100, LEFTLEG_BAR_Y + 50, 80, 30, "Scrollbar Value:");
	out.leftfoot->textsize(24);

	// Create scrollbarleftleg
	aPenguin_Scrollbar.positionx = new Fl_Scrollbar(POSITIONX_BAR_X, POSITIONX_BAR_Y, BAR_SIZE_W, BAR_SIZE_H, "Position X");
	aPenguin_Scrollbar.positionx->type(FL_HORIZONTAL);
	aPenguin_Scrollbar.positionx->bounds(0, 100);              // min/max value of the slider's positions
	((Fl_Valuator*)aPenguin_Scrollbar.positionx)->value(0); // the initial value (in fltk1.3+ you can use scrollbarHead->value(150); 
	aPenguin_Scrollbar.positionx->step(1);
	aPenguin_Scrollbar.positionx->callback(ScrollbarX_CB, (void*)&out.positionx);
	// Create output to show scrollbar's value
	out.positionx = new Fl_Output(POSITIONX_BAR_X + 100, POSITIONX_BAR_Y + 50, 80, 30, "Scrollbar Value:");
	out.positionx->textsize(24);

	// Create scrollbarleftleg
	aPenguin_Scrollbar.positiony = new Fl_Scrollbar(POSITIONY_BAR_X, POSITIONY_BAR_Y, BAR_SIZE_W, BAR_SIZE_H, "Position Y");
	aPenguin_Scrollbar.positiony->type(FL_HORIZONTAL);
	aPenguin_Scrollbar.positiony->bounds(0, 100);              // min/max value of the slider's positions
	((Fl_Valuator*)aPenguin_Scrollbar.positiony)->value(0); // the initial value (in fltk1.3+ you can use scrollbarHead->value(150); 
	aPenguin_Scrollbar.positiony->step(1);
	aPenguin_Scrollbar.positiony->callback(ScrollbarY_CB, (void*)&out.positiony);
	// Create output to show scrollbar's value
	out.positiony = new Fl_Output(POSITIONY_BAR_X + 100, POSITIONY_BAR_Y + 50, 80, 30, "Scrollbar Value:");
	out.positiony->textsize(24);

}


Angle rotating(Angle angle)
{
	if (aFlag.Auto)
	{
		if (aFlag.RotateFlag) {
			if (aFlag.Rotate.head)
				angle.head += 1;
			if (aFlag.Rotate.leftfoot)
				angle.leftfoot += 1;
			if (aFlag.Rotate.leftleg)
				angle.leftleg += 1;
			if (aFlag.Rotate.rightfoot)
				angle.rightfoot -= 1;
			if (aFlag.Rotate.rightleg)
				angle.rightleg -= 1;
			if (aFlag.Rotate.wing)
				angle.wing += 1;
		}
		else
		{
			if (aFlag.Rotate.head)
				angle.head -= 1;
			if (aFlag.Rotate.leftfoot)
				angle.leftfoot -= 1;
			if (aFlag.Rotate.leftleg)
				angle.leftleg -= 1;
			if (aFlag.Rotate.rightfoot)
				angle.rightfoot += 1;
			if (aFlag.Rotate.rightleg)
				angle.rightleg += 1;
			if (aFlag.Rotate.wing)
				angle.wing -= 1;
		}
		if (angle.head > 30)
		{
			aFlag.RotateFlag = 0;
		}
		else if (angle.head < -30)
		{
			aFlag.RotateFlag = 1;
		}
	}
	else
	{
		angle.head = aPenguin_Scrollbar.head->value();
		angle.leftfoot = aPenguin_Scrollbar.leftfoot->value();
		angle.leftleg = aPenguin_Scrollbar.leftleg->value();
		angle.rightfoot = aPenguin_Scrollbar.rightfoot->value();
		angle.rightleg = aPenguin_Scrollbar.rightleg->value();
		angle.wing = aPenguin_Scrollbar.wing->value();
	}
	return angle;
}

Color changeColor(Color color)
{
	if(aFlag.Auto == 1)
	{
		if (aFlag.Color == 0)
		{
			if (color.B < 0.7 )
				color.B += COLORDELTA;
			else if (color.B >= 0.7 && color.R < 0.7)
				color.R += COLORDELTA;
			else if (color.R >= 0.7 && color.G < 0.7)
				color.G += COLORDELTA;
			else aFlag.Color = 1;
		}
		else
		{
			if (color.B > 0.3)
				color.B -= COLORDELTA;
			else if (color.B <= 0.3 && color.R >= 0.3)
				color.R -= COLORDELTA;
			else if (color.R <= 0.3 && color.G > 0.3)
				color.G -= COLORDELTA;
			else aFlag.Color = 0;
		}
		
	}
	return color;
}

MoveA moveing(MoveA x)
{
	if (aFlag.Auto == 1) {
		if (aFlag.Move == 0)
		{
			x.x += 0.01;
		}
		else
		{
			x.x -= 0.01;
		}
		if (x.x > 0.5)
			aFlag.Move = 1;
		else if (x.x < -0.5)
			aFlag.Move = 0;

		if (aFlag.Mouth == 1)
		{
			x.mouth += 0.001;
		}
		else
		{
			x.mouth -= 0.001;
		}

		if (x.mouth >= 0.01)
			aFlag.Mouth = 0;
		else if (x.mouth <= -0.005)
			aFlag.Mouth = 1;
		
	}
	else
	{
		x.x = float((aPenguin_Scrollbar.positionx->value() - 50)) / 100;
		x.y = float((aPenguin_Scrollbar.positiony->value() - 50)) / 100;
	}
	return x;
}


