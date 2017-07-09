#include "IncludesFile.h"

#pragma once

namespace SubSystem
{
	class Radio;
	class PosControl;
	struct Specs;
	struct Vector;
	struct Line;
	struct Point;

	class Radio
	{
		Radio(std::string ip);
		~Radio();

		bool Isconnected();
		void Update();
	};

	class PosControl
	{
	public:
		PosControl(Specs specs);
		~PosControl();

		std::vector<Vector> CalcVects(Vector);
	private:
		double Dist_LinePoint(Line line, Point point);
		double NegInv(double number){return 1 / number;};

		std::vector<Vector> m_WheelPos;

		Specs m_specs;
	};

	struct Specs
	{
		Specs(double diam, double wheelNumer, double angle);
		double Diam_mm;//distance between the wheels and the center (assuming they are at equal dstance)
		double Angle;//Angle between different wheels -> deduce number of wheels
		double WheelNumber;
	};

	struct Vector
	{
		Vector(double angle, double val){};
		Vector(){Angle = 0; Val = 0;};
		double Angle;
		double Val;
	};

	struct Line
	{
		Line(double coef, double const_){Coef = coef; Const = const_;};
		Line(Point point1, Point point2);
		Line(Vector);//Assume the vectors pass by (0,0)
		Line(){Coef = 0; Const = 0;};
		double Coef;
		double Const;
	};

	struct Point
	{
		Point(double x, double y){X = x, Y = y;};
		Point(Vector){};//Assume the vector pass by (0, 0)
		Point(){X = 0; Y = 0;};

		double X;
		double Y;
	};
};
