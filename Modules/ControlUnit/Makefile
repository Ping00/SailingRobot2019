####################################################
#
# Makefile SAILBOT DEMO
#
####################################################


CC = g++
CFLAGS = -Wall -lSDL2 -pthread -L/usr/lib -I/usr/include/SDL2 -D_REENTRANT
TARGET = boatDemo

# Lägg till eventuella nya källkodsfiler för ditt program här
SOURCES = demo.cpp ../Modules/Compass/Module_CMPS12.cpp

all : $(TARGET)

$(TARGET) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $@

clean :
	rm $(TARGET) *~
