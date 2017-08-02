#pragma once 

struct Vector
{
	Vector(long double angle, long double val){Angle = angle; Val = val;};
	Vector(){Angle = 0; Val = 0;};
	double Angle;
	double Val;
};