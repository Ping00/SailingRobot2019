#include "logger.hpp"
#include <string>
#include "../IO/IO.hpp"
#include "../../Hardware/GPS/GPS_data.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
Logger::Logger(std::string path)
{
    m_entries = 0;
    m_file_path = path;

}

void Logger::log_data(LOG packet)
{
    m_log = packet;
    m_available = true;
}

void Logger::publish()
{
    if(m_available)
    {
        int bearing             = m_log.m_bearing;
        double latitude         = m_log.m_latitude;
        double longitude        = m_log.m_longitude;
        double speed            = m_log.m_speed;
        std::string timestamp   = m_log.m_timestamp;
        double waypoint         = m_log.m_distance_from_waypoint;
        double checkpoint       = m_log.m_distance_from_destination;

        std::stringstream stream;
        stream << timestamp << " " << std::setprecision(15) << latitude << " " << std::setprecision(15) << longitude;

        std::string output = stream.str();


        IO io;
        io.write_file(output,m_file_path);
        m_entries++;
        m_available = false;
    }
    else
    {
        std::cout << "NO NEW LOG AVAILABLE" << std::endl;
    }
}

void Logger::publish_waypoint(GPS_DATA data, std::string message)
{
      std::string timestamp = data.get_time();
      double lat = data.get_latitude();
      double lon = data.get_longitude();

      std::stringstream stream;
      stream << timestamp << " : " << std::setprecision(10) << lat << "," << std::setprecision(10) << lon;
      std::string output = stream.str();

      IO io;
      io.write_file(output + " : "+ message ,m_file_path);
      m_entries++;
      m_available = false;

}

void Logger::write(std::string message)
{
    std::stringstream stream;
    stream << message;

    IO io;
    io.write_file(message ,m_file_path);
}
