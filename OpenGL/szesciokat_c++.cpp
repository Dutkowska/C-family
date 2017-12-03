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

GLuint texture1;
GLuint texture2;
GLuint texture3;
GLuint texture4;
GLuint texture5;
GLuint texture6;

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

	glClear(GL_COLOR_BUFFER_BIT |
		GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glRotatef(rot, 0, 0, 1);	gluPerspective(fovy, aspect, zNear, zFar);		glBindTexture(GL_TEXTURE_2D, texture1);
	glBegin(GL_QUADS);
	/* prz */
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture2);
	glBegin(GL_QUADS);
	/* tyl */
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture3);
	glBegin(GL_QUADS);
	/* gora */
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture4);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture5);
	glBegin(GL_QUADS);
	/* pr */
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture6);
	glBegin(GL_QUADS);
	/* Le */
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();

	glPopMatrix();



	glutSwapBuffers();
}


GLuint texture;
GLuint texturee;

bool LoadBitmapTex(LPTSTR szFileName, GLuint &texid)
{
	HBITMAP hBMP;//uchwyt do bitmapy
	BITMAP BMP;//struktura opisujaca parametry bitmapy, wingdi.h, tez jest tu np BITMAPINFOHEADER
	//wczytaj bitmape, parametr tworzacy sekcje DIB kolokwialnie "tablice z pixelami"
	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), szFileName, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION |
		LR_LOADFROMFILE);
	if (!hBMP)
	{
		return FALSE;
	}
	//pobierz informacje o obiekcie bitmapy, zapisane dane do struktury
	GetObject(hBMP, sizeof(BMP), &BMP);
	//wygeneruj teksture
	glGenTextures(1, &texid);
	//ustaw pwyrownanie struktury na 4 (slowo)
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	//zbinduj jako teksture 2D
	glBindTexture(GL_TEXTURE_2D, texid);
	//W jaki sposb powinna skalowac sie tekstura
	//generalnie tekstury maja rozmiary potegi 2, patrz mipmapy
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	if (BMP.bmBitsPixel != 24)//musi byc bitmapa 24bit per pixel
	{
		DeleteObject(hBMP);
		return FALSE;
	}
	//Dolacz bitmape do tekstury
	glTexImage2D(GL_TEXTURE_2D, 0, 3, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);
	//usun bitmape z pamieci
	DeleteObject(hBMP);
	return TRUE;
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
		glRotated(yy, 1, 0, 0);
		glRotated(xx, 0, 1, 0);
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
	glLoadIdentity();
	glOrtho(-2, 2, -2, 2, -10, 10);

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);

	
	glEnable(GL_TEXTURE_2D);

	
	LoadBitmapTex(_T("tex1.bmp"), texture1);
	LoadBitmapTex(_T("tex2.bmp"), texture2); 
	LoadBitmapTex(_T("tex3.bmp"), texture3);
	LoadBitmapTex(_T("tex4.bmp"), texture4);
	LoadBitmapTex(_T("tex5.bmp"), texture5);
	LoadBitmapTex(_T("tex6.bmp"), texture6);

	//ustawienie macierzy modelu-widoku na jednostkowa
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glRotated(xrot += 0.5, 1, 0, 0);
	glRotated(yrot += 0.5, 0, 1, 0);
	glRotated(zrot += 0.5, 0, 0, 1);
	//inicjalizacja koloru tla na czerny (RGB 0-1,0-1,0-1), kana³ alpha
	glTranslated(transx, transy, 0.0); 	glutMouseFunc(MouseButton);	glutMotionFunc(MouseMotion);	glutDisplayFunc(funkcjaRenderujaca);	glutKeyboardFunc(funkcjaKlawiatury);	glRotatef(0.3f, 1.0f, 0.0f, 0.0f);
	glutMainLoop();
	return 0;
}