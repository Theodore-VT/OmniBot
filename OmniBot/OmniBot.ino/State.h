#ifndef STATE_H
#define STATE_H




struct State
{
	State(){};
	bool Mot1, Mot2, Mot3; // False if Motor(Number) is broken
	
	double Yaw[2], Pintch[2], Roll[2]; // [Angle, Acceleration]

	bool IsOnFire; //true if Temp > 40 celcius(shutdown)
};

#endif