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
	static int STATE_MACHINE = GET_GOAL;

	switch(STATE_MACHINE)
	{
		case GET_GOAL:
		{
			m_dir = this->GetComm();
			STATE_MACHINE = SEND_DATA;
			
			break;
		}
		
		case SEND_DATA:
		{
			this->SendArduino("AD=", m_dir.Angle);
			this->SendArduino("VD=", m_dir.Val);
			STATE_MACHINE = RETRIEVE_DATA;

			break;
		}

		case RETRIEVE_DATA:
		{
			
		}

		case DATA_ANALITIC:
		{
		
		}

		case ON_FIRE:
		{
		
		}

		case ON_BACK:
		{
		
		}

		case MOTOR_DOWN:
		{
		
		}

		case NOT_ON_GROUND:
		{
		
		}
	}
	
}

Vector Robot::GetComm()
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

	return Dir;
}

