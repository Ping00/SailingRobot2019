#ifndef __UTILITIES_HPP__
#define __UTILITIES_HPP__
#include "Data_Containers/VEC2.hpp"
class Utilities
{
      public:
	
      static double  degrees_to_radians(double degrees);
      static double  radians_to_degrees(double radians);
      static int     convert_coordinates(double v_high, double v_low, double u_high, double u_low, double position);
      static VEC2    degrees_to_vector(double value);
      static double  vector_to_degrees(VEC2 vector);
	
};
#endif//__UTILITIES_HPP__
