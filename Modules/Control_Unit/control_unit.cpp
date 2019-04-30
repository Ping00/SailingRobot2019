#include "control_unit.hpp"
#include <iostream>
Control_Unit::Control_Unit()
{
  m_active              = false;
  m_waypoint_reached    = false;
  m_destination_reached = false;

  m_destination.latitude = 0;
  m_destination.longitude = 0;

  m_waypoint.latitude = 0;
  m_waypoint.longitude = 0;
}

bool Control_Unit::init()
{
    if(m_destination.latitude == 0 && m_destination.longitude == 0)
    {
        std::cout << "DESTINATION HAS NOT BEEN SET!" << std::endl;
        return false;
    }
    else
    {
        m_active = true;
        return true;
    }
}

bool Control_Unit::get_active()
{
    return m_active;
}