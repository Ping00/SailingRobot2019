#include <iostream>
#include "module_CMPS12.hpp"
Module_CMPS12::Module_CMPS12()
{

}

Module_CMPS12::~Module_CMPS12()
{

}

bool Module_CMPS12::init()
{
    std::cout << "Module Initializing" << std::endl;
    return m_CMPS12_hardware_connection.init();
}

void Module_CMPS12::run()
{
    CMPS12_DATA set;
    m_CMPS12_hardware_connection.read();
}

bool Module_CMPS12::getInitialized()
{
    return m_initialized;
}
