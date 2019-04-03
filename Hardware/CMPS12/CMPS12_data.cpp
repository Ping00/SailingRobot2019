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
   m_data[entry] = data;
}

int CMPS12_DATA::get_entry(DATA_SET_REGISTRY entry)
{
   return m_data[entry];
}

int CMPS12_DATA::get_entry(int entry)
{
   return m_data[entry];
}

void CMPS12_DATA::set_entry(int entry, int data)
{
   m_data[entry] = data;
}

bool CMPS12_DATA::get_valid()
{
   return m_data_reading_valid;
}
