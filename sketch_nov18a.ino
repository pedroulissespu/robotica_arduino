int Sensor1 = 0;
int Valor_Sensor1 = 0; 
int Sensor2 = 1; 
int Valor_Sensor2 = 0;
int Sensor3 = 2; 
int Valor_Sensor3 = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  Valor_Sensor1 = analogRead(Sensor1); 
  Valor_Sensor2 = analogRead(Sensor2); 
   Valor_Sensor3 = analogRead(Sensor3);
  Serial.println(Valor_Sensor1);
  Serial.println("I");
  Serial.println(Valor_Sensor2);
    Serial.println("I");
  Serial.println(Valor_Sensor3);
  delay(250);
}
