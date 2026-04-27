int Sensorwert;
int Pin

void SetupAirQuality(int pin) {
  pinMode(Pin, INPUT);
}

String GetAirQuality() {
  Sensorwert = analogRead(Pin);

  if (Sensorwert < 80) {
    return "Extrem schlecht";
  } else if (Sensorwert < 150) {
    return "Sehr schlecht";
  } else if (Sensorwert < 220) {
    return "Schlecht";
  } else if (Sensorwert < 300) {
    return "Mittel";
  } else if (Sensorwert < 380) {
    return "Gut";
  } else {
    return "Sehr gut";
  }
}