#ifndef __MODULE_GPS_HPP__
#define __MODULE_GPS_HPP__
#include "../../Hardware/GPS/GPS.hpp"
class Module_GPS
{
	private:
	
		bool	m_initialized;
		
		GPS		m_gps_hardware_connection;
		
	public:
		Module_GPS();
		bool init();
};
#endif//__MODULE_GPS_HPP__
