#include "Module_Wind_Sensor.hpp"
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
		m_reading = m_hardware_connection_MA3.read(m_spi_channel);
}

int 	Module_Wind_Sensor::get_reading()
{
	return m_reading;
}
