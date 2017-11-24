/*
           1 engine
             =-=
              |
              |
             / \
           /     \
         =-=     =-=
      2 engine   3 engine
*/

#include <Wire.h>

byte encoder1PinA = 53;
byte encoder1PinB = 52;
byte encoder2PinA = 51;
byte encoder2PinB = 50;
byte encoder3PinA = 49;
byte encoder3PinB = 48;

byte pwmEngine1Fovard = 3;
byte pwmEngine1Back   = 4;
byte pwmEngine2Fovard = 5;
byte pwmEngine2Back   = 6;
byte pwmEngine3Fovard = 5;
byte pwmEngine3Back   = 6;

int motor1Count = 0;
int motor2Count = 0;
int motor3Count = 0;

int prmEngine1 = 0;
int prmEngine2 = 0;
int prmEngine3 = 0;

const float s_PI       = 3.14159265359;
const float s_L        = 0.125;     //Distance from robot center to whell center in m;
const float s_RW       = 80;        //Radius of the wheels in mm.
const float s_GEAR     = 16;        //gear.
const float s_sqrt3of2 = sqrt(3)/2; //sqrt(3)/2
const float s_PRM = 19.1;           //(60 * GEAR) / (2 * PI * RW );

/*
 * vars after calculate
 */
int velocity = 0; // velocity of robot
int omega1 = 0;
int omega2 = 0;
int omega3 = 0;

/*
 * input vars from raspberry pi
 */
int inTime = 0;
int radiusOfCircle = 0;


void setup()
{
  Wire.begin(8);                //join i2c bus with adress #8
  Wire.onReceive(receiveEvent); //register event
  
  /*
     all inputs(encoders) -> A & B channels
  */
  pinMode(encoder1PinA, INPUT);
  pinMode(encoder1PinB, INPUT);
  pinMode(encoder2PinA, INPUT);
  pinMode(encoder2PinB, INPUT);
  pinMode(encoder3PinA, INPUT);
  pinMode(encoder3PinB, INPUT);
  attachInterrupt(encoder1PinA, motor1interruptA, CHANGE);
  attachInterrupt(encoder1PinB, motor1interruptB, CHANGE);
  attachInterrupt(encoder2PinA, motor2interruptA, CHANGE);
  attachInterrupt(encoder2PinB, motor2interruptB, CHANGE);
  attachInterrupt(encoder3PinA, motor3interruptA, CHANGE);
  attachInterrupt(encoder3PinB, motor3interruptB, CHANGE);


  /*
     all outputs(PWM)
  */
  pinMode(pwmEngine1Fovard, OUTPUT);
  pinMode(pwmEngine1Back  , OUTPUT);
  pinMode(pwmEngine2Fovard, OUTPUT);
  pinMode(pwmEngine2Back  , OUTPUT);
  pinMode(pwmEngine3Fovard, OUTPUT);
  pinMode(pwmEngine3Back  , OUTPUT);
  analogWrite(pwmEngine1Fovard, 0);
  analogWrite(pwmEngine1Back  , 0);
  analogWrite(pwmEngine2Fovard, 0);
  analogWrite(pwmEngine2Back  , 0);
  analogWrite(pwmEngine3Fovard, 0);
  analogWrite(pwmEngine3Back  , 0);

}

void loop()
{

}

void receiveEvent(int howMany)
{
  while(1 < Wire.available())
  {
    //http://forum.arduino.cc/index.php?topic=48477.0
  }
}


void motor1interruptA()
{
  if (digitalRead(encoder1PinA) != digitalRead(encoder1PinB))
  {
    motor1Count--;
  }
  else
  {
    motor1Count++;
  }
}

void motor1interruptB()
{
  if (digitalRead(encoder1PinA) != digitalRead(encoder1PinB))
  {
    motor1Count++;
  }
  else
  {
    motor1Count--;
  }
}

void motor2interruptA()
{
  if (digitalRead(encoder2PinA) != digitalRead(encoder2PinB))
  {
    motor2Count--;
  }
  else
  {
    motor2Count++;
  }
}

void motor2interruptB()
{
  if (digitalRead(encoder2PinA) != digitalRead(encoder2PinB))
  {
    motor2Count++;
  }
  else
  {
    motor2Count--;
  }
}

void motor3interruptA()
{
  if (digitalRead(encoder3PinA) != digitalRead(encoder3PinB))
  {
    motor3Count--;
  }
  else
  {
    motor3Count++;
  }
}

void motor3interruptB()
{
  if (digitalRead(encoder3PinA) != digitalRead(encoder3PinB))
  {
    motor3Count++;
  }
  else
  {
    motor3Count--;
  }
}

bool whichDirectonHbridgeA() //less then zero -> false
{
  bool whichDirection = prmEngine1 < 0 ? false : true;
  return whichDirection;
}

bool whichDirectonHbridgeB() //less then zero -> false
{
  bool whichDirection = prmEngine2 < 0 ? false : true;
  return whichDirection;
}

bool whichDirectonHbridgeC() //less then zero -> false
{
  bool whichDirection = prmEngine3 < 0 ? false : true;
  return whichDirection;
}

void setVelocity(float radius, float inTime)  //Set velocity of driving
{
  velocity = ((2 * s_PI * radius) / inTime);
}

void setOmega1(float inTime) //set omega1
{
  omega1 = ((-velocity * s_sqrt3of2 + ((2 * s_PI * s_L) / inTime) / s_RW) * s_PRM);
}

void setOmega2(float inTime) //set omega2
{
  omega2 = ((((2 * s_PI * s_L) / (inTime)) / s_RW) * s_PRM);
}

void setOmega3(float inTime) //set omega3
{
  omega3 = ((velocity * s_sqrt3of2 + ((2 * s_PI * s_L) / inTime) / s_RW) * s_PRM);
}
