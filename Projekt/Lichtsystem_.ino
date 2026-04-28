void Lichtsystem() {
  tasterstatus = digitalRead(Lichtschalter);

  if(tasterstatus == HIGH) {
    if(Lichtstatus == true) {
      digitalWrite(Licht, LOW);
      Lichtstatus = false;
    } else {
      digitalWrite(Licht, HIGH);
      Lichtstatus = true;
    }
  }
}