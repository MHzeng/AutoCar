#include"const.h"

void motor_pidController(MOTOR *motor)  //电机1pid控制 输入期望速度与当前速度返回控制量
{
  float Kp=10;
  float Ti=10;
  float Td=100;
  motor->eI=motor->target-motor->velocity;
  float T=PERIOD;
  float q0=Kp*(1+T/Ti+Td/(T));
  float q1=-Kp*(1+2*Td/(T));
  float q2=Kp*Td/(T);
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
