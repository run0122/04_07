const int led[] = { 10, 11, 12 };

const int sensorMin = 0;    // sensor minimum, discovered through experiment
const int sensorMax = 600;  // sensor maximum, discovered through experiment

int lastrange = 0;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  for (int x = 0; x <= 2; x++) {
    pinMode(led[x], OUTPUT);
  }
}

void turnoff() {
  for (int x = 0; x <= 2; x++) {
    digitalWrite(led[x], LOW);
  }
}

void loop() {
  // read the sensor:
  int sensorReading = analogRead(A1);
  // map the sensor range to a range of four options:
  int range = map(sensorReading, sensorMin, sensorMax, 3, 0);

  // do something different depending on the range value:
  switch (range) {
    case 0:  // your hand is on the sensor
      if (lastrange != range) {
        turnoff();
      }
      Serial.println("dark");
      for (int x = 0; x <= 2; x++) {
        digitalWrite(led[x], HIGH);
      }
      break;
    case 1:  // your hand is close to the sensor
      if (lastrange != range) {
        turnoff();
      }
      Serial.println("dim");
      for (int x = 0; x <= 1; x++) {
        digitalWrite(led[x], HIGH);
      }
      break;
    case 2:  // your hand is a few inches from the sensor
      if (lastrange != range) {
        turnoff();
      }
      Serial.println("medium");
      digitalWrite(led[0], HIGH);
      break;
    case 3:  // your hand is nowhere near the sensor
      Serial.println("bright");
      break;
  }
  lastrange = range;
  delay(1);
  // delay in between reads for stability
}
