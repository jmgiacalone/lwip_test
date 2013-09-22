// Do not remove the include below
#include "lwip_test.h"

void printf(char *fmt, ... ){
        char tmp[128]; // resulting string limited to 128 chars
        va_list args;
        va_start (args, fmt );
        vsnprintf(tmp, sizeof(tmp), fmt, args);
        va_end (args);
        SerialUSB.print(tmp);
}


//The setup function is called once at startup of the sketch
void setup()
{
	  SerialUSB.begin(115200);

	  while (!SerialUSB.available());
	  SerialUSB.print("Starting\n");
// Add your initialization code here
	ethPinsInit();
	SerialUSB.print("Pins\n");
	pinMode(11,OUTPUT);

	  /* Bring up the ethernet interface & initializes timer0, channel0 */
	  init_ethernet();

	  SerialUSB.print("Setup complete.\r\n");
}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
	ethernet_task();
	digitalWrite(11,ledState);
}
