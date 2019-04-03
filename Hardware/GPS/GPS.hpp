#ifndef __GPS_HPP__
#define __GPS_HPP__
#include <libgpsmm.h>
#include <memory>
#include "GPS_data.hpp"
class GPS
{
	private:
		bool m_initialized;
		
		//GPSMM is a pointer to go around the initializer list
		gpsmm* m_gps;
		
	public:
		GPS();
		bool init();
		GPS_DATA read();
};
#endif//__GPS_HPP__ 
