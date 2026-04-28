//-------------------------------//
//WPU Projekt von Aaron und David//
//-------------------------------//


void setup() {
  Serial.begin(9600);

  //LCD Libary initalisieren
  lcd.init();
  lcd.backlight();

  //Pins festlegen
  pinMode(Piezzo, OUTPUT);
  pinMode(Lichtschalter, INPUT_PULLUP);
  pinMode(Licht, OUTPUT);
  pinMode(Luefter, OUTPUT);


}

void loop() {

  Temperatursystem();

  Lichtsystem();

  Feuerarlam();

  Lueftersystem();


  //LCD
  lcd.setCursor(0,0);
  lcd.print(temperatur);

  delay(500); //Hat Arduino crashes verursacht
}