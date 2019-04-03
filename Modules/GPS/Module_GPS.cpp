#include "Module_GPS.hpp"
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
			
	}
}

GPS_DATA Module_GPS::get_reading()
{
	return m_data_reading;
}
