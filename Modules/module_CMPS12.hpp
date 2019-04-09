#ifndef __MODULE_CMPS12_HPP__
#define  __MODULE_CMPS12_HPP__
#include <vector>
class Module_CMPS12
{

    private:
      //Hardware component for our compass module
      CMPS12                    m_CMPS12_hardware_connection;

      //Container for X amount of stored data-pulls
      std::vector<CMPS12_Data>  m_CMPS12_data_set;

      //Is this module initialized
      bool                      m_active;

    public:
      Module_CMPS12();
      ~Module_CMPS12();
      void init();
      void run();

      //For Eventual Observer request
      //bool send();

};
#endif//__MODULE_CMPS12_HPP__
