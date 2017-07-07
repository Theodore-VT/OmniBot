#include "Computer.h"


Computer::Computer(void)
{
}


Computer::~Computer(void)
{
}

void Computer::Error(std::string message)
{
	std::cout<<message<<"\n";

	std::abort();
}
