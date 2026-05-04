//-------------------------------//
//WPU Projekt von Aaron und David//
//-------------------------------//

void SetupMonitor() {
  lcd.init();
  lcd.backlight();
}

void WriteOnMonitor(String Message, int line) {
  lcd.setCursor(0, line);
  lcd.print(Message);
}

void ErraseMonitor() {
  lcd.clear();
}