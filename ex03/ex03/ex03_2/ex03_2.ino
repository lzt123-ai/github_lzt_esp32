// ex03 代码 - 第二次提交
const int ledPin = 2;

const int dotDuration = 200;   
const int dashDuration = 600;  
const int gapDuration = 200;   
const int letterGap = 1000;    
const int endPause = 2000;     

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // 1. 发送 "S" (三个短闪)
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(dotDuration);
    digitalWrite(ledPin, LOW);
    delay(gapDuration); 
  }
  delay(letterGap); 

  // 2. 发送 "O" (三个长闪)
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(dashDuration);
    digitalWrite(ledPin, LOW);
    delay(gapDuration);
  }
  delay(letterGap); 

  // 3. 再发送一次 "S" (三个短闪)
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(dotDuration);
    digitalWrite(ledPin, LOW);
    delay(gapDuration);
  }
  delay(endPause); 
}