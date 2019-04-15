#include "CMPS12.hpp"
#include <iostream>
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

    const int registry_entries = 31;



    return data;
}