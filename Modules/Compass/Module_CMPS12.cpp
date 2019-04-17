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
    m_initialized = m_CMPS12_hardware_connection.init();
    return m_initialized;
}

void Module_CMPS12::run()
{
    CMPS12_DATA set;
    set = m_CMPS12_hardware_connection.read();
}

bool Module_CMPS12::getInitialized()
{
    return m_initialized;
}
