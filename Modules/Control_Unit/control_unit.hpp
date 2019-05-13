#ifndef __CONTROL_UNIT_HPP__
#define __CONTROL_UNIT_HPP__
#include <queue>
#include <string>
#include "../../Utilities/Data_Containers/GPS_POSITION.hpp"
class Control_Unit
{
    private:

        bool          m_active;                     //Is the Control Unit Activated
        bool          m_waypoint_reached;           //Have we reached our waypoint
        bool          m_waypoint_set;               //Have we set a waypoint?
        bool          m_destination_set;            //Have we set a destination
        bool          m_destination_reached;        //Have we reached our destination

        std::queue<GPS_POSITION>  m_destination;    //Queue of all our destinations
        GPS_POSITION              m_waypoint;       //Our current waypoint

        double        m_distance_threshold;         //The distance we are allowed to be away from the waypoint to consider it reached (Meters)

        double        m_time_threshold;             //How long should we wait until we establish a new waypoint If the old one hasnt been reached

    public:
        Control_Unit();
        bool    is_active();

        bool    init(std::string destination, std::string settings);

        void    set_waypoint(GPS_POSITION waypoint);
        GPS_POSITION get_destination();

        void    set_destination(GPS_POSITION destination);
        GPS_POSITION get_waypoint();

        void    set_threshold(double value);
        double  get_threshold();

};
#endif//__CONTROL_UNIT_HPP__
