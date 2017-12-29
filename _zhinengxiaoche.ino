#include <Microduino_Motor.h>
#include <Microduino_MotorPlus.h>const int EchoPin = 2; //超声波信号输入
const int TrigPin = 3; //超声波控制信号输出
#define motor_pin1A 6
#define motor_pin1B 8
#define motor_pin2A 5
#define motor_pin2B 7
uint8_t publicsped =255;
float distance=100;
Motor MotorLeft(motor_pin2A, motor_pin2B);
Motor MotorRight(motor_pin1A, motor_pin1B);
void setup(){  Serial.begin(115200);  //初始化  
pinMode(TrigPin,OUTPUT);  
pinMode(EchoPin,INPUT);  
pinMode(motor_pin1A,OUTPUT);  
pinMode(motor_pin1B,OUTPUT);  
pinMode(motor_pin2A,OUTPUT);  
pinMode(motor_pin2B,OUTPUT);  
digitalWrite(motor_pin1A,HIGH);  
digitalWrite(motor_pin2B,HIGH);  
MotorLeft.begin();   //电机MotorLeft初始化  
MotorRight.begin();  //电机MotorLeft初始化  }
void towards() //前进
{  MotorLeft.setSpeed(publicsped);  
MotorRight.setSpeed(-publicsped);}
void Left()//左转
{  MotorLeft.setSpeed(publicsped / 2); 
MotorRight.setSpeed(-publicsped);}
void Left(int left, int right)
{  MotorLeft.setSpeed(left);  
MotorRight.setSpeed(-right);}
void loop()
{  Serial.println("Start");  // 产生一个10us的高脉冲去触发
TrigPin  digitalWrite(TrigPin, LOW); 
delayMicroseconds(2);  
digitalWrite(TrigPin, HIGH);  
delayMicroseconds(10);  
digitalWrite(TrigPin, LOW);  // 检测脉冲宽度，并计算出距离  
distance = pulseIn(EchoPin, HIGH) / 58.00;  
Serial.print(distance);  
Serial.print("cm "); //不换行  
//delay(10);  
//由于模拟口不够
  if (distance > 50)    
  towards(); 
  else  
  {if(distance<50&&distance>25)      
  Left();     
  else    
  Left(200,100);}       
  // delay(500);}
