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
		Rectangl h(0.44, 0.7, _x, _y, 0, 1, 1, 1);
		hitbox = h;
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
		hitbox.draw();
	}
	void move(double dx, double dy)
	{
		x += dx;
		y += dy;
		Rectangl h(0.44, 0.7, x, y, 0, 1, 1, 1);
		hitbox = h;
		Circle c(x, y, 0.22, r, g, b);
		head = c;
		Rectangl b(0.2, 0.7, x, y, 0, r, b, g);
		body = b;
		Draw();
	}
public:
	Rectangl hitbox;
private:
	Circle head;
	Rectangl body;
	
};
