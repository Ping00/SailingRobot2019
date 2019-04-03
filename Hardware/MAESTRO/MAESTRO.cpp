#include "MAESTRO.hpp"
MAESTRO::MAESTRO()
{
	portname = "/dev/ttyACM0";
}

bool MAESTRO::init(const char* port)
{
	
}

void MAESTRO::command(int handle, int channel, MAESTRO_COMMAND command, int value)
{
	
}
