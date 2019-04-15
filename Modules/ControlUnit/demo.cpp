#include <iostream>
#include "../Compass/module_CMPS12.hpp"
int main(void)
{

    std::cout << "Starting Test" << std::endl;
    Module_CMPS12 compass;
    bool compass_state = compass.init();
    if(compass_state)
    {
        while(true)
        {
            std::cout << "COMPASS OK!" << std::endl;
        }
    }

    return 0;
}
