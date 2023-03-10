#include"const.h"



void Track()
{
  int i,j;
  int pin[8];
  int pin_statu[8];
  pin[0]=L4,pin[1]=L3,pin[2]=L2,pin[3]=L1,pin[4]=M,pin[5]=R1,pin[6]=R2,pin[7]=R3,pin[8]=R4;
  for(i=0;i<9;i++)
  {
    pin_statu[i]=0;
  }
  for (i=0 ; i< 9 ; i++)
    if ( digitalRead(pin[i] == HIGH)) pin_statu[i] = 1;
  if (pin_statu[0] && pin_statu[8]) ;
  if (pin_statu[6] && pin_statu[7] && pin_statu[8] )
  {
    motor1.target=0.5*V;
    motor2.target=-0.5*V;
    delay(200);
  }
  if(pin_statu[0] && pin_statu[1] && pin_statu[2])
  {
    motor1.target=-0.5*V;
    motor2.target=0.5*V;
    delay(200);
  }
  do{
    int i=-1, j = 9;
    i++, j--;
    if(pin_statu[i]) track.eI = i-4;
    if(pin_statu[j]) track.eI = j-4;
  }while(!pin_statu[i] && !pin_statu[j] && i<j);
  track_pidController2();
  motor1.target=track.output*V*0.1;
  motor2.target=-track.output*V*0.1;
}