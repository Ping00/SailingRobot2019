####################################################
#
# Makefile SAILBOT DEMO
#
####################################################

CC = g++
CFLAGS = -Wall -pthread -D_REENTRANT -lwiringPi
TARGET = boatDemo

# Lägg till eventuella nya källkodsfiler för ditt program här
SOURCES = demo.cpp

all : $(TARGET)

$(TARGET) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $@

clean :
	rm $(TARGET) *~
