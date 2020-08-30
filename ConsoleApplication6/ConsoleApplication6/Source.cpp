#include <stdlib.h>
#include <GL/glut.h>  
#include  <GL/GL.h>
#include <time.h>
#include <GL/GLU.h>
#define _USE_MATH_DEFINES
#include <math.h>

float yc = 0, xc = 0, zc = 0, ac = 0, sc = 0, dc = 0, fc = 0;
float teta = 0, omega = 0, gamma = 0; //rotation angles for teapots
double long  slices = 30, stacks = 50, radius = 5, alfa = 0, delta_a = M_PI / stacks, beta = 0, delta_b = M_PI * 2 / slices;
float height_of_sun = 24.0, rotation_sun = 0.0f;
//necessary coordinates for creating the sun 

float tree_x, tree_z; // coordinates for trees

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
	gluLookAt(1.0 + xc, 6.0 + yc, 1.0 + zc, 0.0 + ac, 1.0 + sc, 0.0 + dc, 1.0f + fc, 1.0f + fc, 1.0f + fc);

	///////////////triangles

	glPushMatrix();
	glBegin(GL_TRIANGLES);
	glColor3f(0.1f, 0.457, 0.1f);
	glVertex3f(-100, 0, 100);
	glVertex3f(100, 0, 100);
	glVertex3f(-100, 0, -100);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.1f, 0.457, 0.1f);
	glVertex3f(-100, 0, -100);
	glVertex3f(100, 0, 100);
	glVertex3f(100, 0, -100);
	glEnd();
	glPopMatrix();

	////////////////////torus

	glPushMatrix();
	glTranslatef(0, 0, 0);
	glColor3f(0.466, 0.1f, 0.1f);
	glutSolidTorus(0.4, 0.9, 50, 50);
	glPopMatrix();

	///////////teapots

	for (int i = 0; i < 6; i++){
		glPushMatrix();
		glRotatef(teta, 0, 1, 0);
		glTranslatef(2.3* sin(gamma), 0.4, 2.3* cos(gamma));
		gamma = gamma + (M_PI / 3);
		glRotatef(omega, 0, 1, 0);
		glColor3f(0.190f, 0.70f, 1.0f);
		glutSolidTeapot(0.26);
		glPopMatrix();
	}
	for (int i = 0; i < 10; i++){
		glPushMatrix();
		glRotatef(-teta, 0, 1, 0);
		glTranslatef(7.5 * sin(gamma), 0.4, 7.5 * cos(gamma));
		gamma = gamma + (M_PI / 5);
		glRotatef(-omega, 0, 1, 0);
		glColor3f(0.995f, 0.3f, 0.0f);
		glutSolidTeapot(0.49);
		glPopMatrix();
	}
	///sun here

	glPushMatrix();
	glRotatef(rotation_sun, 0, 1, 0);
	for (int i = 0; i < slices + 1; i++) {  //begin creating a slice
		glBegin(GL_TRIANGLES);			 //first triangle of the slice
		glColor3f(1.0, 1.0, 0.0);
		glVertex3f(radius*sin(alfa)*cos(beta), radius*sin(alfa)*sin(beta) + height_of_sun, radius*cos(alfa));
		alfa = alfa + delta_a;
		glVertex3f(radius*sin(alfa)*cos(beta), radius*sin(alfa)*sin(beta) + height_of_sun, radius*cos(alfa));
		beta = beta + delta_b;
		glVertex3f(radius*sin(alfa)*cos(beta), radius*sin(alfa)*sin(beta) + height_of_sun, radius*cos(alfa));
		glEnd();
		for (int j = 0; j < stacks - 2; j++) {  //every triangle in the slice which are between the first and the last triangle
			glBegin(GL_TRIANGLES);
			glColor3f(1.0, 1.0, 0.0);
			glVertex3f(radius*sin(alfa)*cos(beta), radius*sin(alfa)*sin(beta) + height_of_sun, radius*cos(alfa));
			beta = beta - delta_b;
			glVertex3f(radius*sin(alfa)*cos(beta), radius*sin(alfa)*sin(beta) + height_of_sun, radius*cos(alfa));
			alfa = alfa + delta_a;
			glVertex3f(radius*sin(alfa)*cos(beta), radius*sin(alfa)*sin(beta) + height_of_sun, radius*cos(alfa));
			glEnd();
			////I am sorry I could not find a way better way to do this 
			////these two triangles create the middle rectangular area between first and last triangle in the slice
			glBegin(GL_TRIANGLES);
			glColor3f(0.0, 0.0, 0.0);
			alfa = alfa - delta_a;
			beta = beta + delta_b;
			glVertex3f(radius*sin(alfa)*cos(beta), radius*sin(alfa)*sin(beta) + height_of_sun, radius*cos(alfa));
			alfa = alfa + delta_a;
			beta = beta - delta_b;
			glVertex3f(radius*sin(alfa)*cos(beta), radius*sin(alfa)*sin(beta) + height_of_sun, radius*cos(alfa));
			beta = beta + delta_b;
			glVertex3f(radius*sin(alfa)*cos(beta), radius*sin(alfa)*sin(beta) + height_of_sun, radius*cos(alfa));
			glEnd();
		}
		glBegin(GL_TRIANGLES);	//this is the last triangle of the sllice
		glColor3f(1.0, 1.0, 0.0);
		glVertex3f(radius*sin(alfa)*cos(beta), radius*sin(alfa)*sin(beta) + height_of_sun, radius*cos(alfa));
		beta = beta - delta_b;
		glVertex3f(radius*sin(alfa)*cos(beta), radius*sin(alfa)*sin(beta) + height_of_sun, radius*cos(alfa));
		alfa = alfa + delta_a;
		glVertex3f(radius*sin(alfa)*cos(beta), radius*sin(alfa)*sin(beta) + height_of_sun, radius*cos(alfa));
		glEnd();
		alfa = 0;
		beta = delta_b*(i);
	}
	glPopMatrix();
	rotation_sun += 0.80;
	omega = omega + 0.735;
	teta = teta + 0.666;

	//cones 
	tree_x = 1;
	tree_z = 1;

	glPushMatrix();
	glTranslated(tree_x, 0.4, tree_z);

	glColor3f(0.0, 1.0, 0.0);
	glutSolidCone(0.11, 0.7, 30, 20);

	///
	glTranslatef(tree_x, 0.4, tree_z);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(0.11, 30, 30);
	glPopMatrix();
	glutSwapBuffers();
}


int InitGL(GLvoid) {

	/*GLfloat mat_specular[] = { 0.0f, 1.0f, 1.0f, 0.0f };
	GLfloat mat_shininess[] = { 5.0f };
	GLfloat light_position[] = { 0.0f, height_of_sun, 1.0f, 1.0f };
	glEnable(GL_DEPTH_TEST);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_specular);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_shininess);
	glLightfv(GL_LIGHT7, GL_POSITION, light_position);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


	glClearDepth(1.0f);							// Depth Buffer Setup
	glShadeModel(GL_SMOOTH);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT4);
	*/
	glClearColor(0.995f, 0.3f, 0.0f, 0.7f);
	glColorMaterial(GL_FRONT, GL_SPECULAR);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_CULL_FACE);
	glDepthFunc(GL_LEQUAL);
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
	case GLUT_KEY_F3: ac -= 0.1; break;
	case GLUT_KEY_F4: ac += 0.1; break;
	case GLUT_KEY_F5: sc -= 0.1; break;
	case GLUT_KEY_F6: sc += 0.1; break;
	case GLUT_KEY_F7: dc -= 0.1; break;
	case GLUT_KEY_F8: dc += 0.1; break;
	case GLUT_KEY_F9: fc += 0.1; break;
	case GLUT_KEY_F10: fc -= 0.1; break;

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