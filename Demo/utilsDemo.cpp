#include <iostream>
#include "../Utilities/utilities.hpp"

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

    double result = Utilities::coordinates_to_degrees(lat_default,lon_default,lat_w,lon_w);
    std::cout << "DEGREES WEST: " << result << std::endl;

     result = Utilities::coordinates_to_degrees(lat_default,lon_default,lat_n,lon_n);
    std::cout << "DEGREES NORTH: " << result << std::endl;

     result = Utilities::coordinates_to_degrees(lat_default,lon_default,lat_s,lon_s);
    std::cout << "DEGREES SOUTH: " << result << std::endl;

    result = Utilities::coordinates_to_degrees(lat_default,lon_default,lat_e,lon_e);
   std::cout << "DEGREES EAST: " << result << std::endl;

    return 0;
}
