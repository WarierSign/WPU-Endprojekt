//Libaries
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Sensorpins
int Temperatursensor = A0;
int Lichtschalter = 2;
int Licht = 3;
int Piezzo = 6;
int Luefter = 5;

//Sensorwerte
int RohOuputTemperatur = 0;
int temperatur;
int tasterstatus = 0;

//Zeiten
int TemperaturUpdateDelay = 500;

//Andere Variablien
LiquidCrystal_I2C lcd(0x27, 16, 2);
int Feuertemp = 25;
int Lueftertemp = 20;
bool Lichtstatus;
bool Feuer = false; //gerade kein Feuer hoffentlich
bool Luefterstatus = false;

void setup() {
  Serial.begin(9600);

  //Monitor starten
  lcd.init();
  lcd.backlight();

  //Pins festlegen
  pinMode(Piezzo, OUTPUT);
  pinMode(Lichtschalter, INPUT_PULLUP);
  pinMode(Licht, OUTPUT);
  pinMode(Luefter, OUTPUT);

  //Variablen festlegen
  Lichtstatus = false; //Licht ist gerade aus;
}

void loop() {

  Temperatursystem();

  Lichtsystem();

  Feuerarlam();

  Lueftersystem();


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
    Serial.print("Feuer an");
  }
  else {
    Serial.print("Feuer aus");
    digitalWrite(Piezzo, LOW);
  }
}

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
