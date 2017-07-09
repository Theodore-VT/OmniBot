#include "SubSystem.h"

#define PI 3.141592

namespace SubSystem
{
	PosControl::PosControl(Specs specs)
	{
		std::cout<<"Init the Posistion Control system!\n";
		m_specs = specs;

		for(int i = 0; i < specs.WheelNumber; ++i)//linking virtual model to real robot
		{
			m_WheelPos.push_back(Vector(m_specs.Angle * i, m_specs.Diam_mm));//defining the position of the wheels
		}
	}

	std::vector<Vector> PosControl::CalcVects(Vector GlobalVector)
	{
		std::vector<Vector> vectors;

		for(int i = 0; i < m_specs.WheelNumber; ++i)
		{
			Vector TempVector;
			TempVector.Val = this->Dist_LinePoint(Line(GlobalVector), Point(m_WheelPos[i]));
		}
	}

	double PosControl::Dist_LinePoint(Line line, Point point)
	{
		
	}

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

	Point::Point(Vector vector)
	{
		X = vector.Val * std::cos(vector.Angle * PI / 180);
		Y = vector.Val * std::sin(vector.Angle * PI / 180);
	}
};


