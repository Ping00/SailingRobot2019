#include "CMPS12.hpp"
#include <iostream>
#include <vector>
#include "CMPS12_I2C_registry.hpp"
#include <wiringPi.h>
#include <wiringPiI2C.h>
CMPS12::CMPS12()
{
    m_file_directory = 0;
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
    m_file_directory = wiringPiI2CSetup(I2C_DEVICE_ADDRESS);
    if(m_file_directory == -1)
    {
        std::cout << "CMPS Hardware Failed to Initialize" << std::endl;
        m_initialized = false;
    }
    m_initialized = true;
    return m_initialized;
}

CMPS12_DATA CMPS12::read()
{
    //Data set
    CMPS12_DATA data;

    //Read data if
    if(m_initialized)
    {
        std::vector<int> raw_data;
        raw_data.reserve(TOTAL_REGISTRY_ENTRIES);

        //If Our Read Equals -1 then we have a connection error between the pins


        //Read All Entries into our raw data

    }
    else
    {
        throw "ERROR: CMPS WAS NOT INITIALIZED!";
    }

    return data;
}
