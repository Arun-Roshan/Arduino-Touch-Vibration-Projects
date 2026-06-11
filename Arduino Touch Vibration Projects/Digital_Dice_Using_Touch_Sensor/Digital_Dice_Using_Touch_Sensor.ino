#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define TOUCH_PIN 2
#define BUZZER_PIN 8

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

bool lastTouch = LOW;

int diceValue = 1;
int lastRolls[3] = {0, 0, 0};

void beep()
{
  tone(BUZZER_PIN, 1500);
  delay(100);
  noTone(BUZZER_PIN);
}

void drawDice(int value)
{
  int x = 5;
  int y = 12;
  int s = 40;

  display.drawRect(x, y, s, s, SSD1306_WHITE);

  switch (value)
  {
    case 1:
      display.fillCircle(x+20, y+20, 3, SSD1306_WHITE);
      break;

    case 2:
      display.fillCircle(x+10, y+10, 3, SSD1306_WHITE);
      display.fillCircle(x+30, y+30, 3, SSD1306_WHITE);
      break;

    case 3:
      display.fillCircle(x+10, y+10, 3, SSD1306_WHITE);
      display.fillCircle(x+20, y+20, 3, SSD1306_WHITE);
      display.fillCircle(x+30, y+30, 3, SSD1306_WHITE);
      break;

    case 4:
      display.fillCircle(x+10, y+10, 3, SSD1306_WHITE);
      display.fillCircle(x+30, y+10, 3, SSD1306_WHITE);
      display.fillCircle(x+10, y+30, 3, SSD1306_WHITE);
      display.fillCircle(x+30, y+30, 3, SSD1306_WHITE);
      break;

    case 5:
      display.fillCircle(x+10, y+10, 3, SSD1306_WHITE);
      display.fillCircle(x+30, y+10, 3, SSD1306_WHITE);
      display.fillCircle(x+20, y+20, 3, SSD1306_WHITE);
      display.fillCircle(x+10, y+30, 3, SSD1306_WHITE);
      display.fillCircle(x+30, y+30, 3, SSD1306_WHITE);
      break;

    case 6:
      display.fillCircle(x+10, y+10, 3, SSD1306_WHITE);
      display.fillCircle(x+30, y+10, 3, SSD1306_WHITE);
      display.fillCircle(x+10, y+20, 3, SSD1306_WHITE);
      display.fillCircle(x+30, y+20, 3, SSD1306_WHITE);
      display.fillCircle(x+10, y+30, 3, SSD1306_WHITE);
      display.fillCircle(x+30, y+30, 3, SSD1306_WHITE);
      break;
  }
}

void showDiceScreen(int value)
{
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(30, 0);
  display.println("DIGITAL DICE");

  drawDice(value);

  display.setTextSize(2);
  display.setCursor(60, 20);
  display.print(value);

  display.setTextSize(1);
  display.setCursor(55, 45);
  display.print("Result:");
  display.print(value);

  display.setCursor(0, 56);
  display.print("Last:");
  display.print(lastRolls[0]);
  display.print(" ");
  display.print(lastRolls[1]);
  display.print(" ");
  display.print(lastRolls[2]);

  display.display();
}

void rollingAnimation()
{
  for (int i = 0; i < 15; i++)
  {
    int tempValue = random(1, 7);

    display.clearDisplay();

    display.setTextSize(1);
    display.setCursor(30, 0);
    display.println("DIGITAL DICE");

    drawDice(tempValue);

    display.setTextSize(2);
    display.setCursor(60, 20);
    display.print(tempValue);

    display.setTextSize(1);
    display.setCursor(55, 45);
    display.println("Rolling...");

    display.display();

    delay(120);
  }
}

void setup()
{
  pinMode(TOUCH_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  randomSeed(analogRead(A0));

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  showDiceScreen(diceValue);
}

void loop()
{
  bool touchState = digitalRead(TOUCH_PIN);

  if (touchState == HIGH && lastTouch == LOW)
  {
    rollingAnimation();

    diceValue = random(1, 7);

    lastRolls[2] = lastRolls[1];
    lastRolls[1] = lastRolls[0];
    lastRolls[0] = diceValue;

    beep();

    showDiceScreen(diceValue);

    delay(300);
  }

  lastTouch = touchState;
}