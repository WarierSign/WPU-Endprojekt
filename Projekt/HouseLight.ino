//-------------------------------//
//WPU Projekt von Aaron und David//
//-------------------------------//


bool on = false;

void SetupHouseLight(int pin) {
  pinMode(pin, OUTPUT);
}

void ToogleLight(int pin) {
  digitalWrite(pin, !on);
  on = !on;
}
