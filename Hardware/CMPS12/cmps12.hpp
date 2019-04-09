#ifndef __CMPS12_HPP__
#define  __CMPS12_HPP__

enum typedef
{
  A = 0x00

} CMPS12_REGISTRY;

class CMPS12
{
    private:
      //ADD DATA CONTAINER MEMBERS


    public:
      CMPS12();

      //Read data from I2C Pins, store data in members
      CMPS12 read();

};
#endif//__CMPS12_HPP__