#BATT_MEAS_TICK_INTERVAL	1000   //in seconds



void isItTimeToTakeBatteryLog(void){
	
	uint8_t systemTicks = getSystemTime();  //Assume every tick is a second for this

	if()
	//Decide if it's time to take a battery measurement
	//Assume you have a method already takeBatteryLog() that does all this




	//talk through overflow issues and how to address (around system ticks): let's assume that system ticks overflow in the timerModule where the system time is updated. How do we schedule through this?
	//Also talk through any potential battery drain issues


}


ISR ON_EVERY_SYSTEM_TICK ()   //a tick is every second
{
	takeBatteryLog();  //Take a battery log
}


