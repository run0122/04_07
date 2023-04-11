// 1. Digital

void setup() {
  Serial.begin(9600); /* PC모니터로 결과를 쉽게 확인하기위해
                          시리얼 통신을 정의해 줍니다.
                       */

  pinMode(2, INPUT);  // 8번 핀으로 데이터를 값을 받습니다.
}

void loop() {

  /*조건문인 IF문을 사용하여 빛이 차단되면 
  "CDS OFF"문구가 출력 됩니다.
*/
  if (digitalRead(2) == HIGH) {

    Serial.println("CDS off");  // 빛이차단되면 출력됩니다
  }

  delay(500);
}

// 2. Analog

// void setup() {
//   Serial.begin(9600); /* PC모니터로 결과를 쉽게 확인하기위해
//                           시리얼 통신을 정의해 줍니다.
// */
// }

// void loop() {
//   Serial.println(analogRead(A1));//조도센서의 감지되는 광량을 출력합니다.
//   delay(500);
// }