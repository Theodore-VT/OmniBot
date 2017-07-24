#ifndef ROBOT_H
#define ROBOT_H

#include "IncludesFile.h"
#include "Vector.h"
#include "Point.h"
#include "Specs.h"
#include "Line.h"
#include "State.h"

class Robot
{
public:
	Robot();
	~Robot();

	void Run();

private:

	void Move(Vector vector){};
	void GetComm();
	void SendArduino(char * name, int val);
	void ReceiveArduino(State state);

	Vector m_dir;
	State m_state;
};

#endif