#ifndef POINT_H
#define POINT_H

#include "Vector.h"
#include <math.h>

struct Point
{
	Point(double x, double y){X = x, Y = y;};
	Point(Vector vector){X = sin(vector.Angle * M_PI / 180) * vector.Val; Y = cos(vector.Angle * M_PI / 180) * vector.Val;};//Assume the vector pass by (0, 0)
	Point(){X = 0; Y = 0;};

	double X;
	double Y;
};

#endif