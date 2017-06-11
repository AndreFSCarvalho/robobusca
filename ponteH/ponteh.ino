#define ponteA 2
#define ponteB 3
#define ponteC 4
#define ponteD 5


void tras() {
  digitalWrite(ponteA, LOW);
  digitalWrite(ponteB, HIGH);
  digitalWrite(ponteC, HIGH);
  digitalWrite(ponteD, LOW);
}

void frente() {
  digitalWrite(ponteA, HIGH);
  digitalWrite(ponteB, LOW);
  digitalWrite(ponteC, LOW);
  digitalWrite(ponteD, HIGH);
}


void esquerda() {
  digitalWrite(ponteA, LOW);
  digitalWrite(ponteB, HIGH);
  digitalWrite(ponteC, LOW);
  digitalWrite(ponteD, HIGH);
}


void direita () {
  digitalWrite(ponteA, HIGH);
  digitalWrite(ponteB, LOW);
  digitalWrite(ponteC, HIGH);
  digitalWrite(ponteD, LOW);
}


void parar () {
  digitalWrite(ponteA, LOW);
  digitalWrite(ponteB, LOW);
  digitalWrite(ponteC, LOW);
  digitalWrite(ponteD, LOW);
}

void setup() {
  pinMode(ponteA, OUTPUT);
  pinMode(ponteB, OUTPUT);
  pinMode(ponteC, OUTPUT);
  pinMode(ponteD, OUTPUT);
}


void loop() {


}


