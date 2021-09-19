NormalMotor leftMotor(13, 12);
NormalMotor rightMotor(8, 7);
const int delayL = 1000;

void setup() {
  leftMotor.setup();
  rightMotor.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  leftMotor.forward();
  delay(delayL);
  leftMotor.brake();
  delay(delayL);
}

class NormalMotor {
  private: 
    int pin1;
    int pin2;
  public:
    NormalMotor(int sPin1, int sPin2) {
      pin1 = sPin1;
      pin2 = sPin2;
    }
    void setup() {
      pinMode(pin1, OUTPUT);
      pinMode(pin2, OUTPUT);
    }
    void forward(){
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, LOW);
    }
    void backard(){
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, HIGH);
    }
    void brake(){
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, HIGH);
    }
    void off(){
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
    }
}
