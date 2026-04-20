//Libaries
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Sensorpins
int Temperatursensor = A0;
int Lichtschalter = 2;
int Licht = 3;
int Piezzo = 6;

//Sensorwerte
int RohOuputTemperatur = 0;
int temperatur;
int tasterstatus = 0;

//Zeiten
int TemperaturUpdateDelay = 500;

//Andere Variablien
LiquidCrystal_I2C lcd(0x27, 16, 2);
int Feuertemp = 25;
bool Lichtstatus;
bool Feuer = false; //gerade kein Feuer hoffentlich

void setup() {
  Serial.begin(9600);

  //Monitor starten
  lcd.init();
  lcd.backlight();

  //Pins festlegen
  pinMode(Piezzo, OUTPUT);
  pinMode(Lichtschalter, INPUT_PULLUP);
  pinMode(Licht, OUTPUT);

  //Variablen festlegen
  Lichtstatus = false; //Licht ist gerade aus;
}

void loop() {

  Temperatursystem();

  Lichtsystem();

  Feuerarlam();


  //Monitor
  lcd.setCursor(0,0);
  lcd.print(temperatur);
}

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

void Temperatursystem() {
  RohOuputTemperatur = analogRead(Temperatursensor);
  temperatur = map(RohOuputTemperatur, 0, 410, -50, 150);
  delay(TemperaturUpdateDelay);
}

void Feuerarlam() {
  if(temperatur >= Feuertemp) {
    Feuer = true;
  } else {
    Feuer = false;
  }

  Serial.print(Feuer);

  if(Feuer == true) {
    digitalWrite(Piezzo, HIGH);
    delay(500);
    digitalWrite(Piezzo, LOW);
  }
}
