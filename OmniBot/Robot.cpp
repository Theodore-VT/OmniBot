#include "Robot.h"


Robot::Robot(Specs specs)
{
	m_specs = specs;

	for(int i = 0; i < specs.WheelNumber; ++i)//linking virtual model to real robot
	{
		m_WheelPos.push_back(Vector(m_specs.Angle * i, m_specs.Diam_mm));//defining the position of the wheels
	}
}


Robot::~Robot()
{
}


std::vector<Vector> Robot::CalcVects(Vector GlobalVector)
{
	std::vector<Vector> vectors;

	for(int i = 0; i < m_specs.WheelNumber; ++i)
	{
		vectors.push_back(Vector(0.0, this->Dist_LinePoint(Line(GlobalVector), Point(m_WheelPos[i]))));
	}

	return vectors;
}

double Robot::Dist_LinePoint(Line &line, Point &point)
{
	Line Perp(0, 0);
	Point Inter(0, 0);

	if(line.Coef != 0)
		Perp.Coef = this->NegInv(line.Coef);

	std::cout<<"P Slope : "<<Perp.Coef<<"\n";
	Perp.Const = point.Y - (point.X * Perp.Coef);
	std::cout<<"P Const : "<<Perp.Const<<"\n";
	double TempX;

	line.Coef *= 1000;
	line.Const *= 1000;
	Perp.Const *= 1000;
	Perp.Coef *= 1000;

	int deltaCoef = (int(line.Coef) - int(Perp.Coef)) ? (int(line.Coef) - int(Perp.Coef)) > 0 : 1;

	TempX = (int(line.Const) - int(Perp.Const)) / deltaCoef;

		
	line.Coef /= 1000;
	line.Const /= 1000;
	Perp.Const /= 1000;
	Perp.Coef /= 1000;

	TempX /= 1000;

	Inter.Y = Perp.Const;
	Inter.X = TempX;

	std::cout<<"Inter : "<<Inter.X<<",  "<<Inter.Y<<"\n";

	double Dist = std::sqrtf(std::powf((Inter.Y - point.Y), 2) + std::powf((Inter.X - point.X), 2)); 

	return Dist;
}
