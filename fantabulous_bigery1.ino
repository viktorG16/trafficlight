
const int segmentPins[7] = {2, 3, 4, 5, 6, 7, 8};

const int redLED = 9;
const int yellowLED = 10;
const int greenLED = 11;


const byte digits[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, 
  {0, 1, 1, 0, 0, 0, 0}, 
  {1, 1, 0, 1, 1, 0, 1}, 
  {1, 1, 1, 1, 0, 0, 1}, 
  {0, 1, 1, 0, 0, 1, 1}, 
  {1, 0, 1, 1, 0, 1, 1}, 
  {1, 0, 1, 1, 1, 1, 1}, 
  {1, 1, 1, 0, 0, 0, 0}, 
  {1, 1, 1, 1, 1, 1, 1}, 
  {1, 1, 1, 1, 0, 1, 1}  
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
  countdown(2); 
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
