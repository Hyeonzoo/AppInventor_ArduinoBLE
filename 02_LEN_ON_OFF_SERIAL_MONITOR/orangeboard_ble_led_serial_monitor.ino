// 참고 ex-blink, ex-SerialEvent
// 오렌지보드BLE의 시리얼 모니터를 앱인벤터에서 보여주는 코드입니다.

#include <SoftwareSerial.h>

SoftwareSerial BTSerial(4, 5); //RX, TX

int cnt = -1; // 카운트를 하는 cnt변수 -1로 초기화

void setup() {
  Serial.begin(9600); //시리얼 모니터
  BTSerial.begin(9600); //블루투스 시리얼
  pinMode(13, OUTPUT);
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:

  // 블루투스 통신
  while (BTSerial.available()) {
      // get the new byte:
      char btChar = (char)BTSerial.read(); 
      
      if (btChar == 'a' || btChar=='1') {
        cnt = 0;
        digitalWrite(13, HIGH);
      }
      else if (btChar == 'b'  || btChar=='0') {
        cnt = -1;
        digitalWrite(13, LOW);
      }
    }
    
  if(cnt>-1) {
    //String buf = String.format("%d", cnt);
    char buf[10] = {0,};
    sprintf(buf, "Cnt: %d", cnt);
    
    Serial.println(buf);// Serial.write(buf), 블루투스 측 내용을 시리얼 모니터에 출력
    BTSerial.println(buf); // BTSerial.write(buf), 시리얼 모니터 내용을 블루투스 측에 write
    
    cnt = cnt +1;
  }
  delay(1000); 
}

// 아두이노
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    
    if (inChar == 'a' || inChar=='0') {
      cnt = 0;
      digitalWrite(13, HIGH);
    }
    else if (inChar == 'b'  || inChar=='1') {
      cnt = -1;
      digitalWrite(13, LOW);
    }
  }
}
