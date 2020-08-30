#include <windows.h>  
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
	gluLookAt(1.0, 6.0 + yc, 1.0 + xc,0.0, 1.0+zc, 0.0,1.0f, 1.0f, 1.0f);
	double long slices = 30;
	double long stacks = 50;
	double long radius = 5;
	double long alfa = 0; double long delta_a = M_PI / stacks;
	double long beta = 0; double long delta_b = M_PI * 2 / slices;
	for (int i = 0; i < slices+1; i++) {  //begin creating a slice
		glBegin(GL_TRIANGLES);			 //first triangle of the slice
		glColor3f(0.0, 1.0, 0.8);
		//glVertex3f(radius*sin(alfa)*cos(beta), radius*sin(alfa)*sin(beta), radius*cos(alfa));
		alfa = alfa + delta_a;
	//	glVertex3f(radius*sin(alfa)*cos(beta), radius*sin(alfa)*sin(beta), radius*cos(alfa));
		beta = beta + delta_b;
		//glVertex3f(radius*sin(alfa)*cos(beta), radius*sin(alfa)*sin(beta), radius*cos(alfa));
		glEnd();
		for (int j = 0; j < stacks-2; j++) {  //every triangle in the slice which are between the first and the last triangle
			glBegin(GL_TRIANGLES);
			glColor3f(0.9, 0.89, 0.757);
		//	glVertex3f(radius*sin(alfa)*cos(beta), radius*sin(alfa)*sin(beta), radius*cos(alfa));
			beta = beta - delta_b;
			//glVertex3f(radius*sin(alfa)*cos(beta), radius*sin(alfa)*sin(beta), radius*cos(alfa));
			alfa = alfa + delta_a;
			//glVertex3f(radius*sin(alfa)*cos(beta), radius*sin(alfa)*sin(beta), radius*cos(alfa));
			glEnd();
			////I am sorry I could not find a way better way to do this 
			////these two triangles create the middle rectangular area between first and last triangle in the slice
			glBegin(GL_TRIANGLES);
			glColor3f(1.0, 0.0, 1.0);
			alfa = alfa - delta_a;
			beta = beta + delta_b;
		//	glVertex3f(radius*sin(alfa)*cos(beta), radius*sin(alfa)*sin(beta), radius*cos(alfa));
			alfa = alfa + delta_a;
			beta = beta - delta_b;
			//glVertex3f(radius*sin(alfa)*cos(beta), radius*sin(alfa)*sin(beta), radius*cos(alfa));
			beta = beta + delta_b;
			//glVertex3f(radius*sin(alfa)*cos(beta), radius*sin(alfa)*sin(beta), radius*cos(alfa));
			glEnd();
		}
		glBegin(GL_TRIANGLES);	//this is the last triangle of the sllice
		glColor3f(0.0, 1.0, 0.4);
	//	glVertex3f(radius*sin(alfa)*cos(beta), radius*sin(alfa)*sin(beta), radius*cos(alfa));
		beta = beta + delta_b;
		//glVertex3f(radius*sin(alfa)*cos(beta), radius*sin(alfa)*sin(beta), radius*cos(alfa));
		alfa = alfa + delta_a;
		glVertex3f(radius*sin(alfa)*cos(beta), radius*sin(alfa)*sin(beta), radius*cos(alfa));
		glEnd();
		alfa = 0;
		beta = delta_b*(i);
	}
	glutSwapBuffers();
}	
int InitGL(GLvoid) {						   // All Setup For OpenGL Goes Here
	glShadeModel(GL_SMOOTH);				  // Enable Smooth Shading
	glClearColor(0.0f, 1.0f, 1.0f, 0.0f);    // Black Background
	glClearDepth(1.0f);				  // Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);	
	glEnable(GL_BACK);
			
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
	case GLUT_KEY_F1: zc -= 0.1; break;
	case GLUT_KEY_F2: zc += 0.1; break;
	}
}
int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);  
	glutInitWindowPosition(100, 100);    // Position The Window
	glutInitWindowSize(640, 480);       // Window Size
	glutCreateWindow("sphere");        // Create The Window
	InitGL();						  // Init OpenGL Window
	glutDisplayFunc(renderScene);    // Display Callback
	glutIdleFunc(renderScene);      // Sets The Global Idle Callback.
	glutReshapeFunc(changeSize);   // Sets The Reshape Callback 
	glutSpecialFunc(Keys);
	glutMainLoop();
	return 0;
}