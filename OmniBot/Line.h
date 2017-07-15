#include "Vector.h"
#include "Point.h"

#pragma once

struct Line
{
	Line(double coef, double const_){Coef = coef; Const = const_;};
	Line(Point point1, Point point2);
	Line(Vector);//Assume the vectors pass by (0,0)
	Line(){Coef = 0; Const = 0;};
	double Coef;
	double Const;
};

Line::Line(Vector vector)//vector pass by (0, 0)
{
	Point point1(vector), point2(0, 0);

	Coef = point2.Y / point2.X;

	Const = 0;
}

Line::Line(Point point1, Point point2)
{
	Coef = (point1.Y - point2.Y) / (point1.X - point2.X);//delta af vals

	Const = point2.Y - point2.X * Coef;
}