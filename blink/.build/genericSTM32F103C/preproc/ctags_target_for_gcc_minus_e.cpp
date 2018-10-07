# 1 "/home/nilay/STM32/STM32-ArduinoWithDebug/blink/blink.ino"
# 1 "/home/nilay/STM32/STM32-ArduinoWithDebug/blink/blink.ino"
# 2 "/home/nilay/STM32/STM32-ArduinoWithDebug/blink/blink.ino" 2
/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  Modified by Roger Clark. www.rogerclark.net for Maple mini 25th April 2015 , where the LED is on PB1
  
 */

// the setup function runs once when you press reset or power the board
byte count = 0;
char mess[1024]= {0};
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
  digitalWrite(PC13, 0x1); // turn the LED on (HIGH is the voltage level)
  snprintf(mess, 1024, "high executed");
  delay(1000); // wait for a second
  digitalWrite(PC13, 0x0); // turn the LED off by making the voltage LOW
  snprintf(mess, 1024, "low executed");
  delay(1000); // wait for a second
}
