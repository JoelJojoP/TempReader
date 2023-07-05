/*
*   An example code to demonstrate the use of TempReader library.
*   This program prints the chip temperature to the serial monitor at every 0.5sec interval.
*/

// Import TempReader
#include <TempReader.h>

// Create an object of TempReader
TempReader t;

void setup() {
  // Initialise Serial Communication
  Serial.begin(115200);
}

void loop() {
  // Read the temperature value in degree fahrenheit
  int temp = t.ReadTempinF();

  // Display the value in the serial monitor
  Serial.print("Chip temperature is ");
  Serial.print(temp);
  Serial.println(" degrees Fahrenheit");

  delay(500);
}
