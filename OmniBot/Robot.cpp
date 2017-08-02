#include "Robot.h"
#define GET_GOAL 0
#define SEND_DATA 1
#define RETRIEVE_DATA 2
#define DATA_ANALITIC 3
#define ON_FIRE 4
#define MOTOR_DOWN 5
#define LOW_BATTERY 6


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
	static int PREV_STATE_MACHINE = STATE_MACHINE;

	switch(STATE_MACHINE)
	{
		case GET_GOAL:
		{
			m_dir = this->GetComm();
			PREV_STATE_MACHINE = STATE_MACHINE;
			STATE_MACHINE = SEND_DATA;
			
			break;
		}
		
		case SEND_DATA:
		{
			this->SendArduino("LD=", m_dir.Angle);
			this->SendArduino("VD=", m_dir.Val);
			PREV_STATE_MACHINE = STATE_MACHINE;
			STATE_MACHINE = RETRIEVE_DATA;

			break;
		}

		case RETRIEVE_DATA:
		{
			State TempState();

			m_state = TempState;

			PREV_STATE_MACHINE = STATE_MACHINE;
			STATE_MACHINE = DATA_ANALITIC;
			break;
		}

		case DATA_ANALITIC:
		{
			static int Step = 0;
			
			if(m_state.IsOnFire && Step == 0)
			{
				Step++;
				PREV_STATE_MACHINE = STATE_MACHINE;
				STATE_MACHINE = ON_FIRE;
				break;
			}
			
			if((!m_state.Mot1 || !m_state.Mot2 || !m_state.Mot3) && Step == 1)
			{
				Step++;
				PREV_STATE_MACHINE = STATE_MACHINE;
				STATE_MACHINE = MOTOR_DOWN;
				break;
			}

			if(m_state.IsLowBat && Step == 2)
			{
				Step++;
				PREV_STATE_MACHINE = STATE_MACHINE;
				STATE_MACHINE = LOW_BATTERY;
				break;
			}

			PREV_STATE_MACHINE = DATA_ANALITIC;
			STATE_MACHINE = GET_GOAL;
			Step = 0;
			break;
		}

		case ON_FIRE:
		{
			SendArduino("KFN", 0);

			if(this->CanShutdown)
			{
				SendArduino("STD", 1); //Shutdown as quick as possible
			}

			else 
			{
				PREV_STATE_MACHINE = STATE_MACHINE;
				STATE_MACHINE = DATA_ANALITIC;
			}
			break;
		}

		case MOTOR_DOWN:
		{
			if(!this->CanShutDown)
			{
				PREV_STATE_MACHINE = STATE_MACHINE;
				STATE_MACHINE = DATA_ANALITIC;
				SendArduino("DCC", 0); //DriveControChanges ... 
			}

			else
			{
				SendArduino("STD", 0); // Shutdown 
			}

			break;
		}

		case LAW_BATTERY:
		{
			break;
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

