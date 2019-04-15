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

      //Container for X amount of stored data-pulls
      std::vector<CMPS12_DATA>  m_CMPS12_data_set;

      //Is this module initialized
      bool                      m_active;

    public:
      Module_CMPS12();
      ~Module_CMPS12();
      bool init();
      void run();

};
#endif//__MODULE_CMPS12_HPP__
