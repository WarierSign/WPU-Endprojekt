#include <SoftwareSerial.h>
SoftwareSerial bleSerial(2, 3);
int BleData;
int BleInput;

void BluetoothInit () {
  while (!Serial) {}
  bleSerial.begin(9600);
}

void BluetoothRead () {
  if (bleSerial.available()) {
    BleData = bleSerial.read();
  }
  else {
    Serial.print("BluetoothFail ErrorCode:BleRead")
  }
}

void BluetoothWrite () {
  if (bleSerial.available()) {
    bleSerial.write(BleInput);
  }
  else {
    Serial.print("BluetoothFail ErrorCode:BleWrite")
  }
}

void BluetoothCheck () {
  
}
