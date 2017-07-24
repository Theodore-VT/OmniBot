#ifndef LINE_H
#define LINE_H

#include "Vector.h"
#include "Point.h"


struct Line
{
	Line(double coef, double const_){Coef = coef; Const = const_;};
	Line(Point point1, Point point2);
	Line(Vector);//Assume the vectors pass by (0,0)
	Line(){Coef = 0; Const = 0;};
	double Coef;
	double Const;
};


#endif