#include <Arduino.h>
#include <EmonLib.h>

const int sensorPin = A0;
const float calibration = 12;
const float phase_shift = 0;

void setup() {
  Serial.begin(9600);

  emon1.voltage(sensorPin, calibration, phase_shift);  // Voltage: input pin, calibration, phase_shift
}

void loop() {
  emon1.calcVI(20,2000);         // Calculate all. No.of wavelengths, time-out
  emon1.serialprint();           // Print out all variables
}
