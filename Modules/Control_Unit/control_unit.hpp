#ifndef __CONTROL_UNIT_HPP__
#define __CONTROL_UNIT_HPP__
#include <queue>
#include <string>
class Control_Unit
{
    private:
        //Is the Control Unit Activated
        bool          m_active;

        //Have we reached our waypoint
        bool          m_waypoint_reached;
        
        //Have we set a waypoint?
        bool          m_waypoint_set;

        //Have we set a destination
        bool          m_destination_set;
        
        //Have we reached our destination
        bool          m_destination_reached;

        //Queue of all our destinations
        std::queue<GPS_POSITION>  m_destination;
        
        //Our current waypoint
        GPS_POSITION              m_waypoint;
        
        //The distance we are allowed to be away
        //From the waypoint to consider it reached (Meters)
        double        m_distance_threshold;
        
        //How long should we wait until we establish a new waypoint
        //If the old one hasnt been reached
        double        m_time_threshold;

        long int      m_data_tick;

    public:
        Control_Unit();
        bool    is_active();

        bool    init();
        bool    init(std::string file);

        void    set_waypoint(GPS_POSITION waypoint);
        GPS_POSITION get_destination();

        void    set_destination(GPS_POSITION destination);
        GPS_POSITION get_waypoint();

        void    set_threshold(double value);
        double  get_threshold();

};
#endif//__CONTROL_UNIT_HPP__
