//-------------------------------//
//WPU Projekt von Aaron und David//
//-------------------------------//

void Temperatursystem() {
  RohOuputTemperatur = analogRead(Temperatursensor);
  temperatur = map(RohOuputTemperatur, 0, 410, -50, 150);
  delay(TemperaturUpdateDelay);
}
