#include"const.h"

void motor_pidController(MOTOR *motor)  //电机1pid控制 输入期望速度与当前速度返回控制量
{
  float Kp=7;
  float Ti=40;
  float Td=100;
  motor->eI=motor->target-motor->velocity;
  float T=PERIOD;
  float q0=Kp*(1+T/Ti+Td/T);
  float q1=-Kp*(1+2*Td/T);
  float q2=Kp*Td/T;
  motor->u=motor->u+q0*motor->eI+q1*motor->eII+q2*motor->eIII;
  motor->eIII=motor->eII;
  motor->eII=motor->eI;
  if(motor->u>=255)
  {
    motor->u=255;    
  }
  if(motor->u<=-255)
  {
    motor->u=-255;  
  }
  motor->output=motor->u;
  
}
void track_pidController2()//寻线的pid控制
{
  float Kp=1;
  float Ti=500;
  float Td=0;
  float T=PERIOD;
  float q0=Kp*(1+T/Ti+Td/T);
  float q1=-Kp*(1+2*Td/T);
  float q2=Kp*Td/T;
  track.u=track.u+q0*track.eI+q1*track.eII+q2*track.eIII;
  track.eIII=track.eII;
  track.eII=track.eI;

  track.output=track.u;
  
}