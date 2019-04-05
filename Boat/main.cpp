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

#define OFFSET 90

//Multithreaded for polling devices at different time-intervals
//Thread for driving rudder
void drive_rudder(Module_SERVO& rudder)
{
  std::cout << "Starting Automatic Rudder Servo"<< std::endl;
  while(true)
  {
      rudder.run();
  }
}

//Thread for driving sail
void drive_sail(Module_SERVO& sail)
{
  std::cout << "Starting Automatic Sail Servo"<< std::endl;
  while(true)
  {
      sail.run();
  }
}

//Thread for polling wind sensor
void poll_wind_sensor(Module_Wind_Sensor& wind)
{
      std::cout << "Starting Automatic Wind Sensor"<< std::endl;
  while(true)
  {
    //std::cout << "Polling Wind Sensor!" << std::endl;
    wind.run();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }
}

//Thread for polling gps
void poll_gps_sensor(Module_GPS& gps)
{
  std::cout << "Starting Automatic GPS"<< std::endl;
  while(true)
  {
    //std::cout << "Polling GPS!" << std::endl;
    gps.run();
    std::this_thread::sleep_for(std::chrono::milliseconds(1200));
  }
}

//Thread for polling compass
void poll_compass(Module_CMPS12& compass)
{
  std::cout << "Starting Automatic Compass"<< std::endl;
  while(true)
  {
    //std::cout << "Polling Compass!" << std::endl;
    compass.run();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

//thread for logging competition data at regular intervals
void log_data()
{
    std::cout << "Starting Automatic Logger"<< std::endl;
    //Wait for initial time so we have time to do all setup beforehand
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
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
    init_status[0] = servo_rudder.init();
    init_status[1] = servo_sail.init();
    init_status[2] = module_gps.init();
    init_status[3] = module_compass.init();
    init_status[4] = module_wind.init();


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

    //Default our Servos to their Default positions from start
    servo_sail.set_target(0);
    servo_rudder.set_target(0);

    std::cout << "Activating Threads..." << std::endl;
    //IF all modules were initialize properly we launch our threads
    std::thread t1(poll_wind_sensor,std::ref(module_wind));
    std::thread t2(poll_compass,std::ref(module_compass));
    std::thread t3(poll_gps_sensor,std::ref(module_gps));
    std::thread t4(drive_rudder,std::ref(servo_rudder));
    std::thread t5(drive_sail,std::ref(servo_sail));
    //std::thread t6(log_data,std::ref(data_logger))

    //Wait for modules to collect initial set of data
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << " - Collecting Initial Dataset - " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    //Publish Initial Log of journey
    //INITIAL WAYPOINT (START)
    //INITIAL READINGS

    //SCHOOL TEMP
    GPS_DATA TEMP_GPS_DATA;
    TEMP_GPS_DATA.set_valid(true);
    TEMP_GPS_DATA.set_latitude(60.10347832490164);
    TEMP_GPS_DATA.set_longitude(19.928544759750366);
    TEMP_GPS_DATA.set_speed(0);
    TEMP_GPS_DATA.set_time_value(5235);
    TEMP_GPS_DATA.set_timestamp("12:00:00");

    CMPS12_DATA TEMP_COMPASS_DATA;
    TEMP_COMPASS_DATA.set_entry(DATA_SET_COMPASS_BEARING_DEGREES_16,122);

    int TEMP_WIND = 5;
    
    //TEMP WAYPOINT TEST DATA
    GPS_POSITION TEMP_WAYPOINT;
    TEMP_WAYPOINT.latitude = 60.105879322635616;
    TEMP_WAYPOINT.longitude = 19.926559925079346;
    
    //control_unit.set_waypoint(TEMP_WAYPOINT);
    
    while(control_unit.is_active())
    {
      //std::this_thread::sleep_for(std::chrono::milliseconds(600));
      //module_compass.report();
      //module_gps.report();
      //module_wind.report();

      
        //Take a nap
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        //std::cout << "Primary Loop" << std::endl;
        //std::cout << "------------------" << std::endl;
        
      
        //GRAB A SET OF ITERATION DATA AT THIS MOMENT IN TIME
        //GPS_DATA      gps_reading     = TEMP_GPS_DATA;
        //CMPS12_DATA   compass_reading = TEMP_COMPASS_DATA;
        //int           wind_reading    = TEMP_WIND;
        
        //GRAB A SET OF ITERATION DATA AT THIS MOMENT IN TIME
        GPS_DATA      gps_reading     = module_gps.get_reading();
        CMPS12_DATA   compass_reading = module_compass.get_reading();
        int           wind_reading    = module_wind.get_reading();
        
        
        /*
        //TODO REPORT IF ANY DATA IS UNAVAILABLE
        //IF ALL DATA IS OK
        //TODO GENERATE LOG OF ALL DATA
        LOG fresh_log;
        fresh_log.m_entry_id                    = 0;
        fresh_log.m_bearing                     = 0;
        fresh_log.m_latitude                    = 0;
        fresh_log.m_longitude                   = 0;
        fresh_log.m_speed                       = 0;
        fresh_log.m_timestamp                   = "";
        fresh_log.m_distance_from_waypoint      = 0;
        fresh_log.m_distance_from_destination   = 0;
        data_logger.log_data(fresh_log);
        */
         
        //Set a waypoint if there is none
        //NOTE Replace with DO-WHILE?
        if(control_unit.is_waypoint_set() == false)
        {
            std::cout << "No Waypoint set" << std::endl;

            int wind_bearing = wind_reading;
            GPS_POSITION current_position = Utilities::extract_position_from_data(gps_reading); //GRAB FROM GPS AND UTILITIES TO FORMAT
            int time_unit = gps_reading.get_time_value(); //GRAB FROM GPS AND REFORMAT

            std::cout << "Wind Bearing Is: " << wind_bearing << std::endl;

            std::cout << "Current Lat: " << current_position.latitude << std::endl;
            std::cout << "Current Lon: " << current_position.longitude << std::endl;

            //Grab our destination from our control unit
            GPS_POSITION destination = control_unit.get_destination();
            std::cout << "Destination Lat: " << destination.latitude << std::endl;
            std::cout << "Destination Lon: " << destination.longitude << std::endl;

            //Calulate destination bearing
            double destination_bearing = Utilities::coordinates_to_degrees(
              current_position.latitude,
              current_position.longitude,
              destination.latitude,
              destination.longitude);

            std::cout << "Destination Bearing: " << destination_bearing << std::endl;

            //Calculate our angle of approach (AOA)
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

            std::cout << "Reccommended AOA IS: " << AOA << std::endl;

            //Calculate our angle to the new waypoint according to the AOA
            double waypoint_angle = Utilities::normalize(AOA+destination_bearing);

            std::cout << "Waypoint Angle Is: " << waypoint_angle << std::endl;

            //Calculate the distance to our destination
            double destination_distance = calculation_unit.calculate_distance(current_position,destination);

            std::cout << "Distance to destination is: " << destination_distance*1000 << " meters" << std::endl;

            //Calculate how far away our waypoint should be
            double waypoint_distance = destination_distance / control_unit.get_distance_factor();

            std::cout << "Waypoint Distance is: " << waypoint_distance*1000 << " meters" << std::endl;
            if(waypoint_distance < control_unit.get_waypoint_creation_threshold())
            {
                std::cout << "Threshold Reached, limiting waypoint" << std::endl;
                waypoint_distance = control_unit.get_waypoint_creation_threshold();
                std::cout << "New Distance is: " << waypoint_distance*1000 << " meters" <<std::endl;
            }

            //Generate new waypoint
            GPS_POSITION new_waypoint = calculation_unit.calculate_waypoint(current_position,waypoint_distance,waypoint_angle);
            std::cout << "Waypoint Lat: " << new_waypoint.latitude << std::endl;
            std::cout << "Waypoint Lon: " << new_waypoint.longitude << std::endl;

            //Set the waypoint
            control_unit.set_waypoint(new_waypoint);

            //Set our time unit for our timeout
            control_unit.set_time_value(time_unit);

            //Register Status in Journey LOG
            //TODO REGISTER
            std::cout << "Waypoint set" << std::endl;
        }

        
        
        //TEST 1 (WAYPOINT GUIDANCE)
        
        //General CONTROL SECTION
        int wind_bearing = wind_reading;
        int compass_bearing = compass_reading.get_entry(DATA_SET_COMPASS_BEARING_DEGREES_16);

        std::cout << "Wind Bearing IS: " << wind_bearing << std::endl;
        std::cout << "Boat Bearing Is: " << compass_bearing << std::endl;


        //Grab our current position and waypoint details
        GPS_POSITION current_position  = Utilities::extract_position_from_data(gps_reading);
        GPS_POSITION waypoint_position = control_unit.get_waypoint();

        std::cout << "Current Lat: " << current_position.latitude << std::endl;
        std::cout << "Current Lon: " << current_position.longitude << std::endl;

        std::cout << "Waypoint Lat: " << waypoint_position.latitude << std::endl;
        std::cout << "Waypoint Lon: " << waypoint_position.longitude << std::endl;

        //Get Bearing to waypoint
        double waypoint_bearing = Utilities::coordinates_to_degrees(
          current_position.latitude,
          current_position.longitude,
          waypoint_position.latitude,
          waypoint_position.longitude);

        std::cout << "Waypoint Bearing: " << waypoint_bearing << std::endl;

        //Calculate the directional offset of our waypoint
        int waypoint_offset = waypoint_bearing - compass_bearing;

        std::cout << "Waypoint Offset: " << waypoint_offset << std::endl;


        //Generate Vectors to use in our calculation of positions (NOTE THE OFFSET IS 90)
        VEC2 rudder_vector = Utilities::degrees_to_vector(waypoint_offset + OFFSET);
        VEC2 sail_vector   = Utilities::degrees_to_vector(wind_bearing   + OFFSET);

        //Calculate our settings
        double rudder_setting = calculation_unit.calculate_rudder_position(rudder_vector);
        double sail_setting   = calculation_unit.calculate_sail_position(sail_vector);

        std::cout << "Rudder Settings: " << rudder_setting << std::endl;
        std::cout << "Sail   Settings: " << sail_setting << std::endl;

        //Set our servos with our calculated targets
        servo_rudder.set_target(rudder_setting);
        servo_sail.set_target(sail_setting);

        
        
        //DESTINATION CALCULATIONS
        double waypoint_distance = calculation_unit.calculate_distance(current_position,waypoint_position);
        double goal_threshold = control_unit.get_calculated_threshold();
        std::cout << "We are " << waypoint_distance*1000 << " meters from our waypoint" << std::endl;

        std::cout << "DISTANCE THRESHOLD: " << goal_threshold << std::endl;
        std::cout << "WAYPOINT DISTANCE : " << waypoint_distance << std::endl;

        //HAVE WE GOTTEN CLOSE ENOUGH TO OUR WAYPOINT
        if(waypoint_distance < control_unit.get_calculated_threshold())
        {
            std::cout << "We Are close enough to our destination, grab a new waypoint" << std::endl;
            control_unit.set_waypoint_status(false);
            //TODO LOG EVENT
            //Set our message in our custom logger to be "Waypoint Reached"
        }

        //Grab our goal (Checkpoint)
        GPS_POSITION checkpoint = control_unit.get_destination();
        std::cout << "Checkpoint Lat: " << checkpoint.latitude << std::endl;
        std::cout << "Checkpoint Lon: " << checkpoint.longitude << std::endl;

        //Check how close we are to our Checkpoint(Goal)
        double checkpoint_distance = calculation_unit.calculate_distance(current_position,checkpoint);
        std::cout << "Distance to Checkpoint: " << checkpoint_distance*1000 << " meters"<<  std::endl;
        std::cout << "DISTANCE THRESHOLD: " << goal_threshold*1000 << " meters"<<std::endl;

        //HAVE WE GOTTEN CLOSE ENOUGH TO THE CHECKPOINT
        if(checkpoint_distance < goal_threshold)
        {
            std::cout << "CHECKPOINT REACHED" << std::endl;
            //Pops the top checkpoint off and turns itself off if at end.
            //TODO LOG EVENT
            control_unit.update_journey();

        }

        //HAS TOO MUCH TIME PASSED SINCE WE ESTABLISHED THE WAYPOINT
        int gps_time = gps_reading.get_time_value();
        std::cout << "GPS TIME: " << gps_time << std::endl;
        if(control_unit.time_discrepency_reached(gps_time))
        {
            std::cout << "TOO MUCH TIME HAS PASSED!" << std::endl;
            //Set flag to false to generate new waypoint
            control_unit.set_waypoint_status(false);
        }

        


        //------ OLD CODE --------
        /*
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

                int wind_bearing = 0.0; // = VALUE FROM SENSOR
                GPS_DATA gps_data; //=READING FROM SENSOR
                GPS_POSITION current_position; // = VALUE FROM GPS (USE UTILITIES TO EXTRACT FROM DATA)
                int time_unit = 0; //FETCH FROM GPS DATA
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
                //WAYPOINT LOG TO JOURNEY LOG

            }

        }

        //CONTROL BOAT
        //CALCULATE BEARING FROM CURRENT POSITION AND WAYPOINT;
        GPS_DATA current_gps_reading;
        int time_value = 0;
        GPS_POSITION current_position;  //FETCH FROM GPS
        current_position.latitude = 60.10347765644805;
        current_position.longitude = 19.928544759750366;
        GPS_POSITION waypoint_position; //FETCH FROM CONROL UNIT
        waypoint_position.latitude = 60.10599161445948;
        waypoint_position.longitude = 19.928770065307617;

        int wind_bearing    = 0;  //FETCH DATA FROM MODULES
        int compass_bearing = 0;  //FETCH DATA FROM MODULES

        int waypoint_bearing = Utilities::coordinates_to_degrees(
          current_position.latitude,
          current_position.longitude,
          waypoint_position.latitude,
          waypoint_position.longitude);


        int destination_offset = waypoint_bearing - compass_bearing;
        std::cout << "DESTINATION BEARING : " << destination_offset << std::endl;

        VEC2 destination_vector = Utilities::degrees_to_vector(destination_offset + OFFSET);
        VEC2 wind_vector = Utilities::degrees_to_vector(wind_bearing + OFFSET);

        //Calculate rudder & Sail Positions
        double sail_setting = calculation_unit.calculate_sail_position(wind_vector);
        double rudder_setting = calculation_unit.calculate_rudder_position(destination_vector);

        //Set Servos to these values
        servo_sail.set_target(sail_setting);
        servo_rudder.set_target(rudder_setting);


        //Check if we have reached our target
        //Calculate Distance between our current point and waypoint
        double checkpoint_distance = calculation_unit.calculate_distance(current_position,waypoint_position);

        */



    }

    std::cout << "JOURNEY DONE!" << std::endl;

    return 0;
}
