#include <Arduino.h>
#line 1 "C:\\Users\\Acer Gk\\Documents\\Data Kuliah\\GITHUB REPO\\Water-depth\\code\\main\\main.ino"
#include <LiquidCrystal.h>
LiquidCrystal lcd(11, 10, 9, 8, 7, 6);
#include <NewPing.h> 

#define TRIGGER_PIN 13
#define ECHO_PIN 12
NewPing ultrasonic(TRIGGER_PIN, ECHO_PIN); 

#define ledaman 2
#define led1 3
#define led2 4
#define led3 5

#line 14 "C:\\Users\\Acer Gk\\Documents\\Data Kuliah\\GITHUB REPO\\Water-depth\\code\\main\\main.ino"
void setup();
#line 35 "C:\\Users\\Acer Gk\\Documents\\Data Kuliah\\GITHUB REPO\\Water-depth\\code\\main\\main.ino"
void loop();
#line 14 "C:\\Users\\Acer Gk\\Documents\\Data Kuliah\\GITHUB REPO\\Water-depth\\code\\main\\main.ino"
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
  pinMode(ledaman, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
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
    digitalWrite(ledaman, HIGH); 
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(200);
  }
  else if ((distance <= 150) && (distance > 100)) { 
    digitalWrite(led1, HIGH); 
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(ledaman, LOW);
    delay(200);
  }
  else if ((distance <= 200) && (distance > 150)) { 
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(ledaman, LOW);
    delay(200);
  }
  else if (distance > 300) { 
    digitalWrite(led3, HIGH); 
    digitalWrite(led2, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(ledaman, LOW);
    delay(200);
  }
}

