#include <stdlib.h>
#include <GL/glut.h> 
#define _USE_MATH_DEFINES
#include <math.h>


float yc = 0;
float xc = 0;
float zc = 0;

void changeSize(int w, int h) {
	if (h == 0) h = 1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(40.0f, w / h, 1.0f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}
void renderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(8.0 + xc, 6.0 + yc, 1.0 + zc, 0.0, 1.0, 0.0, 1.0f, 1.0f, 1.0f);
	

	glutSwapBuffers();
}
int InitGL(GLvoid) {         // All Setup For OpenGL Goes Here
	glShadeModel(GL_SMOOTH);      // Enable Smooth Shading
	glClearColor(0.0f, 1.0f, 1.0f, 0.0f);    // Black Background
	glClearDepth(1.0f);      // Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);         // The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	return true;
}
void Keys(int key, int p, int q) {
	switch (key) {
	case GLUT_KEY_LEFT: xc -= 0.1; break;
	case GLUT_KEY_RIGHT: xc += 0.1; break;
	case GLUT_KEY_UP: yc += 0.1; break;
	case GLUT_KEY_DOWN: yc -= 0.1; break;
	/*case GLUT_KEY_F1: zc -= 0.1; break;
	case GLUT_KEY_F2: zc += 0.1; break;
	case GLUT_KEY_F3: ac -= 0.1; break;
	case GLUT_KEY_F4: ac += 0.1; break;
	case GLUT_KEY_F5: sc -= 0.1; break;
	case GLUT_KEY_F6: sc += 0.1; break;
	case GLUT_KEY_F7: dc -= 0.1; break;
	case GLUT_KEY_F8: dc += 0.1; break;*/
	}
}
int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);    // Position The Window
	glutInitWindowSize(640, 480);       // Window Size
	glutCreateWindow("sphere");        // Create The Window
	InitGL();        // Init OpenGL Window
	glutDisplayFunc(renderScene);    // Display Callback
	glutIdleFunc(renderScene);      // Sets The Global Idle Callback.
	glutReshapeFunc(changeSize);   // Sets The Reshape Callback 
	glutSpecialFunc(Keys);
	glutMainLoop();
	return 0;
}