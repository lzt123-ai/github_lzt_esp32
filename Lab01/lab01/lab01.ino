// 根据你的ESP32开发板修改LED引脚（先测试2，不行换13/21/8）
#define LED_PIN 2  
#define LED_RED 4
void setup() {
  // 初始化串口通信，115200波特率
  Serial.begin(115200);
  // 等待串口初始化完成（ESP32建议添加）
  while (!Serial) {
    delay(10);
  }
  // 初始化LED引脚为输出模式
  pinMode(LED_PIN, OUTPUT); 
    pinMode(LED_RED, OUTPUT);
  Serial.println("系统初始化完成！"); // 仅打印一次初始化信息
}

void loop() {
  Serial.println("Hello ESP32! LED点亮");
  digitalWrite(LED_PIN, HIGH);   // 点亮LED
    digitalWrite(LED_RED, HIGH);   // 点亮LED
  delay(1000);                   // 等待1秒
  
  Serial.println("Hello ESP32! LED熄灭");
  digitalWrite(LED_PIN, LOW);    // 熄灭LED
    digitalWrite(LED_RED, LOW);    // 熄灭LED
  delay(1000);                   // 等待1秒
}