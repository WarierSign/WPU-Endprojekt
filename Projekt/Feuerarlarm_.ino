void Feuerarlam() {
  if(temperatur >= Feuertemp) {
    Feuer = true;
  } else {
    Feuer = false;
  }

  Serial.print(Feuer);

  if(Feuer == true) {
    digitalWrite(Piezzo, HIGH);
    Serial.print("Feuer an");
  }
  else {
    Serial.print("Feuer aus");
    digitalWrite(Piezzo, LOW);
  }
}