#include "calculation_unit.hpp"
#include <math.h>
#include <iostream>
double Calculation_Unit::calculate_rudder_position(VEC2 vector)
{
    //NOTE VECTOR BEARING SHOULD BE ROTATED 90 DEGREES SO THAT X,Y = 0,1 IS NORTH

    //NOTE Dead zone represents how much of our centering we should ignore
    //This is to prevent constant wiggle as we try to center in on our target
    const double RUDDER_DEAD_ZONE = 0.2;

    //V.x = cos(A)
    //V.y = sin(A)
    
    //If Y is negative then we need to turn around
    if(vector.y <= 0)
    {
        //TURN RIGHT
        if(vector.x >= 0)
        {
            std::cout << "WRONG SIDE : TURN RIGHT " << std::endl;
        }
        //TURN LEFT
        else if(vector.x < 0)
        {
            std::cout << "RONG SIDE : TURN LEFT" << std::endl;
        }
    }
    //We are looking in the correct half
    else
    {
        int threshold = abs(vector.x) - RUDDER_DEAD_ZONE;
        std::cout << "DEADZONE: " << threshold << std::endl;
        
    }


    return 0;
}

double Calculation_Unit::calculate_sail_position(VEC2)
{
    return 0;
}
