#include "logger.hpp"
#include <string>
#include "../IO/IO.hpp"
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

        int id                  = m_log.m_entry_id;
        int bearing             = m_log.m_bearing;
        double latitude         = m_log.m_latitude;
        double longitude        = m_log.m_longitude;
        double speed            = m_log.m_speed;
        std::string timestamp   = m_log.m_timestamp;
        double waypoint         = m_log.m_distance_from_waypoint;
        double checkpoint       = m_log.m_distance_from_destination;

        std::stringstream stream;
        stream << timestamp << " " << std::setprecision(10) << latitude << " " << std::setprecision(10) << longitude <<std::endl;

        std::string data = stream.str();


        IO io;
        io.write_file(data,m_file_path);
        m_entries++;
        m_available = false;
    }
    else
    {
        std::cout << "NO NEW LOG AVAILABLE" << std::endl;
    }
}

void Logger::publish_waypoint(GPS_POSITION position, std::string message)
{
    if(m_available)
    {

      std::string data = "";



      IO io;
      io.write_file("THIS IS JUST A TEST : " + message ,m_file_path);
      m_entries++;
      m_available = false;
    }
    else
    {
        std::cout << "NO NEW LOG AVAILABLE" << std::endl;
    }
}