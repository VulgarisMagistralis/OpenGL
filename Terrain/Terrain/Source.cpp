//#include <stdlib.h>
#include <IL/il.h>			 
#include<glew.h>
#include <glut.h>
#include <math.h>
#include <time.h>

#pragma comment(lib, "devil.lib")
#pragma comment(lib, "glew32.lib")

unsigned int buffer[2];
int tw, th;
unsigned char *imageData;
GLUquadric *gluNewQuadratic = gluNewQuadric();
double cam_x = 0, cam_y, cam_z = 0;
double next_x, next_z;
float height(int x, int z) {//gives the height of a point
	return imageData[tw*x + z] / 255.0 * 215.0;
}
void changeSize(int w, int h) {
	if (h == 0) h = 1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(40.0f, w / h, 1.0f, 10000.0f);
	glMatrixMode(GL_MODELVIEW);
}
void addTree(int x_val, int z_val){
	int root = height(x_val, z_val);

	glPushMatrix();
	glTranslated(x_val, root, z_val);
	glColor3f(1.0, 0.027, 0.755);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	gluCylinder(gluNewQuadratic, 0.5, 0.5, 10, 44, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslated(x_val, root, z_val);
	glColor3f(1.0, 0.0, 0.2);
	glRotatef(90.0, 0.0, 0.0, 1.0);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();
}
GLfloat position[4] = { 0.0,0.0,1.0,0.0 };
GLfloat ambiance[4] = { 1.2,0.2,0.0,1.2 };
GLfloat diffuse[4] = { 0.8,0.7,0.0,0.0 };
void renderScene(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glLightfv(GL_LIGHT2, GL_POSITION, position);
	glLightfv(GL_LIGHT2, GL_AMBIENT, ambiance);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse);
	gluLookAt(200, 200, 200, 0, 0, 0, 0, 1, 0);
	for (int i = 0; i < tw - 1; ++i) {
		glColor3f(0.0, 1.0, 0.0);
		glDrawArrays(GL_TRIANGLE_STRIP, i*th * 2, th * 2);
	}
	srand(time(NULL));
	int x_tree;
	int z_tree;
	for (int i = 0; i < tw / 3; i++){
		x_tree = (rand() % tw) - (tw / 2);
		z_tree = (rand() % tw) - (tw / 2);
		addTree(x_tree, z_tree);
	}
	glutSwapBuffers();
}
void loadImage(char *filename){
	unsigned int t;
	ilGenImages(1, &t);
	ilBindImage(t);
	ilLoadImage((ILstring)"terreno2.jpg");
	ilConvertImage(IL_LUMINANCE, IL_UNSIGNED_BYTE);
	tw = ilGetInteger(IL_IMAGE_WIDTH);
	th = ilGetInteger(IL_IMAGE_HEIGHT);
	imageData = ilGetData();
}						  //^^^^^to limit the height between 0-215
void terrainCreate(){
	float *v = (float*)malloc(sizeof(float)*(tw - 1)*th * 2 * 3);
	float *n = (float*)malloc(sizeof(float)*(tw - 1)*tw * 2 * 3);
	int c = 0;
	int norm = 0;
	for (int i = 0; i < tw - 1; i++){
		for (int j = 0; j < th; j++){
			v[c++] = (i + 1) - tw / 2;
			v[c++] = height(i + 1, j);
			v[c++] = j - th / 2;
				n[norm++] = (i + 1) - tw / 2;
				n[norm++] = height(i + 1, j);
				n[norm++] = j - th / 2;
			v[c++] = i - tw / 2;
			v[c++] = height(i, j);
			v[c++] = j - th / 2;
				n[norm++] = i - tw / 2;
				n[norm++] = height(i, j);
				n[norm++] = j - th / 2;

		}
	}
	glGenBuffers(2, buffer);	 //Generate buffer objects
	glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
	glVertexPointer(3, GL_FLOAT, 0, 0);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*(tw - 1)*th * 2 * 3, v, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, buffer[1]);
	glNormalPointer(GL_FLOAT, 0, 0);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*(tw - 1)*th * 2 * 3, n, GL_STATIC_DRAW);

} 
int main(int argc, char **argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Earth");

	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glewInit();
	ilInit();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHTING);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);	//IMPORTANT
	loadImage("terreno2.jpg");
	terrainCreate();

	glDepthFunc(GL_LEQUAL);
	glPolygonMode(GL_FRONT, GL_LINE);
	glEnable(GL_CULL_FACE);
	glutMainLoop();
}