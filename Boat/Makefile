####################################################
#
# Makefile SAILBOT PROD
#
####################################################

CC = g++
CFLAGS = -Wall -pthread -D_REENTRANT -lwiringPi -lgps
TARGET = boat

# Lägg till eventuella nya källkodsfiler för ditt program här
SOURCES = main.cpp ../Modules/Control_Unit/control_unit.cpp ../Utilities/Data_Containers/GPS_POSITION.cpp ../Modules/GPS/Module_GPS.cpp ../Modules/Servo/Module_SERVO.cpp ../Hardware/MAESTRO/MAESTRO.cpp ../Utilities/utilities.cpp ../Hardware/GPS/GPS_data.cpp ../Utilities/Data_Containers/VEC2.cpp ../Modules/Compass/Module_CMPS12.cpp ../Hardware/CMPS12/CMPS12.cpp ../Hardware/CMPS12/CMPS12_data.cpp ../Modules/Wind_Sensor/Module_Wind_Sensor.cpp ../Hardware/MA3/MA3.cpp ../Hardware/GPS/GPS.cpp


all : $(TARGET)

$(TARGET) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $@

clean :
	rm $(TARGET) *~
 
