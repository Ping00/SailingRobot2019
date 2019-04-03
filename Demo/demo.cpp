#include <iostream>
#include "../Modules/Compass/Module_CMPS12.hpp"
int main(void)
{

    std::cout << "Starting Test" << std::endl;
    Module_CMPS12 compass;

    bool compass_state = compass.init();


    if(compass_state)
    {
        std::cout << "COMPASS OK!" << std::endl;
        while(true)
        {
            compass.run();
            compass.report();
        }
    }

    return 0;
}
