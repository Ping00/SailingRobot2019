#include "cmps12.hpp"
#include <iostream>
CMPS12::CMPS12()
{

}

uint16_t CMPS12::bitshift(uint8 high, uint8 low)
{
    uint16_t result = (high << 8 | low);
    return result;
}

CMPS12_DATA CMPS12::read()
{
    CMPS12_DATA data;

    return data;
}