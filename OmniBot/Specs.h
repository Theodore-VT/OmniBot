#ifndef SPECS_H
#define SPECS_H

struct Specs
{
	//Specs(double diam, double wheelNumer, double angle);
	Specs(){Diam_mm = 200; Angle = 60; WheelNumber = 3;};
	double Diam_mm;//distance between the wheels and the center (assuming they are at equal dstance)
	double Angle;//Angle between different wheels -> deduce number of wheels
	double WheelNumber;
};

#endif