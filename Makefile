# build an executable for JetsonMX28

CC = g++
CFLAGS = -g -Wall -O2

all: simpleMove.cpp
		$(CC)  $(CFLAGS) simpleMove.cpp jetsonGPIO.c JetsonMX28.cpp -o simpleMove
        
 clean:
		$(RM) count *.o 
