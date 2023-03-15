#include<MsTimer2.h>
#include"const.h"

typedef struct 
{
  float eI;
  float eII;
  float eIII;
  volatile long encoderVal; 
  float velocity;
  float target;
  float u;
  int output;
} MOTOR;

volatile long cnt=0;

int stopstatu=0;
int avoidstatu=0;
int detectstatu=1;

long stopcnt;
long detectcnt;

int lastpin;

int cm=100;

MOTOR motor1,motor2;



void setup() {
//初始化串口通讯
  Serial.begin(9600);
//定时触发函数
TCCR1B = TCCR1B & B11111000 | B00000001;

//初始化编码器引脚，添加触发函数
pinMode(ENCODER_A1, INPUT);
pinMode(ENCODER_B1, INPUT);
pinMode(ENCODER_A2, INPUT);
pinMode(ENCODER_B2, INPUT);

pinMode(PWM1, OUTPUT);
pinMode(PWM2, OUTPUT);

pinMode(R1, INPUT);
pinMode(R2, INPUT);
pinMode(R3, INPUT);
pinMode(R4, INPUT);
pinMode(L1, INPUT);
pinMode(L2, INPUT);
pinMode(L3, INPUT);
pinMode(L4, INPUT);
pinMode(M, INPUT);

pinMode(INL1a, OUTPUT);
pinMode(INL1b, OUTPUT);
pinMode(INL2a, OUTPUT);
pinMode(INL2b, OUTPUT);

pinMode(TrigPin, OUTPUT);
pinMode(EchoPin, INPUT);

servo1.attach(PIN_SERVO1);
servo2.attach(PIN_SERVO2);

attachInterrupt(0, getEncoder1, CHANGE);
attachInterrupt(1, getEncoder2, CHANGE);

motor1.target=V;
motor2.target=V;

MsTimer2::set(PERIOD, control);
MsTimer2::start();
}

void loop() {
  // put your main code here, to run repeatedly:
//  Serial.print(motor1.target); Serial.print("\t");
//  Serial.println(motor2.target);
// Serial.print("\t");
//Serial.print("\n");
//Serial.println(u2);
//Serial.println(u2);
}
