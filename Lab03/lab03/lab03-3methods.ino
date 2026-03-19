/*
// 定义LED引脚
const int ledPin = 2;  const int ledRED = 4; const int ledYELLOW = 16; const int ledGREEN = 17;
// 设置PWM属性
const int freq = 5000;          // 频率 5000Hz
const int resolution = 8;       // 分辨率 8位 (0-255)

void setup() {
  Serial.begin(115200);

  // 【新版用法】直接将引脚、频率和分辨率绑定
  // 它会自动返回一个关联的通道（如果需要的话）
  ledcAttach(ledPin, freq, resolution);
  ledcAttach(ledRED, freq, resolution);
  ledcAttach(ledYELLOW, freq, resolution);
  ledcAttach(ledGREEN, freq, resolution);
}

void loop() {
  // 逐渐变亮
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // 【新版用法】直接通过引脚号写入，不再需要指定通道
    ledcWrite(ledPin, dutyCycle);   
    delay(10);
  }

  // 逐渐变暗
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    ledcWrite(ledPin, dutyCycle);   
    delay(10);
  }

  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // 【新版用法】直接通过引脚号写入，不再需要指定通道
    ledcWrite(ledRED, dutyCycle);   
    delay(10);
  }

  // 逐渐变暗
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    ledcWrite(ledRED, dutyCycle);   
    delay(10);
  }

  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // 【新版用法】直接通过引脚号写入，不再需要指定通道
    ledcWrite(ledYELLOW, dutyCycle);   
    delay(10);
  }

  // 逐渐变暗
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    ledcWrite(ledYELLOW, dutyCycle);   
    delay(10);
  }

  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // 【新版用法】直接通过引脚号写入，不再需要指定通道
    ledcWrite(ledGREEN, dutyCycle);   
    delay(10);
  }

  // 逐渐变暗
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    ledcWrite(ledGREEN, dutyCycle);   
    delay(10);
  }
//若改成0-63,63-0,   64-127,127-64,   128-191，191-128,   191-255,255-191虽然四个灯是依次亮，但是后面两个灯亮度都比较亮看不出来变化
*/

/*
void loop() {
  // 逐渐变亮
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // 【新版用法】直接通过引脚号写入，不再需要指定通道
    ledcWrite(ledPin, dutyCycle); 
    ledcWrite(ledRED, 255-dutyCycle); 
    ledcWrite(ledYELLOW, dutyCycle);
    ledcWrite(ledGREEN, 255-dutyCycle);
    delay(10);
  }
  // 逐渐变暗
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    ledcWrite(ledPin, dutyCycle); 
    ledcWrite(ledRED, 255-dutyCycle);  
    ledcWrite(ledYELLOW, dutyCycle);
    ledcWrite(ledGREEN, 255-dutyCycle);
    delay(10);
  }这是1和3灯同步，2和4灯同步，并且两者相反
 
  Serial.println("Breathing cycle completed");
}
*/ 

// 1. 定义4个LED的引脚
const int ledPin0 = 2;
const int ledPin1 = 4;   
const int ledPin2 = 16;   
const int ledPin3 = 17;   

const int freq = 5000;          // 频率
const int resolution = 8;       // 分辨率

void setup() {
  // 【重要修改】新版直接使用 ledcAttach(引脚, 频率, 分辨率)
  // 不再需要 ledcSetup 和 ledcAttachPin，也不需要手动管理通道号
  ledcAttach(ledPin0, freq, resolution);
  ledcAttach(ledPin1, freq, resolution);
  ledcAttach(ledPin2, freq, resolution);
  ledcAttach(ledPin3, freq, resolution);
}

void loop() {
  // --- 依次点亮 ---
  fadeIn(ledPin0);
  fadeIn(ledPin1);
  fadeIn(ledPin2);
  fadeIn(ledPin3);

  delay(500); 

  // --- 依次熄灭 --
  fadeOut(ledPin0);
  fadeOut(ledPin1);
  fadeOut(ledPin2);
  fadeOut(ledPin3);

  delay(500);
}

// 辅助函数：渐变亮起
// 【重要修改】参数现在是引脚号 (pin)，而不是通道号
void fadeIn(int pin) {
  for (int duty = 0; duty <= 255; duty++) {
    ledcWrite(pin, duty); // 新版直接传引脚
    delay(5); 
  }
}

// 辅助函数：渐变熄灭
void fadeOut(int pin) {
  for (int duty = 255; duty >= 0; duty--) {
    ledcWrite(pin, duty); // 新版直接传引脚
    delay(5); 
  }
}