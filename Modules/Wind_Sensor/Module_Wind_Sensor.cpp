#include "Module_Wind_Sensor.hpp"
#include "../../Utilities/utilities.hpp"
Module_Wind_Sensor::Module_Wind_Sensor(int spi_channel)
{
	m_initialized = false;
	m_spi_channel = spi_channel;
}

bool	Module_Wind_Sensor::init()
{
		bool result = m_hardware_connection_MA3.init(m_spi_channel);
		m_initialized = result;
		return result;
}

void 	Module_Wind_Sensor::read()
{
	//The values retrieved from the sensor need to be converted to our range
	//(Initial values are between 2-1020, we want 0 - 359	
	int reading = m_hardware_connection_MA3.read(m_spi_channel);
	m_reading = Utilities::convert_coordinates(2,1020,0,359,reading);
	
	//TODO ADD OFFSET SO THE READING POINTS NORTH
	
}

int 	Module_Wind_Sensor::get_reading()
{
	return m_reading;
}

void Module_Wind_Sensor::report()
{
		std::cout << "Wind Bearing: " << m_reading << std::endl;
}



