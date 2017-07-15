#include "IncludesFile.h"
#include "Vector.h"
#include "Point.h"
#include "Specs.h"
#include "Line.h"

#pragma once
class Robot
{
public:
	Robot(Specs specs);
	~Robot();

	std::vector<Vector> CalcVects(Vector);

private:

	double Dist_LinePoint(Line &line, Point &point);
	double NegInv(double number){return -(1 / number);};
	Point LineInter(Line line1, Line line2);

	std::vector<Vector> m_WheelPos;

	Specs m_specs;
};

