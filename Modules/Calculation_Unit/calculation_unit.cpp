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

    double percentile = (position - from_low) / (from_high - from_low);
    int result = percentile*(to_high - to_low )+to_low;
    std::cout << "PERCENTILE: " << percentile << std::endl;
    std::cout << "RESULT: " << result << std::endl;

    /*
  int servo_lower_limit = m_servo_hardware_connection.get_lower_limit();
	int servo_upper_limit = m_servo_hardware_connection.get_upper_limit();

	std::cout << "TARGET IS: " << m_target << std::endl;

	double percentile = (m_target - m_lower_boundary) / (m_upper_boundary - m_lower_boundary);

	std::cout << "PERCENTILE IS: " << percentile << std::endl;

	int destination = percentile*(servo_upper_limit-servo_lower_limit)+servo_lower_limit;
  */

    return 0;
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

VEC2    Calculation_Unit::degrees_to_vector(double value)
{
    VEC2 temp;
    return temp;
}

double  Calculation_Unit::vector_to_degrees(VEC2 vector)
{
    return 0;
}