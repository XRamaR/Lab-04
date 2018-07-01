#pragma once
#include "Circle_1.h"
#include "Figure_1.h"
#include "Rectangl_1.h"
class Monster : public Figure
{
public:
	Monster(int a)
	{
		x = 0.1*(rand() % 40 - 17);
		y = 0.1*(rand() % 40 - 17);
		r = 0;
		g = 0.5;
		b - 0.5;
		Circle m(x, y, 0.5, r, g, b);
		body = m;
	}
	void move(double dx, double dy)
	{
		x += dx;
		y += dy;
		Circle m(x, y, 0.5, r, g, b);
		body = m;
		Draw();
	}
	void track(double p_x, double p_y)
	{
		if (x > p_x)
			this->move(-0.1, 0);
		if (x < p_x)
			this->move(0.1, 0);
		if (y > p_y)
			this->move(0,-0.1);
		if (y < p_y)
			this->move(0, 0.1);
	}
	void Draw()
	{
		body.draw();
	}
private:
	Circle body;
};