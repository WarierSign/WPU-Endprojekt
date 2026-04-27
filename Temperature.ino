#include <Thermistor.h>
#include <NTC_Thermistor.h>

int Pin;
int Referenzwiderstand = 10000;
int Nominalwiderstand = 10000;
int Nominaltemperatur = 25;
int Bwert = 3950;
Thermistor thermistor;

void SetupTemperature(int pin) {
  Pin = pin;
}

int GetTemp() {
  const double temperature = thermistor->readCelsius();
  return(temperature);
}