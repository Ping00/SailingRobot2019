#include <iostream>
#include "../Utilities/utilities.hpp"
#include "../Modules/Calculation_Unit/calculation_unit.hpp"
#include <iomanip>
int main(void)
{
    //SCHOOL
    double lat_default = 60.10347832490164;
    double lon_default = 19.928544759750366;

    //EAST (OCEAN COASTLINE)
    double lat_w = 60.103536543676114;
    double lon_w = 19.92392239983178;

    //NORTH (CAR DEALER)
    double lat_n = 60.10603612287117;
    double lon_n = 19.92850923735216;

    //SOUTH (STAVAMOSTERS)
    double lat_s = 60.09530995015463;
    double lon_s = 19.929149916771962;


    double lat_e = 60.10346709484701;
    double lon_e = 19.929850459229783;
    double result = 0;

/*
    result = Utilities::coordinates_to_degrees(lat_default,lon_default,lat_n,lon_n);
    std::cout << "DEGREES NORTH: " << result << std::endl;

    result = Utilities::coordinates_to_degrees(lat_default,lon_default,lat_w,lon_w);
    std::cout << "DEGREES EAST: " << result << std::endl;



     result = Utilities::coordinates_to_degrees(lat_default,lon_default,lat_s,lon_s);
    std::cout << "DEGREES SOUTH: " << result << std::endl;

    result = Utilities::coordinates_to_degrees(lat_default,lon_default,lat_e,lon_e);
    std::cout << "DEGREES WEST: " << result << std::endl;

    std::cout << "-----------" << std::endl;

    double sail = 0;
    double sailPos = 0.0;
    sailPos = Utilities::convert_coordinates(-1,1,0,1,sail);
    std::cout << "Old target is at: " << sail << std::endl;
    std::cout << "New Target is at: " << sailPos << std::endl;

    std::cout << "-----------" << std::endl;

    GPS_DATA location;

    location.set_latitude(60.10347832490164);
    location.set_longitude(19.928544759750366);


    std::cout << "-----------" << std::endl;
    Calculation_Unit CU;
    double distance_kilometers = 0.2;

    GPS_DATA place = CU.calculate_waypoint(location,distance_kilometers,90);



    std::cout << "LAT: " << std::setprecision(20) << place.get_latitude() << std::endl;
    std::cout << "LON: " << std::setprecision(20) << place.get_longitude() << std::endl;
    */
    //-------------

    /*
    for(int i = 0; i < 360; i++)
    {
      double flipped = Utilities::flip_degrees(i);
      std::cout << "FLIP: "<<  i << " TO " << flipped << std::endl;
    }
    */

    //School Coords
    double start_lat = 60.10347832490164;
    double start_lon = 19.928544759750366;

    Calculation_Unit CU;
    //SCHOOL
    GPS_DATA location;

    location.set_latitude(start_lat);
    location.set_longitude(start_lon);


    std::cout << "-----------" << std::endl;
    // 0.2km = 200m
    double distance_kilometers = 0.2;

    GPS_DATA place = CU.calculate_waypoint(location,distance_kilometers,90);
    std::cout << "LAT: " << std::setprecision(20) << place.get_latitude() << std::endl;
    std::cout << "LON: " << std::setprecision(20) << place.get_longitude() << std::endl;

    double distance = CU.calculate_distance(location,place);

    std::cout << "DISTANCE FROM A -> B :" << distance << std::endl;

    for(int i = 0; i < 360; i++)
    {
      GPS_DATA place = CU.calculate_waypoint(location,distance_kilometers,i);
      double distance = CU.calculate_distance(location,place);
      std::cout << "DISTANCE FROM A -> B :" << distance << std::endl;
    }

    return 0;
}
