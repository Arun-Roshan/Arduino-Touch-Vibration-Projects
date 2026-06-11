#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define VIBRATION_PIN 2
#define ARM_TOUCH_PIN 3
#define RESET_TOUCH_PIN 4
#define BUZZER_PIN 8

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

bool systemArmed = false;
bool alarmActive = false;

bool lastArmTouch = LOW;
bool lastResetTouch = LOW;

unsigned long movementCount = 0;

void updateDisplay()
{
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(15, 0);
  display.println("SECURITY SYSTEM");

  display.setCursor(0, 20);
  display.print("Status: ");
  display.println(systemArmed ? "ARMED" : "DISARMED");

  display.setCursor(0, 40);
  display.print("Movements: ");
  display.println(movementCount);

  display.display();
}

void showAlarmScreen()
{
  display.clearDisplay();

  display.setTextSize(2);
  display.setCursor(5, 5);
  display.println("WARNING!");

  display.setTextSize(1);
  display.setCursor(5, 35);
  display.println("TAMPER DETECTED!");

  display.display();
}

void showResetMessage()
{
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(20, 25);
  display.println("SYSTEM RESET");

  display.display();

  delay(1000);
}

void setup()
{
  pinMode(VIBRATION_PIN, INPUT);
  pinMode(ARM_TOUCH_PIN, INPUT);
  pinMode(RESET_TOUCH_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(BUZZER_PIN, LOW);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    while (true);
  }

  updateDisplay();
}

void loop()
{
  bool armTouch = digitalRead(ARM_TOUCH_PIN);
  bool resetTouch = digitalRead(RESET_TOUCH_PIN);

  // Arm / Disarm System
  if (armTouch == HIGH && lastArmTouch == LOW)
  {
    systemArmed = !systemArmed;

    if (!systemArmed)
    {
      alarmActive = false;
      noTone(BUZZER_PIN);
    }

    updateDisplay();
    delay(250);
  }

  // Vibration Detection
  if (digitalRead(VIBRATION_PIN) == HIGH)
  {
    if (systemArmed)
    {
      alarmActive = true;
    }
    else
    {
      movementCount++;
      updateDisplay();
      delay(250);
    }
  }

  // Alarm Mode
  if (alarmActive)
  {
    tone(BUZZER_PIN, 1500);
    showAlarmScreen();
  }

  // Secret Reset Button
  if (resetTouch == HIGH && lastResetTouch == LOW)
  {
    alarmActive = false;
    movementCount = 0;

    noTone(BUZZER_PIN);

    showResetMessage();
    updateDisplay();

    delay(250);
  }

  lastArmTouch = armTouch;
  lastResetTouch = resetTouch;
}