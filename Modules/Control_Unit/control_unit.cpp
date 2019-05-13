#include "control_unit.hpp"
#include <iostream>
Control_Unit::Control_Unit()
{
  m_active                  = false;
  m_waypoint_reached        = false;
  m_waypoint_set            = false;
  m_destination_reached     = false;
  m_destination_set         = false;

  m_waypoint.latitude       = 0;
  m_waypoint.longitude      = 0;

  m_distance_threshold      = 0;
  m_time_threshold          = 0;
}

bool Control_Unit::init(std::string destination, std::string settings)
{
    if(m_destination_set)
    {
        m_active = true;
        return true;
    }
    else
    {
        std::cout << "DESTINATION HAS NOT BEEN SET" << std::endl;
        return false;
    }
}

void Control_Unit::set_waypoint(GPS_POSITION waypoint)
{
    m_waypoint = waypoint;
    m_waypoint_set = true;
}


bool Control_Unit::is_active()
{
    return m_active;
}
