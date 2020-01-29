#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include <Adafruit_NeoPixel.h>
byte gammatable[256];
byte valenc;
byte val;
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
int i = 0;
int enc_l[2];
int enc_r[2];

void setup(){
  pinMode(motorA,OUTPUT);
  pinMode(motorB,OUTPUT);
  pinMode(motorC,OUTPUT);
  pinMode(motorD,OUTPUT);
  pinMode(PWM_motAB,OUTPUT);
  pinMode(PWM_motCD,OUTPUT);
  //attachInterrupt(0, SPEED_l, CHANGE);
  //attachInterrupt(1, SPEED_l, CHANGE);
  attachInterrupt(4, SPEED_r, CHANGE);
  attachInterrupt(5, SPEED_r, CHANGE);
  
  
 

  Serial.begin(9600);
}


void loop() {
  
  digitalWrite(motorA,HIGH);
  digitalWrite(motorB,LOW);
  analogWrite(PWM_motCD,110);
  
  
  enc_l[0] = digitalRead(ENCC);

  enc_l[1] = digitalRead(ENCD);

  Serial.print("C:");
  Serial.print(enc_l[0]);
  Serial.print(" ");
 
  Serial.print("D:");
  Serial.print(enc_l[1]);
 
  Serial.println();

  delay(500);

}
void SPEED_l(){
 
  enc_l[0] = !digitalRead(ENCA);
  enc_l[1] = !digitalRead(ENCB);

  Serial.print("A:");
  Serial.print(enc_l[0]);
  Serial.print(" ");
 
  Serial.print("B:");
  Serial.print(enc_l[1]);
 
  Serial.println();

}

void SPEED_r(){

  enc_r[0] = !digitalRead(ENCC);
  enc_r[1] = !digitalRead(ENCD);

  Serial.print("割り込みC:");
  Serial.print(enc_r[0]);
  Serial.print(" ");
 
  Serial.print("割り込みD:");
  Serial.print(enc_r[1]);
 
  Serial.println();
 }
