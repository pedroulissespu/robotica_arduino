#include <AFMotor.h>

AF_DCMotor motorD1(1); //M1
AF_DCMotor motorD2(2); //M2
AF_DCMotor motorE1(3); //M3
AF_DCMotor motorE2(4); //M4

int Sensor1 = 0;
int Valor_Sensor1 = 0; 
int Sensor2 = 1; 
int Valor_Sensor2 = 0;
int Sensor3 = 2;
int Valor_Sensor3 = 0; 
const int dirA = 7;
const int dirB = 8;

void setup(){
  pinMode(dirA, OUTPUT);
  pinMode(dirB, OUTPUT);
  digitalWrite(dirA, HIGH); 
  digitalWrite(dirB, HIGH);
}

void loop(){
  Valor_Sensor1 = analogRead(Sensor1); 
  Valor_Sensor2 = analogRead(Sensor2); 
  Valor_Sensor3 = analogRead(Sensor3);  
  
  if((Valor_Sensor1 > 700) && (Valor_Sensor2 > 700)){
    analogWrite(motorD1, 150); 
    analogWrite(motorE1, 150);
    analogWrite(motorD2, 150); 
    analogWrite(motorE2, 150);
  }
  
  if((Valor_Sensor1 < 700) && (Valor_Sensor2 > 700)){
    analogWrite(motorD1, 0); 
    analogWrite(motorE1, 200);
    analogWrite(motorD2, 0); 
    analogWrite(motorE2, 200);
  }
  
  if((Valor_Sensor1 > 700) && (Valor_Sensor2 < 700)){
    analogWrite(motorD1, 200); 
    analogWrite(motorE1, 0);
    analogWrite(motorD2, 200); 
    analogWrite(motorE2, 0);
  }  
  
}
