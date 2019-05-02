#include <iostream>
#include "../Utilities/utilities.hpp"
#include "../Modules/Calculation_Unit/calculation_unit.hpp"
#include <iomanip>
#include <vector>
int main(void)
{
    GPS_POSITION start;
    start.latitude = 0;
    start.longitude = 0;

    GPS_POSITION destination;
    destination.latitude = 0;
    destination.longitude = 0;

    GPS_POSITION current_position = start;

    return 0;
}
