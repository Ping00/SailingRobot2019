#ifndef __CONTROL_UNIT_HPP__
#define __CONTROL_UNIT_HPP__
class Control_Unit
{
    private:
        bool          m_active;

        bool          m_waypoint_reached;
        bool          m_waypoint_set;

        bool          m_destination_set;
        bool          m_destination_reached;

        GPS_POSITION  m_destination;
        GPS_POSITION  m_waypoint;

        double        m_threshold;

        long int      m_data_tick;

    public:
        Control_Unit();
        bool    is_active();

        bool    init();
        bool    init(GPS_POSITION destination);

        void    set_waypoint(GPS_POSITION waypoint);
        GPS_POSITION get_destination();

        void    set_destination(GPS_POSITION destination);
        GPS_POSITION get_waypoint();

        void    set_threshold(double value);
        double  get_threshold();

};
#endif//__CONTROL_UNIT_HPP__
