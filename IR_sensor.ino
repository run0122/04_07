int sensor = 3;              // 라인트레이서 센서을 9번 핀에 연결
int Buzzer = 9;              // Buzzer를 7번 핀에 연결

void setup() {
  Serial.begin(9600);
  pinMode(Buzzer, OUTPUT);   // Buzzer는 '출력'
  pinMode(sensor, INPUT);    // 라인트레이서 센서는 '입력'
}
void loop() {
  int val = digitalRead(sensor);  // 센서 값을 읽어와서
  Serial.println(val);
  if (val == HIGH) {         // 검정색 주행선 위에 있으면
    noTone(Buzzer);               // Buzzer에서 소리가 나지 않는다
    delay(100);
  } else {                   // 검정색 주행선을 벗어나면
    tone(Buzzer, 220);            // Buzzer에서 소리가 난다
    delay(100);
  }
}
