#include <iostream>
#include "Module_CMPS12.hpp"
Module_CMPS12::Module_CMPS12()
{

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
    CMPS12_DATA set;
    set = m_CMPS12_hardware_connection.read();
    //Check if set was valid by examining Calibration byte
    //-1 Means set was invalid (Data failed due to wire connection)
    
}

bool Module_CMPS12::getInitialized()
{
    return m_initialized;
}
