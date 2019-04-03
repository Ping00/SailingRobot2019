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
	
}

void Module_GPS::read_data()
{
	
}

GPS_DATA Module_GPS::get_reading()
{
		GPS_DATA temp;
		
		return temp;

}
