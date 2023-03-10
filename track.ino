#include"const.h"

struct
{
  float eI;
  float eII;
  float eIII;
  float target;
  float u;
  float output;
} track;

void Track()
{
  int i;
  int pin[8];
  pin[0]=L4,pin[1]=L3,pin[2]=L2,pin[3]=L1,pin[4]=M,pin[5]=R1,pin[6]=R2,pin[7]=R3,pin[8]=R4;
  for(i=0;i<9;i++)
  {
    a[i]=0;
  }
  for (i=0 ; i< 9 ; i++)
    if ( digitalRead(pin[i] == HIGH)) a[i] = 1;
  if (a[0] && a[8]) ;
  if (a[6] && a[7] && a[8] )
  {
    motor1.target=0.5V;
    motor2.target=-0.5V;
    delay(200);
  }
  if(a[0] && a[1] && a[2])
  {
    motor1.target=-0.5V;
    motor2.target=0.5V;
    delay(200);
  }
  do{
    int i=-1, j = 9;
    i++, j--;
    if(a[i]) track.eI = i-4;
    if(a[j]) track.eI = j-4;
  }while(!a[i] && !a[j] && i<j)
  track_pidController2();
  motor1.target=track.output*V*0.1;
  motor2.target=-track.output*V*0.1;
}