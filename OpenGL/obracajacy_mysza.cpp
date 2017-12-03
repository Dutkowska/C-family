// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <GL\freeglut.h>
#include "stdafx.h"
#include <GL\GL.h>
#include <GL\GLU.h>

#include <GL\glut.h>
#include <stdio.h>


/*
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>

#include <iostream>


#include "stdafx.h" */
int rot = 0;double xrot;
double yrot;
double zrot;
double fovy = 0;
double aspect = 0;
double zNear = 0;
double zFar = 0;

int transx=0;
int transy=0;
int l = -10;
int p = 10;
int button_x;
int button_y;

int xx;
int yy;
int zz;

int button_m = GLUT_UP;


void funkcjaRenderujaca()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(rot, 0, 0, 1);	gluPerspective(fovy, aspect, zNear, zFar);
	glBegin(GL_QUADS);
	// gora
	glColor3f(1.0f, 0.0f, 0.0f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);

	glEnd();

	glBegin(GL_QUADS);
	// przs
	glColor3f(0.0f, 1.0f, 0.0f);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, -0.5f, 0.5f);

	glEnd();

	glBegin(GL_QUADS);
	// pr
	glColor3f(0.0f, 0.0f, 1.0f);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);

	glEnd();

	glBegin(GL_QUADS);
	// le
	glColor3f(0.0f, 0.0f, 0.5f);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);

	glEnd();

	glBegin(GL_QUADS);
	// gora
	glColor3f(0.5f, 0.0f, 0.0f);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);

	glEnd();

	glBegin(GL_QUADS);
	// tyl
	glColor3f(0.0f, 0.5f, 0.0f);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);

	glEnd();
	glPopMatrix();



	glutSwapBuffers();
}


void funkcjaKlawiatury(unsigned char key, int x, int y)
{
	printf("Key %c, pos(X: %d, Y: %d)\n", key, x, y);//uwaga tylko gdy mamy
		switch (key)
	{
		case 27: // ESCAPE key
			exit(0);
			break;
		case 'e':
			//wcisnieto klawisz e
			rot++;//zwieksz kat obrotu
			if (rot > 360)
			{
				rot = 0;
			}
			glutPostRedisplay();
			break;

		case'x':

			glRotated(30, 1, 0, 0);
			glutPostRedisplay();

		case'y':

			glRotated(30, 0, 1, 0);
			glutPostRedisplay();

		case'z':
			glRotated(30, 0, 0, 1);
			glutPostRedisplay();

		case'p':
			fovy++;
			aspect++;
			zNear++;
			zFar++;
	}
	
}


void MouseButton(int button, int state,
	int x, int y){
	if (button == GLUT_LEFT_BUTTON){
		button_m = state;
		if (state == GLUT_DOWN)
		{
			button_x = x;
			button_y = y;
		}
	}
}

void MouseMotion(int x, int y){
	if (button_m == GLUT_DOWN){

		yy = button_y - y;
		xx = button_x - x;
		glRotated(yy, 0, 1, 0);
		glRotated(xx, 1, 0, 0);
		/*
		transx = ;
		transy = */
		button_x = x;
		button_y = y;
		glutPostRedisplay();
	}


}


int main(int argc, char* args[])
{
	glutInit(&argc, args);
	glutInitContextVersion(2, 1);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(300, 300);
	glutCreateWindow("OpenGL");

	//... kod w main po stworzeniu okna i kontekstu opengl
	//ustawienie macierzy projekcji na jednostkowa
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();\

	//ustawienie macierzy modelu-widoku na jednostkowa
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glRotated(xrot += 0.5, 1, 0, 0);
	glRotated(yrot += 0.5, 0, 1, 0);
	glRotated(zrot += 0.5, 0, 0, 1);
	//inicjalizacja koloru tla na czerny (RGB 0-1,0-1,0-1), kana³ alpha
	glClearColor(1.f, 0.f, 0.f, 1.f);	glTranslated(transx, transy, 0.0); 	glutMouseFunc(MouseButton);	glutMotionFunc(MouseMotion);	glutDisplayFunc(funkcjaRenderujaca);	glutKeyboardFunc(funkcjaKlawiatury);	glRotatef(0.3f, 1.0f, 0.0f, 0.0f);
	glutMainLoop();
	return 0;
}