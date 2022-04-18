#include <AFMotor.h>

AF_DCMotor motorD1(1); //M1
AF_DCMotor motorD2(2); //M2
AF_DCMotor motorE1(3); //M3
AF_DCMotor motorE2(4); //M4

int Sensor1 = 0 ;
int Valor_Sensor1 = 0 ; 
int Sensor2 = 1 ; 
int Valor_Sensor2 = 0 ;
int Sensor3 = 2 ;
int Valor_Sensor3 = 0 ; 
int leftOffset = 0, rightOffset = 0, centre = 0;
int speed1 = 10, speed2 = 18, direction1 = 12, direction2 = 13;
int startSpeed = 125, rotate = 30;
int threshold = 5;
int left = startSpeed, right = startSpeed;

void setup (){
  motorD1.setSpeed(125);
  motorD2.setSpeed(125);
  motorE1.setSpeed(125);
  motorE2.setSpeed(125);
  delay(1000);
  calibrate();
  delay(3000);
}

void control_motors(byte vel_dir, byte vel_esq, word var_dir = RELEASE, word var_esq = RELEASE) {
  motorD2.run(var_dir);  motorD2.setSpeed(vel_dir);     
  motorD1.run(var_dir);  motorD1.setSpeed(vel_dir);   
  motorE2.run(var_esq);  motorE2.setSpeed(vel_esq);     
  motorE1.run(var_esq);  motorE1.setSpeed(vel_esq);   
}

void calibrate()
{
 for (int x=0; x<10; x++)
 {
   delay(100);
 Valor_Sensor1 = analogRead(Sensor1);
 Valor_Sensor2 = analogRead(Sensor2);
 Valor_Sensor3 = analogRead(Sensor3);
   leftOffset = leftOffset + Valor_Sensor1;
   centre = centre + Valor_Sensor2;
   rightOffset = rightOffset + Valor_Sensor3;
   delay(100);
 }
 leftOffset = leftOffset /10;
 rightOffset = rightOffset /10;
 centre = centre / 10;
 leftOffset = centre - leftOffset;
 rightOffset = centre - rightOffset;
}

void loop()
{
  left = startSpeed;
  right = startSpeed;
 
   Valor_Sensor1 = analogRead(Sensor1) + leftOffset;
   Valor_Sensor2 = analogRead(Sensor2);
   Valor_Sensor3 = analogRead(Sensor3) + rightOffset;
  if (Valor_Sensor1 > Valor_Sensor2+threshold)
  {
    left = startSpeed + rotate;
    right = startSpeed - rotate;
  }
  if (Valor_Sensor3 > (Valor_Sensor2+threshold))
  {
    left = startSpeed - rotate;
    right = startSpeed + rotate;
  }
 
  motorE1.setSpeed(left);
  motorE1.run(FORWARD);
  motorD1.setSpeed(right);
  motorD1.run(FORWARD);
  motorE2.setSpeed(left);
  motorE2.run(FORWARD);
  motorD2.setSpeed(right);
  motorD2.run(FORWARD);
  
}
