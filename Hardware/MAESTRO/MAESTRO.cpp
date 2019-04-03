#include "MAESTRO.hpp"
MAESTRO::MAESTRO();

bool MAESTRO::init();

void MAESTRO::command(int handle, int channel, MAESTRO_COMMAND command, int value); 
