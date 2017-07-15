#include "IncludesFile.h"
#include "Vector.h"

#pragma once
class DriveBase
{
public:
	DriveBase(std::vector<int> ports);
	~DriveBase();

	void WriteMotors(std::vector<Vector> vectors);
	void Update();

private:
	std::vector<int> m_motors_vals;
	int m_wheelNumber;
};

