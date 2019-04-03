#include "Module_SERVO.hpp"
#include <iostream>
Module_SERVO::Module_SERVO(double lower_limit, double upper_limit, int channel)
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
	if(m_initialized)
	{
		int servo_position = calculate_position(m_target);
	
		
		m_servo_hardware_connection.command(
			m_servo_hardware_connection.get_file_descriptor(),
			m_channel,
			MAESTRO_SET_POSITION,
			servo_position);
		
	}
	else
	{
			std::cout << "Module_Servo not initialized" << std::endl;
	}
}

void Module_SERVO::set_target(int limit)
{
	if(limit < m_upper_boundary || limit > m_lower_boundary)
	{
		m_target = limit;
	}
}


int Module_SERVO::calculate_position(double position)
{
	int servo_lower_limit = m_servo_hardware_connection.get_lower_limit();
	int servo_upper_limit = m_servo_hardware_connection.get_upper_limit();
	
	double percentile = (m_target - m_lower_boundary) / (m_upper_boundary - m_lower_boundary);
	
	int destination = percentile*(servo_upper_limit-servo_lower_limit)+servo_lower_limit;
	
	return destination;
}

