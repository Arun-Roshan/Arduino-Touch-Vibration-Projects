# Arduino-Touch-Vibration-Projects
Arduino Uno projects using Touch Sensors, Vibration Sensors, OLED Displays, LEDs, and Buzzers for security, monitoring, automation, and interactive applications.

## 1. Objective

The objective of this repository is to develop practical Arduino-based interactive and security applications using OLED displays, touch sensors, vibration sensors, LEDs, and buzzers. These projects demonstrate touch-based control systems, digital gaming applications, intrusion detection, security monitoring, alarm systems, event counting, and real-time status display using embedded systems.

---

## 2. Components Used

### Hardware Components

* Arduino Uno
* OLED Display (SSD1306 I2C)
* TTP223 Touch Sensor
* SW-420 Vibration Sensor
* LED
* Active Buzzer Module
* Breadboard
* Jumper Wires
* 220Ω Resistor

### Software Components

* Arduino IDE
* Adafruit SSD1306 Library
* Adafruit GFX Library
* Wire Library

---

## 3. Circuit Diagram

The projects use different combinations of the following modules.

### OLED Display

| OLED Pin | Arduino Uno |
| -------- | ----------- |
| VCC      | 5V          |
| GND      | GND         |
| SDA      | A4          |
| SCL      | A5          |

### Touch Sensor

| Touch Sensor Pin | Arduino Uno  |
| ---------------- | ------------ |
| VCC              | 5V           |
| GND              | GND          |
| OUT              | D2 / D3 / D4 |

### Vibration Sensor

| Vibration Sensor Pin | Arduino Uno |
| -------------------- | ----------- |
| VCC                  | 5V          |
| GND                  | GND         |
| DO                   | D2 / D4     |

### LED

| LED Pin     | Arduino Uno                     |
| ----------- | ------------------------------- |
| Anode (+)   | D6 / D7 (through 220Ω resistor) |
| Cathode (-) | GND                             |

### Buzzer Module

| Buzzer Pin | Arduino Uno |
| ---------- | ----------- |
| S          | D8          |
| VCC        | 5V          |
| GND        | GND         |

---

## 4. Code Explanation

This repository contains the following Arduino projects:

### Touch Controlled Lamp

Uses a touch sensor to toggle an LED ON and OFF. The OLED display shows the current LED status while a buzzer provides feedback whenever a touch is detected.

### Dual Touch LED Controller

Uses two touch sensors to independently control two LEDs. The OLED displays the status of both LEDs, and different buzzer tones indicate which touch sensor was activated.

### Vibration Knock Alarm System

Detects knocks using a vibration sensor and displays the knock count on the OLED. If multiple knocks occur within a specified time period, an alarm is triggered. A touch sensor is used to reset the alarm.

### Touch Vibration Security System

Implements a security alarm system where a touch sensor arms and disarms the system. Vibrations trigger a tamper alarm, while a second touch sensor acts as a secret reset button.

### Digital Dice Using Touch Sensor

Simulates a digital dice using a touch sensor. Touching the sensor generates a random dice value from 1 to 6, displays animated dice graphics on the OLED, and produces a buzzer sound for user feedback.

### Smart Security Monitoring Station

A complete monitoring and security dashboard that supports armed, safe, and alarm states. It tracks movement events, intrusion alerts, security levels, and displays system status in real time on the OLED.

---

## 5. Output Images

### Touch Controlled Lamp

<img width="1600" height="1200" alt="WhatsApp Image 2026-06-11 at 8 13 07 PM (1)" src="https://github.com/user-
attachments/assets/e8999356-c178-41e5-b25f-c9e4df76bef2" />
<img width="1600" height="1200" alt="WhatsApp Image 2026-06-11 at 8 13 07 PM" src="https://github.com/user-attachments/assets/54b53893-e353-48e1-9674-8289a12caeca" />

### Dual Touch LED Controller

<img width="1600" height="1200" alt="WhatsApp Image 2026-06-11 at 8 13 08 PM" src="https://github.com/user-attachments/assets/d2ef4417-a114-42a3-bb5f-889c9bc567d5" />
<img width="1600" height="1200" alt="WhatsApp Image 2026-06-11 at 8 13 07 PM" src="https://github.com/user-attachments/assets/3f63a0ca-f268-4fd6-999f-b3c53a96a109" />


### Vibration Knock Alarm System

<img width="1600" height="1200" alt="WhatsApp Image 2026-06-11 at 8 13 09 PM" src="https://github.com/user-attachments/assets/2f7038c1-e9e3-4a78-a78f-8ae8a6a98e84" />
<img width="1600" height="1200" alt="WhatsApp Image 2026-06-11 at 8 13 08 PM" src="https://github.com/user-attachments/assets/1890fc32-4c9c-4fc1-9dc0-76eb815f5bdb" />


### Touch Vibration Security System

<img width="1600" height="1200" alt="WhatsApp Image 2026-06-11 at 8 13 10 PM" src="https://github.com/user-attachments/assets/dacd2877-8d7e-41e6-911c-d6dcd58bdd36" />
<img width="1600" height="1200" alt="WhatsApp Image 2026-06-11 at 8 13 09 PM" src="https://github.com/user-attachments/assets/90988f50-25a4-4bd6-a087-a3d29407e577" />


### Digital Dice Using Touch Sensor

<img width="1600" height="1200" alt="WhatsApp Image 2026-06-11 at 8 13 09 PM" src="https://github.com/user-attachments/assets/08df0c82-4d7c-4e12-9df6-72b52590917a" />

### Smart Security Monitoring Station

<img width="1600" height="1200" alt="WhatsApp Image 2026-06-11 at 8 13 10 PM (1)" src="https://github.com/user-attachments/assets/c57abba2-4081-4990-8cb7-9ec2d0c11621" />
<img width="1600" height="1200" alt="WhatsApp Image 2026-06-11 at 8 13 10 PM" src="https://github.com/user-attachments/assets/b5af07b8-e9e4-40f3-b1f5-3bcab27c16c8" />

---

## 6. Learning Outcome

After completing these projects, learners will be able to:

* Interface OLED displays with Arduino Uno using I2C communication.
* Work with touch sensors for user input and control applications.
* Detect vibrations and movement using vibration sensors.
* Control LEDs and buzzers through sensor-based interactions.
* Design touch-controlled switching systems.
* Develop digital gaming applications such as a virtual dice.
* Implement intrusion detection and security alarm systems.
* Create real-time monitoring dashboards using OLED displays.
* Develop event counting and alarm notification systems.
* Apply embedded systems concepts to practical security and automation projects.


**Arun Roshan**
