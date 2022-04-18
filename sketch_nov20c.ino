
#include <AFMotor.h>

AF_DCMotor motorDirFrente(1);
AF_DCMotor motorDirTras(2);
AF_DCMotor motorEsqFrente(3);
AF_DCMotor motorEsqTras(4);

int sensordir=A3;
int sensoresq=A4;
int valsensordir = 0;
int valsensoresq = 0;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  valsensoresq = analogRead (sensoresq);
  valsensordir= analogRead (sensordir);

 if
   ( valsensoresq < 200 && valsensordir < 200)
   {
  motorDirFrente.run(FORWARD);
  motorDirFrente.setSpeed(190);
  motorEsqFrente.run(FORWARD);
  motorEsqFrente.setSpeed(190);
  motorDirTras.run(FORWARD);
  motorDirTras.setSpeed(190);
  motorEsqTras.run(FORWARD);
  motorEsqTras.setSpeed(190);
   }
   else
   {

     if
     ( valsensoresq > 200 && valsensordir < 200)
    {
  motorDirFrente.run(FORWARD);
  motorDirFrente.setSpeed(200);
  motorEsqFrente.run(FORWARD);
  motorEsqFrente.setSpeed(125);
  motorDirTras.run(FORWARD);
  motorDirTras.setSpeed(200);
  motorEsqTras.run(FORWARD);
  motorEsqTras.setSpeed(125);
    }
 else {
   if (valsensoresq < 200 && valsensordir > 200)
   {
  motorDirFrente.run(FORWARD);
  motorDirFrente.setSpeed(125);
  motorEsqFrente.run(FORWARD);
  motorEsqFrente.setSpeed(200);
  motorDirTras.run(FORWARD);
  motorDirTras.setSpeed(125);
  motorEsqTras.run(FORWARD);
  motorEsqTras.setSpeed(200);
   }
   else
   {
     if (valsensoresq > 200 && valsensordir > 200)
     {
  motorDirFrente.run(FORWARD);
  motorDirFrente.setSpeed(125);
  motorEsqFrente.run(FORWARD);
  motorEsqFrente.setSpeed(125);
  motorDirTras.run(FORWARD);
  motorDirTras.setSpeed(125);
  motorEsqTras.run(FORWARD);
  motorEsqTras.setSpeed(125);
     }}
      }
    }}
