#include "State.h"

State::State()
{
	system("GetData");

	std::ifstream Data("ArduinoData");

	Data>>Mot1;
	Data>>Mot2;
	Data>>Mot3;

	Data>>Yaw[0]; Data>>Yaw[1];
	Data>>Pintch[0]; Data>>Pintch[1];
	Data>>Roll[0]; Data>>Roll[1];

	Data>>IsOnFire;

	Data.close();
}