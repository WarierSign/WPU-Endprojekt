void Lueftersystem() {
  if(temperatur >= Lueftertemp) {
    Luefterstatus = true;
  } else {
    Luefterstatus = false;
  }



  if(Luefterstatus == true) {
    Serial.print("Lüfter aktiv");
    digitalWrite(Luefter, HIGH);
  }
  else {
    Serial.print("Lüfter deaktiv");
    digitalWrite(Luefter, LOW);
  }
}