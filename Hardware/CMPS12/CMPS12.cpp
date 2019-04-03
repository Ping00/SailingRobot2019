#include "CMPS12.hpp"
#include <iostream>
#include <vector>
#include "CMPS12_I2C_registry.hpp"
#include <wiringPi.h>
#include <wiringPiI2C.h>
CMPS12::CMPS12()
{
    m_file_descriptor = 0;
    m_initialized   = false;
}

int CMPS12::bitshift(int high, int low)
{
    int result = (high << 8 | low);
    return result;
}

bool CMPS12::init()
{
    std::cout << "CMPS Hardware Initializing" << std::endl;
    wiringPiSetup();
    m_file_descriptor = wiringPiI2CSetup(I2C_DEVICE_ADDRESS);
    if(m_file_descriptor == -1)
    {
        std::cout << "CMPS Hardware Failed to Initialize" << std::endl;
        m_initialized = false;
    }
    m_initialized = true;
}

CMPS12_DATA CMPS12::read()
{

    //Read data if we are initialized
    if(m_initialized)
    {
        CMPS12_DATA data_set;
        
        std::vector<int> raw_data;
        raw_data.reserve(31);
        //Last Registry is to affirm if the package was OK or not
        for(int i = 0; i < TOTAL_REGISTRY_ENTRIES; i++)
        {
            raw_data[i] = wiringPiI2CReadReg8(m_file_descriptor,i);
            if(raw_data[i] == -1)
            {
                std::cout << "Data Corrupt!" << std::endl;
            }
            else
            { 
                std::cout << "Data OK!" << std::endl;
            }
        }
        
        //Check that data set was not corrupt
        
        
        return data_set;
        
    }
    else
    {
        throw "ERROR: CMPS WAS NOT INITIALIZED!";
    }
}
