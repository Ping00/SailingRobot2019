#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__
#include <string>
#include "../../Utilities/Data_Containers/LOG.hpp"
class Logger
{
    private:
        int                 m_entries;

        std::string         m_file_path;

    public:
        Logger();

        void                publish();
        void                log();
};
#endif//__LOGGER_HPP__
