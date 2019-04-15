#include "CMPS12.hpp"
#include <iostream>
#include <vector>
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
    //Data set
    CMPS12_DATA data;

    //Read data if
    if(initialized)
    {
        std::vector<int> raw_data;
        raw_data.reserve(TOTAL_REGISTRY_ENTRIES);

        //Read All Entries into our raw data
        for(int i = 0; i < TOTAL_REGISTRY_ENTRIES; i++)
        {
            
        }
    }
    else
    {
        std::cout << "ERROR: CMPS WAS NOT INITIALIZED!" << std::endl;
        return data;
    }

    return data;
}