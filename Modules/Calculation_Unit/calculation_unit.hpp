#ifndef __CALCULATION_UNIT_HPP__
#define __CALCULATION_UNIT_HPP__
#include "VEC2.hpp"
class Calculation_Unit
{
    private:


    public:
      double  degrees_to_radians(double degrees);
      double  radians_to_degrees(double radians);
      double  convert_coordinates(double v_high, double v_low, double u_high, double u_low, double position);
      double  calculate_rudder_position(VEC2 vector);
      double  calculate_sail_position(VEC2 vector);
      VEC2    degrees_to_vector(double value);
      double  vector_to_degrees(VEC2 vector);
};
#endif//__CALCULATION_UNIT_HPP__
