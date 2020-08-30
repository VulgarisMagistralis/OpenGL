#include <GL\glut.h>
#include <math.h>


void displayCube(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glColor3f(0.4, 0.0, 0.0);
	glutWireCube(1.0);
	glFlush();
}
void reshapeCube(int x, int y)
{
	if (x == 0)	x = 1;
	float ratio = y*1.0 / x;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, x, y);
	gluPerspective(51.0, ratio, 1.0, 0.0);

}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB |GLUT_DEPTH);
	glShadeModel(GL_FLAT);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);

	glutCreateWindow("Cube");
	glutDisplayFunc(displayCube);
	glutReshapeFunc(reshapeCube);
	gluLookAt(1.0, 1.0, 1.0, 0.1, 0.1, 0.1, 0.1, 1.0, 0.0);
	glClearColor(1.0, 0.4, 0.8, 0.0);

	glutMainLoop();
}