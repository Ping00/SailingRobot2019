#include <iostream>
#include <unistd.h>
#include <math.h>
#include "../Utilities/utilities.hpp"
#include "../Utilities/Data_Containers/VEC2.hpp"
#include "../Modules/Compass/Module_CMPS12.hpp"
#include "../Modules/Servo/Module_SERVO.hpp"
#include "../Modules/GPS/Module_GPS.hpp"
#include "../Modules/Calculation_Unit/calculation_unit.hpp"
int main(int argc, char* argv[])
{
    static const int RUDDER = 1;
    static const int SAIL = 0;

    std::cout << "Starting DEMO" << std::endl;
    
    
    Module_CMPS12       compass;
    Module_SERVO        servo(-1,1,RUDDER);
    Module_GPS          gps;
    
    
    
    
    Calculation_Unit    CU;

    bool compass_state = compass.init();
    bool servo_state = servo.init();
    bool gps_state = gps.init();
    

    
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
    
    /*
    if(compass_state == false || servo_state == false)
    {
        return -1;
    }
    */
    std::cout << "[ OK ] ALL SYSTEMS" << std::endl;
    sleep(2);
    std::cout << "- STARTING SYSTEM -" << std::endl;
    
    
    const int offset = 90;
    int waypoint = 120;

    VEC2 waypoint_vec = Utilities::degrees_to_vector(waypoint + offset);
    
    while(true)
    {
        compass.run();
        int bearing = compass.get_reading().get_entry(DATA_SET_COMPASS_BEARING_DEGREES_16);
        std::cout << "BEARING: " << bearing << std::endl;
        
        int offset_bearing = bearing + offset;
        
        VEC2 current_pos = Utilities::degrees_to_vector(offset_bearing);
        
        std::cout << "CURRENT X : " << current_pos.x << std::endl;
        std::cout << "CURRENT Y : " << current_pos.y << std::endl;
        std::cout << "------------" << std::endl;
        std::cout << "WAYPOINT X : " << waypoint_vec.x << std::endl;
        std::cout << "WAYPOINT Y : " << waypoint_vec.y << std::endl;

        
        int dest_offset = waypoint - bearing;
        std::cout << "DESTINATION BEARING: " << dest_offset << std::endl;
        
        VEC2 dest = Utilities::degrees_to_vector(dest_offset + 90);

        std::cout << "DEST X : " << dest.x << std::endl;
        std::cout << "DEST Y : " << dest.y << std::endl;

        double rudder_setting = CU.calculate_rudder_position(dest);
        std::cout << "REUDDER:: " << rudder_setting << std::endl;

        servo.set_target(rudder_setting);
        servo.run();

        /*
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
        
        //double course = servo.calculate_course(combined);
        
        //servo.set_target(course);
        //servo.run();
        
        //compass.report();
        */
    }
    
    return 0;
}
