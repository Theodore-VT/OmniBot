#include "Robot.h"

bool operator ==(Vector vec1, Vector vec2)
{
	if((vec1.Angle == vec2.Angle) && (vec1.Val == vec2.Val))
		return 1;

	return 0;
}

Robot::Robot()
{
}


Robot::~Robot()
{
}

void Robot::Run()
{
	
}

void Robot::GetComm()
{
	Vector Null_Vec;
	Vector Dir;

	system("EtReceive");
	std::ifstream Comm("UserComm");

	Comm>>Dir.Angle;
	Comm>>Dir.Val;

	Comm.close();

	if(Dir == Null_Vec)
	{
		system("VisReceive");
		std::ifstream Comm("UserComm");

		Comm>>Dir.Angle;
		Comm>>Dir.Val;

		Comm.close();
	}

	m_dir = Dir;
}

