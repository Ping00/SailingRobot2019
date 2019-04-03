#ifndef __MAESTRO_HPP__
#define __MAESTRO_HPP__
#include "MAESTRO_REGISTRY.hpp"
class MAESTRO
{
    private:
    bool  m_initialized;
    int   m_file_descriptor;
    const char* portname;

    public:
      MAESTRO();

      bool init();

      void command(int handle, int channel, MAESTRO_REGISTRY command, int value);

};
#endif//__MAESTRO_HPP__
