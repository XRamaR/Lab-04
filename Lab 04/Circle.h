#pragma once
#include <GL/freeglut.h>
#include "Figure.h"
#include <math.h>
#include <stdio.h>    
#include <stdlib.h>     
#include <time.h> 

#define M_PI acos(-1.0)

class Circle : public Figure
{
public:
	Circle()
	{

	}
	Circle(double _x, double _y, double _radius, double _r, double _g, double _b)
	{
		radius = _radius;
		x = _x;
		y = _y;
		r = _r;
		g = _g;
		b = _b;
	}
	void draw()
	{
		int triangleAmount = 30; //# of triangles used to draw circle
								 //GLfloat radius = 0.8f; //radius
		GLfloat twicePi = 2.0f * M_PI;

		glPushMatrix();
		{
			glColor3d(r, g, b);
			glTranslatef(x, y, 0);

			glBegin(GL_POLYGON);
			{
				for (double kat = 0; kat < 2 * 3.14; kat += 3.14 / 1000)
				{
					glVertex3f(cos(kat) * radius, sin(kat) * radius, 0.0);
				}
			}
			glEnd();
		}
		glPopMatrix();
	}
	bool Mouse_inside(float mouse_x, float mouse_y)
	{
		if (abs((mouse_x - x)) < radius && abs((mouse_y - y)) < radius)
			return true;
		else
			return false;
	}
	void Drag(float dx, float dy)
	{
		this->x = dx;
		this->y = dy;
	}
public:
	double radius;
};