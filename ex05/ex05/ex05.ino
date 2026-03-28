int speedLevel = 1;
bool lastTouchState = false;
unsigned long lastDebounceTime = 0;

void loop() {
  bool touchState = digitalRead(touchPin);
  if (touchState != lastTouchState) {
    lastDebounceTime = millis();
  }
  if (millis() - lastDebounceTime > debounceDelay) {
    if (touchState != lastTouchState) {
      lastTouchState = touchState;
      if (touchState) speedLevel = (speedLevel % 3) + 1;
    }
  }
  for (int i = 0; i <= 255; i++) {
    analogWrite(ledPin, i);
    delay(speedLevel * 10);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(ledPin, i);
    delay(speedLevel * 10);
  }
}
