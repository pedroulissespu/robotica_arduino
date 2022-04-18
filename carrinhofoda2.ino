#include <AFMotor.h>


AF_DCMotor motorDirFrente(1);
AF_DCMotor motorDirTras(2);
AF_DCMotor motorEsqFrente(3);
AF_DCMotor motorEsqTras(4);

void setup() {
  Serial.begin(9600);
}

void frente() {
  motorDirFrente.run(FORWARD);
  motorDirFrente.setSpeed(200);
  motorEsqFrente.run(FORWARD);
  motorEsqFrente.setSpeed(200);
  motorDirTras.run(FORWARD);
  motorDirTras.setSpeed(200);
  motorEsqTras.run(FORWARD);
  motorEsqTras.setSpeed(200);
}

void loop() {
  int valSensorEsq = analogRead(5);
  int valSensorFre = analogRead(3);
  int valSensorDir = analogRead(4);

  if (valSensorEsq < 600 and valSensorDir > 600) {
    motorDirFrente.run(BACKWARD);
    motorDirFrente.setSpeed(200);
    motorEsqFrente.run(FORWARD);
    motorEsqFrente.setSpeed(220);
    motorDirTras.run(BACKWARD);
    motorDirTras.setSpeed(180);
    motorEsqTras.run(FORWARD);
    motorEsqTras.setSpeed(240);
    delay(50);
  } 
  else if ( valSensorEsq > 600 and valSensorDir <600) {
    motorDirFrente.run(FORWARD);
    motorDirFrente.setSpeed(220);
    motorEsqFrente.run(BACKWARD);
    motorEsqFrente.setSpeed(200);
    motorDirTras.run(FORWARD);
    motorDirTras.setSpeed(240);
    motorEsqTras.run(BACKWARD);
    motorEsqTras.setSpeed(180);
    delay (50);
  }
    else {
    frente();
}
}
