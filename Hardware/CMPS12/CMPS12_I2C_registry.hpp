#ifndef __CMPS12_I2C_REGISTRY__
#define __CMPS12_I2C_REGISTRY__
typedef enum
{
  COMMAND_REGISTER_SOFTWARE_READ_8          = 0x00,
  COMPASS_BEARING_8                         = 0x01,
  COMPASS_BEARING_16_HIGH_BYTE              = 0x02,
  COMPASS_BEARING_16_LOW_BYTE               = 0x03,
  PITCH_ANGLE_8                             = 0x04,
  ROLL_ANGLE_8                              = 0x05,
  MAGNETOMETER_X_RAW_16_HIGH_BYTE           = 0x06,
  MAGNETOMETER_X_RAW_16_LOW_BYTE            = 0x07,
  MAGNETOMETER_Y_RAW_16_HIGH_BYTE           = 0x08,
  MAGNETOMETER_Y_RAW_16_LOW_BYTE            = 0x09,
  MAGNETOMETER_Z_RAW_16_HIGH_BYTE           = 0x0A,
  MAGNETOMETER_Z_RAW_16_LOW_BYTE            = 0x0B,
  ACCELEROMETER_X_RAW_16_HIGH_BYTE          = 0x0C,
  ACCELEROMETER_X_RAW_16_LOW_BYTE           = 0x0D,
  ACCELEROMETER_Y_RAW_16_HIGH_BYTE          = 0x0E,
  ACCELEROMETER_Y_RAW_16_LOW_BYTE           = 0x0F,
  ACCELEROMETER_Z_RAW_16_HIGH_BYTE          = 0x10,
  ACCELEROMETER_Z_RAW_16_LOW_BYTE           = 0x11,
  GYRO_X_RAW_16_HIGH_BYTE                   = 0x12,
  GYRO_X_RAW_16_LOW_BYTE                    = 0x13,
  GYRO_Y_RAW_16_HIGH_BYTE                   = 0x14,
  GYRO_Y_RAW_16_LOW_BYTE                    = 0x15,
  GYRO_Z_RAW_16_HIGH_BYTE                   = 0x16,
  GYRO_Z_RAW_16_LOW_BYTE                    = 0x17,
  COMPASS_TEMPERATURE_16_HIGH_BYTE          = 0x18,
  COMPASS_TEMPERATURE_16_LOW_BYTE           = 0x19,
  COMPASS_BEARING_16_HIGH_BYTE_DEGREES      = 0x1A,
  COMPASS_BEARING_16_LOW_BYTE_DEGREES       = 0x1B,
  PITCH_ANGLE_16_HIGH_BYTE                  = 0x1C,
  PITCH_ANGLE_16_LOW_BYTE                   = 0x1D,
  CALIBRATION_STATE_8                       = 0x1E

} CMPS12_I2C_REGISTRY; 

typedef enum
{
  DATA_SET_COMMAND_REGISTER_SOFTWARE_READ_8           = 0x00,
  DATA_SET_COMPASS_BEARING_8                          = 0x01,
  DATA_SET_COMPASS_BEARING_16                         = 0x02,
  DATA_SET_PITCH_ANGLE_8                              = 0x03,
  DATA_SET_ROLL_ANGLE_8                               = 0x04,
  DATA_SET_MAGNETOMETER_X_RAW_16                      = 0x05,
  DATA_SET_MAGNETOMETER_Y_RAW_16                      = 0x06,
  DATA_SET_MAGNETOMETER_Z_RAW_16                      = 0x07,
  DATA_SET_ACCELEROMETER_X_RAW_16                     = 0x08,
  DATA_SET_ACCELEROMETER_Y_RAW_16                     = 0x09,
  DATA_SET_ACCELEROMETER_Z_RAW_16                     = 0x0A,
  DATA_SET_GYRO_X_RAW_16                              = 0x0B,
  DATA_SET_GYRO_Y_RAW_16                              = 0x0C,
  DATA_SET_GYRO_Z_RAW_16                              = 0x0D,
  DATA_SET_COMPASS_TEMPERATURE_16                     = 0x0E,
  DATA_SET_COMPASS_BEARING_DEGREES_16                 = 0x0F,
  DATA_SET_PITCH_ANGLE_16                             = 0x10,
  DATA_SET_CALIBRATION_STATE_8                        = 0x11

} DATA_SET_REGISTRY; 
#endif//__CMPS12_I2C_REGISTRY__
