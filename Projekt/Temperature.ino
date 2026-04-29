//-------------------------------//
//WPU Projekt von Aaron und David//
//-------------------------------//


#include <Thermistor.h>
#include <NTC_Thermistor.h>


int pin;
int Pin;
int Referenzwiderstand = 10000;
int Nominalwiderstand = 10000;
int Nominaltemperatur = 25;
int Bwert = 3950;
Thermistor thermistor;

void SetupTemperature(int pin) {
  Pin = pin;
  pinMode(Pin, INPUT);
}

int GetTemp() {
  const double temperature = thermistor->readCelsius();
  return(temperature);
}