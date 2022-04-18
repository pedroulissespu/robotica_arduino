#include <AFMotor.h>


AF_DCMotor motorDirFrente(1);
AF_DCMotor motorDirTras(2);
AF_DCMotor motorEsqFrente(3);
AF_DCMotor motorEsqTras(4);

void setup() {
  Serial.begin(9300);
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
  int valSensorEsq = analogRead(0);
  int valSensorFre = analogRead(1);
  int valSensorDir = analogRead(2);

  if (valSensorEsq < 300 and valSensorDir > 300) {
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
  else if ( valSensorEsq > 300 and valSensorDir <300) {
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
