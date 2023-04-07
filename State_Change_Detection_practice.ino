#include <Servo.h>

const int buttonPin = 7;
const int ledPin1 = 12;
const int ledPin2 = 11;
const int ledPin3 = 10;
const int analogPin = A0;
const int servoPin = 6;

int buttonPushCounter = 0;
int buttonState = 0;
int lastButtonState = 0;

Servo myservo;

int val;
int pos;
int trigger = 0;

void goBack(){
  for (pos = val; pos >= 0; pos--) {
    myservo.write(pos);
    delay(15);
  }
}
void goFront(){
  for (pos = 0; pos <= val; pos++) {
    myservo.write(pos);
    delay(15);
  }
}

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  myservo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      Serial.println("off");
    }
    delay(50);
  }
  lastButtonState = buttonState;

  if (buttonPushCounter % 3 == 0) {             // Servo 수동 작동
    val = analogRead(analogPin);
    val = map(val, 0, 1023, 0, 180);
    myservo.write(val);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    trigger = 1;
  } else if (buttonPushCounter % 3 == 1) {      // Servo를 0으로
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    if(trigger == 1){
      goBack();
      trigger = 0;
    }
  } else if (buttonPushCounter % 3 == 2) {      // Servo를 기존 위치로
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);
    if(trigger == 0){
      goFront();
      trigger = 1;
    }
  }
}
