/*
    Example for moving the Dynamixel MX28-AT series servos
*/

#include<iostream>
#include "JetsonMX28.h"

#define SEC 1000000 // 1 Second in micro second units for delay
#define MSEC 1000	// 1 milli second in micro second units for delay
#define ID 1        // ID for singl servo
#define GPIO 0   	// 1 for GPIO, 0 for USB

#define OFF 0 // Sets "Servo" position mode

using namespace std;

int main()
{
    JetsonMX28 control;

#if GPIO
    control.begin();
#else 
	control.beginUSB();
#endif

	control.setEndless(ID, OFF); // Sets the servo to "Servo" mode
    
    for(int i = 0; i < 3; i ++)
    {
        control.move(ID,0);
        usleep(2*SEC);
        
        control.move(ID,1024);
        usleep(2*SEC);
        
        control.move(ID,2048);
        usleep(2*SEC);
        
        control.move(ID,3072);
        usleep(2*SEC);
        
        control.move(ID,4095);
        usleep(2*SEC);
        
        control.move(ID,3072);
        usleep(2*SEC);
        
        control.move(ID,2048);
        usleep(2*SEC);
        
        control.move(ID,1024);
        usleep(2*SEC);
        
    }
    
    control.disconnect();
    return 0;
}

