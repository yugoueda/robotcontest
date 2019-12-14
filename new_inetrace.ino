// モータ
const int motorA = 36;
const int motorB = 37;
const int PWM_motAB = 6;
const int motorC = 39;
const int motorD = 38;
const int PWM_motCD = 5;
const int ledA = 13;
//サーボ
const int servo1 = 13; //茶
//　フォトトランジスタ
const int sensorA = 46;  //外側左
const int sensorB = 47;  //内側左
const int sensorC = 48;  //内側右
const int sensorD = 49;  //外側右
//エンコーダ
const int ENCA = 2;
const int ENCB = 3;
const int ENCC = 18;
const int ENCD = 19;
//PSDセンサ
const int PSD1 = 0;
//　センサから読み取った値（analog）
int valA = 0;
int valB = 0;
int valC = 0;
int valD = 0;
int valPSD1 = 0;
int valPSD2 = 0;
int turn = 0;
int motor_val[2];

void setup() {
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  pinMode(motorC, OUTPUT);
  pinMode(motorD, OUTPUT);
  pinMode(PWM_motAB, OUTPUT);
  pinMode(PWM_motCD, OUTPUT);
  pinMode(ENCA, INPUT_PULLUP);
  pinMode(ENCB, INPUT_PULLUP);
  pinMode(ENCC, INPUT_PULLUP);
  pinMode(ENCD, INPUT_PULLUP);
  Serial.begin(9600);
}
void loop() {
  turn++;
  valA = digitalRead(sensorA);
  valB = digitalRead(sensorB);
  valC = digitalRead(sensorC);
  valD = digitalRead(sensorD);
  valPSD1 = analogRead(PSD1);
  Serial.print(turn);
  Serial.print("  ");
  Serial.print(valA);
  Serial.print("  ");
  Serial.print(valB);
  Serial.print("  ");
  Serial.print(valC);
  Serial.print("  ");
  Serial.print(valD);
  Serial.print("  ");
  Serial.println(valPSD1);
  
  if (valA == 0 && valB == 1 && valC == 1 && valD == 0) {
    //1通常時直進
    motor_val[0] = ;
    motor_val[1] = ;
  } else if (valA == 0 && valB == 0 && valC == 1 && valD == 0) {
    //2通常時左旋回
    motor_val[0] = ;
    motor_val[1] = ;
  } else if (valA == 0 && valB == 1 && valC == 0 && valD == 0) {
    //3通常時右旋回
    motor_val[0] = ;
    motor_val[1] = ;
  } else if (valA == 1 && valB == 1 && valC == 1 && valD == 1) {
    //4横棒時直進
    motor_val[0] = ;
    motor_val[1] = ;
  } else if (valA == 0 && valB == 1 && valC == 1 && valD == 1) {
    //5横棒時左旋回a
    motor_val[0] = ;
    motor_val[1] = ;
  } else if (valA == 1 && valB == 1 && valC == 1 && valD == 0) {
    //6横棒時右旋回a
    motor_val[0] = ;
    motor_val[1] = ;
  } else if (valA == 1 && valB == 1 && valC == 0 && valD == 0) {
    //7横棒時右旋回b
    motor_val[0] = ;
    motor_val[1] = ;
  } else if (valA == 0 && valB == 0 && valC == 1 && valD == 1) {
    //8横棒時左旋回b
    motor_val[0] = ;
    motor_val[1] = ;
  } else if (valA == 1 && valB == 0 && valC == 1 && valD == 0) {
    //9横棒時右旋回c
    motor_val[0] = ;
    motor_val[1] = ;
  } else if (valA == 0 && valB == 1 && valC == 0 && valD == 1) {
    //10横棒時左旋回c
    motor_val[0] = ;
    motor_val[1] = ;
  } else if (valA == 0 && valB == 0 && valC == 0 && valD == 0 && turn < 50 ) {
    //11開幕時右直進
    motor_val[0] = ;
    motor_val[1] = ;
  } else if (valA == 0 && valB == 0 && valC == 0 && valD == 0 && turn > 51 ) {
    //12探索
    motor_val[0] = ;
    motor_val[1] = ;
  } else {
    motor_val[0] = ;
    motor_val[1] = ;
  }
  
  digitalWrite(motorA, int(motor_val[0]>=0)
  digitalWrite(motorB, int(motor_val[0]<0));
  analogWrite(PWM_motAB, abs(motor_val[0]));
  digitalWrite(motorC, int(motor_val[1]>=0)
  digitalWrite(motorD, int(motor_val[1]<0));
  analogWrite(PWM_motCD, abs(motor_val[1]));
  
  Serial.print(motor_val[0]);
  Serial.print("  ");
  Serial.println(motor_val[1]);
  
  //モーターの動作を0.05秒つづける
  delay(50);
}
