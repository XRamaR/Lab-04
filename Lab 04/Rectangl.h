#pragma once
#define NDEBUG
#include <GL/freeglut.h>
#include "Figure.h"
#include "time.h"
#include <math.h>

class Rectangl : public Figure
{
public:
	Rectangl(double _k)
	{
		w = 0.1*(rand() % 10 + 5);
		h = 0.1*(rand() % 10 + 5);
		x = 0.1*(rand() % 40 - 17);
		y = 0.1*(rand() % 40 - 17);
		r = 0.1*(rand() % 10);
		g = 0.1*(rand() % 10);
		b = 0.1*(rand() % 10);
		k = _k;
	}

	void draw() {
		glPushMatrix();

		glTranslated(x, y, 0.0);
		glRotated(0, 1.0, 0.0, 0.0);
		glRotated(0, 0.0, 1.0, 0.0);
		glRotated(k, 0.0, 0.0, 1.0);

		glColor3d(r, g, b);

		glBegin(GL_POLYGON);
		{
			glVertex3d(-w / 2, h / 2, 0);
			glVertex3d(w / 2, h / 2, 0);
			glVertex3d(w / 2, -h / 2, 0);
			glVertex3d(-w / 2, -h / 2, 0);
		}
		glEnd();
		glPopMatrix();
	}
	bool Mouse_Inside(float mouse_x, float mouse_y)
	{
		if (abs(mouse_x - x) < 0.5*w && abs(mouse_y - y) < 0.5*h)
			return true;
		else
			return false;
	}
	bool X_closer(float mouse_x, float mouse_y)
	{
		if (abs(mouse_x - x) < abs(mouse_y - y))
			return true;
		else
			return false;
	}
	void strech(float mouse_x, float mouse_y)
	{
		if (abs(mouse_x - x) > abs(mouse_y - y))
		{
			//x = x + 0.5*(abs(mouse_x - x));
			w = w + 2 * (abs(mouse_x - x) - 0.5*w);
		}
		else
		{
			//y = y + 0.5*(abs(mouse_y - y));
			h = h + 2 * (abs(mouse_y - y) - 0.5*h);
		}
	}
private:
	double w, h;
};