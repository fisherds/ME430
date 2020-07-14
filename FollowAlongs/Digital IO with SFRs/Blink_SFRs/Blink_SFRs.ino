// Note: Pin 6 on Arduino = ATmega2560 PH3

// LED_BUILTIN is PB7
// #define REG_DDR_LED DDRB
// #define REG_PORT_LED PORTB
// #define BIT_LED 7

#define REG_DDR_LED DDRH
#define REG_PORT_LED PORTH
#define BIT_LED 3

void setup() {
  // pinMode(LED_BUILTIN, OUTPUT);
  REG_DDR_LED |= _BV(BIT_LED); 
}

void loop() {
  // digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  REG_PORT_LED |= _BV(BIT_LED);
  delay(1000);                       // wait for a second

  // digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  REG_PORT_LED &= ~_BV(BIT_LED);
  delay(1000);                       // wait for a second
}