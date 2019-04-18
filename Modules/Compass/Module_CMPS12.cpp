#include <iostream>
#include "Module_CMPS12.hpp"
//#include "../../Hardware/CMPS12/CMPS12_DATA_registry.hpp"
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
    if(m_initialized)
    {
         CMPS12_DATA data;
        data = m_CMPS12_hardware_connection.read();
        if(data.get_valid())
        {
            m_CMPS12_data_reading = data;
        }
        else
        {
            std::cout << "CONNECTION ERROR: CHECK CABLING" << std::endl;
        }
    }
}

bool Module_CMPS12::getInitialized()
{
    return m_initialized;
}

CMPS12_DATA Module_CMPS12::get_reading()
{
    return m_CMPS12_data_reading;
}

void Module_CMPS12::report()
{
    std::cout << "-------------------------" << std::endl;
    std::cout << "Bearing: " << m_CMPS12_data_reading.get_entry(DATA_SET_COMPASS_BEARING_DEGREES_16) << std::endl;
    std::cout << "Pitch  : " << m_CMPS12_data_reading.get_entry(DATA_SET_PITCH_ANGLE_8) << std::endl;
    std::cout << "Roll   : " << m_CMPS12_data_reading.get_entry(DATA_SET_ROLL_ANGLE_8) << std::endl;
}
