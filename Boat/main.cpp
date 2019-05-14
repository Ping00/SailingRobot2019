#include <iostream>
#include <thread>
#include <chrono>

#include "../Utilities/Data_Containers/GPS_POSITION.hpp"
#include "../Utilities/utilities.hpp"

#include "../Modules/Compass/Module_CMPS12.hpp"
#include "../Modules/GPS/Module_GPS.hpp"
#include "../Modules/Wind_Sensor/Module_Wind_Sensor.hpp"
#include "../Modules/Control_Unit/control_unit.hpp"
#include "../Modules/Calculation_Unit/calculation_unit.hpp"
#include "../Modules/Servo/Module_SERVO.hpp"

#include "../Core/Logger/logger.hpp"

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
    //std::this_thread::sleep_for(std::chrono::milliseconds(1500));
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

//thread for logging competition data at regular intervals
void log_data()
{
    //Wait for initial time so we have time to do all setup beforehand
    std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    while(true)
    {
        //std::cout << "Logging Data!" << std::endl;
        //std::this_thread::sleep_for(std::chrono::milliseconds(2000));
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
    Module_GPS          module_gps;
    Module_CMPS12       module_compass;
    Module_Wind_Sensor  module_wind(WIND_SENSOR_SPI_CHANNEL);

    //Data Loggers (One for competition, other for journey debugging)
    Logger data_logger("Logs/contest.txt");
    Logger waypoint_logger("Logs/waypoint.txt");

    //Init All Modules & Servos
    std::vector<bool> init_status;
    int modules = 5;
    //Set all of them to false for safety
    for(int i = 0; i < modules; i++)
    {
        init_status.push_back(false);
    }

    //NOTE RE-ENABLE ON PI AS IT IS THE ONLY ONE WITH PROPER SPI / I2C CONNECTIONS
    //init_status[0] = servo_rudder.init();
    //init_status[1] = servo_sail.init();
    //init_status[2] = module_gps.init();
    //init_status[3] = module_compass.init();
    //init_status[4] = module_wind.init();


    //Check if all modules were initialized properly
    bool components_initialized = control_unit.validate_inits(init_status);
    if(components_initialized)
    {
        //Read our Data files which determine our goals and other details
        std::string destination = "Settings/destination.txt";
        std::string settings = "Settings/settings.txt";
        bool final_status = control_unit.init(destination,settings);
        if(final_status)
        {
            std::cout << "[ OK ]    : DESTINATION SET" << std::endl;
        }
        else
        {
            std::cout << "[ ERROR ] : DESTINATION SET"  << std::endl;
            return -1;
        }
    }
    else
    {
        std::cout << "Some Components Failed To Initialize" << std::endl;
        return -1;
    }

    std::cout << "Activating Threads..." << std::endl;
    //IF all modules were initialize properly we launch our threads
    //std::thread t1(poll_wind_sensor);
    //std::thread t2(poll_compass);
    //std::thread t3(poll_gps_sensor);
    //std::thread t4(drive_rudder,std::ref(servo_rudder));
    //std::thread t5(drive_sail,std::ref(servo_sail));
    //std::thread t6(log_data,std::ref(data_logger))

    //NOTE TEMP VARIABLES
    bool valid_gps_reading = true;
    bool valid_wind_reading = true;

    //Wait for modules to collect initial set of data
    std::cout << " - Collecting Initial Dataset - " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    //Publish Initial Log of journey
    //INITIAL WAYPOINT (START)
    //INITIAL READINGS

    //TODO REMOVE TEST
    int time_test = 0;

    while(control_unit.is_active())
    {
        //Take a nap
        std::this_thread::sleep_for(std::chrono::milliseconds(400));

        std::cout << "Primary Loop" << std::endl;

        //IF WE DONT HAVE A WAYPOINT SET.
        if(control_unit.is_waypoint_set() == false)
        {
            //  -> SELECT WAYPOINT
            std::cout << "We Dont have a waypoint at this moment" << std::endl;

            //Check if data sets are valid
            bool gps_reading  = valid_gps_reading;
            bool wind_reading = valid_wind_reading;

            //If both are valid we determine our AOA
            if(gps_reading && wind_reading)
            {
                std::cout << "Both Readings OK!" << std::endl;

                double wind_bearing = 0.0; // = VALUE FROM SENSOR
                GPS_DATA gps_data; //=READING FROM SENSOR
                GPS_POSITION current_position; // = VALUE FROM GPS (USE UTILITIES TO EXTRACT FROM DATA)
                int time_unit = time_test; //FETCH FROM GPS DATA (TIME TEST IS TEMP)
                control_unit.set_time_value(time_unit);

                GPS_POSITION destination = control_unit.get_destination();

                std::cout << "DLAT:" << destination.latitude << std::endl;
                std::cout << "DLON:" << destination.longitude << std::endl;

                double destination_bearing = Utilities::coordinates_to_degrees(
                  current_position.latitude,
                  current_position.longitude,
                  destination.latitude,
                  destination.longitude);

                //OUR DESIRED ANGLE OF APPORACH TO TARGET
                double AOA = 0.0;
                if(control_unit.get_angle_direction() == STARBOARD)
                {
                    std::cout << "Heading Starboard" << std::endl;
                    AOA = calculation_unit.calculate_angle_of_approach(destination_bearing,wind_bearing);
                    control_unit.alternate_angle();
                }
                else if(control_unit.get_angle_direction() == PORT)
                {
                    std::cout << "Heading Port" << std::endl;
                    AOA = Utilities::flip_degrees(calculation_unit.calculate_angle_of_approach(destination_bearing,wind_bearing));
                    control_unit.alternate_angle();
                }

                //Add our Approach angle to our bearing angle and normalize it
                double waypoint_angle = Utilities::normalize(AOA+destination_bearing);

                //Calculate the distance to our current checkpoint-pin
                double checkpoint_distance = calculation_unit.calculate_distance(current_position,destination);

                //Calculate how far away our waypoint should be
                double waypoint_distance = checkpoint_distance / control_unit.get_distance_factor();

                //TODO ADD CONSTRAINT SO THAT IF DISTANCE BECOMES TOO SMALL, TRUNCATE IT

                //Generate waypoint coordinates
                GPS_POSITION new_waypoint = calculation_unit.calculate_waypoint(current_position,waypoint_distance,waypoint_angle);

                control_unit.set_waypoint(new_waypoint);
                //LOG THESE DETAILS

            }

        }
        std::cout << "Time: " << time_test << std::endl;
        if(control_unit.time_discrepency_reached(time_test))
        {
            std::cout << "TIME REACHED, RESET!" << std::endl;
            control_unit.set_waypoint_status(false);
        }

        time_test++;

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
