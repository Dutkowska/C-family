

#include "stdafx.h"
#define GLEW_STATIC
#include<GL/glew.h>
#include<GL/freeglut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include <stdio.h>

float rotx = 0.0f;
float roty = 0.0f;
float rotz = 0.0f;
float  dx = 0.0f;
float dy = 0.0f;

GLint loc_color_r;
GLint loc_alpha;
int alpha;

bool init()
{

	glEnable(GL_DEPTH_TEST);
	return true;
}
void funkcjaRenderujaca()
{
	glClearColor(0.0f, 0.1f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glutSwapBuffers();
}

static const GLfloat triangle_vertex[] = {
	-0.5f, -0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	-0.5f, 0.5f, 0.0f,

	-0.5f, 0.5f, 0.0f,
	0.5f, 0.5f, 0.0f,
	0.5f, -0.5f, 0.0f, };


void resize(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45.0f, 1.0f * w / h, 1.0f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


#define glsl(s)  "#version 150 \n" #s

const GLchar* simply_fragment_shader = glsl(

	out vec4 out_color;
void main()
{
	out_color = vec4(1.0, 0.3, 0.5, 0.6);
}

);


const GLchar* shader_pozycja = glsl(

	in vec3 position;
uniform float alpha;
mat3 rotation = mat3(
	vec3(cos(alpha), -sin(alpha), 0.0),
	vec3(sin(alpha), cos(alpha), 0.0),
	vec3(0.0, 0.0, 1.0)
	);
void main()
{
	gl_Position = vec4(rotation * position, 1.0);
}

);

void funkcjaKlawiatury(unsigned char key, int x, int y)
{
	printf("Key %c, pos(X: %d, Y: %d)\n", key, x, y);
	switch (key)
	{
	case 27: // ESCAPE key
		exit(0);
		break;
	case '-':
		//wcisnieto klawisz e
		alpha--;//zmnieksz kat obrotu
		if (alpha > 2)
		{
			alpha = 0;
		}
		glUniform1f(loc_alpha, alpha);
		glutPostRedisplay();
		break;
	case '+':
		//wcisnieto klawisz w
		alpha++;//zwieksz kat obrotu
		if (alpha > 2)
		{
			alpha = 0;
		}
		glUniform1f(loc_alpha, alpha);
		glutPostRedisplay();
		break;
	}
}

int button_x;
int button_y;

int xx;
int yy;
int zz;

int button_m = GLUT_UP;


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

		if (button_x > x){
			alpha--;//zmnieksz kat obrotu
			if (alpha > 2)
			{
				alpha = 0;
			}
			glUniform1f(loc_alpha, alpha);
			glutPostRedisplay();
			button_x = x;
			
		}
		if (button_x < x){
			alpha++;//zwieksz kat obrotu
			if (alpha > 2)
			{
				alpha = 0;
			}
			glUniform1f(loc_alpha, alpha);
			glutPostRedisplay();
			button_x = x;
			
		}
		/*

		yy = button_y - y;
		xx = button_x - x;
		glRotated(yy, 0, 1, 0);
		glRotated(xx, 1, 0, 0);
		/*
		transx = ;
		transy = */
		/*
		button_x = x;
		button_y = y;
		glutPostRedisplay(); */
	}


}

int main(int argc, char* argv[])
{


	glEnable(GL_DEPTH_TEST);
	glutInit(&argc, argv);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("obrot");




	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		printf(
			"Err %d"
			, err);
		return 0;
	}


	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertex), triangle_vertex, GL_STATIC_DRAW);


	GLuint Shaderpoz = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(Shaderpoz, 1, &shader_pozycja, NULL);
	glCompileShader(Shaderpoz);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &simply_fragment_shader, NULL);
	glCompileShader(fragmentShader);


	GLuint shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, fragmentShader);
	glAttachShader(shaderProgram, Shaderpoz);

	glBindFragDataLocation(shaderProgram, 0, "out_color");
	glLinkProgram(shaderProgram);

	glUseProgram(shaderProgram);



	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");

	glEnableVertexAttribArray(posAttrib);




	glVertexAttribPointer(
		posAttrib,

		3,

		GL_FLOAT,

		GL_FALSE,

		0,

		0

		);

	loc_color_r = glGetUniformLocation(shaderProgram, "r_color");
	loc_alpha = glGetUniformLocation(shaderProgram, "alpha");
	if (loc_color_r != -1)
	{
		glUniform1f(loc_color_r, 1);
	}

	glutMouseFunc(MouseButton);	glutMotionFunc(MouseMotion);

	glutKeyboardFunc(funkcjaKlawiatury);
	glutDisplayFunc(funkcjaRenderujaca);
	glutMainLoop();
	return 0;
}