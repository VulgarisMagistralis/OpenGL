#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#define _USE_MATH_DEFINES
#include <math.h>

float yc = 0;
float xc = 0;
void changeSize(int w, int h) {
	if (h == 0) h = 1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(500.0f, w / h, 1.0f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}
void renderScene() {
	// Cone
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glutPostRedisplay();
	gluLookAt(5.0, 6.0 + yc, 1.0 + xc, 0.0, 1.0, 0.0, 1.0f, 1.0f, 1.0f);

	long double stacks = 10;
	int slices = 10;
	long double angle = 0;
	long double radius = 10;
	long double h = 5;
	long double dif = h / (stacks);
	long double delta = M_PI / slices;
	float rdif = radius / stacks;
	float r = rdif;

	for (int i = 0; i < slices * 2; i++) {				
		glBegin(GL_TRIANGLES);
		glColor3f(0.0, 1, 0.0);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(radius*sin(angle), 0.0f, radius*cos(angle));
		glVertex3f(radius*sin(angle + delta), 0.0f, radius*cos(angle + delta));
		angle = angle + delta;
		glEnd();
	}
	
	for (int i = 0; i < slices * 2; i++) {								
		glBegin(GL_TRIANGLES);
		glColor3f(1, 0, 0);
		glVertex3f(0.0f, h, 0.0f);
		glVertex3f(r*sin(angle), h - dif, r*cos(angle));
		glVertex3f(r*sin(angle + delta), h - dif, r*cos(angle + delta));
		angle = angle + delta;
		glEnd();
	}
	
	for (int i = 0; i < stacks - 1; i++){
		h = h - dif;
		r = r + rdif;
		for (int j = 0; j < (slices * 2); j++){
			glBegin(GL_TRIANGLES);
			glColor3f(0, 0, 1);
			glVertex3f((r - rdif)*sin(angle), h, (r - rdif)*cos(angle));
			glVertex3f(r*sin(angle), h - dif, r*cos(angle));
			glVertex3f(r*sin(angle + delta), h - dif, r*cos(angle + delta));

			glEnd();
			glBegin(GL_TRIANGLES);
			glColor3f(0, 1, 0);
			glVertex3f((r - rdif)*sin(angle), h, (r - rdif)*cos(angle));
			glVertex3f(r*sin(angle + delta), h - dif, r*cos(angle + delta));
			glVertex3f((r - rdif)*sin(angle + delta), h, (r - rdif)*cos(angle + delta));
			angle = angle + delta;
			glEnd();

		}	  	
	}				

	glutSwapBuffers();
}
int InitGL(GLvoid)          // All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);       // Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);    // Black Background
	glClearDepth(1.0f);				  // Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);        // Enables Depth Testing
	glEnable(GL_CULL_FACE);
	glDepthFunc(GL_LEQUAL);        // The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations         // Initialization Went OK
	return true;          // Initialization Went OK
}
void Keys(int key, int p, int q)
{
	switch (key)
	{
	case GLUT_KEY_LEFT: xc -= 0.1; break;
	case GLUT_KEY_RIGHT: xc += 0.1; break;
	case GLUT_KEY_UP: yc += 0.1; break;
	case GLUT_KEY_DOWN: yc -= 0.1; break;
	}
}
int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);// Initial Display Mode.
	glutInitWindowPosition(100, 100);     // Position The Window
	glutInitWindowSize(640, 480);      // Window Size
	glutCreateWindow("cone");        // Create The Window
	InitGL();           // Init OpenGL Window
	glutDisplayFunc(renderScene);      // Display Callback
	glutIdleFunc(renderScene);       // Sets The Global Idle Callback.
	glutReshapeFunc(changeSize);      // Sets The Reshape Callback 
	glutSpecialFunc(Keys);
	glutMainLoop();
	return 0;
}
