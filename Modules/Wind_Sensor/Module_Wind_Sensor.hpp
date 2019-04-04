#ifndef __MODULE_WIND_SENSOR_HPP__
#define __MODULE_WIND_SENSOR_HPP__
class Module_Wind_Sensor
{
	private:
		bool m_initialized;
		MA3 m_hardware_connection_MA3;
		
		int m_spi_channel;
		
		int m_reading;

	public:
		Module_Wind_Sensor(int spi_channel);
		bool	init();
		void 	read();
		int 	get_reading();
};
#endif//__MODULE_WIND_SENSOR_HPP__
