#include "GPS_POSITION.hpp"
GPS_POSITION::GPS_POSITION()
{
    latitude    = 0;
    longitude   = 0;
}

GPS_POSITION::GPS_POSITION(double lat_value, double lon_value)
{
    latitude    = lat_value;
    longitude   = lon_value;
}
