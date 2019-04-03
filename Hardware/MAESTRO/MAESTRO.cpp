#include "MAESTRO.hpp"
#include <termios.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <iostream>
#include <fcntl.h>
MAESTRO::MAESTRO()
{
	//992 & 2000 respectively IN MCU (Maestro Control Unit)
	m_lower_limit = 3968;
    m_upper_limit = 8000;
    m_portname = "/dev/ttyACM0";
}

bool MAESTRO::init()
{
	bool result = false;
	
	struct termios options;
    tcgetattr(m_file_descriptor ,&options);
    options.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
    options.c_oflag &= ~(ONLCR | OCRNL);
    tcsetattr(m_file_descriptor,TCSANOW, &options);
	
	m_file_descriptor = open(portname, O_RDWR | O_NOCTTY);
	if(m_file_descriptor < 0)
    {
        printf("Init Failed to open file descriptor\n");
        return false;
    }
	
	return result;
}

void MAESTRO::command(int handle, int channel, MAESTRO_REGISTRY command, int value)
{
	
}
