#include <iostream>
#include "Module_CMPS12.hpp"
Module_CMPS12::Module_CMPS12()
{
    std::cout << "Constructing [Module] : CMPS12" << std::endl;
    m_initialized = false;
}

Module_CMPS12::~Module_CMPS12()
{

}

bool Module_CMPS12::init()
{
    std::cout << "Module Initializing" << std::endl;

    bool state = m_CMPS12_hardware_connection.init();
    m_initialized = state;
    return state;
}

void Module_CMPS12::run()
{
    CMPS12_DATA data;
    data = m_CMPS12_hardware_connection.read();
    if(data.get_entry(DATA_SET_CALIBRATION_STATE_8) != -1)
    {
            std::cout << "DATA OK" << std::endl;
    }
}

bool Module_CMPS12::getInitialized()
{
    return m_initialized;
}
