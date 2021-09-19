// Arduino入門編㉒ モータードライバを使いDCモーターを制御する(PWM制御)
// https://burariweb.info

// デジタルピンの定義
const int IN1 = 8;
const int IN2 = 7;
const int IN3 = 13;
const int IN4 = 12;
const int ENA = 10;  // PWM制御で使うENAピンをD9に(モーター1のPWM制御ピン)
const int ENB = 11; // PWM制御で使うENBピンをD10に(モーター2のPWM制御ピン)

int i = 0;
int step = 5;

void setup(){

  pinMode(IN1, OUTPUT);  // デジタルピンを出力に設定
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  
}

void loop(){

  digitalWrite(IN1, HIGH); // HIGH LOWの組み合わせでモーター回転
  digitalWrite(IN2, LOW);  // 2つのモーターを正回転
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  delay(1000);

}
