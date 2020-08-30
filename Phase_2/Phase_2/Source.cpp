#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

//variables for planets

////////

//Variables for camera
float cam_x, cam_y;
/////
void changeSize(int w, int h){
	if (h == 0)
		h = 1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(40.0f, w / h, 1.0f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}
void renderScene(){	//draw
	gluLookAt(1.0f+cam_x,6.0f+cam_y,1.0f,0.0f,1.0f,0.0f,1.0f,1.0f,1.0f);
}
int InitGL(GLvoid){
	glClearColor(0.254f, 0.568f, 0.898f, 1.0f);
	glEnable(GL_CULL_FACE);
	glDepthFunc(GL_LEQUAL);
	return 1;
}
void keys(int key,int p,int q){
	switch (key){
	case GLUT_KEY_DOWN:	 cam_x -= 0.3; break;
	case GLUT_KEY_LEFT:  cam_x += 0.3; break;
	case GLUT_KEY_RIGHT: cam_y += 0.3; break;
	case GLUT_KEY_UP: 	 cam_y -= 0.3; break;
	}
}