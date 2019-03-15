#include <Arduino.h>
/*
  STM32 - BluePill (stm32f103c8t6)
  Example Sketch
  Author: Nilay savant
 */

// the setup function runs once when you press reset or power the board
byte count = 0;
char mess[1024] = {0};
void setup()
{
  // initialize digital pin PB1 as an output.
  pinMode(PC13, OUTPUT);
}
// the loop function runs over and over again forever
void loop()
{
  count = count + 1;
  snprintf(mess, 1024, "count executed");
  digitalWrite(PC13, HIGH); // turn the LED on (HIGH is the voltage level)
  snprintf(mess, 1024, "high executed");
  delay(1000);             // wait for a second
  digitalWrite(PC13, LOW); // turn the LED off by making the voltage LOW
  snprintf(mess, 1024, "low executed");
  delay(1000); // wait for a second
}
