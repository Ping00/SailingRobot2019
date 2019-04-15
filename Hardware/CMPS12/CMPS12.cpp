#include "CMPS12.hpp"
#include <iostream>
#include "CMPS12_I2C_registry.hpp"
CMPS12::CMPS12()
{

}

int CMPS12::bitshift(int high, int low)
{
    int result = (high << 8 | low);
    return result;
}

CMPS12_DATA CMPS12::read()
{
    CMPS12_DATA data;
    


    return data;
}