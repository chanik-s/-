#include <Keypad.h>
#include <Wire.h>
#include <Servo.h>

Servo myServo;


const byte rows = 4; //four rows
const byte cols = 4; //four columns

byte rowPins[rows] = {12,11,10,9};
byte colPins[cols] = {8,7,6,5};

char keys[rows][cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

String password="23";
String userInput="";

int count=0;
int n=0;// 입력 시도 횟수

void setup(){
  Serial.begin(9600);
  Wire.begin(1);
  Wire.onRequest(requestEvent); //요청시 requestEvent함수 호출
  Serial.print("PassWord:");
  myServo.attach(3);
  
}

void loop(){
  
  

}
void requestEvent() { //요청 시 수행 함수
   char key = keypad.getKey();
  
  
   if(key!=NO_KEY&&count!=2){ //키 입력이 있고 횟수가 2 미만인 경우
        Serial.print(key); 
        userInput += key;
        count+=1;
     }
   if(count==2){
        count=0;  //카운트 초기화
      if(userInput == password){ //비밀번호를 맞춘 경우
         Serial.println();
         myServo.write(180);     //서보모터로 금고 개폐 동작
         Serial.println("Open");  //개방
         Wire.write('q');         //마스터 1로 데이터 전송
         

         }
       else 
         { 
           Serial.println();
           Serial.println("Wrong password");//틀린 경우의 출력
           Wire.write('w');   //마스터 1로 데이터 전송
           
         
           n++;
               
          if(n==3)  //시도 횟수가 3회인 경우
           {
            
            Serial.println();
            Serial.println("Do not try anymore");  //경고 문구 출력
            
            
          }             
       } userInput="";
      }
       
        
     
  
