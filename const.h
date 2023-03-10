#ifndef _CONST_H_
#define _CONST_H_

#define ENCODER_A1 2 //电机 1 
#define ENCODER_B1 5
#define ENCODER_A2 3 //电机 2
#define ENCODER_B2 4
#define PWM1 9 //电机1PWM输出
#define PWM2 10 //电机2PWM输出
#define L1 42 //左红外
#define L2 40
#define L3 38
#define L4 36
#define R1 46 //右红外
#define R2 48
#define R3 50
#define R4 52
#define M 44 //中红外
#define INL1a 23  //正反转控制
#define INL1b 22
#define INL2a 25
#define INL2b 24


#define PERIOD 10 //控制周期
#define V 15 //参考速度

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

#endif