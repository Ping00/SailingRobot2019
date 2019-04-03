#include "Module_GPS.hpp"
#include <iostream>
Module_GPS::Module_GPS()
{
	
}

bool Module_GPS::init()
{
	bool result = m_gps_hardware_connection.init();
	m_initialized = result;
	return result;
}

void Module_GPS::run()
{
	if(m_initialized)
	{
		GPS_DATA reading = m_gps_hardware_connection.read();
		if(reading.get_valid())
		{
			m_data_reading = reading;
		}
		else
		{
			std::cout << "GPS: DATA READING NOT VALID" << std::endl;
		}
	}
}

GPS_DATA Module_GPS::get_reading()
{
	return m_data_reading;
}
