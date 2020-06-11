const int waveStepsPerRevolution = 2048;
const int sequencesPerRevolution = waveStepsPerRevolution / 4;
#define DELAY_MS 2

void setup() {
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
}

void loop() {

  for (int k = 0; k < sequencesPerRevolution; k++) {
    //forwardWave();
    //forwardFull();
    forwardHalf();
  }
  delay(2000);
  
  for (int k = 0; k < sequencesPerRevolution; k++) {
//    reverseWave();
//    reverseFull();
    reverseHalf();
  }
  delay(2000);

}

void forwardHalf() {
  waveStep1();
  delay(DELAY_MS);
  fullStep1();
  delay(DELAY_MS);
  waveStep2();
  delay(DELAY_MS);
  fullStep2();
  delay(DELAY_MS);
  waveStep3();
  delay(DELAY_MS);
  fullStep3();
  delay(DELAY_MS);
  waveStep4();
  delay(DELAY_MS);
  fullStep4();
  delay(DELAY_MS);
}

void reverseHalf() {
  fullStep4();
  delay(DELAY_MS);
  waveStep4();
  delay(DELAY_MS);
  fullStep3();
  delay(DELAY_MS);
  waveStep3();
  delay(DELAY_MS);
  fullStep2();
  delay(DELAY_MS);
  waveStep2();
  delay(DELAY_MS);
  fullStep1();
  delay(DELAY_MS);
  waveStep1();
  delay(DELAY_MS);
}

void forwardFull() {
  fullStep1();
  delay(DELAY_MS);
  fullStep2();
  delay(DELAY_MS);
  fullStep3();
  delay(DELAY_MS);
  fullStep4();
  delay(DELAY_MS);
}

void reverseFull() {
  fullStep4();
  delay(DELAY_MS);
  fullStep3();
  delay(DELAY_MS);
  fullStep2();
  delay(DELAY_MS);
  fullStep1();
  delay(DELAY_MS);
}

void forwardWave() {
  waveStep1();
  delay(DELAY_MS);
  waveStep2();
  delay(DELAY_MS);
  waveStep3();
  delay(DELAY_MS);
  waveStep4();
  delay(DELAY_MS);
}

void reverseWave() {
  waveStep4();
  delay(DELAY_MS);
  waveStep3();
  delay(DELAY_MS);
  waveStep2();
  delay(DELAY_MS);
  waveStep1();
  delay(DELAY_MS);
}

void waveStep1() {
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

void fullStep1() {
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

void waveStep2() {
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

void fullStep2() {
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void waveStep3() {
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void fullStep3() {
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
}

void waveStep4() {
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}

void fullStep4() {
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}
