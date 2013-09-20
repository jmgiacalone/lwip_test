// Do not remove the include below
#include "lwip_test.h"

void printf(char *fmt, ... ){
        char tmp[128]; // resulting string limited to 128 chars
        va_list args;
        va_start (args, fmt );
        vsnprintf(tmp, 128, fmt, args);
        va_end (args);
        SerialUSB.print(tmp);
}

//The setup function is called once at startup of the sketch
void setup()
{
// Add your initialization code here
	ethPinsInit();
	pinMode(11,OUTPUT);
	  // start serial port at 9600 bps:
	  //SerialUSB.begin(115200);
	  while (!SerialUSB.available());

	  /* Bring up the ethernet interface & initializes timer0, channel0 */
	  init_ethernet();

	  printf("Setup complete.\r\n");
}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
	ethernet_task();
	digitalWrite(11,ledState);
}
