#include"const.h"

int t1 = V, t2 = V;



void getEncoder1(void)  //电机1编码器读取
{
  if(digitalRead(ENCODER_A1)==LOW)
  {
    if(digitalRead(ENCODER_B1)==LOW)
    {
      motor1.encoderVal++;
    }
    else
    {
      motor1.encoderVal--;
    }
  }
  else
  {
    if(digitalRead(ENCODER_B1)==LOW)
    {
      motor1.encoderVal--;
    }
    else
    {
      motor1.encoderVal++;
    }
  }
}

void getEncoder2(void)//电机2编码器读取
{
  if(digitalRead(ENCODER_A2)==LOW)
  {
    if(digitalRead(ENCODER_B2)==HIGH)
    {
      motor2.encoderVal++;
    }
    else
    {
      motor2.encoderVal--;

    }
  }
  else
  {
    if(digitalRead(ENCODER_B2)==HIGH)
    {
      motor2.encoderVal--;
    }
    else
    {
      motor2.encoderVal++;
    }
  }
}

void control(void) //读取红外探测器 获得期望速度
{
cnt++;
if(cnt==100)
{
  servo2.write(90);
}
if(cnt==200)
{
  servo1.write(55);
}
if(cnt==300)
{
  servo2.write(135);
}
if(cnt==400)
{
  servo1.write(120);
}
if(cnt>=500)
{
// if(detectstatu==1)
// {
//   ultrasonic();
// }
if(stopstatu==1)
{
  End();
}
if(stopstatu==0&&avoidstatu==0)
{
  Track();
  motor1.target = motor1.target * 0.6 + t1 * 0.4;
  motor2.target = motor2.target * 0.6 + t2 * 0.4;
}
// if(avoidstatu==1)
// {
//   Avoid();
// }
  
// motor1.target=0.5*V;
// motor2.target=0.5*V;



t1=motor1.target;
t2=motor2.target;


//通过编码器值计算电当前速度，并将编码器值归零
  motor1.velocity=(motor1.encoderVal/780.0)*3.1415*2.0*(1000/PERIOD);

  motor1.encoderVal=0; 
  motor2.velocity=(motor2.encoderVal/780.0)*3.1415*2.0*(1000/PERIOD);

  motor2.encoderVal=0;

//通过期望速度与当前速度计算控制量，并通过控制量调整电机转速
  motor_pidController(&motor1);
  // Serial.println(output);
  if(motor1.output>0)
  {
    digitalWrite(INL1a,LOW);
    digitalWrite(INL1b,HIGH);
    analogWrite(PWM1,motor1.output);  
  }
  else
  {
    digitalWrite(INL1a,HIGH);
    digitalWrite(INL1b,LOW);
    analogWrite(PWM1,abs(motor1.output)); 
  }
  motor_pidController(&motor2);
  if(motor2.output>0)
  {
    digitalWrite(INL2a,LOW);
    digitalWrite(INL2b,HIGH);
    analogWrite(PWM2,motor2.output);  
  }
  else
  {
    digitalWrite(INL2a,HIGH);
    digitalWrite(INL2b,LOW);
    analogWrite(PWM2,abs(motor2.output));    
  }
}
}

