#include <Wire.h>
int sensor = A2;

void setup(){
  Wire.begin(3);
  pinMode(sensor,INPUT);
  Wire.onRequest(requestEvent); //요청시 requestEvent함수 호출
  Serial.begin(9600);
  pinMode(5,INPUT);
}

void loop(){
}
void requestEvent(){
   int val = analogRead(sensor);//아날로그 센서 값 읽기
  if(val>300) //압력값이 300을 넘어가면
  {      
   
    Wire.write('a');//a 를 송신한다
  }
    else 
    {
      Wire.write('b');//아닐경우 b를 송신한다
    }
  if(digitalRead(5))
  {
    Wire.write('m');   //기울기 값 인지시 마스터 1로 데이터 전송
    
  }
  
  
}
