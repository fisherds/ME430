#include <Servo.h>

#define PIN_PUSHBUTTON 2
#define PIN_LED 3
#define PIN_JOYSTICK_X 0
#define PIN_JOYSTICK_Y 1
#define PIN_SERVO 9

String inputString = "";
bool stringComplete = false;
Servo myServo;

int joystickX;
int lastSentJoystickX = 0;
int joystickY;
int lastSentJoystickY = 0;
const int JOYSTICK_THRESHOLD = 15;

void setup() {
  Serial.begin(9600);
  inputString.reserve(200);
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_PUSHBUTTON, INPUT_PULLUP);
  myServo.attach(PIN_SERVO);
}

void loop() {
  if (!digitalRead(2)) {
    Serial.println("B");
    delay(500);
  }
  // Joystick stuff goes here!
  joystickX = analogRead(PIN_JOYSTICK_X);
  if (abs(joystickX - lastSentJoystickX) > JOYSTICK_THRESHOLD) {
    Serial.println(String("X ") + joystickX);
    lastSentJoystickX = joystickX;
  }
  
  joystickY = analogRead(PIN_JOYSTICK_Y);
  if (abs(joystickY - lastSentJoystickY) > JOYSTICK_THRESHOLD) {
    Serial.println(String("Y ") + joystickY);
    lastSentJoystickY = joystickY;
  }
  
  if (stringComplete) {
    inputString.toUpperCase();
    inputString.trim();  // Gets rid of the CR  ASCII value 13
    Serial.println(inputString); // Optional send to MATLAB

    if (inputString.equalsIgnoreCase("LED ON")) {
      digitalWrite(PIN_LED, HIGH);
    }
    if (inputString.equalsIgnoreCase("LED OFF")) {
      digitalWrite(PIN_LED, LOW);
    }
    
    if (inputString.startsWith("SERVO ")) {
      int degrees = inputString.substring(6).toInt();
      myServo.write(degrees);
    }
    
    inputString = "";
    stringComplete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();    
    if (inChar == '\n') {  // Line feed.  ASCII value 10
      stringComplete = true;
    } else {
      inputString += inChar;
    }
  }
}
