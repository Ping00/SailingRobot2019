####################################################
#
# Makefile SAILBOT DEMO
#
####################################################
#g++ demo.cpp -o boatDemo ../Modules/Compass/Module_CMPS12.cpp ../Hardware/#CMPS12/CMPS12_data.cpp ../Hardware/CMPS12/CMPS12.cpp -lwiringPi

CC = g++
CFLAGS = -Wall -pthread -D_REENTRANT
TARGET = boatDemo

# Lägg till eventuella nya källkodsfiler för ditt program här
SOURCES = demo.cpp ../Modules/Compass/Module_CMPS12.cpp ../Hardware/CMPS12/CMPS12_data.cpp ../Hardware/CMPS12/CMPS12.cpp -lwiringPi

all : $(TARGET)

$(TARGET) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $@

clean :
	rm $(TARGET) *~
