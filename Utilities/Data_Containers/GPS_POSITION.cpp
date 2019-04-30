#include "GPS_POSITION.hpp"
GPS_POSITION::GPS_POSITION()
{
    latitude    = 0;
    longitude   = 0;
}

GPS_POSITION::GPS_POSITION(double lat, double lon)
{
    latitude    = lat;
    longitude   = lon;
}
