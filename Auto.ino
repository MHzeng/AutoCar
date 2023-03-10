#include<MsTimer2.h>
#include"const.h"
//引脚定义
//电机1为左电机，电机2为右电机
// #define ENCODER_A1 2 //电机 1 
// #define ENCODER_B1 5
// #define ENCODER_A2 3 //电机 2
// #define ENCODER_B2 4
// #define PWM1 9 //电机1PWM输出
// #define PWM2 10 //电机2PWM输出
// #define L1 42 //左红外
// #define L2 40
// #define L3 38
// #define L4 36
// #define R1 46 //右红外
// #define R2 48
// #define R3 50
// #define R4 52
// #define M 44 //中红外
// #define INL1a 23  //正反转控制
// #define INL1b 22
// #define INL2a 25
// #define INL2b 24


//pid 控制量
// float u1=0;
// float u2=0;
// //pid 偏移量
// float e1I;
// float e1II;
// float e1III;
// float e2I;
// float e2II;
// float e2III;


// void getEncoder1(void)  //电机1编码器读取
// {
//   if(digitalRead(ENCODER_A1)==LOW)
//   {
//     if(digitalRead(ENCODER_B1)==LOW)
//     {
//       encoderVal1++;
//     }
//     else
//     {
//       encoderVal1--;
//     }
//   }
//   else
//   {
//     if(digitalRead(ENCODER_B1)==LOW)
//     {
//       encoderVal1--;
//     }
//     else
//     {
//       encoderVal1++;
//     }
//   }
// }

// void getEncoder2(void)//电机2编码器读取
// {
//   if(digitalRead(ENCODER_A2)==LOW)
//   {
//     if(digitalRead(ENCODER_B2)==HIGH)
//     {
//       encoderVal2++;
//     }
//     else
//     {
//       encoderVal2--;

//     }
//   }
//   else
//   {
//     if(digitalRead(ENCODER_B2)==HIGH)
//     {
//       encoderVal2--;
//     }
//     else
//     {
//       encoderVal2++;
//     }
//   }
// }


// int pidController1(float targetVelocity,float currentVelocity)  //电机1pid控制 输入期望速度与当前速度返回控制量
// {
//   float output;
//   e1I=targetVelocity-currentVelocity;
//   float T=PERIOD;
//   float q0=Kp*(1+T/Ti+Td/T);
//   float q1=-Kp*(1+2*Td/T);
//   float q2=Kp*Td/T;
//   u1=u1+q0*e1I+q1*e1II+q2*e1III;
//   e1III=e1II;
//   e1II=e1I;
//   if(u1>=255)
//   {
//     u1=255;    
//   }
//   if(u1<=-255)
//   {
//     u1=-255;  
//   }
//   output=u1;
//   return (int)output;
// }
// int pidController2(float targetVelocity,float currentVelocity)//电机2pid控制 输入期望速度与当前速度返回控制量
// {
//   float output;
//   e2I=targetVelocity-currentVelocity;
//   float T=PERIOD;
//   float q0=Kp*(1+T/Ti+Td/T);
//   float q1=-Kp*(1+2*Td/T);
//   float q2=Kp*Td/T;
//   u2=u2+q0*e2I+q1*e2II+q2*e2III;
//   e2III=e2II;
//   e2II=e2I;
//   if(u2>=255)
//   {
//     u2=255;    
//   }
//   if(u2<=-255)
//   {
//     u2=-255;  
//   }
//   output=u2;
//   return (int)output;
// }



// void control(void) //读取红外探测器 获得期望速度
// {
//   int target1 = V, target2 = V;
//  if (digitalRead(M) == HIGH)
//  {
//  target1 = V;
//  target2 = V;
//  }
//  if (digitalRead(L1) == HIGH) //低左转
//  {
//  target1 = V * 0.6;
//  target2 = V * 0.95;
//  }
//  if (digitalRead(R1) == HIGH) //低右转
//  {
//  target1 = V * 0.95;
//  target2 = V * 0.6;
//  }
//  if (digitalRead(L2) == HIGH) //中左转
// {
// target1 = V * 0.2;
// target2 = V * 0.8;
// }
// if (digitalRead(R2) == HIGH) //中右转
// {
// target1 = V * 0.8;
// target2 = V * 0.2;
// }
// if (digitalRead(L3) == HIGH) //high左转
// {
// target1 = 0.1*V;
// target2 = V * 0.7;
// }
// if (digitalRead(R3) == HIGH) //high右转
// {
// target1 = V * 0.7;
// target2 = 0.1*V;
// }
//  if (digitalRead(L4) == HIGH) //直角左转
//  {
//  target1 = V * 0;
//  target2 = V * 0.5;
//  }
//  if (digitalRead(R4) == HIGH) //直角右转
//  {
//  target1 = V * 0.5;
//  target2 = V * 0;
//  }


// target1 = target1 * 0.7 + t1 * 0.3;
// target2 = target2 * 0.7 + t2 * 0.3;

// t1 = target1;
// t2 = target2;

// //通过编码器值计算电当前速度，并将编码器值归零
//   velocity1=(encoderVal1/780.0)*3.1415*2.0*(1000/PERIOD);
//   encoderVal1=0; 
//   velocity2=(encoderVal2/780.0)*3.1415*2.0*(1000/PERIOD);
//   encoderVal2=0;

// //通过期望速度与当前速度计算控制量，并通过控制量调整电机转速
//   int output=pidController1(target1,velocity1);
//   // Serial.println(output);
//   if(output>0)
//   {
//     digitalWrite(INL1a,LOW);
//     digitalWrite(INL1b,HIGH);
//     analogWrite(PWM1,output);  
//   }
//   else
//   {
//     digitalWrite(INL1a,HIGH);
//     digitalWrite(INL1b,LOW);
//     analogWrite(PWM1,abs(output)); 
//   }
//   int output1=pidController2(target2,velocity2);
//   if(output1>0)
//   {
//     digitalWrite(INL2a,LOW);
//     digitalWrite(INL2b,HIGH);
//     analogWrite(PWM2,output1);  
//   }
//   else
//   {
//     digitalWrite(INL2a,HIGH);
//     digitalWrite(INL2b,LOW);
//     analogWrite(PWM2,abs(output1));    
//   }
// }

MOTOR motor1,motor2;

void setup() {
//初始化串口通讯
  Serial.begin(9600);
//定时触发函数
TCCR1B = TCCR1B & B11111000 | B00000001;
MsTimer2::set(PERIOD, control);
MsTimer2::start();
//初始化编码器引脚，添加触发函数
pinMode(ENCODER_A1, INPUT);
pinMode(ENCODER_B1, INPUT);
pinMode(ENCODER_A2, INPUT);
pinMode(ENCODER_B2, INPUT);
attachInterrupt(0, getEncoder1, CHANGE);
attachInterrupt(1, getEncoder2, CHANGE);

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
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print(motor1.velocity); Serial.print("\t");
Serial.println(motor2.velocity);
// Serial.print("\t");
//Serial.print("\n");
//Serial.println(u2);
//Serial.println(u2);
}
