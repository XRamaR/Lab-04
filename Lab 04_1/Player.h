#pragma once
#include "Circle_1.h"
#include "Figure_1.h"
#include "Rectangl_1.h"
#include <math.h>
#include <stdio.h>    
#include <stdlib.h>     
#include <time.h>

class Player : public Figure
{
public:
	Player(double _x, double _y)
	{
		r = 0;
		g = 0.4;
		b = 0.8;
		Circle c(_x, _y, 0.22, r, g, b);
		head = c;
		Rectangl b(0.2, 0.7, _x, _y, 0, r, b, g);
		body = b;
		x = _x;
		y = _y;
	}
	void Draw()
	{
		head.draw();
		body.draw();
	}
	void move(double dx, double dy)
	{
		x += dx;
		y += dy;
		Circle c(x, y, 0.22, r, g, b);
		head = c;
		Rectangl b(0.2, 0.7, x, y, 0, r, b, g);
		body = b;
		Draw();
	}
private:
	Circle head;
	Rectangl body;
};
