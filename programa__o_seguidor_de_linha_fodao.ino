
#include <AFMotor.h>

AF_DCMotor motorDirFrente(1);
AF_DCMotor motorDirTras(2);
AF_DCMotor motorEsqFrente(3);
AF_DCMotor motorEsqTras(4);

  int valSensorEsq ;
  int valSensorFre ;
  int valSensorDir ;

void LEFT (void);
void RIGHT (void);
void STOP (void);

void setup()
{
  Serial.begin(9600);
}

void loop() 
{
 
  motorDirFrente.run(FORWARD);
  motorDirFrente.setSpeed(190);
  motorEsqFrente.run(FORWARD);
  motorEsqFrente.setSpeed(190);
  motorDirTras.run(FORWARD);
  motorDirTras.setSpeed(190);
  motorEsqTras.run(FORWARD);
  motorEsqTras.setSpeed(190);

while(1)
{ 
valSensorEsq = analogRead(0);
valSensorFre = analogRead(1);
valSensorDir = analogRead(2);
  if((valSensorEsq==0 && valSensorDir==1)==1)
  LEFT();
  else if((valSensorDir==0 && valSensorEsq==1)==1)
  RIGHT();
}
}

void LEFT (void)
{
    motorDirTras.run(FORWARD);
    motorDirTras.setSpeed(0);
    motorEsqTras.run(BACKWARD);
    motorEsqTras.setSpeed(30);
   
   
   while(valSensorEsq==0)
   {
    valSensorEsq = analogRead(0);
    valSensorFre = analogRead(1);
    valSensorDir = analogRead(2);
    if(valSensorDir==0)
    {
      int lprev=valSensorEsq;
      int rprev=valSensorDir;
      STOP();
      while(((lprev==valSensorEsq)&&(rprev==valSensorDir))==1)
      {
        valSensorEsq = analogRead(0);
        valSensorFre = analogRead(1);
        valSensorDir = analogRead(2);
      }
    }
      motorDirFrente.run(FORWARD);
      motorDirFrente.setSpeed(255);
      motorEsqFrente.run(BACKWARD);
      motorEsqFrente.setSpeed(0);
   }
motorDirTras.run(FORWARD);
motorDirTras.setSpeed(255);
motorEsqTras.run(BACKWARD);
motorEsqTras.setSpeed(0);
}

void RIGHT (void)
{
    motorDirFrente.run(FORWARD);
    motorDirFrente.setSpeed(0);
    motorEsqFrente.run(BACKWARD);
    motorEsqFrente.setSpeed(30);

   while(valSensorDir==0)
   {
      valSensorEsq = analogRead(0);
      valSensorFre = analogRead(1);
      valSensorDir = analogRead(2);
    if(valSensorEsq==0)
    {
      int lprev=valSensorEsq;
      int rprev=valSensorDir;
     STOP();
      while(((lprev==valSensorEsq)&&(rprev==valSensorDir))==1)
      {
        valSensorEsq = analogRead(0);
        valSensorFre = analogRead(1);
        valSensorDir = analogRead(2);
      }
    }
motorDirTras.run(FORWARD);
motorDirTras.setSpeed(255);
motorEsqTras.run(BACKWARD);
motorEsqTras.setSpeed(0);
    }
motorDirFrente.run(FORWARD);
motorDirFrente.setSpeed(255);
motorEsqFrente.run(BACKWARD);
motorEsqFrente.setSpeed(0);
}
void STOP (void)
{
  motorDirFrente.run(BACKWARD);
  motorDirFrente.setSpeed(0);
  motorEsqFrente.run(BACKWARD);
  motorEsqFrente.setSpeed(0);
  motorDirTras.run(BACKWARD);
  motorDirTras.setSpeed(0);
  motorEsqTras.run(BACKWARD);
  motorEsqTras.setSpeed(0);
  
}
