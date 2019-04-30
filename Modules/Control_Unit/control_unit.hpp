#ifndef __CONTROL_UNIT_HPP__
#define __CONTROL_UNIT_HPP__
class Control_Unit
{
    private:
        boolean       m_active;
        boolean       m_waypoint_reached;
        boolean       m_destination_reached;
        GPS_POSITION  m_destination;
        GPS_POSITION  m_waypoint;

    public:
        Control_Unit();
        void set_waypoint(GPS_POSITION waypoint);
        void set_destination(GPS_POSITION destination);



};
#endif//__CONTROL_UNIT_HPP__
