#ifndef __CMPS12_DATA_HPP__
#define  __CMPS12_DATA_HPP__
#include <inttypes.h>
#include <vector>
#include "CMPS12_I2C_registry.hpp"
class CMPS12_DATA
{
    private:
      std::vector<int> m_data;
      
      //const int DATA_ENTRIES = 18;

      /*
      int   m_command_register;
      int   m_compass_bearing_8bit;
      int   m_compass_bearing_16bit;
      int   m_pitch_angle;
      int   m_roll_angle;
      int   m_magnometer_x_axis;
      int   m_magnometer_y_axis;
      int   m_magnometer_z_axis;
      int   m_accelerometer_x_axis;
      int   m_accelerometer_y_axis;
      int   m_accelerometer_z_axis;
      int   m_gyro_x_axis;
      int   m_gyro_y_axis;
      int   m_gyro_z_axis;
      int   m_temperature;
      int   m_compass_bearing_degrees;
      int   m_pitch_angle_16bit;
      int   calibration;
      */

    public:
        CMPS12_DATA();
        void set_entry(CMPS12_DATA entry, int data);
        int get_entry(CMPS12_DATA entry);
};
#endif
