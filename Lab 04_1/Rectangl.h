#pragma once
#define NDEBUG
#include <GL/freeglut.h>
#include "Figure.h"
#include "time.h"
#include <math.h>

class Rectangl : public Figure
{
public:
	Rectangl()
	{

	}
	Rectangl(double _w, double _h, double _x, double _y, double _k, double _r, double _g, double _b) {
		w = _w;
		h = _h;
		x = _x;
		y = _y;
		k = _k;
		r = _r;
		g = _g;
		b = _b;
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