#include "calculation_unit.hpp"
#include <math.h>
#include <iostream>
#include "../../Utilities/utilities.hpp"
#define EARTH_RADIUS 6371.0
double Calculation_Unit::calculate_rudder_position(VEC2 vector)
{
    //NOTE VECTOR BEARING SHOULD BE ROTATED 90 DEGREES SO THAT X,Y = 0,1 IS NORTH

    //NOTE Dead zone represents how much of our centering we should ignore
    //This is to prevent constant wiggle as we try to center in on our target
    const double RUDDER_DEAD_ZONE = 0.225;

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
    //Even if we are head on we want to move
    //slightly to the side for good measure
    const double angle_discrepancy = 5;
    const double max_angle = 90.0;

    //Calculate single side of our bearings (To get other side just)
    double offset = abs(destination_bearing - wind_bearing);
    if(offset > 180) offset = abs(offset - 360);

    std::cout << "OFFSET: " << offset << std::endl;

    //Cut it in half so that we can only turn +- 90 degrees
    offset = offset / 2;

    //Add our discrepancy;

    std::cout << "PROPER ANGLE OFFSET: " << offset << std::endl;

    //If our angle is too big or too small
    //Offset with our discrepancy so we get a small variation
    if(offset < angle_discrepancy) offset += angle_discrepancy;
    if(offset > max_angle - offset) offset -= angle_discrepancy;
    return offset;
}

GPS_POSITION Calculation_Unit::calculate_waypoint(GPS_POSITION current_position, double distance, double direction)
{
    //STOLEN FROM THE INTERNET (Hende d, c, they did not specifiy what they meant)


    //LATITUDE
    double latitude_radians = Utilities::degrees_to_radians(current_position.latitude);
    double angle_radians = Utilities::degrees_to_radians(direction);
    double d = distance / EARTH_RADIUS;
    double c = asin(sin(latitude_radians)*cos(d) + cos(latitude_radians)*sin(d)*cos(angle_radians));
    double corrected_latitude = Utilities::radians_to_degrees(c);

    //LONGITUDE
    double c2 = atan2(sin(angle_radians)*sin(d)*cos(latitude_radians), cos(d) - sin(latitude_radians)*sin(c));
    double corrected_longitude = current_position.longitude + Utilities::radians_to_degrees(c2);

    GPS_POSITION coords;
    coords.latitude = corrected_latitude;
    coords.longitude = corrected_longitude;
    return coords;


}

double Calculation_Unit::calculate_distance(GPS_POSITION point_a, GPS_POSITION point_b)
{

  //Convert to radian
  double distance_latitude = Utilities::degrees_to_radians(point_b.latitude - point_a.latitude);
  double distance_longitude = Utilities::degrees_to_radians(point_b.longitude - point_a.longitude);

  double factor =
  sin(distance_latitude / 2) *
  sin(distance_latitude / 2) +
  cos(Utilities::degrees_to_radians(point_a.latitude)) *
  cos(Utilities::degrees_to_radians(point_b.latitude)) *
  sin(distance_longitude / 2) *
  sin(distance_longitude / 2);

  double range = 2 * atan2(sqrt(factor),sqrt(1-factor));
  double distance = range * EARTH_RADIUS;
  return distance;
}