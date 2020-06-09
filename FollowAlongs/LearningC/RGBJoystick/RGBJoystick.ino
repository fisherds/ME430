void setup() {
  Serial.begin(9600); // Com speed.  bits per second
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  red();
  delay(1000);
//  green();
//  delay(1000);
  off();
  delay(1000);
    
  //rgb(61, 217, 212);
}

void rgb(int r, int g, int b) {
  // Parameters should be 0 to 255!
  analogWrite(9, r);
  analogWrite(10, g);
  analogWrite(11, b);
}

void red() {
  analogWrite(9, 255);
  analogWrite(10, 0);
  analogWrite(11, 0);
}

void green() {
  analogWrite(9, 0);
  analogWrite(10, 255);
  analogWrite(11, 0);
}

void off() {
  analogWrite(9, 0);
  analogWrite(10, 0);
  analogWrite(11, 0);
}
