#ifndef __MAESTRO_HPP__
#define __MAESTRO_HPP__

typedef enum
{

} MAESTRO_COMMAND;

class MAESTRO
{
    private:

    public:
      MAESTRO();

      bool init();

      command(int handle, int channel, MAESTRO_COMMAND command, int value);

};
#endif//__MAESTRO_HPP__
