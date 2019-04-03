#include "utilities.hpp"
#include <math.h>
#include <iostream>
#define EPSILON 1e-14
double Utilities::degrees_to_radians(double degrees)
{
    return degrees * (M_PI/180);
}


double Utilities::radians_to_degrees(double radians)
{
    return radians * (180/M_PI);
}

int Utilities::convert_coordinates(double from_low, double from_high, double to_low, double to_high, double position)
{
    double percentile = (position - from_low) / (from_high - from_low);
    int result = percentile * (to_high - to_low ) + to_low;
    return result;
}

VEC2 Utilities::degrees_to_vector(double value)
{
    //Convert our degrees to radians
    //(cos & sin uses radians for its calculations)
    double radians = degrees_to_radians(value);

    VEC2 vec;
    //We inverse x so it matches our rotation (Right + | Left -)
    vec.x = -cos(radians);
    vec.y = sin(radians);
    
    //PI/2 gives a value very close to 0 (1e-17 etc)
    if(std::abs(vec.x) < EPSILON) vec.x = 0;
    if(std::abs(vec.y) < EPSILON) vec.y = 0;
    
    return vec;
}

double Utilities::vector_to_degrees(VEC2 vector)
{
    //A = atan2(V.y, V.x)
    return 0;
}

