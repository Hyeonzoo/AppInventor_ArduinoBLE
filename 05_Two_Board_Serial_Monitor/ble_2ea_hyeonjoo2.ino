#include <SoftwareSerial.h>

SoftwareSerial BTSerial(4, 5);   
String dev = "HJ02";

void setup() {  
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if (BTSerial.available()){
    char data = BTSerial.read();
    Serial.println(data);
    
    if(data == '1'){
      digitalWrite(13, HIGH);

      String toSend = dev + "_ON";
      Serial.print(toSend);
      BTSerial.print(toSend);
    }

    else if(data == '0'){
      digitalWrite(13, LOW);
      
      String toSend = dev + "_OFF";
      Serial.print(toSend);
      BTSerial.print(toSend);
    }
  }
}
