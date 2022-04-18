#define m1A_pin 3
#define m1B_pin 5
#define m2A_pin 9
#define m2B_pin 6
#define potL 210
#define potS 6
#define potF 115
#define linha 500


void setup() {
  pinMode(m1A_pin, OUTPUT);
  pinMode(m1B_pin, OUTPUT);
  pinMode(m2A_pin, OUTPUT);
  pinMode(m2B_pin, OUTPUT);
}

void loop() {
  int s1=analogRead(A0);
  int s2=analogRead(A1);
  
  if(s1 < linha  &&  s2 < linha){
    control('w');
  }
 else if(s1 > linha && s2 < linha){
   control('a');
 }
 else if(s2 > linha && s1 < linha){
   control('d');
 }
 else if(s1 > linha && s2 > linha){
   control('w');
 }              
}
void control(char dir){
    switch(dir){
       case 'w':
           analogWrite(m1A_pin, 0);
           analogWrite(m1B_pin, potF);
           analogWrite(m2A_pin, 0);
           analogWrite(m2B_pin, potF);
           break;
       case 'z':
           analogWrite(m1A_pin, potF);
           analogWrite(m1B_pin, 0);
           analogWrite(m2A_pin, potF);
           analogWrite(m2B_pin, 0);
           break;
       case 'd':
           analogWrite(m1A_pin, potS);
           analogWrite(m1B_pin, 0);
           analogWrite(m2A_pin, 0);
           analogWrite(m2B_pin, potL);
           break;
       case 'a':
           analogWrite(m1A_pin, 0);
           analogWrite(m1B_pin, potL);
           analogWrite(m2A_pin, potS);
           analogWrite(m2B_pin, 0);
           break;        
      }       
}
