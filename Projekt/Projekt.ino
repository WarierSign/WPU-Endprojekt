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

  //Pins festlegen
  pinMode(Piezzo, OUTPUT);
  pinMode(Lichtschalter, INPUT_PULLUP);
  pinMode(Luefter, OUTPUT);

  //setup Klasssen
  SetupMonitor();
  BluetoothInit();
  //SetupAirQuality(//weiß net welchen pin);
  SetupHouseLight(Licht);
  SetupTemperature(Temperatursensor);

  //einmal clearen weil why not
  ErraseMonitor();
}

void loop() {

  Temperatursystem();

  Lichtsystem();

  Feuerarlam();

  Lueftersystem();


  //LCD
  WriteOnMonitor(String(temperatur));

  delay(500); //Hat Arduino crashes verursacht
}

