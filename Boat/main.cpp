#include <iostream>
#include <thread>
#include <chrono>
#include "../Utilities/Data_Containers/GPS_POSITION.hpp"

#include "../Modules/Compass/Module_CMPS12.hpp"
#include "../Modules/GPS/Module_GPS.hpp"
#include "../Modules/Wind_Sensor/Module_Wind_Sensor.hpp"
#include "../Modules/Control_Unit/control_unit.hpp"
#include "../Modules/Calculation_Unit/calculation_unit.hpp"
#include "../Modules/Servo/Module_SERVO.hpp"

#define RUDDER_CHANNEL 1
#define SAIL_CHANNEL 0

#define RUDDER_LOWER_THRESHOLD -1
#define RUDDER_UPPER_THRESHOLD 1

#define SAIL_LOWER_THRESHOLD 0
#define SAIL_UPPER_THRESHOLD 1

#define WIND_SENSOR_SPI_CHANNEL 0

//Multithreaded for polling devices at different time-intervals
//Thread for driving rudder
void drive_rudder(Module_SERVO& rudder)
{
  while(true)
  {
      rudder.run();
  }
}

//Thread for driving sail
void drive_sail(Module_SERVO& sail)
{
  while(true)
  {
      sail.run();
  }
}

//Thread for polling wind sensor
void poll_wind_sensor()
{
  while(true)
  {
    //std::cout << "Polling Wind Sensor!" << std::endl;
    //std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }
}

//Thread for polling gps
void poll_gps_sensor()
{
  while(true)
  {
    //std::cout << "Polling GPS!" << std::endl;
    //std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  }
}

//Thread for polling compass
void poll_compass()
{
  while(true)
  {
    //std::cout << "Polling Compass!" << std::endl;
    //std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

int main(int argc, char* argv[])
{
    //--------------------------------
    //#These will help us determine where we go
    Control_Unit control_unit;
    Calculation_Unit calculation_unit;

    //#These will control our boat
    Module_SERVO servo_rudder(
      RUDDER_LOWER_THRESHOLD,
      RUDDER_UPPER_THRESHOLD,
      RUDDER_CHANNEL);

    Module_SERVO servo_sail(
      SAIL_LOWER_THRESHOLD,
      SAIL_UPPER_THRESHOLD,
      SAIL_CHANNEL);

    //#These will poll data for us
    Module_GPS          gps;
    Module_CMPS12       compass;
    Module_Wind_Sensor  wind(WIND_SENSOR_SPI_CHANNEL);

    //Init All Modules
    


    //#Read our textfile which has wind and destination data
    //This way we dont have to recompile each time we want to change those variables

    //Check if all modules were initialized properly


    //IF all modules were initialize properly
    bool system_active = true;
    std::thread t1(poll_wind_sensor);
    std::thread t2(poll_compass);
    std::thread t3(poll_gps_sensor);
    std::thread t4(drive_rudder,std::ref(servo_rudder));
    std::thread t5(drive_sail,std::ref(servo_sail));

    //IF NO then cancel program and print errorlog.
    //#Launch our Servo threads

    while(system_active)
    {
        //Take a nap
        std::this_thread::sleep_for(std::chrono::milliseconds(10000));


        //Data is polled constantly, all we need to do is retrieve it

        //Check


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
