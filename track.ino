#include"const.h"



void Track()
{
  // motor1.target=V;
  // motor2.target=V;
  int i,j;
  int pin[9];
  int pin_statu[9];
  pin[0]=L4;pin[1]=L3;pin[2]=L2;pin[3]=L1;pin[4]=M;pin[5]=R1;pin[6]=R2;pin[7]=R3;pin[8]=R4;
  for(i=0;i<9;i++)
  {
    pin_statu[i]=0;
  }
  for (i=0 ; i< 9 ; i++)
  {
    if ( digitalRead(pin[i]) == HIGH) pin_statu[i] = 1;
  }
  if (pin_statu[0] && pin_statu[8]) ;
  if (pin_statu[6] && pin_statu[7] && pin_statu[8] )
  {
    motor1.target=0.5*V;
    motor2.target=-0.5*V;
  }
  if(pin_statu[0] && pin_statu[1] && pin_statu[2])

  {
    motor1.target=-0.5*V;
    motor2.target=0.5*V;
  }


  if (pin_statu[4])
  {
  track.eI=0;
  }
  if (pin_statu[3]) //低左转
  {
  track.eI=-1;
  }
  if (pin_statu[5]) //低右转
  {
  track.eI=1;
  }
  if (pin_statu[2]) //中左转
  {
  track.eI=-2;
  }
  if (pin_statu[6]) //中右转
  {
  track.eI=2;
  }
  if (pin_statu[1]) //high左转
  {
  track.eI=-3;
  }
  if (pin_statu[7]) //high右转
  {
  track.eI=3;
  }
  if (pin_statu[0]) //直角左转
  {
  track.eI=-4;
  }
  if (pin_statu[8]) //直角右转
  {
  track.eI=4;
  }


  track_pidController2();
  motor1.target=V+track.output*V*0.1;
  motor2.target=V-track.output*V*0.1;
  //Serial.println(track.output);
  //Serial.print("\t");
  //Serial.println(motor2.target);

}