/*
    Simple Example for writing to Dynamixel MX-28AT servos
*/

#include<iostream>
#include "JetsonMX28.h"

#define SEC 1000000 // 1 Second in micro second units for delay
#define MSEC 1000	// 1 milli second in micro second units for delay
#define ID 1        // ID for singl servo
#define USBUART 0   // 1 for USB, 0 for GPIO UART 

using namespace std;

int main()
{
    JetsonMX28 control;

#if UARTFLAG
    control.begin();
#else 
	control.beginUSB();
#endif
    
    for(int i = 0; i < 5; i ++)
    {
        control.move(ID,0);
        usleep(2*SEC);
        
        control.move(ID,1000);
        usleep(2*SEC);
    }
    
    control.disconnect();
    return 0;
}

