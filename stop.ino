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
  int time2=45;
  int time3=20;
  int time4=20;
  int time5=30;
  int time6=70;
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
  if(cnt>=stopcnt+time1+time2+1&&cnt<=stopcnt+time1+time2+time3)
  {
    motor1.target=0;
    motor2.target=0;
  }
  if(cnt>=stopcnt+time1+time2+time3+1&&cnt<=stopcnt+time1+time2+time3+time4)
  {
    motor1.target=-V;
    motor2.target=-V;
  }
  if(cnt>=stopcnt+time1+time2+time3+time4+1)
  {
    motor1.target=0;
    motor2.target=0;
  }
  if(cnt==stopcnt+time1+time2+time3+time4+time5)
  {
    servo1.write(55);
  }
  if(cnt==stopcnt+time1+time2+time3+time4+time5+time6)
  {
    servo2.write(90);  
  }

}