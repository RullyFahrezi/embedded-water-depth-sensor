# 1 "C:\\Users\\Acer Gk\\Documents\\Data Kuliah\\GITHUB REPO\\small project\\code\\code.ino"

# 3 "C:\\Users\\Acer Gk\\Documents\\Data Kuliah\\GITHUB REPO\\small project\\code\\code.ino" 2
LiquidCrystal lcd(11, 10, 9, 8, 7, 6);
# 5 "C:\\Users\\Acer Gk\\Documents\\Data Kuliah\\GITHUB REPO\\small project\\code\\code.ino" 2



NewPing ultrasonic(13, 12);






void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("AYO!!!");
  lcd.setCursor(0, 1);
  lcd.print("Mengukur Kedalaman");
  delay(500);

  lcd.setCursor(0, 0);
  lcd.print("Ukur");
  lcd.setCursor(0, 1);
  lcd.print("Sensor Air");
  Serial.begin(9600);
  pinMode(2, 0x1);
  pinMode(3, 0x1);
  pinMode(4, 0x1);
  pinMode(5, 0x1);
  delay(600);
  lcd.clear();
}

void loop() {
  delay(1000);
  int distance = ultrasonic.ping_cm();
  Serial.print("Hasil Sensor: ");
  Serial.print(distance);
  Serial.print("cm");
  Serial.print(" ");

  lcd.setCursor(0, 0);
  lcd.print("Ketinggian Air");
  lcd.setCursor(0, 1);
  lcd.print("Tinggi: ");
  lcd.print(distance);
  lcd.setCursor(14, 1);
  lcd.print("cm");

  if ((distance <= 100) && (distance > 0)) {
    digitalWrite(2, 0x1);
    digitalWrite(3, 0x0);
    digitalWrite(4, 0x0);
    digitalWrite(5, 0x0);
    delay(200);
  }
  else if ((distance <= 150) && (distance > 100)) {
    digitalWrite(3, 0x1);
    digitalWrite(4, 0x0);
    digitalWrite(5, 0x0);
    digitalWrite(2, 0x0);
    delay(200);
  }
  else if ((distance <= 200) && (distance > 150)) {
    digitalWrite(4, 0x1);
    digitalWrite(3, 0x0);
    digitalWrite(5, 0x0);
    digitalWrite(2, 0x0);
    delay(200);
  }
  else if (distance > 300) {
    digitalWrite(5, 0x1);
    digitalWrite(4, 0x0);
    digitalWrite(3, 0x0);
    digitalWrite(2, 0x0);
    delay(200);
  }
}
