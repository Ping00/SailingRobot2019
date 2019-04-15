#ifndef __CMPS12_HPP__
#define __CMPS12_HPP__
#include "CMPS12_data.hpp"
class CMPS12
{
    private:
      //Place in Utilities eventually
      uint16_t bitshift(int high, int low);

    public:
      CMPS12();

      //Establish connection to I2C device
      bool init();

      //Read data from I2C Pins, return retrieved data
      CMPS12_DATA read();

};
#endif//__CMPS12_HPP__
