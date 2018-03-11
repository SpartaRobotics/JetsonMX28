/*
    Simple Example for writing to Dynamixel MX-28AT servos
*/

#include<iostream>
#include "JetsonMX28.h"

#define SEC 1000000 // 1 Second in micro second units for delay
#define MSEC 1000	// 1 milli second in micro second units for delay
#define ID 1        // ID for singl servo
#define GPIO 1      // 1 for GPIO UART, 0 for USB UART

#define SERVO 0  // Sets continous rotation mode
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
    
    control.setEndless(ID, SERVO);
    
    for(int i = 0; i < 3; i++)
    {
		control.moveSpeed(ID, 0, 1023);
		usleep(2*SEC);
		control.moveSpeed(ID, 1024, 100);
		usleep(2*SEC);
		control.moveSpeed(ID, 2048, 300);
		usleep(2*SEC);
		control.moveSpeed(ID, 3072, 256);
		usleep(2*SEC);
		control.moveSpeed(ID, 4095, 768);
		usleep(2*SEC);
		control.moveSpeed(ID, 3072, 256);
		usleep(2*SEC);
		control.moveSpeed(ID, 2048, 50);
		usleep(2*SEC);
		control.moveSpeed(ID, 1024, 512);
		usleep(2*SEC);

    }
    
    control.disconnect();
    return 0;
}

