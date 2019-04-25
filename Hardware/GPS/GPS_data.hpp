#ifndef __GPS_DATA_HPP__
#define __GPS_DATA_HPP__
#include <string>
class GPS_DATA
{
	private:
		bool					m_valid;
		double				m_latitude;
		double				m_longitude;
		double				m_speed;
		std::string 	m_time;

	public:
		GPS_DATA();

		void set_latitude(double latitude);
		void set_longitude(double longitude);
		void set_timestamp(std::string timestamp);

		void set_valid(bool valid);
		bool get_valid();

		double get_latitude();
		double get_longitude();
		std::string get_time();
};
#endif//__GPS_DATA_HPP__
