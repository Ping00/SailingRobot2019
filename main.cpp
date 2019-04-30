#include <iostream>

//Multithreaded for sail servo control
void sail_servo(Module_SERVO sail)
{
    sail.run();
}

//Multithreadning for rudder servo control
void rudder_servo(Module_SERVO rudder)
{
    rudder.run();
}


int main(int argc, char* argv[])
{
    //--------------------------------
    //#These will help us determine where we go
    Control_Unit      control_unit;
    Calculation_Unit  calculation_unit;

    //#These will control our boat
    Module_SERVO      servo_rudder;
    Module_SERVO      servo_sail;

    //#These will get us our desired data
    Module_GPS        gps;
    Module_CMPS12     compass;
    //MA3? (WindSensor Module)

    //INIT ALL MODULES

    //#Read our (Temp?) textfile which has wind and destination data
    //This way we dont have to recompile each time we want to change those variables

    //Check if all modules were initialized properly


    //IF all modules were initialize properly
    bool system_active = true;

    //IF NO then cancel program and print errorlog.

    //#Launch our Servo threads

    while(control_unit.is_active())
    {
        //Step 1: FETCH FRESH DATA
        //When we fetch data, each item should possess the same data_tick +- a threshold
        //This tells us that our data is fresh enough to be used (Aka, we dont want a GPS of tick 10, a compass tick of 50)


        //If we dont have a waypoint (IF WAYPOINT SET = FALSE)
        //If our data is fresh enough to be used
        //Get new waypoint
        //->  Use destination and wind to calculate our AOA
        //    Grab distance to destination
        //    Make our waypoint distance half of that (negotiable)
        //    Grab coordinate of waypoint
        //    Set waypoint

        //NOTE REMEMBER TO ADD OFFSET OF 90 DEGREES TO MAKE Y +1 NORTH IN OUR VEC2

        //Calculate offset to waypoint
        //Waypoint - Current bearing = RUDDER OFFSET;

        //Make VEC2 of above, (ADD THE 90 DEGREE SHIFT)

        //GRAB RUDDER POSITION FROM THIS VECTOR BASED ON OUR CU
        //Wind - Current bearing = WIND OFFSET (Add 90 shift in VEC2)
        //Use the wind offset to get the sails proper position

        //Set the rudder value (thread will move part by itself)
        //Set the sail value (thread will move part by itself)




        //INCREMENT DATA TICK
    }




    return 0;
}
