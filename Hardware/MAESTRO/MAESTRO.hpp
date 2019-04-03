#ifndef __MAESTRO_HPP__
#define __MAESTRO_HPP__

class MAESTRO
{
    private:
    bool  m_initialized;
    int   m_file_descriptor;
    const char* portname;

    public:
      MAESTRO();

      bool init();

      command(int handle, int channel, MAESTRO_COMMAND command, int value);

};
#endif//__MAESTRO_HPP__
