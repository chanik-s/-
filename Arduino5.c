#include <LiquidCrystal.h>

LiquidCrystal lcd3(12,11,10,9,8,7);
void setup()
{
  Serial.begin(9600); 
  lcd3.begin(16,2);
  lcd3.setCursor(0,0);
  pinMode(3,INPUT);  //스위치
  pinMode(6,OUTPUT); //피에조
}

void loop()
{
  if(Serial.available())  //시리얼 통신 시
  {
    char data=Serial.read();
    if(data=='c')  //마스터 1로부터 압력센서 관련 데이터 읽은 경우
    {
      lcd3.write("Under Attack");  
      digitalWrite(6,HIGH);
    }
    if(data=='n')  //마스터 1로부터 기울기 센서 관련 데이터 읽은 경우
    {
      lcd3.setCursor(0,1);
      lcd3.write("Robbed");
    }
  }
  if(digitalRead(3))  //스위치 값 입력 시( DC 모터 동작 )
    {
      Serial.write('u');  //시리얼 통신 통해 master 1로 데이터 전송
      delay(1000);
    }
    
}

