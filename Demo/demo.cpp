#include <iostream>
#include <unistd.h>
#include "../Modules/Compass/Module_CMPS12.hpp"
#include "../Modules/Servo/Module_SERVO.hpp"
int main(void)
{

    std::cout << "Starting Test" << std::endl;
    Module_CMPS12   compass;
    Module_SERVO    servo_rudder;

    bool compass_state = compass.init();


    if(compass_state)
    {
        std::cout << "COMPASS OK!" << std::endl;
    }
    sleep(2);
    
    while(true)
    {
        compass.run();
        compass.report();
    }

    return 0;
}
