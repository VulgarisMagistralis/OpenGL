#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include <GL/glut.h>


float camX = 0, camY, camZ = 5;
int startX, startY, tracking = 0;

int alpha = 0, beta = 0, r = 5;

#define POINT_COUNT 5
// Points that make up the loop for catmull-rom interpolation
float p[POINT_COUNT][3] = { { -1, -1, 0 }, { -1, 1, 0 }, { 1, 1, 0 }, { 0, 0, 0 }, { 1, -1, 0 } };
void getCatmullRomPoint(float t, int *indices, float *res,float *rest) {

	// catmull-rom matrix
	 float m[4][4] = { { -0.5f, 1.5f, -1.5f, 0.5f },
	{ 1.0f, -2.5f, 2.0f, -0.5f },											 
	{ -0.5f, 0.0f, 0.5f, 0.0f },
	{ 0.0f, 1.0f, 0.0f, 0.0f } };
	
	 float mm[4][4] = { { 3 * t*t, 2 * t, 1, 0 },
	 { 0,1,0,0 },
	 { 2*t*0-1*1, 1*0-3*t*t*0, 3*t*t*0-2*t*0, 0.0f },
	 { 0.0f, 0.0f, 0.0f, 0.0f } };
	
	res[0] = 0.0; res[1] = 0.0; res[2] = 0.0;
	rest[0] = 0.0; rest[1] = 0.0; rest[2] = 0.0;
	// Compute point res = T * M * P
	int k = 0;
	float temp_arr[4];
	float tm[4] = { t*t*t, t*t, t, 1 };
	float tmt[4] = { 3 * t*t, 2 * t, 1, 0 };
	for (int i = 0; i < 4;++i){
		temp_arr[i]=0;
		for (int j = 0; j < 4; ++j){  
			temp_arr[i] += tm[j] * m[j][i];
		}
		
	}
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 4; ++j){
			res[i] += temp_arr[j]* p[indices[j]][i];
		}
	}
	for (int i = 0; i < 4; ++i){
		temp_arr[i] = 0;
		for (int j = 0; j < 4; ++j){
			temp_arr[i] += tmt[j] * mm[j][i];
		}

	}
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 4; ++j){
			rest[i] += temp_arr[j] * p[indices[j]][i];
		}
	}
	// where Pi = p[indices[i]]
	// ...
}
// given  global t, returns the point in the curve
void getGlobalCatmullRomPoint(float gt, float *res,float *rest) {

	float t = gt * POINT_COUNT; // this is the real global t
	int index = floor(t);  // which segment
	t = t - index; // where within  the segment

	// indices store the points
	int indices[4];
	indices[0] = (index + POINT_COUNT - 1) % POINT_COUNT;
	indices[1] = (indices[0] + 1) % POINT_COUNT;
	indices[2] = (indices[1] + 1) % POINT_COUNT;
	indices[3] = (indices[2] + 1) % POINT_COUNT;

	getCatmullRomPoint(t, indices, res,rest);
}
void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if (h == 0)
		h = 1;

	// compute window's aspect ratio 
	float ratio = w * 1.0 / h;

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective
	gluPerspective(45, ratio, 1, 1000);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}
void renderCatmullRomCurve() {
	float gt;
	float res[3];
	float rest[3];
	// desenhar a curva usando segmentos de reta - GL_LINE_LOOP
	
	glBegin(GL_LINE_LOOP);
	float ri[1000];
	float r = 0.03f;
	for (size_t i = 0; i < 500; i++)
	{
		r =r+ 0.002f;
		ri[i]=r;
	}
	for (size_t i = 0; i < 500; i++)
	{
		r =r- 0.002f;
		ri[500+i] = r;
	}
	for (int i = 0; i < 1000; ++i){
		gt = i / 1000.0f;
	
		glColor3f(ri[i], 0.6-ri[i], 0);
		getGlobalCatmullRomPoint(gt, res,rest);
		glVertex3fv(res);
	}
	glEnd();
}
float angle=0.01;
void renderScene(void) {
	static float t = 0;
	float res[3];
	float rest[3];
	//glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(camX, camY, camZ,
		0.0, 0.0, 0.0,
		0.0f, 1.0f, 0.0f);

	renderCatmullRomCurve();
	// apply transformations here
	// ...
	//t->gt will then get global
	getGlobalCatmullRomPoint(t, res, rest);
	glTranslatef(res[0], res[1], res[2]);
	glColor3f(1, 1, 1);
	glRotated(-angle, rest[0], rest[1], rest[2]);
	glutWireTeapot(0.4);
	angle=angle-0.0001;
	glutSwapBuffers();
	t += 0.00009;
}
void processMouseButtons(int button, int state, int xx, int yy)
{
	if (state == GLUT_DOWN)  {
		startX = xx;
		startY = yy;
		if (button == GLUT_LEFT_BUTTON)
			tracking = 1;
		else if (button == GLUT_RIGHT_BUTTON)
			tracking = 2;
		else
			tracking = 0;
	}
	else if (state == GLUT_UP) {
		if (tracking == 1) {
			alpha += (xx - startX);
			beta += (yy - startY);
		}
		else if (tracking == 2) {

			r -= yy - startY;
			if (r < 3)
				r = 3.0;
		}
		tracking = 0;
	}
}
void processMouseMotion(int xx, int yy)
{
	int deltaX, deltaY;
	int alphaAux, betaAux;
	int rAux;

	if (!tracking)
		return;

	deltaX = xx - startX;
	deltaY = yy - startY;

	if (tracking == 1) {

		alphaAux = alpha + deltaX;
		betaAux = beta + deltaY;

		if (betaAux > 85.0)
			betaAux = 85.0;
		else if (betaAux < -85.0)
			betaAux = -85.0;

		rAux = r;
	}
	else if (tracking == 2) {

		alphaAux = alpha;
		betaAux = beta;
		rAux = r - deltaY;
		if (rAux < 3)
			rAux = 3;
	}
	camX = rAux * sin(alphaAux * 3.14 / 180.0) * cos(betaAux * 3.14 / 180.0);
	camZ = rAux * cos(alphaAux * 3.14 / 180.0) * cos(betaAux * 3.14 / 180.0);
	camY = rAux *							     sin(betaAux * 3.14 / 180.0);
}
void main(int argc, char **argv) {
	// inicialization
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 320);
	glutCreateWindow("CG@DI-UM");

	// callback registration 
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);

	// mouse callbacks
	glutMouseFunc(processMouseButtons);
	glutMotionFunc(processMouseMotion);

	// OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	// enter GLUT's main cycle 
	glutMainLoop();
}
