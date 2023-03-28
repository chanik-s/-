#include <Wire.h>
#define M 7
int inches = 0;

long readUItrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin,LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin,LOW);
  pinMode(echoPin,INPUT);
  return pulseIn(echoPin,HIGH);
  
}


void setup() {
  Wire.begin(2); //슬레이브 주소                
  Wire.onRequest(requestEvent); //요청시 requestEvent함수 호출
  Serial.begin(9600);
  pinMode(6,OUTPUT); //RED
  pinMode(5,OUTPUT); //GREEN
  
}

void loop() {
  
}      

void requestEvent() { 
  
    int cm=0.01723*readUItrasonicDistance(M,M);
    inches=(cm/2.54);
    
    
    Serial.print(inches);
    Serial.print("in, ");
    Serial.print(cm);
    Serial.println("CM");
   
  
    Serial.println(cm);
    if(cm>3&&cm<333)    //초음파 센서 동작 인지 시
    {
      Wire.write('r');   //마스터 1로 데이터 전송
      digitalWrite(6,HIGH);  //led red HIGH
      digitalWrite(5,LOW);
      
      
    }
    else  //동작 미 인지시
    { Wire.write('t');  //마스터 1로 데이터 전송  
     digitalWrite(5,HIGH);  //led green HIGH
     digitalWrite(6,LOW);
      
    }
  
  
       
}
