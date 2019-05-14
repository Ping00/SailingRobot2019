#include "control_unit.hpp"
#include <iostream>
#include "../../Core/IO/IO.hpp"
#include "../../Core/Parser/Parser.hpp"
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
    Parser parser;

    //Get file data and remove all comments
    std::vector<std::string> data_raw = io.read_file(destination);
    std::vector<std::string> data_clean = parser.remove_comments(data_raw);
    int checkpoints = data_clean.size();
    std::cout << "We Have #" << checkpoints << " Checkpoints to travel to" << std::endl;

    //Store each checkpoints in reverse (FIFO, we want our first one to be on top of the stack)
    for(int i = checkpoints; i > 0; i--)
    {
        std::vector<std::string> split = parser.split_string(data_clean[i-1],',');
        if(split.size() == 2)
        {
            GPS_POSITION pin;
            pin.latitude  = std::atof(split[0].c_str());
            pin.longitude = std::atof(split[1].c_str());
            m_destination.push(pin);
        }
        else
        {
            std::cout << "COORDINATE ERROR" << std::endl;
            m_active = false;
            return false;
        }
    }
    std::cout << "Destination Coordinates Logged" << std::endl;
    m_destination_set = true;

    //Store threshold variables
    std::vector<std::string> settings_raw = io.read_file(settings);
    std::vector<std::string> settings_clean = parser.remove_comments(settings_raw);
    //NOTE THAT OUR ELEMENTS ARE THE SETTINGS POSITIONS; REMOVAL OF SETTINGS OR
    //ADDING WITHOUT MENDING WILL CAUSE FAULTS
    int total_settings = settings_clean.size();
    std::cout << "Total Settings found: " << total_settings << std::endl;
    if(total_settings < 2)
    {
        std::cout << "SETTINGS FILE CORRUPT / MISSING: DEFAULTING TO STANDARD VALUES (0/0)" << std::endl;
        m_distance_threshold = 0;
        m_time_threshold = 0;
    }
    else
    {
          //NOTE WE DONT REMOVE EMPTY LINES SO WE SKIP [1] AS IT IS EMPTY
          m_distance_threshold = std::atof(settings_clean[0].c_str());
          m_time_threshold = std::atof(settings_clean[2].c_str());
    }

    std::cout << "Distance (M) : " << m_distance_threshold << std::endl;
    std::cout << "Time     (S) : " << m_time_threshold << std::endl;

    m_active = true;
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
    //TODO REMOVE THE TWO LINES BELOW AFTER TESTING IS DONE
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
