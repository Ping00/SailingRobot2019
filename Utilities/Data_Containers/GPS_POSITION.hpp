#ifndef __GPS_POSITION_HPP
#define __GPS_POSITION_HPP
class GPS_POSITION
{
    public:
        GPS_POSITION();
        GPS_POSITION(double lat_value, double lon_value);
        double latitude;
        double longitude;
};
#endif//__GPS_POSITION_HPP
