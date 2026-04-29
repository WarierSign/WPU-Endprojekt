//-------------------------------//
//WPU Projekt von Aaron und David//
//-------------------------------//


#include <SoftwareSerial.h>


SoftwareSerial bleSerial(RXDPin, TXDPin);
int BleOutput;
int BleInput;

void BluetoothInit() {
  while (!Serial) {}
  bleSerial.begin(9600);
}

void BluetoothGet() {
  BluetoothCheck();
  BleOutput = bleSerial.read();
}

void BluetoothSend() {
  BluetoothCheck();
  bleSerial.write(BleInput);
}

void BluetoothCheck() {
  if (bleSerial.available()) {

  }
  else {
    Serial.println("Bluetooth Gerät nicht verbunden");
    Serial.println("Warten auf Koppelung");
    delay(1000);
    Serial.print("Nach Gerät suchen");


    BleChecking:
    if (bleSerial.available()) {
      return;
    }
    else {
      Serial.print(".")
      delay(1000);
      goto BleChecking;
  }
}
