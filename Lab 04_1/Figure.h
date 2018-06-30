#pragma once
class Figure
{
public:
	void move(double dx, double dy)
	{
		x = x + dx;
		y = y + dy;
	}
public:
	float x, y, k;
	double r, g, b;
	bool picked = false;
};