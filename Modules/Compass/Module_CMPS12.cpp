#include <iostream>
#include "Module_CMPS12.hpp"
Module_CMPS12::Module_CMPS12()
{
<<<<<<< HEAD
    std::cout << "Constructing [Module] : CMPS12" << std::endl;
    m_initialized = false;
=======
    m_tick_counter = 0;
    m_iterator_counter = 0;
    m_CMPS12_data_set.reserve(100);
>>>>>>> 81256546be03e52f9f5bc9e72155e1198344fe28
}

Module_CMPS12::~Module_CMPS12()
{

}

bool Module_CMPS12::init()
{
    std::cout << "Module Initializing" << std::endl;
<<<<<<< HEAD
    m_initialized = m_CMPS12_hardware_connection.init();
    return m_initialized;
=======
    bool state = m_CMPS12_hardware_connection.init();
    m_initialized = state;
    return state;
>>>>>>> 81256546be03e52f9f5bc9e72155e1198344fe28
}

void Module_CMPS12::run()
{
<<<<<<< HEAD
    CMPS12_DATA set;
    set = m_CMPS12_hardware_connection.read();
=======
    CMPS12_DATA data;
    data = m_CMPS12_hardware_connection.read();
    if(data.get_entry(DATA_SET_CALIBRATION_STATE_8) != -1)
    {
            std::cout << "DATA OK" << std::endl;
            //Data was OK place it on the stack
            m_CMPS12_data_set[m_iterator_counter] = data;
    }
>>>>>>> 81256546be03e52f9f5bc9e72155e1198344fe28
}

bool Module_CMPS12::getInitialized()
{
    return m_initialized;
}
