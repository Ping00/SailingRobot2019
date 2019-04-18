#include "CMPS12_data.hpp"
#include <iostream>
#define TOTAL_ENTRIES 18
CMPS12_DATA::CMPS12_DATA()
{
   m_data.reserve(TOTAL_ENTRIES);
   m_data_reading_valid = false;
}

void CMPS12_DATA::set_entry(DATA_SET_REGISTRY entry, int data)
{
    swich(entry)
    {
        default:
            std::cout << "NOT IMPLEMENTED IN THIS VERSION" << std::endl;
            break;
        
    }
}

int CMPS12_DATA::get_entry(DATA_SET_REGISTRY entry)
{
        swich(entry)
    {
        default:
            std::cout << "NOT IMPLEMENTED IN THIS VERSION" << std::endl;
            break;
        
    }
}

int CMPS12_DATA::get_entry(int entry)
{
    swich(entry)
    {
        default:
            std::cout << "NOT IMPLEMENTED IN THIS VERSION" << std::endl;
            break;
        
    }
}

void CMPS12_DATA::set_entry(int entry, int data)
{
    swich(entry)
    {
        default:
            std::cout << "NOT IMPLEMENTED IN THIS VERSION" << std::endl;
            break;
        
    }
}

void CMPS12_DATA::set_valid(bool valid)
{
    m_data_reading_valid = valid;
}

bool CMPS12_DATA::get_valid()
{
    return m_data_reading_valid;
}
