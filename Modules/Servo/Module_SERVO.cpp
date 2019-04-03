#include "Module_SERVO.hpp"
Module_SERVO::Module_SERVO(int upper_limit, int lower_limit, int channel)
{
	m_upper_boundary = upper_limit;
	m_lower_boundary = lower_limit;
	m_channel = channel;
	m_initialized = false;
}
		
bool Module_SERVO::init()
{
	bool result = m_servo_hardware_connection.init();
	m_initialized = result;
	return result;
}

		
void Module_SERVO::run()
{
	m_servo_hardware_connection.command(
		m_servo_hardware_connection.get_file_descriptor(),
		m_channel,
		MAESTRO_SET_POSITION,
		m_target);
}

void Module_SERVO::set_target(int limit)
{
	if(limit < m_upper_boundary || limit > m_lower_boundary)
	{
		m_target = limit;
	}
}
