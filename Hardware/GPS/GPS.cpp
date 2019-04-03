#include "GPS.hpp"
GPS::GPS()
{
	
} 

bool GPS::init()
{
	m_gps = gpsmm("localhost",DEFAULT_GPSD_PORT);
	
	
}
