#include "calculation_unit.hpp"
#include <math.h>
#include <iostream>
double Calculation_Unit::calculate_rudder_position(VEC2 vector)
{
    //NOTE VECTOR BEARING SHOULD BE ROTATED 90 DEGREES SO THAT X,Y = 0,1 IS NORTH

    //NOTE Dead zone represents how much of our centering we should ignore
    //This is to prevent constant wiggle as we try to center in on our target
    const double RUDDER_DEAD_ZONE = 0.1;

    //V.x = cos(A)
    //V.y = sin(A)
    
    //If Y is negative then we need to turn around
    if(vector.y <= 0)
    {
        //TURN RIGHT
        if(vector.x >= 0)
        {
            std::cout << "WRONG SIDE : TURN RIGHT " << std::endl;
            return 1;
        }
        //TURN LEFT
        else if(vector.x < 0)
        {
            std::cout << "RONG SIDE : TURN LEFT" << std::endl;
            return -1;
        }
    }
    //We are looking in the correct half
    else
    {
        double threshold = RUDDER_DEAD_ZONE - abs(vector.x);
        std::cout << "DEADZONE: " << threshold << std::endl;
        if(threshold >= 0)
        {
                //GO STRAIGHT
                std::cout << "THRESHOLD REACHED GO STRAIGHT!!" << std::endl;
                return 0;
        }
        else
        {
            //TURN RIGHT
            if(vector.x >= 0)
            {
                std::cout << "CORRECT SIDE : TURN RIGHT " << std::endl;
                return 0.75;
            }
            //TURN LEFT
            else if(vector.x < 0)
            {
                std::cout << "CORRECT SIDE : TURN LEFT" << std::endl;
                return -0.75;
            }
        }
    }


    return 0;
}

double Calculation_Unit::calculate_sail_position(VEC2)
{
    return 0;
}
