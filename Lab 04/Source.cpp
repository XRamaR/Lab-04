#include <iostream>
#include <GL/freeglut.h>
#include <vector>
#include <stdlib.h> 
#include <time.h> 

#include "Circle.h"
#include "Rectangl.h"

double openglX;
double openglY;

std::vector<Rectangl*> rectangles;

/* GLUT callback Handlers */
void resize(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void idle()
{
	glutPostRedisplay();
}

void display()
{
	// clear the scene
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	{
		for (auto r : rectangles)
			r->draw();
	}
	glPopMatrix();

	glutSwapBuffers();
}

void InitGLUTScene(const char* window_name)
{
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(40, 40);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow(window_name);

	// set white as the clear colour
	glClearColor(1, 1, 1, 1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
}

void FunkcjaDoObslugiKlawiatury(unsigned char key, int mouse_x, int mouse_y)
{
	//if (key == 'w')
	//{
	//	//rectangles[0].move(0, 0.1);
	//	circles[0].move(0, 0.1);
	//}
	//if (key == 's')
	//{
	//	//rectangles[0].move(0, -0.1);
	//	circles[0].move(0, -0.1);
	//}
	//if (key == 'a')
	//{
	//	//rectangles[0].move(-0.1, 0);
	//	circles[0].move(-0.1, 0);
	//}
	//if (key == 'd')
	//{
	//	//rectangles[0].move(0.1, 0);
	//	circles[0].move(0.1, 0);
	//}
	//circles[0].move(mouse_x,mouse_y);
}
void OnMouseClick(int button, int state, int x, int y)
{
	bool firstclick = false;
	float openglX = ((double)x - 400) / 800 * 6.68;
	float openglY = -((double)y - 300) / 600 * 5.0;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		system("cls");
		float wspolrzednaX = openglX;
		float wspolrzednaY = openglY;

		for (auto it : rectangles)
		{
			if (it->Mouse_Inside(wspolrzednaX, wspolrzednaY))
			{
				it->picked = true;
				if (!firstclick)
					firstclick = true;
			}
		}
		if (!firstclick)
		{
			for (auto it : rectangles)
			{
				if (it->picked)
				{
					it->strech(wspolrzednaX, wspolrzednaY);
					/*if (it->X_closer)
					{

					}*/
					it->picked = false;
				}
			}
			firstclick = true;
		}
	}
}

void SetCallbackFunctions()
{
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(FunkcjaDoObslugiKlawiatury);
	glutMouseFunc(OnMouseClick);
}

int main(int argc, char *argv[])
{
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
		rectangles.push_back(new Rectangl(0));
	/*Rectangl r(0);
	rectangles.push_back(r);
	Rectangl r_1(0);
	rectangles.push_back(r_1);
	Rectangl r_2(0);
	rectangles.push_back(r_2);
	Rectangl r_3(0);
	rectangles.push_back(r_3);
	Rectangl r_4(0);
	rectangles.push_back(r_4);*/


	glutInit(&argc, argv);
	InitGLUTScene("freeglut template");
	SetCallbackFunctions();


	glutMainLoop();
	rectangles.clear();
	return 0;
}