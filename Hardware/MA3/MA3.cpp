#include "MA3.hpp"
#include <iostream>
MA3::MA3()
{

}

bool MA3::init()
{
    //Load SPI Drivers
    if(system("gpio load spi") == -1)
    {
        std::cout << "Failed to load the GPIO SPI Drivers" << std::endl;
        return false;
    }

}