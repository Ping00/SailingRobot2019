#ifndef __CALCULATION_UNIT_HPP__
#define __CALCULATION_UNIT_HPP__
#include "../../Utilities/Data_Containers/VEC2.hpp"
class Calculation_Unit
{
    private:


    public:
      double calculate_rudder_position(VEC2 vector);
      double calculate_sail_position(VEC2 vector);
};
#endif//__CALCULATION_UNIT_HPP__
