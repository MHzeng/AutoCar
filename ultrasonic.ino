#include"const.h"

void ultrasonic()
{

digitalWrite(TrigPin, LOW); //低高低电平发一个短时间脉冲去 TrigPin
delayMicroseconds(2);
digitalWrite(TrigPin, HIGH);
delayMicroseconds(10);
digitalWrite(TrigPin, LOW);
cm = pulseIn(EchoPin, HIGH) / 58; //将回波时间换算成 cm
cm = (int(cm * 100)) / 100; //保留两位小数
if(cm<=50)
{
  avoidstatu=1;
  detectcnt=cnt;
}
Serial.println(cm);
}

void Avoid(void)
{
  int time1=10;
  int time2=50;
  int time3=20;
  if(cnt<=detectcnt+time1)
  {
    motor1.target=V;
    motor2.target=-V;
  }
  if(cnt>=detectcnt+time1+1&&cnt<=detectcnt+time1+time2)
  {
    motor1.target=V;
    motor2.target=V;
  }
  if(cnt>=detectcnt+time1+time2+1&&cnt<=detectcnt+time1+time2+time3);
  {
    motor1.target=-V;
    motor2.target=V;
  }
  if(cnt>=detectcnt+time1+time2+time3+1)
  {
    motor1.target=V;
    motor2.target=V;
    if(digitalRead(L4)==HIGH)
    {
      motor1.target=V;
      motor2.target=-V;
      avoidstatu=0;
      detectstatu=0;
    }
  }

}