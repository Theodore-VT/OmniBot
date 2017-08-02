#ifndef POINT_H
#define POINT_H

#include "Vector.h"
#include "IncludesFile.h"

struct Point
{
	Point(double x, double y){X = x, Y = y;};
	Point(){X = 0; Y = 0;};
	Point(Vector vector){X = std::cos(vector.Angle) * vector.Val; Y = std::sin(vector.Angle) * vector.Val;};//Assume the vector pass by (0, 0)
	double X;
	double Y;
};

#endif