#include <LiquidCrystal.h>

#define LDR_PIN A0
#define SOIL_PIN A1
#define BUZZER_PIN 6

#define LCD_VO_PIN 9
#define LCD_CONTRAST 80

#define LDR_MIN_RAW 0
#define LDR_MAX_RAW 78

#define SOIL_DRY_RAW 1023
#define SOIL_WET_RAW 385

#define MIN_LIGHT_THRESHOLD 20
#define MIN_WATER_THRESHOLD 40

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);

  pinMode(LCD_VO_PIN, OUTPUT);
  analogWrite(LCD_VO_PIN, LCD_CONTRAST);

  lcd.begin(16, 2);
  pinMode(BUZZER_PIN, OUTPUT);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("System Starting..");
  delay(2000);
}

void loop() {
  int lightValue = analogRead(LDR_PIN);
  int soilValue = analogRead(SOIL_PIN);

  int lightPercentage = map(lightValue, LDR_MIN_RAW, LDR_MAX_RAW, 0, 100);
  lightPercentage = constrain(lightPercentage, 0, 100);

  int soilPercentage = map(soilValue, SOIL_DRY_RAW, SOIL_WET_RAW, 0, 100);
  soilPercentage = constrain(soilPercentage, 0, 100);

  lcd.clear();

  bool triggerBuzzer = false;

  lcd.setCursor(0, 0);
  if (lightPercentage < MIN_LIGHT_THRESHOLD) {
    lcd.print("NEED SUN!");
    triggerBuzzer = true;
  } else {
    lcd.print("Light: ");
    lcd.print(lightPercentage);
    lcd.print("%");
  }

  lcd.setCursor(0, 1);
  if (soilPercentage < MIN_WATER_THRESHOLD) {
    lcd.print("NEED WATER!");
    triggerBuzzer = true;
  } else {
    lcd.print("Water: ");
    lcd.print(soilPercentage);
    lcd.print("%");
  }

  if (triggerBuzzer == true) {
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  Serial.print("Light: ");
  Serial.print(lightPercentage);
  Serial.print("% | Water: ");
  Serial.print(soilPercentage);
  Serial.println("%");

  delay(1000);
}
