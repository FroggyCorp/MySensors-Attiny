#define MY_NODE_ID 123
#define sensorid 2

#define MY_RADIO_RFM69
#define MY_RFM69_NEW_DRIVER
#define MY_RFM69_FREQUENCY RFM69_433MHZ // Set your frequency here
#define MY_IS_RFM69HW // Omit if your RFM is not "H"
#define MY_RFM69_TX_POWER_DBM 5
#define MY_RFM69_MAX_POWER_LEVEL_DBM 10

#define MY_RFM69_SPI_SPEED (4*10000ul)  // datasheet says 10Mhz max.

//#define MY_RFM69_ENABLE_ENCRYPTION //+1850 B

extern void serialEventRun(void) __attribute__((weak));

#define MY_DISABLED_SERIAL
//#define SIGRD   RSIG    // Signature Row from Store Program Memory Control and Status Register
#define EIFR    GIFR    // External/General Interrupt Flag Register
#define WDTCSR  WDTCR   // WDT Control Register
#define TCCR1A TCCR1 // optional
#define TIFR1 TIFR	// optional

#define MY_PASSIVE_NODE
#define MY_RFM69_IRQ_PIN 4 //Need to be set to work
#define MY_RFM69_CS_PIN 3 //D8 // NSS. Use MY_RFM69_SPI_CS for older versions (before 2.2.0)



#include <MySensors-Attiny.h>

MyMessage msg(sensorid, V_TRIPPED);

void setup() {
  // put your setup code here, to run once:

}

void presentation() {
  // Register binary input sensor to gw (they will be created as child devices)
  // You can use S_DOOR, S_MOTION or S_LIGHT here depending on your usage. 
  // If S_LIGHT is used, remember to update variable type you send in. See "msg" above.
  sendSketchInfo("Passive node", "0.1"); 
  
  present(sensorid, S_DOOR, "test", false);  
}

void loop() {
  // put your main code here, to run repeatedly:
int value = 1;
send(msg.set(value==HIGH ? 1 : 0));
delay(5000);
value = 0;
send(msg.set(value==HIGH ? 1 : 0));
delay(5000);
}