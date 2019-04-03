#include "GPS.hpp"
#include <iostream>
GPS::GPS()
{
	
} 

bool GPS::init()
{
	//Init and bind
	gpsmm gps("localhost",DEFAULT_GPSD_PORT);
	m_gps = &gps;
	
	if(m_gps == nullptr)
	{
		std::cout << "Failed to bind GPS with gpsmm" << std::endl;
		return false;
	}
	
	//Check if our DAEMON is running
	if(gps.stream(WATCH_ENABLE | WATCH_JSON) == nullptr)
	{
			std::cout << "GPSD DAEMON NOT RUNNING" << std::endl;
			return false;
	}
	
	return true;
	
}

GPS_DATA GPS::read()
{
	GPS_DATA data_reading;
	
	return data_reading;
}
