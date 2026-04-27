bool on = false;

void ToogleLight(int pin) {
  digitalWrite(pin, !on);
  on = !on;
}