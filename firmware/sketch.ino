

const int LED_PIN = 3;
const int BUTTON_PIN = 2;
const int POT_PIN = A0;

bool ledOn = false;
int lastButtonReading = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {

int reading = digitalRead(BUTTON_PIN);
if (reading != lastButtonReading) {
  lastDebounceTime = millis(); 
}

if ((millis() - lastDebounceTime) > debounceDelay) {
  static int buttonState = HIGH;
  if (reading != buttonState) {
    buttonState = reading;
    if (buttonState == LOW) {
      ledOn = !ledOn;
    }
  }
}
lastButtonReading = reading;

if (ledOn) {
  int potValue = analogRead(POT_PIN);
  int brightness = map(potValue, 0, 1023, 0, 225);
  analogWrite(LED_PIN, brightness);
} else {
  analogWrite(LED_PIN, 0;)
}
}