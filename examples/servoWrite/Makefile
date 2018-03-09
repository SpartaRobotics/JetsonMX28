# build an executable for JetsonMX28

CC = g++
CFLAGS = -g -Wall -I../../include

HDIR = ../../include
SDIR = ../../src
ODIR = ../../src/obj

TARGET = simpleMove

all: $(TARGET)

$(TARGET): $(TARGET).o JetsonMX28.o jetsonGPIO.o
	$(CC) $(CFLAGS) $< $(ODIR)/JetsonMX28.o $(ODIR)/jetsonGPIO.o -o $@
		
$(TARGET).o: $(TARGET).cpp
	$(CC) $(CFLAGS) -c $< -o $@
	
JetsonMX28.o: $(SDIR)/JetsonMX28.cpp $(HDIR)/JetsonMX28.h $(HDIR)/jetsonGPIO.h
	$(CC) $(CFLAGS) -c $< -o $(ODIR)/$@

jetsonGPIO.o: $(SDIR)/jetsonGPIO.c	$(HDIR)/jetsonGPIO.h
	$(CC) $(CFLAGS) -c $< -o $(ODIR)/$@


target: $(TARGET)

$(TARGET): $(TARGET).o JetsonMX28.o jetsonGPIO.o
	$(CC) $(CFLAGS) $< $(ODIR)/JetsonMX28.o $(ODIR)/jetsonGPIO.o -o $@

clean:
	$(RM) -f core *.o $(TARGET)

cleanall:
		$(RM) -f core *.o $(TARGET) -f core $(ODIR)/*.o
