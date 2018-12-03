#ifdef _WIN32
#  include <windows.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#ifndef __APPLE__
#  include <GL/glut.h>
#else
#  include <GLUT/glut.h>
#endif
#include <AR/gsub.h>
#include <AR/video.h>
#include <AR/param.h>
#include <AR/ar.h>

#define  OBJ1_PATT_NAME    "Data/patt.hiro"
#define  OBJ2_PATT_NAME    "Data/patt.kanji"
#define  OBJ3_PATT_NAME    "Data/patt.sample1"
#define  OBJ4_PATT_NAME    "Data/patt.sample2"
#define  OBJ1_SIZE         80.0
#define  OBJ2_SIZE         80.0

#define  DELTA				50
#define  LENGTH				100

#define  OBJ1_MODEL_ID      1
#define  OBJ2_MODEL_ID      2
#define  OBJ3_MODEL_ID      3
#define  OBJ4_MODEL_ID      4

typedef struct {
	char    *patt_name;
	int     patt_id;
	int     model_id;
	int     visible;
	double  width;
	double  center[2];
	int     cylinder[3];//圓盤疊的位置跟大小
	double  trans[3][4];
} OBJECT_T;

OBJECT_T   object[4] = {
	{ OBJ1_PATT_NAME, -1, OBJ1_MODEL_ID, 0, OBJ1_SIZE,{ 0.0,0.0 },{ 0,0,0 } },
	{ OBJ2_PATT_NAME, -1, OBJ2_MODEL_ID, 0, OBJ2_SIZE,{ 0.0,0.0 },{ 3,2,1 } },
	{ OBJ3_PATT_NAME, -1, OBJ3_MODEL_ID, 0, OBJ2_SIZE,{ 0.0,0.0 },{ 0,0,0 } },
	{ OBJ4_PATT_NAME, -1, OBJ4_MODEL_ID, 0, OBJ2_SIZE,{ 0.0,0.0 },{ 0,0,0 } }
};

/* set up the video format globals */

#ifdef _WIN32
char			*vconf = "Data\\WDM_camera_flipV.xml";
#else
char			*vconf = "";
#endif

int             xsize, ysize;
int             thresh = 100;
int             count = 0;
int				move = 0;
int				previous = -1;

char           *cparam_name = "Data/camera_para.dat";
ARParam         cparam;

static void   init(void);
static void   cleanup(void);
static void   keyEvent(unsigned char key, int x, int y);
static void   mainLoop(void);
static void   draw(int object, double trans[3][4],int cylinder[3]);



int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	init();

	arVideoCapStart();
	argMainLoop(NULL, keyEvent, mainLoop);
	return (0);
}

static void   keyEvent(unsigned char key, int x, int y)
{
	/* quit if the ESC key is pressed */
	if (key == 0x1b) {
		printf("*** %f (frame/sec)\n", (double)count / arUtilTimer());
		cleanup();
		exit(0);
	}
}

/* main loop */
static void mainLoop(void)
{
	ARUint8         *dataPtr;
	ARMarkerInfo    *marker_info;
	int             marker_num;
	int             i, j, k;
	int				tmp =-1;

	/* grab a vide frame */
	if ((dataPtr = (ARUint8 *)arVideoGetImage()) == NULL) {
		arUtilSleep(2);
		return;
	}
	if (count == 0) arUtilTimerReset();
	count++;

	argDrawMode2D();
	argDispImage(dataPtr, 0, 0);

	/* detect the markers in the video frame */
	if (arDetectMarker(dataPtr, thresh, &marker_info, &marker_num) < 0) {
		cleanup();
		exit(0);
	}
	arVideoCapNext();

	argDrawMode3D();
	argDraw3dCamera(0, 0);
	glClearDepth(1.0);
	glClear(GL_DEPTH_BUFFER_BIT);

	/* check for object visibility */
	for (i = 0; i < 4; i++) {
		k = -1;
		for (j = 0; j < marker_num; j++) {
			if (object[i].patt_id == marker_info[j].id) {
				if (k == -1) k = j;
				else if (marker_info[k].cf < marker_info[j].cf) k = j;
			}
		}
		object[i].visible = k;
		if (k >= 0) {
			arGetTransMat(&marker_info[k],
				object[i].center, object[i].width,
				object[i].trans);
			/*check touch*/
			if (object[i].model_id == 1)	//抓到標誌物
			{
				tmp = i;
				for (j = 0; j < 4; j++) {
					if (j != tmp &&
						(abs(object[tmp].trans[0][3] - LENGTH * object[tmp].trans[0][2] - object[j].trans[0][3]) < DELTA) &&
						(abs(object[tmp].trans[1][3] + LENGTH * object[tmp].trans[1][2] - object[j].trans[1][3]) < DELTA) &&
						(abs(object[tmp].trans[2][3] - LENGTH * object[tmp].trans[2][2] - object[j].trans[2][3]) < DELTA) &&
						(abs(object[tmp].trans[2][3] - object[j].trans[2][3]) > 0)
						) {
						if (object[tmp].cylinder[0] != 0 &&
							object[j].model_id != previous) {
							printf("move = %d\n",++move);
							previous = object[j].model_id;
							for (int a = 0; a < 3; a++) {
								if (object[j].cylinder[a] == 0) {
									object[j].cylinder[a] = object[tmp].cylinder[0];
									object[tmp].cylinder[0] = 0;
									break;
								}
							}
						}
						else if (object[tmp].cylinder[0] == 0 &&
							object[j].model_id != previous){
							previous = object[j].model_id;
							for (int a = 0; a < 3; a++) {
								if (object[j].cylinder[2-a] != 0) {
									object[tmp].cylinder[0] = object[j].cylinder[2-a];
									object[j].cylinder[2-a] = 0;
									break;
								}
							}							

						}
					}
					
				}
			}
			draw(object[i].model_id, object[i].trans,object[i].cylinder);
		}
	}
	//用4個標誌，一個當提取物，另外三個當金字塔，提取物與金字塔重疊時，金字塔上的圓圈移到提取物上
	
	
	argSwapBuffers();

	if (object[1].visible >= 0
		&& object[2].visible >= 0
		) {
		double  wmat1[3][4], wmat2[3][4];

		arUtilMatInv(object[1].trans, wmat1);
		arUtilMatMul(wmat1, object[2].trans, wmat2);

		/*
		for (j = 0; j < 3; j++) {
			for (i = 0; i < 4; i++) printf("%8.4f ", wmat2[j][i]);
			printf("\n");
		}
		printf("\n\n");
		*/
		
	}
}

static void init(void)
{
	ARParam  wparam;
	int      i;

	/* open the video path */
	if (arVideoOpen(vconf) < 0) exit(0);
	/* find the size of the window */
	if (arVideoInqSize(&xsize, &ysize) < 0) exit(0);
	printf("Image size (x,y) = (%d,%d)\n", xsize, ysize);

	/* set the initial camera parameters */
	if (arParamLoad(cparam_name, 1, &wparam) < 0) {
		printf("Camera parameter load error !!\n");
		exit(0);
	}
	arParamChangeSize(&wparam, xsize, ysize, &cparam);
	arInitCparam(&cparam);
	printf("*** Camera Parameter ***\n");
	arParamDisp(&cparam);

	for (i = 0; i < 4; i++) {
		if ((object[i].patt_id = arLoadPatt(object[i].patt_name)) < 0) {
			printf("pattern load error: %s\n", object[i].patt_name);
			exit(0);
		}
	}

	/* open the graphics window */
	argInit(&cparam, 1.0, 0, 0, 0, 0);
}

/* cleanup function called when program exits */
static void cleanup(void)
{
	arVideoCapStop();
	arVideoClose();
	argCleanup();
}

static void draw(int object, double trans[3][4], int cylinder[3])
{
	double    gl_para[16];
	GLfloat   mat_ambient[] = { 0.0, 0.0, 1.0, 1.0 };
	GLfloat   mat_flash[] = { 0.0, 0.0, 1.0, 1.0 };
	GLfloat   mat_flash_shiny[] = { 50.0 };
	GLfloat   light_position[] = { 100.0,-200.0,200.0,0.0 };
	GLfloat   ambi[] = { 0.1, 0.1, 0.1, 0.1 };
	GLfloat   lightZeroColor[] = { 0.9, 0.9, 0.9, 0.1 };

	argDrawMode3D();
	argDraw3dCamera(0, 0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	/* load the camera transformation matrix */
	argConvGlpara(trans, gl_para);
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixd(gl_para);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambi);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightZeroColor);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_flash);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_flash_shiny);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMatrixMode(GL_MODELVIEW);


	switch (object) {
	case 0:
		glTranslatef(0.0, 0.0, 25.0);
		glutSolidCube(50.0);
		break;
	case 1:
		GLUquadricObj *quadratic1;
		quadratic1 = gluNewQuadric();
		gluCylinder(quadratic1, 3, 3, 100, 32, 5); //(X,前半徑,後半徑,長度,形狀,X)

		break;
	case 2:
		GLUquadricObj *quadratic2;
		quadratic2 = gluNewQuadric();
		gluCylinder(quadratic2, 3, 3, 100, 32, 5); //(X,前半徑,後半徑,長度,形狀,X)
		break;
	case 3:
		GLUquadricObj *quadratic3;
		quadratic3 = gluNewQuadric();
		gluCylinder(quadratic3, 3, 3, 100, 32, 5); //(X,前半徑,後半徑,長度,形狀,X)
		break;
	case 4:
		GLUquadricObj *quadratic4;
		quadratic4 = gluNewQuadric();
		gluCylinder(quadratic4, 3, 3, 100, 32, 5); //(X,前半徑,後半徑,長度,形狀,X)

		break;
	default:
		glTranslatef(0.0, 0.0, 10.0);
		glutSolidTorus(10.0, 40.0, 24, 24);
		break;
	}

	int count = 0;
	for (int i = 0; i < 3; i++) {
		glTranslatef(0.0, 0.0, 10 * cylinder[i]);
		if (cylinder[i] >= 1) {
			count++;
			glutSolidTorus(5.0 * cylinder[i], 40.0, 24, 24);
		}
	}

	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
}

