#include "Module_Wind_Sensor.hpp"
#include "../../Utilities/utilities.hpp"
#include <iostream>
#define OFFSET 20
Module_Wind_Sensor::Module_Wind_Sensor(int spi_channel)
{
    std::cout << "Constructing [Module] Wind Sensor" << std::endl;
	m_initialized = false;
    m_new_data_available = false;
	m_spi_channel = spi_channel;
}

bool	Module_Wind_Sensor::init()
{
		bool result = m_hardware_connection_MA3.init(m_spi_channel);
		m_initialized = result;
		return result;
}

void 	Module_Wind_Sensor::run()
{
	//The values retrieved from the sensor need to be converted to our range
	//(Initial values are between 2-1020, we want 0 - 359
	int reading = m_hardware_connection_MA3.read(m_spi_channel);
	int bearing_uncorrected = Utilities::convert_coordinates(2,1020,0,359,reading);
	m_reading = Utilities::normalize(bearing_uncorrected - OFFSET);
  m_new_data_available = true;

}

int 	Module_Wind_Sensor::get_reading()
{
	return m_reading;
}

void Module_Wind_Sensor::report()
{
    if(m_new_data_available)
    {
        std::cout << "- - WIND SENSOR - -" << std::endl;
        std::cout << "Wind Bearing: " << m_reading << std::endl;
        std::cout << "-------------------" << std::endl;
        m_new_data_available = false;
    }
}


bool Module_Wind_Sensor::is_new_data_avilable()
{
    return m_new_data_available;
}
