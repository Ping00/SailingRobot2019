#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__
#include <string>
#include "../../Utilities/Data_Containers/LOG.hpp"
#include "../../Utilities/Data_Containers/GPS_POSITION.hpp"
class Logger
{
    private:
        int                 m_entries;
        LOG                 m_log;
        std::string         m_file_path;

    public:
        Logger(std::string path);

        void log_data(LOG packet);
        void publish();
        void publish_waypoint(GPS_POSITION position, std::string message);
};
#endif//__LOGGER_HPP__
