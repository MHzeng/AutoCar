#include"const.h"

void Stop(void)
{
  stopcnt=cnt;
  motor1.target=0;
  motor2.target=0;
  stopstatu=1;
}

void End(void)
{
  
  int time1=20;
  int time2=35;
  int time3=30;
  int time4=70;
  if(cnt<=stopcnt+time1)
  {
    motor1.target=0;
    motor2.target=0;
  }
  if(cnt>=stopcnt+time1&&cnt<=stopcnt+time1+time2)
  {
    motor1.target=V;
    motor2.target=-V;
  }
  if(cnt>=stopcnt+time1+time2+1)
  {
    motor1.target=0;
    motor2.target=0;
  }
  if(cnt==stopcnt+time1+time2+time3)
  {
    servo1.write(55);
  }
  if(cnt==stopcnt+time1+time2+time3+time4)
  {
    servo2.write(90);  
  }

}