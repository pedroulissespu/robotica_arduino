int button = 4;

int infraD = 5;
int infraE = 6;

int ib1 = 8;
int ia1 = 9;
int ib2 = 10;
int ia2 = 11;

void direcao(int comando)
{
  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if (comando == 1) {
    inPin1 = HIGH;
    inPin2 = LOW;
  }

  digitalWrite(ib2, inPin2);
  digitalWrite(ia2 , inPin1);
  digitalWrite(ib1, inPin2);
  digitalWrite(ia1 , inPin1);

}



void stopp() {
  digitalWrite(ib2, LOW);
  digitalWrite(ia2 , LOW);
  digitalWrite(ib1, LOW);
  digitalWrite(ia1 , LOW);
}

void direita()
{
  digitalWrite(ib1, HIGH);
  digitalWrite(ia1 , LOW);
  delay(100);
  digitalWrite(ib2, LOW);
  digitalWrite(ia2 , LOW);

}

void esquerda()
{
  digitalWrite(ib2, HIGH);
  digitalWrite(ia2 , LOW);
  delay(100);
  digitalWrite(ib1, LOW);
  digitalWrite(ia1 , LOW);

}


void setup() {
  pinMode (button, INPUT);
  pinMode (infraD, INPUT);
  pinMode (infraE, INPUT);
  pinMode(ib2, OUTPUT);
  pinMode(ia2 , OUTPUT);
  pinMode(ib1, OUTPUT);
  pinMode(ia1 , OUTPUT);


}

void loop() {
  int estado;
  estado = digitalRead(button);
  while (estado == 1) {

    if (digitalRead(infraD) == 0 and digitalRead(infraE) == 0) {
      direcao (2);
    }
    if (digitalRead(infraD) == 1 and digitalRead(infraE) == 0) {
      stopp();
      delay(200);
      direita();
    }
    if (digitalRead(infraD) == 0 and digitalRead(infraE) == 1) {
      stopp();
      delay(200);
      esquerda();
    }


  }

}
