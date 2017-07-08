#include "SubSystem.h"

namespace SubSystem
{
	PosControl::PosControl(Specs specs)
	{
		std::cout<<"Init the Posistion Control system!\n";
		m_specs = specs;

		for(int i = 0; i < specs.WheelNumber; ++i)//linking virtual model to real robot
		{
			m_WheelPos.push_back(Vector(m_specs.Angle * i, m_specs.Diam_mm));//defining the position of the wheels
		}
	}

	std::vector<Vector> PosControl::CalcVects(Vector GlobalVector)
	{
		std::vector<Vector> vectors;

		for(int i = 0; i < m_specs.WheelNumber; ++i)
		{
			Vector TempVector;
			TempVector.Val = this->Dist_LinePoint(Line(GlobalVector), Point(m_WheelPos[i]));
		}
	}
};

