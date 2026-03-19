// ex02 代码 - 第一次提交
const int ledPin = 2;          // 定义板载LED引脚（ESP32通常用2号引脚）

void setup() {
  pinMode(ledPin, OUTPUT);     // 设置引脚为输出模式
  digitalWrite(ledPin, LOW);   // 初始状态熄灭
}

void loop() {
  // 暂时留空，稍后添加闪烁逻辑
}