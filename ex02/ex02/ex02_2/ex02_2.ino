// ex02 代码 - 第二次提交
const int ledPin = 2;          // 定义板载LED引脚
unsigned long previousMillis = 0; // 记录上一次变化的时间
const long interval = 500;     // 间隔时间：500毫秒

void setup() {
  pinMode(ledPin, OUTPUT);     
  digitalWrite(ledPin, LOW);   
}

void loop() {
  // 准备添加非阻塞延时逻辑
}