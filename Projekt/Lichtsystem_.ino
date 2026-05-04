//-------------------------------//
//WPU Projekt von Aaron und David//
//-------------------------------//

void Lichtsystem() {
  tasterstatus = digitalRead(Lichtschalter);

  if(tasterstatus == HIGH) {
    ToogleLight(Licht); //nutzt direkt die Klasse vom HouseLight anstatt selber eine neue Sache zu machen
  }
}
