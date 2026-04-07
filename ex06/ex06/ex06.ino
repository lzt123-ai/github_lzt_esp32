// 定义两个LED连接的PWM引脚
const int ledPin1 = 5;   // LED 1 连接到引脚 3
const int ledPin2 = 19;   // LED 2 连接到引脚 5

// 定义亮度变量
int brightness1 = 0;     // LED 1 的初始亮度
int brightness2 = 255;   // LED 2 的初始亮度 (与LED1相反)

// 定义每次循环亮度的变化量
int fadeAmount = 5;

void setup() {
  // 设置引脚为输出模式
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  // 设置两个LED的亮度
  // analogWrite 的值范围是 0 (完全熄灭) 到 255 (最亮)
  analogWrite(ledPin1, brightness1);
  analogWrite(ledPin2, brightness2);

  // 计算下一次的亮度
  // LED1 亮度增加
  brightness1 += fadeAmount;
  // LED2 亮度减少
  brightness2 -= fadeAmount;

  // 检查是否达到亮度极限
  // 如果 LED1 达到最亮或最暗，就反转变化方向
  if (brightness1 <= 0 || brightness1 >= 255) {
    fadeAmount = -fadeAmount; // 反转变化方向
  }

  // 等待30毫秒，以产生可见的渐变效果
  delay(30);
}