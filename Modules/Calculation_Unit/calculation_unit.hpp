#ifndef __CALCULATION_UNIT_HPP__
#define __CALCULATION_UNIT_HPP__
#include "../../Utilities/Data_Containers/VEC2.hpp"
#include "../../Hardware/GPS/GPS_data.hpp"
class Calculation_Unit
{
    private:


    public:
      double    calculate_rudder_position(VEC2 vector);
      double    calculate_sail_position(VEC2 vector);
      double    calculate_angle_of_approach(GPS_DATA current_position, GPS_DATA destination, VEC2 wind_directtion);
      GPS_DATA  calculate_waypoint(GPS_DATA current_position, double distance, double direction);
      double    calculate_distance(GPS_DATA point_a, GPS_DATA point_b);
};
#endif//__CALCULATION_UNIT_HPP__
