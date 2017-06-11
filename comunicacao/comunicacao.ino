#include <PS2X_lib.h>

PS2X ps2x;

int error = 0;
byte type = 0;
byte vibrate = 0;

void setup() {

  Serial.begin(57600);
  error = ps2x.config_gamepad(13, 11, 10, 12, true, true);
  type = ps2x.readType();

}

void loop() {

  if (error == 1) {
    return;
  } else {

    ps2x.read_gamepad(false, vibrate);

    Serial.print(ps2x.Analog(PSS_LY), DEC);
    Serial.print(",");
    Serial.print(ps2x.Analog(PSS_LX), DEC);
    Serial.print(",");
    Serial.print(ps2x.Analog(PSS_RY), DEC);
    Serial.print(",");
    Serial.println(ps2x.Analog(PSS_RX), DEC);

    if (ps2x.ButtonPressed(PSB_RED))
      Serial.println("circulo foi pressionado");

    if (ps2x.ButtonPressed(PSB_PINK))
      Serial.println("quadrado foi pressionado");

    if (ps2x.ButtonPressed(PSB_BLUE))
      Serial.println("x foi pressionado");

    if (ps2x.ButtonPressed(PSB_GREEN))
      Serial.println("triangulo foi pressionado");

  }

  delay(50);
}
