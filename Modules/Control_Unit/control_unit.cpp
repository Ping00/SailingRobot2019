#include "control_unit.hpp"
#include <iostream>
Control_Unit::Control_Unit()
{
  m_active                  = false;
  m_waypoint_reached        = false;
  m_waypoint_set            = false;
  m_destination_reached     = false;
  m_destination_set         = false;

  m_destination.latitude    = 0;
  m_destination.longitude   = 0;

  m_waypoint.latitude       = 0;
  m_waypoint.longitude      = 0;
}

bool Control_Unit::init()
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

bool Control_Unit::init(GPS_POSITION destination)
{
    m_destination = destination;
    m_destination_set = true;
    m_active = true;
    return true;
}

void Control_Unit::set_waypoint(GPS_POSITION waypoint)
{
    m_waypoint = waypoint;
    m_waypoint_set = true;
}

void Control_Unit::set_destination(GPS_POSITION destination)
{
    m_destination = destination;
    m_destination_set = true;
}

bool Control_Unit::is_active()
{
    return m_active;
}