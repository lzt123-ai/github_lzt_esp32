bool ledState = false;
bool lastTouchState = false;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void loop() {
  bool touchState = digitalRead(touchPin);
  if (touchState != lastTouchState) {
    lastDebounceTime = millis();
  }
  if (millis() - lastDebounceTime > debounceDelay) {
    if (touchState != lastTouchState) {
      lastTouchState = touchState;
      if (touchState) ledState = !ledState;
    }
  }
  digitalWrite(ledPin, ledState);
}
