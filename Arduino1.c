#include <Wire.h>
#include <LiquidCrystal.h>


LiquidCrystal lcd(12,11,10,9,8,7);
LiquidCrystal lcd2(6,5,4,3,2,A0);
void setup() {
  Wire.begin();
  Serial.begin(9600); 
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd2.begin(16,2);
  lcd2.setCursor(0,0);
  pinMode(A1,OUTPUT);
 
}
int n=0;


void loop(){


    Wire.requestFrom(2,1); //슬레이브(2)에 1byte 요청 
    while (Wire.available()) {
    char c = Wire.read(); 
    Serial.println(c);
     if(c=='r')    //초음파 센서 동작 인지 시
    {
      lcd2.clear();
      lcd2.print("Put Password");
    }
    if(c=='t')      //초음파 센서 미 작동 시
    {
      lcd2.clear();
      lcd2.print("No motion");
    }
     
    
}
  
  Wire.requestFrom(1,1);
  while (Wire.available()) {
    char c = Wire.read(); 
    Serial.println(c);
     if(c=='q')              //password 정상 입력 시
    {
      lcd.clear();
      lcd.print("open"); 
    }
    if(c=='w')               //password 오류 시
    {
      lcd.clear();
      lcd.print("Wrong password");
      n++;
      if(n==3)               //password 3회 오류 시
      {
        lcd.clear();
        lcd.print("Do not try");
        Serial.write('c');   //마스터 2로 데이터 전송
      }
    }
  }
  Wire.requestFrom(3,2);  //요청 데이터 확장으로 b로인한 m 무시 해결
  while (Wire.available()) {
    char c = Wire.read(); 
    Serial.println(c);
     if(c=='a')           //압력 센서 값 300 이상 시
    {
      lcd2.setCursor(0,1);
      lcd2.print("warning");
    }
    if(c=='b')            //압력 센서 값 300 미만 시
    {
      lcd2.setCursor(0,1);
      lcd2.print("NONE");  
    }
    if(c=='m')            //기울기 센서 값 인지 시
    {
     Serial.write('n'); //도난 알림 문구
    }
   }
   if(Serial.available())  //금고 모터 동작 과정
  {
    char data=Serial.read();  //시리얼 데이터 대기
    Serial.print(data);
    if(data=='u')             //master2 스위치 on
      analogWrite(A1,255);    //dc모터 동작
    else
      analogWrite(A1,0);
    
  }
 
}
