#include <Stepper.h>

const int stepsPerRevolution = 2048;  // 32 steps * 64:1 gearhead
//const int stepsPerRevolution = 60;  // Tell a lie for now!
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);  // Order is important!

void setup() {
  // set the speed at 5 rpm:
  myStepper.setSpeed(5);
}

void loop() {
  // step one revolution  in one direction:
  myStepper.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  myStepper.step(-stepsPerRevolution);
  delay(500);
}

