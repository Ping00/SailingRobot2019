#include "control_unit.hpp"
Control_Unit::Control_Unit()
{
  m_active              = false;
  m_waypoint_reached    = false;
  m_destination_reached = false;

  GPS_POSITION empty;
  empty.latitude = 0;
  empty.longitude = 0;

  m_destination = empty;
  m_waypoint = empty;
}
