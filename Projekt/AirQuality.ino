//-------------------------------//
//WPU Projekt von Aaron und David//
//-------------------------------//


void SetupAirQuality(int Pin) {
  pinMode(Pin, INPUT);
}

String GetAirQuality() {
  AirQualityData = analogRead(Pin);

  if (AirQualityData < 80) {
    return "Extrem schlecht";
  } else if (AirQualityData < 150) {
    return "Sehr schlecht";
  } else if (AirQualityData < 220) {
    return "Schlecht";
  } else if (AirQualityData < 300) {
    return "Mittel";
  } else if (AirQualityData < 380) {
    return "Gut";
  } else {
    return "Sehr gut";
  }
}