#include "calculation_unit.hpp"
#include <math.h>
double Calculation_Unit::degrees_to_radians(double degrees)
{
    return degrees * (M_PI/180);
}

double Calculation_Unit::radians_to_degrees(double radians)
{
    return radians * (180/M_PI);
}

double Calculation_Unit::convert_coordinates(double from_low, double from_high, double to_low, double to_high, double position)
{
    return 0;
}

VEC2 radians_to_vector(double value)
{
    VEC2 temp;
    return temp;
}

double Calculation_Unit::calculate_rudder_position(VEC2)
{
    //const double RUDDER_DEAD_ZONE = 0.2;




    return 0;
}

double Calculation_Unit::calculate_sail_position(VEC2)
{
    return 0;
}

double  vector_to_degrees(VEC2 vector)
{

    return 0;
}