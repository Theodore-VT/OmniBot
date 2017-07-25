#include "Line.h"

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
