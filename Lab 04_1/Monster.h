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
	void Track(double p_x, double p_y)
	{
		if (this->x > p_x)
			move(p_x - this->x, 0);
		if (this->x < p_x)
			move(this->x - p_x, 0);
		if (this->y > p_y)
			move(0, this->y - p_y);
		if (this->y < p_y)
			move(0, p_y - this->y);
	}
	void Draw()
	{
		body.draw();
	}
private:
	Circle body;
};