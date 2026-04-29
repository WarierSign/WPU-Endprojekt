//-------------------------------//
//WPU Projekt von Aaron und David//
//-------------------------------//


//Sensorpins
int Temperatursensor = A0;
int Lichtschalter = 2;
int Licht = 3;
int Piezzo = 6;
int Luefter = 5;

//Bluetooth Modul Pins
int RXDPin = 2;
int TXDPin = 3;





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

