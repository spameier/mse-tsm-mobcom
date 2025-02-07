#include "Adafruit_TinyUSB.h"; // Fix https://github.com/adafruit/Adafruit_nRF52_Arduino/issues/653

int buttonPin = 7; // onboard button
int ledPin = 4; // onboard, blue LED

int s = 0; // state

int pressed(int value) {
  //return value == HIGH; // standard, active high
  return value == LOW; // inverted, active low
}

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(115200);
}

void loop() {
  int b = digitalRead(buttonPin);
  Serial.println(b);
  if (s == 0 && pressed(b)) {
    s = 1;
    digitalWrite(ledPin, HIGH); // on
  } else if (s == 1 && !pressed(b)) {
    s = 2;
  } else if (s == 2 && pressed(b)) {
    s = 3;
    digitalWrite(ledPin, LOW); // off
  } else if (s == 3 && !pressed(b)) {
    s = 0;
  }
  delay(1);
}
