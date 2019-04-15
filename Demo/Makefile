####################################################
#
# Makefile SAILBOT CMPS Module TEST
#
####################################################


CC = g++
CFLAGS = -Wall -lSDL2 -pthread -L/usr/lib -I/usr/include/SDL2 -D_REENTRANT
TARGET = boatDemo

# Lägg till eventuella nya källkodsfiler för ditt program här
SOURCES = demo.cpp 

all : $(TARGET)

$(TARGET) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $@

clean :
	rm $(TARGET) *~
