####################################################
#
# Makefile SAILBOT PROD
#
####################################################

CC = g++
CFLAGS = -Wall -pthread -D_REENTRANT -lwiringPi -lgps
TARGET = boat

# Lägg till eventuella nya källkodsfiler för ditt program här
SOURCES = main.cpp

all : $(TARGET)

$(TARGET) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $@

clean :
	rm $(TARGET) *~
 
