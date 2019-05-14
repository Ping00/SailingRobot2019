#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__
#include <string>
#include "../../Utilities/Data_Containers/LOG.hpp"
class Logger
{
    private:
        int                 m_entries;
        LOG                 log;
        std::string         m_file_path;

    public:
        Logger(std::string path);

        void log_data(LOG packet);
        void publish();
};
#endif//__LOGGER_HPP__
