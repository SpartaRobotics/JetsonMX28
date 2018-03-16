/*
    Example for reading position from the Dynamixel MX28-AT series servos
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
    
    control.move(ID, 2048);
    
    for(int i = 0; i < 3; i ++)
    {
        cout << "POSITION: " << control.readPosition(ID) << endl;
        usleep(2*SEC);
    }
    
    control.disconnect();
    
    return 0;
}

