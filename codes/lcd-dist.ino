
#include <LiquidCrystal.h>
#include <NewPing.h>

const int UltrasonicPin = 6;
const int MaxDistance = 200;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

NewPing sonar(UltrasonicPin, UltrasonicPin, MaxDistance);

void setup() {
    Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Distancia");
}

void loop() {

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(sonar.ping_cm());
    lcd.setCursor(10, 1);
  // print the number of seconds since reset:
  lcd.print("cm");
}