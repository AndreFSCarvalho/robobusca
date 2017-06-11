#include <PS2X_lib.h>
#include <Servo.h>

#define pinoPan A3
#define pinoTilt A2
#define ponteA 2
#define ponteB 3
#define ponteC 4
#define ponteD 5


PS2X ps2x;
Servo pan;
Servo tilt;

int error = 0;
byte type = 0;
byte vibrate = 0;
int posPan;
int posTilt;
int posPanFis = 133;
int posTiltFis = 82;
int direcaoX;
int direcaoY;



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

void futuro() {
  if (ps2x.ButtonPressed(PSB_RED))
    Serial.println("circulo foi pressionado");

  if (ps2x.ButtonPressed(PSB_PINK))
    Serial.println("quadrado foi pressionado");

  if (ps2x.ButtonPressed(PSB_BLUE))
    Serial.println("x foi pressionado");

  if (ps2x.ButtonPressed(PSB_GREEN))
    Serial.println("triangulo foi pressionado");
}

void setup() {

  Serial.begin(57600);
  error = ps2x.config_gamepad(13, 11, 10, 12, true, true);
  type = ps2x.readType();

  pan.attach(pinoPan);
  tilt.attach(pinoTilt);
  pan.write (posPanFis);
  tilt.write (posTiltFis);

  pinMode(ponteA, OUTPUT);
  pinMode(ponteB, OUTPUT);
  pinMode(ponteC, OUTPUT);
  pinMode(ponteD, OUTPUT);

}

void loop() {

  if (error == 1) {
    return;
  } else {

    ps2x.read_gamepad(false, vibrate);

    posPan = (ps2x.Analog(PSS_LX));
    posTilt = (ps2x.Analog(PSS_LY));

    posPan =  map (posPan, 0, 255, 180, 85 );
    posTilt = map (posTilt, 0, 255, 5, 160);

    if (posPan > posPanFis) posPanFis++;
    if (posPan < posPanFis) posPanFis--;
    pan.write (posPanFis);
    Serial.print(posPanFis);
    Serial.print(",");

    if (posTilt > posTiltFis) posTiltFis++;
    if (posTilt < posTiltFis) posTiltFis--;
    tilt.write (posTiltFis);
    Serial.print(posTiltFis);
    Serial.print(",");

    direcaoY = (ps2x.Analog(PSS_RY));
    direcaoX = (ps2x.Analog(PSS_RX));
    Serial.print(direcaoY);
    Serial.print(",");
    Serial.println(direcaoX);



    if ((85 < direcaoX < 170) && (direcaoY > 170)) {
      Serial.println("tras");
      tras();
    }else if ((85 < direcaoX < 170) && (direcaoY < 85 )) {
      Serial.println("frente");
      frente();
    }else if ((direcaoX > 170) && (85 < direcaoY < 170)) {
      Serial.println("direita");
      direita();
    }else if ((direcaoX < 85) && (85 < direcaoY < 170)) {
      Serial.println("esquerda");
      esquerda();
    }else{
      Serial.println("parar");
      parar();
    }
  }
  delay(50);
}

