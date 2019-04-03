#include <iostream>
#include "Module_CMPS12.hpp"
Module_CMPS12::Module_CMPS12()
{
    m_tick_counter = 0;
    m_iterator_counter = 0;
    m_CMPS12_data_set.reserve(100);
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
            //Data was OK place it on the stack
            m_CMPS12_data_set[m_iterator_counter] = data;
    }
}

bool Module_CMPS12::getInitialized()
{
    return m_initialized;
}
