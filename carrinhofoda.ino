#include <AFMotor.h>

AF_DCMotor motorDirFrente(1);
AF_DCMotor motorDirTras(2);
AF_DCMotor motorEsqFrente(3);
AF_DCMotor motorEsqTras(4);

void setup() {
  Serial.begin(9600);
}
void esquerda(){
  motorDirFrente.run(FORWARD);
  motorDirFrente.setSpeed(125);
  motorEsqFrente.run(BACKWARD);
  motorEsqFrente.setSpeed(255);
  motorDirTras.run(FORWARD);
  motorDirTras.setSpeed(125);
  motorEsqTras.run(BACKWARD);
  motorEsqTras.setSpeed(255);
}
void direita(){
  motorDirFrente.run(BACKWARD);
  motorDirFrente.setSpeed(125);
  motorEsqFrente.run(FORWARD);
  motorEsqFrente.setSpeed(255);
  motorDirTras.run(BACKWARD);
  motorDirTras.setSpeed(125);
  motorEsqTras.run(FORWARD);
  motorEsqTras.setSpeed(255); 
}
void frente() {
  motorDirFrente.run(FORWARD);
  motorDirFrente.setSpeed(190);
  motorEsqFrente.run(FORWARD);
  motorEsqFrente.setSpeed(190);
  motorDirTras.run(FORWARD);
  motorDirTras.setSpeed(190);
  motorEsqTras.run(FORWARD);
  motorEsqTras.setSpeed(190);
}

void loop() {
  int valSensorEsq = analogRead(0);
  int valSensorFre = analogRead(1);
  int valSensorDir = analogRead(2);
  int valSensorDir2 = analogRead(4);
  int valSensorEsq2 = analogRead(3);

  if (valSensorEsq < 100 and valSensorDir > 100) {
    motorDirFrente.run(BACKWARD);
    motorDirFrente.setSpeed(200);
    motorEsqFrente.run(FORWARD);
    motorEsqFrente.setSpeed(250);
    motorDirTras.run(BACKWARD);
    motorDirTras.setSpeed(200);
    motorEsqTras.run(FORWARD);
    motorEsqTras.setSpeed(250);
  } 
  else if (valSensorEsq > 100 and valSensorDir < 100) {
    motorDirFrente.run(FORWARD);
    motorDirFrente.setSpeed(250);
    motorEsqFrente.run(BACKWARD);
    motorEsqFrente.setSpeed(200);
    motorDirTras.run(FORWARD);
    motorDirTras.setSpeed(250);
    motorEsqTras.run(BACKWARD);
    motorEsqTras.setSpeed(200);
  } 

  else if(valSensorEsq > 100 and valSensorDir > 100) {
    frente();
  }
  else {
    frente();
  }  
   if ( valSensorDir > 100 and valSensorEsq < 100 and valSensorFre > 100){
    direita ();
    delay(1500);
  }
  
  else if ( valSensorDir < 100 and valSensorEsq > 100 and valSensorFre > 100){
    esquerda();
    delay(1500);
  }
  
}
