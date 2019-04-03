#include <iostream>
#include <unistd.h>
#include "../Modules/Compass/Module_CMPS12.hpp"
#include "../Modules/Servo/Module_SERVO.hpp"
int main(int argc, char* argv[])
{
    static int RUDDER = 0;
    static int SAIL = 1;

    std::cout << "Starting Test" << std::endl;
    Module_CMPS12   compass;
    //UPPER AND LOWER SHOULD USE CONVERSION SO THAT 3968 = -1 AND 8000 = 1
    Module_SERVO    servo(8000,3968,RUDDER);
    
    int destination_degree = 120;

    bool compass_state = compass.init();
    bool servo_state = servo.init();

    if(compass_state)
    {
        std::cout << "[ OK ] COMPASS  " << std::endl;
    }
    else
    {
        std::cout << "[ ERROR ] COMPASS  " << std::endl;
    }
    if(servo_state)
    {
        std::cout << "[ OK ] SERVO: RUDDER" << std::endl;
    }
    else
    {
        std::cout << "[ ERROR ] SERVO: RUDDER" << std::endl;
    }
    
    if(compass_state == false || servo_state == false)
    {
            return -1;
    }
    std::cout << "[ OK ] ALL SYSTEMS" << std::endl;
    sleep(2);
    std::cout << "- STARTING SYSTEM -" << std::endl;
    sleep(3);
    while(true)
    {
        compass.run();
        compass.report();
    }

    return 0;
}
