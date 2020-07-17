// Uno
/*
#define REG_DDR_PUSHBUTTON_PRINT DDRD
#define REG_PORT_PUSHBUTTON_PRINT PORTD
#define REG_PIN_PUSHBUTTON_PRINT PIND
#define BIT_PUSHBUTTON_PRINT 3

#define REG_DDR_PUSHBUTTON_COUNT DDRD
#define REG_PORT_PUSHBUTTON_COUNT PORTD
#define REG_PIN_PUSHBUTTON_COUNT PIND
#define BIT_PUSHBUTTON_COUNT 2
*/
// Mega
#define REG_DDR_PUSHBUTTON_PRINT DDRE
#define REG_PORT_PUSHBUTTON_PRINT PORTE
#define REG_PIN_PUSHBUTTON_PRINT PINE
#define BIT_PUSHBUTTON_PRINT 5

#define REG_DDR_PUSHBUTTON_COUNT DDRE
#define REG_PORT_PUSHBUTTON_COUNT PORTE
#define REG_PIN_PUSHBUTTON_COUNT PINE
#define BIT_PUSHBUTTON_COUNT 4

uint16_t pollingCounter = 0;

uint8_t buttonState = 1;
uint8_t lastButtonState = 1;

void setup() {
  Serial.begin(9600);
  // Pins as inputs
  REG_DDR_PUSHBUTTON_PRINT &= ~_BV(BIT_PUSHBUTTON_PRINT);
  REG_DDR_PUSHBUTTON_COUNT &= ~_BV(BIT_PUSHBUTTON_COUNT);
  
  // Enable pull up resistors
  REG_PORT_PUSHBUTTON_PRINT |= _BV(BIT_PUSHBUTTON_PRINT);
  REG_PORT_PUSHBUTTON_COUNT |= _BV(BIT_PUSHBUTTON_COUNT);
}

void loop() {
  if (bit_is_clear(REG_PIN_PUSHBUTTON_PRINT, BIT_PUSHBUTTON_PRINT) ) {
    Serial.println(String("Counter = ") + pollingCounter);
    delay(500);  // Fine for simple things!
  }
  
  // Polling
  buttonState = (REG_PIN_PUSHBUTTON_COUNT >> BIT_PUSHBUTTON_COUNT) & 0x01;
  if (buttonState != lastButtonState) {
    if (!buttonState) {
      pollingCounter++;
    }
    lastButtonState = buttonState;
    delay(50); // Useful for debounce
  }
}

