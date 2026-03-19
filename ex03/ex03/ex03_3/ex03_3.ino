// ex03 代码 - 第三次提交
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
  // 1. 发送 "S"
  for (int i = 0; i < 3; i++) {
    flash(dotDuration);
    delay(gapDuration);
  }
  delay(letterGap); 

  // 2. 发送 "O"
  for (int i = 0; i < 3; i++) {
    flash(dashDuration);
    delay(gapDuration);
  }
  delay(letterGap); 

  // 3. 再发送 "S"
  for (int i = 0; i < 3; i++) {
    flash(dotDuration);
    delay(gapDuration);
  }
  delay(endPause); 
}

// 封装一个闪烁函数，让代码更整洁
void flash(int duration) {
  digitalWrite(ledPin, HIGH); 
  delay(duration);            
  digitalWrite(ledPin, LOW);  
}