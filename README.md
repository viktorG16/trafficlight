# 🚦 Traffic Light with Countdown – Arduino UNO + 5161AS 7-Segment Display

## ✍️ Project Goal

Create a simulation of a traffic light system using three LEDs (red, yellow, green) and a 5161AS 7-segment display to show countdown timers for each traffic light phase.

## 🔧 Required Components

| Component                      | Quantity |
| ----------------------------- | -------- |
| Arduino UNO                   | 1        |
| 7-Segment Display (5161AS)    | 1        |
| Resistors (220Ω – 330Ω)       | 10       |
| LEDs: Red, Yellow, Green      | 1 each   |
| Breadboard                    | 1        |
| Jumper Wires                  | ~20      |
| USB Cable                     | 1        |

## ⚖️ Wiring Diagram

### 7-Segment Display (5161AS – Common Cathode)

| Segment | Display Pin | Arduino Pin |
| ------- | ----------- | ----------- |
| A       | 7           | D2          |
| B       | 6           | D3          |
| C       | 4           | D4          |
| D       | 2           | D5          |
| E       | 1           | D6          |
| F       | 9           | D7          |
| G       | 10          | D8          |
| COM     | 3, 8        | GND         |

**Note:** Each segment pin should go through a 220Ω resistor.

### LED Connections

| Color  | Arduino Pin | Resistor |
| ------ | ----------- | -------- |
| Red    | D9          | 220Ω     |
| Yellow | D10         | 220Ω     |
| Green  | D11         | 220Ω     |

## 💻 Example Arduino Code

```cpp
const int segmentPins[7] = {2, 3, 4, 5, 6, 7, 8};
const int redLED = 9;
const int yellowLED = 10;
const int greenLED = 11;

const byte digits[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

void setup() {
  for (int i = 0; i < 7; i++) pinMode(segmentPins[i], OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop() {
  digitalWrite(greenLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
  countdown(9);
  digitalWrite(greenLED, LOW);

  digitalWrite(yellowLED, HIGH);
  countdown(3);
  digitalWrite(yellowLED, LOW);

  digitalWrite(redLED, HIGH);
  countdown(9);
  digitalWrite(redLED, LOW);
}

void countdown(int start) {
  for (int i = start; i >= 0; i--) {
    displayDigit(i);
    delay(1000);
  }
}

void displayDigit(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digits[num][i]);
  }
}
```

## 🔍 Expected Output

- The **green LED** turns on for 9 seconds. The 7-segment display shows a countdown from 9 to 0.
- The **yellow LED** turns on for 3 seconds with a countdown.
- The **red LED** turns on for 9 seconds with a countdown.
- This cycle repeats continuously.
