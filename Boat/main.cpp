#include <iostream>
#include <thread>
#include <chrono>
//Multithreaded for polling devices at different time-intervals
//Thread for driving rudder
void drive_rudder()
{

}

//Thread for driving sail
void drive_sail()
{

}

//Thread for polling wind sensor
void poll_wind_sensor()
{
  while(true)
  {
    std::cout << "Polling Wind Sensor!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }
}

//Thread for polling gps
void poll_gps_sensor()
{
  while(true)
  {
    std::cout << "Polling GPS!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
}

//Thread for polling compass
void poll_compass()
{
  while(true)
  {
    std::cout << "Polling Compass!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
}

int main(int argc, char* argv[])
{
    //--------------------------------
    //#These will help us determine where we go
    //Control_Unit      control_unit;
    //Calculation_Unit  calculation_unit;

    //#These will control our boat
    //Module_SERVO      servo_rudder;
    //Module_SERVO      servo_sail;

    //#These will get us our desired data
    //Module_GPS          gps;
    //Module_CMPS12       compass;
    //Module_Wind_Sensor  wind;

    //INIT ALL MODULES




    //#Read our (Temp?) textfile which has wind and destination data
    //This way we dont have to recompile each time we want to change those variables

    //Check if all modules were initialized properly


    //IF all modules were initialize properly
    bool system_active = true;
    std::thread t1(poll_wind_sensor);
    std::thread t2(poll_compass);
    std::thread t3(poll_gps_sensor);

    //IF NO then cancel program and print errorlog.
    //#Launch our Servo threads

    while(system_active)
    {
        std::cout << "Main Loop" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
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
