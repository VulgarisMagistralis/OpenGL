#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <sstream>
#include <string.h>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <GL\glew.h>
#include <GL\glut.h> 
#define _USE_MATH_DEFINES
using namespace std;
//camera stuff
float yc = 0, xc = 0, zc = 0, ac = 0, sc = 0, dc = 0, fc = 0;

string filename;
void changeSize(int w, int h) {
	if (h == 0) h = 1;
	float ratio = w * 1.0 / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45.0f, ratio, 1.0f, 1000.0f);
	glMatrixMode(GL_MODELVIEW);
}
int InitGL(GLvoid) {         // All Setup For OpenGL Goes Here
	glShadeModel(GL_SMOOTH);      // Enable Smooth Shading
	//glClearColor(0.0f, 1.0f, 1.0f, 0.0f);    // Black Background
	glClearDepth(1.0f);      // Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	return true;
}

void renderScene(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(5+ac, 5.0+sc, 5.0+dc,
		0+xc,1.0+yc,0+zc,
		0.0, 1.0, 0.0);	
		float *Arrayln;
		float a;
		ifstream planetf(filename);
		int lenght = 0;
		while (planetf >> a)
		{
			lenght++;
		}
		planetf.clear();
		planetf.seekg(0, ios::beg);
		int j = 0;
		Arrayln = (float*)malloc(lenght*sizeof(float));
		while (planetf >> a)
		{
			Arrayln[j] = a;
			j++;
		}
		int i = 0;			  
		for (size_t k = 0; k < lenght/9; k++)
		{
			glBegin(GL_TRIANGLES);
			glColor3f(0.0f, 1, 0);
			glVertex3f(Arrayln[i], Arrayln[i + 1], Arrayln[i + 2]);
			glVertex3f(Arrayln[i + 3], Arrayln[i + 4], Arrayln[i + 5]);
			glVertex3f(Arrayln[i + 6], Arrayln[i + 7], Arrayln[i + 8]);
			glEnd();
			i = i + 9;
		}	   
	glutSwapBuffers();
}
void Keys(int key, int p, int q) {
	switch (key) {
	case GLUT_KEY_LEFT: xc -= 1; break;
	case GLUT_KEY_RIGHT: xc += 1; break;
	case GLUT_KEY_UP: yc += 1; break;
	case GLUT_KEY_DOWN: yc -= 1; break;
	case GLUT_KEY_F1: zc -= 1; break;
	case GLUT_KEY_F2: zc += 1; break;
	case GLUT_KEY_F3: ac -= 1; break;
	case GLUT_KEY_F4: ac += 1; break;
	case GLUT_KEY_F5: sc -= 1; break;
	case GLUT_KEY_F6: sc += 1; break;
	case GLUT_KEY_F7: dc -= 1; break;
	case GLUT_KEY_F8: dc += 1; break;

	}
}
int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);    // Position The Window
	glutInitWindowSize(640, 480);       // Window Size
	glutCreateWindow("Solar System");        // Create The Window
	InitGL();						  // Init OpenGL Window
	glutDisplayFunc(renderScene);    // Display Callback
	glutIdleFunc(renderScene);      // Sets The Global Idle Callback.
	glutReshapeFunc(changeSize);   // Sets The Reshape Callback 
	glutSpecialFunc(Keys);
	glutMainLoop();
	return 0;
}  
