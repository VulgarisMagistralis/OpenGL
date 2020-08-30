#include <stdlib.h>
#include <stdio.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <IL\il.h>
#include <math.h>

#define _PI_ 3.14159

float alfa = 0.0f, beta = 0.0f, radius = 5.0f;
float camX, camY, camZ;

GLuint vertexCount, vertices;

int timebase = 0, frame = 0;


void sphericalToCartesian() {

	camX = radius * cos(beta) * sin(alfa);
	camY = radius * sin(beta);
	camZ = radius * cos(beta) * cos(alfa);
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




void draw() {
	/*glPushMatrix();
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3f(5,5 , 0);
	glVertex3f(-5,- 5, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_LINES);
	glColor3f(1, 1, 0);
	glVertex3f(-5,5, 0);
	glVertex3f(5, -5, 0);
	glEnd();
	glPopMatrix();
	*/

	glColor3f(1, 1, 1);

	glPushMatrix();
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(-5, 0, 0);
	glVertex3f(5, 0, 0);
	glEnd();
	glColor3f(1, 1, 1);
	for (int i = -5; i < 6; i++)
	{
		glBegin(GL_LINES);
		glVertex3f(i, 0.2, 0);
		glVertex3f(i, -0.2, 0);
		glEnd();
	}
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
	glVertex3f(0, 5, 0);
	glVertex3f(0, -5, 0);
	glEnd();
	glColor3f(1, 1, 1);
	for (int i = -5; i < 6; i++)
	{
		glBegin(GL_LINES);
		glVertex3f(-0.2, i, 0);
		glVertex3f(0.2, i, 0);
		glEnd();
	}
	glPopMatrix();
}

void renderScene(void) {

	float pos[4] = { 1.0, 1.0, 1.0, 0.0 };
	float fps;
	int time;
	char s[64];

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glTranslatef(0, 0, 20);
	glutSolidCube(8);
	
	glLoadIdentity();
	
	gluLookAt(0, 0, 20,
		0.0, 0.0, 0.0,
		0.0f, 1.0f, 0.0f);





	/*glPushMatrix();
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
	glVertex3f(0, 0, -5);
	glVertex3f(0, 0, 5);
	glEnd();
	glPopMatrix();*/
	//glRotatef(45, 0, 0, 1);

	glRotatef(45, 0, 0, -1);
	draw();

	glPushMatrix();
	//	glutSolidCube(1);
	glScalef(2, 2, 2);
	glTranslatef(1, 0, 0);
	glScalef(0.5, 0.5, 0.5);
	glutSolidCube(1);
	glPopMatrix();


	// End of frame
	glutSwapBuffers();
}



void processKeys(int key, int xx, int yy)
{
	switch (key) {

	case GLUT_KEY_RIGHT:
		alfa -= 0.1; break;

	case GLUT_KEY_LEFT:
		alfa += 0.1; break;

	case GLUT_KEY_UP:
		beta += 0.1f;
		if (beta > 1.5f)
			beta = 1.5f;
		break;

	case GLUT_KEY_DOWN:
		beta -= 0.1f;
		if (beta < -1.5f)
			beta = -1.5f;
		break;

	case GLUT_KEY_PAGE_DOWN: radius -= 0.1f;
		if (radius < 0.1f)
			radius = 0.1f;
		break;

	case GLUT_KEY_PAGE_UP: radius += 0.1f; break;

	}
	sphericalToCartesian();

}



void initGL() {

	// OpenGL settings 
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	ilInit();
	ilEnable(IL_ORIGIN_SET);
	ilOriginFunc(IL_ORIGIN_LOWER_LEFT);

	// init
	sphericalToCartesian();
	glEnableClientState(GL_VERTEX_ARRAY);


}


void main(int argc, char **argv) {

	// init
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 320);
	glutCreateWindow("CG@DI-UM");

	// callback registration
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);

	// keyboard callback registration
	glutSpecialFunc(processKeys);

	// init GLEW
	glewInit();

	initGL();

	glutMainLoop();
}