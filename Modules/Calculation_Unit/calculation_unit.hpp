#ifndef __CALCULATION_UNIT_HPP__
#define __CALCULATION_UNIT_HPP__
class Calculation_Unit
{
    private:


    public:
      double degrees_to_radians(double degrees);
      double radians_to_degrees(double radians);
      double convert_coordinates(double v_high, double v_low, double u_high, double u_low, double position)
      double calculate_rudder_position(double vec_x, double vec_y);
      double calculate_sail_position(double vec_x, double vec_y);

};
#endif//__CALCULATION_UNIT_HPP__
