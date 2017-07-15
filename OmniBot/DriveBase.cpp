#include "DriveBase.h"


DriveBase::DriveBase(std::vector<int> ports)
{
	m_wheelNumber = ports.size();

#ifdef ARDUINO_COMPIL

	for(int i = 0; i < m_wheelNumber; ++i)
	{
		pinMode(ports[i], OUTPUT);
	}

#endif

}


DriveBase::~DriveBase(void)
{
}
