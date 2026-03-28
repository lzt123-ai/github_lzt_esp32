void loop() {
  for (int i = 0; i <= 255; i++) {
    analogWrite(ledPinA, i);
    analogWrite(ledPinB, 255 - i);
    delay(10);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(ledPinA, i);
    analogWrite(ledPinB, 255 - i);
    delay(10);
  }
}