//-------------------------------//
//WPU Projekt von Aaron und David//
//-------------------------------//


//Sensorwerte
int RohOuputTemperatur = 0;
int temperatur;
int tasterstatus = 0;
int AirQualityData;

//Zeiten
int TemperaturUpdateDelay = 500;

//Andere Variablien
LiquidCrystal_I2C lcd(0x27, 16, 2);
int Feuertemp = 25;
int Lueftertemp = 20;
bool Lichtstatus = false; //Hinzufügen von "= false"
bool Feuer = false; //gerade kein Feuer hoffentlich
bool Luefterstatus = false;
