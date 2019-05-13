#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__
#include <vector>
class Logger
{
    private:
        int              m_entries;
    
    public:
        Logger();
        
        void                publish();
        
        void                log(LOG packet);
        int                 get_amount_of_entries();
}
#endif//__LOGGER_HPP__
