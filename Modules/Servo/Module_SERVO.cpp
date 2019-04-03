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
	int servo_position = calculate_position(m_target);
	
	m_servo_hardware_connection.command(
		m_servo_hardware_connection.get_file_descriptor(),
		m_channel,
		MAESTRO_SET_POSITION,
		servo_position);
}

void Module_SERVO::set_target(int limit)
{
	if(limit < m_upper_boundary || limit > m_lower_boundary)
	{
		m_target = limit;
	}
}

int Module_SERVO::calculate_position(int position)
{
	int servo_lower_limit = m_servo_hardware_connection.get_lower_limit();
	int servo_upper_limit = m_servo_hardware_connection.get_upper_limit();

	//Calculate percentile range for our boundaries
	int percentile = (m_target - m_lower_boundary) / (m_upper_boundary - m_lower_boundary);
	int destination = percentile*(servo_upper_limit-servo_lower_limit)+servo_lower_limit;
	
	std::cout << "SERVO SHOULD BE AT: " << destination <<  << " FOR " << position << std::endl;
	
	return destination;
}
