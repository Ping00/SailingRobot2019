#include <iostream>
#include <unistd.h>
#include "../Modules/Compass/Module_CMPS12.hpp"
#include "../Modules/Servo/Module_SERVO.hpp"
int main(int argc, char* argv[])
{
    static int RUDDER = 0;
    static int SAIL = 1;

    std::cout << "Starting DEMO" << std::endl;
    
    
    Module_CMPS12   compass;
    Module_SERVO    servo(-1,1,RUDDER);
    
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
    
    
    //TESTING SERVO STATES
    servo.set_target(-1);
    servo.run();
    
    servo.set_target(0);
    servo.run();
    
    servo.set_target(1);
    servo.run();
    
    
    
    sleep(3);
    return 1;
    while(true)
    {
        compass.run();
        
        //int bearing = compass.get_reading.get_entry(DATA_SET_COMPASS_BEARING_DEGREES_16);
        
        compass.report();
    }
    
    return 0;
}
