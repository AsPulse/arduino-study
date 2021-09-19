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
    void back(){
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
};
class PWMMotor {
  private: 
    int pin1;
    int pin2;
    int pin3;
    void forward(){
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, LOW);
    }
    void back(){
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
    void setPWM(int value) {
      analogWrite(pin3, value);
    }
    int convert255(double value) {
      return round(value * 255);
    }
  public:
    PWMMotor(int sPin1, int sPin2, int sPin3) {
      pin1 = sPin1;
      pin2 = sPin2;
      pin3 = sPin3;
    }
    void setup() {
      pinMode(pin1, OUTPUT);
      pinMode(pin2, OUTPUT);
      pinMode(pin3, OUTPUT);
    }
    void control(double value){
      int data = convert255(value);
      if( data > 255 ) data = 255;
      if( data < -255 ) data = -255;
      if( data == 0 ) {
        off();
        setPWM(0);
        //Serial.println( "SETPMW: 0" );
      }
      if( data > 0 ) {
        setPWM(data);
        forward();
        Serial.print( "SETPMW: ");
        Serial.println(String(data));
        Serial.flush();
      }
      if( data < 0 ) {
        setPWM(-data);
        back();
        Serial.print( "SETPMW: ");
        Serial.println(String(data));
        Serial.flush();

      }
    }
};

PWMMotor leftM(8, 7, 10);
PWMMotor rightM(13, 12, 11);
const int delayL = 1000;

void setup() {
  Serial.begin( 9600 );
  leftM.setup();
  rightM.setup();
  Serial.println( "Setup finished!" );   
}

void loop() {
  // put your main code here, to run repeatedly:
  rightM.control(0.5);
  leftM.control(0.5);
  delay(1000);
}
