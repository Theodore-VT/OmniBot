#include "Vector.h"

#pragma once


struct Point
{
	Point(double x, double y){X = x, Y = y;};
	Point(Vector){};//Assume the vector pass by (0, 0)
	Point(){X = 0; Y = 0;};

	double X;
	double Y;
};
