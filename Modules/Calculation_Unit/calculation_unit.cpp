#include "calculation_unit.hpp"
#include <math.h>
#include <iostream>
#define EPSILON 1e-14
double Calculation_Unit::degrees_to_radians(double degrees)
{
    return degrees * (M_PI/180);
}

double Calculation_Unit::radians_to_degrees(double radians)
{
    return radians * (180/M_PI);
}

int Calculation_Unit::convert_coordinates(double from_low, double from_high, double to_low, double to_high, double position)
{

    double percentile = (position - from_low) / (from_high - from_low);
    int result = percentile * (to_high - to_low ) + to_low;
    return result;
}

double Calculation_Unit::calculate_rudder_position(VEC2 vector)
{
    //NOTE VECTOR BEARING SHOULD BE ROTATED 90 DEGREES SO THAT X,Y = 0,1 IS NORTH

    //NOTE Dead zone represents how much of our centering we should ignore
    const double RUDDER_DEAD_ZONE = 0.2;

    //V.x = cos(A)
    //V.y = sin(A)


    //If the Y vector is negative then our boat is looking in the opposite direction
    if(vector.y < 0)
    {

    }
    //Means our facing is correct
    else
    {

    }



    return 0;
}

double Calculation_Unit::calculate_sail_position(VEC2)
{
    return 0;
}

VEC2 Calculation_Unit::degrees_to_vector(double value)
{
    //V.x = cos(A)
    //V.y = sin(A)

    //Convert our degrees to radians
    //(cos & sin uses radians for its calculations)
    double radians = degrees_to_radians(value);

    VEC2 vec;
    vec.x = -cos(radians);
    vec.y = sin(radians);
    
    //PI/2 gives a value very close to 0
    if(std::abs(vec.x) < EPSILON) vec.x = 0;
    if(std::abs(vec.y) < EPSILON) vec.y = 0;
    
    return vec;
}

double Calculation_Unit::vector_to_degrees(VEC2 vector)
{
    //A = atan2(V.y, V.x)
    return 0;
}
