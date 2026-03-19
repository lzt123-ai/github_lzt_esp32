// ex02 代码 - 第三次提交
const int ledPin = 2;          
unsigned long previousMillis = 0; 
const long interval = 500;     

void setup() {
  pinMode(ledPin, OUTPUT);     
  digitalWrite(ledPin, LOW);   
}

void loop() {
  unsigned long currentMillis = millis(); // 获取现在的时间

  // 如果距离上次变化已经过了500毫秒
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;       // 更新时间戳
    
    // 翻转LED状态
    int state = digitalRead(ledPin);
    digitalWrite(ledPin, !state);
  }
}

