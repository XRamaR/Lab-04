#include <iostream>
#include <GL/freeglut.h>
#include <vector>
#include <stdlib.h> 
#include <time.h> 

#include "Circle_1.h"
#include "Rectangl_1.h"
#include "Player.h"

double openglX;
double openglY;

Player player(0, 0);

std::vector<Rectangl> walls;

Rectangl wall_1(0.4, 5, -3.2, 0, 0, 1, 0, 0);
Rectangl wall_2(0.4, 5, 3.2, 0, 0, 1, 0, 0);
Rectangl wall_3(6, 0.4, 0, 2.4, 0, 1, 0, 0);
Rectangl wall_4(6, 0.4, 0, -2.4, 0, 1, 0, 0);


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
		for (auto &it : walls)
			it.draw();
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
	
	if (key == 's' && abs(player.hitbox.y-wall_4.y)>0.6)
	{
		player.move(0, -0.1);
		std::cout << abs(player.hitbox.y - wall_4.y) << std::endl;
		std::cout << std::endl;
	}
	if (key == 'w' &&  abs(player.hitbox.y - wall_3.y)>0.6)
	{
		player.move(0, 0.1);
	}
	if (key == 'a' && abs(player.hitbox.x - wall_1.x)>0.5)
	{
		player.move(-0.1, 0);
	}
	if (key == 'd' && abs(player.hitbox.x - wall_2.x)>0.5)
	{
		player.move(0.1, 0);
	}
}
void OnMouseClick(int button, int state, int x, int y)
{
	bool firstclick = false;
	float openglX = ((double)x - 400) / 800 * 6.68;
	float openglY = -((double)y - 300) / 600 * 5.0;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
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
	
	walls.push_back(wall_1);
	walls.push_back(wall_2);
	walls.push_back(wall_3);
	walls.push_back(wall_4);
	
	glutInit(&argc, argv);
	InitGLUTScene("freeglut template");
	SetCallbackFunctions();
	glutMainLoop();

	return 0;
}