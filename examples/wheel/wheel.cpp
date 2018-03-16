/*
    Simple Example for writing to Dynamixel MX-28AT servos
*/

#include<iostream>
#include "JetsonMX28.h"

#define SEC 1000000 // 1 Second in micro second units for delay
#define MSEC 1000	// 1 milli second in micro second units for delay
#define ID 1        // ID for singl servo
#define GPIO 0   	// 1 for GPIO, 0 for USB

#define ROTATION 1  // Sets continous rotation mode
#define CW  0 		// Clockwise
#define CCW 1 		// Counter Clockwise

using namespace std;

int main()
{
    JetsonMX28 control;

#if GPIO
    control.begin();
#else 
	control.beginUSB();
#endif
    
    control.setEndless(ID, ROTATION);
    
    for(int i = 0; i < 3; i++)
    {
		control.turn(ID, CW, 512);
		usleep(3*SEC);
		control.turn(ID, CCW, 1020);
		usleep(3*SEC);
		control.turn(ID, 0, 0); // Either clockwise or counter clockwise as long as speed is 0
		usleep(3*SEC);
    }
    
    control.disconnect();
    return 0;
}

