#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define TOUCH_PIN 2
#define LED_PIN 7
#define BUZZER_PIN 8

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

bool ledState = false;
bool lastTouchState = LOW;
int touchCount = 0;

void updateDisplay() {
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 5);

  if (ledState) {
    display.println("LED ON");
  } else {
    display.println("LED OFF");
  }

  display.setTextSize(1);
  display.setCursor(0, 40);
  display.print("Touches: ");
  display.println(touchCount);

  display.display();
}

void beep() {
  digitalWrite(BUZZER_PIN, HIGH);
  delay(100);
  digitalWrite(BUZZER_PIN, LOW);
}

void setup() {
  pinMode(TOUCH_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }

  display.clearDisplay();
  display.display();

  updateDisplay();
}

void loop() {
  bool touchState = digitalRead(TOUCH_PIN);

  // Detect a new touch
  if (touchState == HIGH && lastTouchState == LOW) {

    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);

    touchCount++;

    beep();

    updateDisplay();

    delay(200); // debounce
  }

  lastTouchState = touchState;
}