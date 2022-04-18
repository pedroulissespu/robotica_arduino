#include <AFMotor.h>

AF_DCMotor motorD1(1); //M1
AF_DCMotor motorD2(2); //M2
AF_DCMotor motorE1(3); //M3
AF_DCMotor motorE2(4); //M4
const int dirA = 7; //direcao do motor A - HIGH ou LOW
const int dirB = 8; //direcao do motor B - HIGH ou LOW  
int Sensor1 = 0;
int Valor_Sensor1 = 0; 
int Sensor2 = 1; 
int Valor_Sensor2 = 0;
int Sensor3 = 2; 
int Valor_Sensor3 = 0;

void setup(){
    motorE1.setSpeed(150);
    motorE2.setSpeed(150);
    motorD1.setSpeed(150);
    motorD2.setSpeed(150);
}

void loop(){
  Valor_Sensor1 = analogRead(Sensor1); 
  Valor_Sensor2 = analogRead(Sensor2); 
  Valor_Sensor3 = analogRead(Sensor3); 
  
  if(((Valor_Sensor1 > 700) && (Valor_Sensor2 > 700) && (Valor_Sensor3 > 700))){
    motorE1.setSpeed(150);
    motorE2.setSpeed(150);
    motorD1.setSpeed(150);
    motorD2.setSpeed(150);
  }
  
  if(((Valor_Sensor1 < 700) && (Valor_Sensor2 > 700) && (Valor_Sensor3 > 700))){
    motorE1.setSpeed(200);
    motorE2.setSpeed(200);
    motorD1.setSpeed(0);
    motorD2.setSpeed(0);
  }
  
  if(((Valor_Sensor1 > 700) && (Valor_Sensor2 > 700) && (Valor_Sensor3 < 700))){
    motorE1.setSpeed(0);
    motorE2.setSpeed(0);
    motorD1.setSpeed(200);
    motorD2.setSpeed(200);
  }  
  
}
