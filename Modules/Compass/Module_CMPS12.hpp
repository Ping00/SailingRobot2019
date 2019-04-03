#ifndef __MODULE_CMPS12_HPP__
#define  __MODULE_CMPS12_HPP__
#include <vector>
#include "../../Hardware/CMPS12/CMPS12.hpp"
#include "../../Hardware/CMPS12/CMPS12_data.hpp"
class Module_CMPS12
{

    private:
      //Hardware component for our compass module
      CMPS12                    m_CMPS12_hardware_connection;

      //Latest reading
      CMPS12_DATA               m_CMPS12_data_reading;

      //Is this module initialized
      bool                      m_initialized;
      

    public:
      Module_CMPS12();
      ~Module_CMPS12();
      bool init();
      void run();

      bool getInitialized();

      CMPS12_DATA get_reading();
      
      void report();

};
#endif//__MODULE_CMPS12_HPP__