#include "control_unit.hpp"
#include <iostream>
#include "../../Core/IO/IO.hpp"
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
    IO io;
    return true;
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

bool Control_Unit::validate_inits(std::vector<bool> statuses)
{
    std::cout << "TESTING AUTO SUCCEED WITH TEST VALUES: [REMOVE WHEN FINISHED TESTING]" << std::endl;
    return true;


    if(statuses[0])
    {
        std::cout << "[OK] : Servo Rudder" << std::endl;
    }
    else
    {
        std::cout << "[ERROR] : Servo Rudder" << std::endl;
    }

    if(statuses[1])
    {
        std::cout << "[OK] : Servo Sail" << std::endl;
    }
    else
    {
        std::cout << "[ERROR] : Servo Sail" << std::endl;
    }

    if(statuses[2])
    {
        std::cout << "[OK] : Module GPS" << std::endl;
    }
    else
    {
        std::cout << "[ERROR] : Module GPS" << std::endl;
    }

    if(statuses[3])
    {
        std::cout << "[OK] : Module Compass" << std::endl;
    }
    else
    {
        std::cout << "[ERROR] : Module Compass" << std::endl;
    }

    if(statuses[4])
    {
        std::cout << "[OK] : Module Wind Sensor" << std::endl;
    }
    else
    {
        std::cout << "[ERROR] : Module Wind Sensor" << std::endl;
    }




    return true;
}
