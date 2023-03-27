#include <Stepper.h>

// Define step constants
#define FULLSTEP 14
#define SENSOR_TILT 34

int value; // Define a numeric variable
int angle = 0; // The current angle of servo motor
const int  stepsPerRevolutions = 2038; 
Stepper myStepper = Stepper(stepsPerRevolutions, 14, 27, 26, 25);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(SENSOR_TILT, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Rotate CW slowly at 5 RPM
  // Check mercury switch state
  if (digitalRead(SENSOR_TILT) == HIGH) {
    myStepper.setSpeed(10);
    myStepper.step(-stepsPerRevolutions);
    delay(1000);
  }
}
