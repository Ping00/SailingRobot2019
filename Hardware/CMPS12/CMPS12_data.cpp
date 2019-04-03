#include "CMPS12_data.hpp"
#define TOTAL_ENTRIES 18
CMPS12_DATA::CMPS12_DATA()
{
   m_data.reserve(TOTAL_ENTRIES);
}

void CMPS12_DATA::set_entry(DATA_SET_REGISTRY entry, int data)
{
   m_data[entry] = data;
}

int CMPS12_DATA::get_entry(DATA_SET_REGISTRY entry)
{
   return m_data[entry];
}
