#include "logger.hpp"
#include <string>
#include "../IO/IO.hpp"
Logger::Logger(std::string path)
{
    m_entries = 0;
    m_file_path = path;

}

void Logger::log_data(LOG packet)
{
    m_log = packet;
}

void Logger::publish()
{
    IO io;
    io.write_file("THIS IS JUST A TEST",m_file_path);
}

void Logger::publish_waypoint(GPS_POSITION position)
{

}