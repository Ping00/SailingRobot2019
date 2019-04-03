#include "Module_SERVO.hpp"
Module_SERVO::Module_SERVO(int upper_limit, int lower_limit)
{
	
}
		
bool Module_SERVO::init()
{
	bool result = m_servo_hardware_connection.init();
	m_initialized = result;
	return result;
}

		
void Module_SERVO::run()
{
	
}

void Module_SERVO::set_target(int limit)
{
	
}
