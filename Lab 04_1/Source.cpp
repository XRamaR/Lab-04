#include <iostream>
#include <GL/freeglut.h>
#include <vector>
#include <stdlib.h> 
#include <time.h> 

#include "Circle.h"
#include "Rectangl.h"
#include "Player.h"

double openglX;
double openglY;

Player player(0, 0);

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
		player.Draw();
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
	//std::cout << "Nacisnieto klawisz: " << key << ", a myszka znajduje sie w pozycji: " << mouse_x << ", " << mouse_y << "(w pikselach)" << std::endl;
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

	if (key == 'a')
	{
		player.move(-0.15, 0);
	}
	if (key == 'd')
	{
		player.move(0.15, 0);
	}
	if (key == 'w')
	{
		player.move(0, 0.15);
	}
	if (key == 's')
	{
		player.move(0, -0.15);
	}
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


	glutInit(&argc, argv);
	InitGLUTScene("freeglut template");
	SetCallbackFunctions();
	glutMainLoop();

	return 0;
}