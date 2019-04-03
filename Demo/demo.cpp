#include <iostream>
#include <unistd.h>
#include <math.h>
#include "../Modules/Compass/Module_CMPS12.hpp"
#include "../Modules/Servo/Module_SERVO.hpp"
int main(int argc, char* argv[])
{
    static int RUDDER = 0;
    static int SAIL = 1;

    std::cout << "Starting DEMO" << std::endl;
    
    
    Module_CMPS12   compass;
    Module_SERVO    servo(-1,1,RUDDER);
    

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
    
    
    int waypoint = 120;
    double waypoint_vec_y = cos(waypoint*(M_PI/180));
    double waypoint_vec_x = sin(waypoint*(M_PI/180));

    
    while(true)
    {
        compass.run();
        int bearing = compass.get_reading().get_entry(DATA_SET_COMPASS_BEARING_DEGREES_16);
        std::cout << "BEARING: " << bearing << std::endl;
        
        //DEGREES (WE NEED RADIANS)
        double vec_y = cos(bearing*(M_PI/180));
        double vec_x = sin(bearing*(M_PI/180));
        
        std::cout << "VEC X: " << vec_x << std::endl;
        std::cout << "VEC Y: " << vec_y << std::endl;
        std::cout << "------------" << std::endl;
        
        
        std::cout << "VEC X: " << waypoint_vec_x << std::endl;
        std::cout << "VEC Y: " << waypoint_vec_y << std::endl;
        std::cout << "------------" << std::endl;
        std::cout << "DIFFERENCE" << std::endl;
        
        double diff_x = waypoint_vec_x - vec_x;
        double diff_y = waypoint_vec_y - vec_y;
        std::cout << "DIF X: " << diff_x << std::endl;
        std::cout << "DIF Y: " << diff_y << std::endl;
        
        double combined = (diff_x + diff_y);
        
        std::cout << "COMBINED: " << combined << std::endl;
        double course = servo.calculate_course(combined);
        std::cout << "COURSE SET: " << course << std::endl;
        
        servo.set_target(course);
        servo.run();
        
        //compass.report();
    }
    
    return 0;
}
