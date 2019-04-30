#include <iostream>

//Multithreaded for sail servo control
void sail_servo(Module_SERVO sail)
{

}

//Multithreadning for rudder servo control
void rudder_servo(Module_SERVO rudder)
{

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

    //Check if all modules were initialized properly

    //IF NO then cancel program and print errorlog.

    //IF all modules were initialize properly
    bool system_active = true;

    //#Launch our Servo threads

    while(control_unit.is_active())
    {
        //








    }




    return 0;
}
