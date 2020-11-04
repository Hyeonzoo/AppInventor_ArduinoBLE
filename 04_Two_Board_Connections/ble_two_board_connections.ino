// 오렌지 보드 두 개 동일한 코드 사용

#include <SoftwareSerial.h>

SoftwareSerial BTSerial(4, 5);   

void setup() {  
  BTSerial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if (BTSerial.available()){
    char data = BTSerial.read();
    Serial.println(data);
    
    if(data == '1'){
      digitalWrite(13, HIGH);
    }

    else if(data == '0'){
      digitalWrite(13, LOW);
    }
  }
}
