#include <GL\glut.h>
#include <math.h>

GLdouble base = 0.2;
GLdouble height = 0.7;
GLint slices = 100;
GLint stacks = 100;

void displayCone(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glColor3f(0.1, 0.1, 0.4);
	glutWireCone(base, height, slices, stacks);
	glFlush();
}
void reshapeCone(int x, int y)
{
	if (x == 0)	x = 1;
	float ratio = y*1.0 / x;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, x, y);
	gluPerspective(35.0, ratio, 2.0, 0.0);
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Cone");
	glutDisplayFunc(displayCone);
	glutReshapeFunc(reshapeCone);
	glLoadIdentity();
	gluLookAt(0.0, 1.4, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glClearColor(0.0, 0.4, 0.6, 0.0);
	glRotatef(270, 1.0, 0.0, 0.0);
	glutMainLoop();
}