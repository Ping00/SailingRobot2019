#include "calculation_unit.hpp"
#include <math.h>
#include <iostream>
#include "../../Utilities/utilities.hpp"
double Calculation_Unit::calculate_rudder_position(VEC2 vector)
{
    //NOTE VECTOR BEARING SHOULD BE ROTATED 90 DEGREES SO THAT X,Y = 0,1 IS NORTH

    //NOTE Dead zone represents how much of our centering we should ignore
    //This is to prevent constant wiggle as we try to center in on our target
    const double RUDDER_DEAD_ZONE = 0.125;

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
                return 0.5;
            }
            //TURN LEFT
            else if(vector.x < 0)
            {
                std::cout << "CORRECT SIDE : TURN LEFT" << std::endl;
                return -0.5;
            }
        }
    }


    return 0;
}

double Calculation_Unit::calculate_sail_position(VEC2 vector)
{
    //IF Y IS POSITIVE THEN WIND AT OUR BACKS (GOOD)
    //IF Y IS NEGATIVE THEN WIND IS BLOWING AT US (BAD)
    //IF Y IS 0 THEN IT IS FROM OUR SIDE

    //Y AXIS DETERMINES HOW HARD WE NEED TO SWING OUR SAILS
    //-1 MIN
    //+1 MAX
    double sail = vector.y;

    double sail_power = Utilities::convert_coordinates(-1,1,0, 1, sail);
    std::cout << "SAILS ARE AT: " << sail_power*100 << " Percentage" << std::endl;
    //POS NEG X IS IRRELEVANT AS SAIL CAN SWING AROUND TO OTHER SIDE
    return sail_power;
}

double Calculation_Unit::calculate_angle_of_approach(double destination_bearing, double wind_bearing)
{
    double x = 0;
    return x;
}

GPS_DATA Calculation_Unit::calculate_waypoint(GPS_DATA current_position, double distance, double direction)
{
    GPS_DATA temp;

    //NOTE DISTANCE IS IN KM, 10m = 0.01

    //LATITUDE
    double latitude_radians = Utilities::degrees_to_radians(current_position.get_latitude());
    double angle_radians = Utilities::degrees_to_radians(direction);

    const double earth_radius = 6371.0;

    double theta = distance / earth_radius;
    double omega_lat = asin(sin(latitude_radians)*cos(theta) + cos(latitude_radians) * sin(theta) * cos(angle_radians));
    double result_latitude = Utilities::radians_to_degrees(omega_lat);

    //LONGITUDE

    double omega_lon = atan2(sin(angle_radians)*sin(theta)*cos(latitude_radians),cos(theta)-sin(latitude_radians)*sin(result_latitude));
    double result_longitude = current_position.get_longitude() + Utilities::radians_to_degrees(omega_lon);

    temp.set_latitude(result_latitude);
    temp.set_longitude(result_longitude);

    return temp;
}

double Calculation_Unit::calculate_distance(GPS_DATA point_a, GPS_DATA point_b)
{

    return 0;
}
