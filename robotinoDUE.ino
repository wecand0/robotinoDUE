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

/*
 * pins in arduino due
 */
byte m_encoder1PinA     = 53;
byte m_encoder1PinB     = 52;
byte m_encoder2PinA     = 51;
byte m_encoder2PinB     = 50;
byte m_encoder3PinA     = 49;
byte m_encoder3PinB     = 48;
byte m_pwmEngine1Fovard = 3;
byte m_pwmEngine1Back   = 4;
byte m_pwmEngine2Fovard = 5;
byte m_pwmEngine2Back   = 6;
byte m_pwmEngine3Fovard = 5;
byte m_pwmEngine3Back   = 6;



class Robotino
{
  public:
    Robotino();
    void Motor1InterruptA();
    void Motor1InterruptB();
    void Motor2InterruptA();
    void Motor2InterruptB();
    void Motor3InterruptA();
    void Motor3InterruptB();
    bool WhichDirectonHbridge1();
    bool WhichDirectonHbridge2();
    bool WhichDirectonHbridge3();
    void SetVelocity(float radius, float inTime);  //Set velocity of driving
    void SetOmega1(float inTime);                  //set omega1
    void SetOmega2(float inTime);                  //set omega1
    void SetOmega3(float inTime);                  //set omega1

  private:
    int m_motor1Count;
    int m_motor2Count;
    int m_motor3Count;

    int m_prmEngine1;
    int m_prmEngine2;
    int m_prmEngine3;

    const float s_PI       = 3.14159265359;
    const float s_L        = 0.125;     //Distance from robot center to whell center in m;
    const float s_RW       = 80;        //Radius of the wheels in mm.
    const float s_GEAR     = 16;        //gear.
    const float s_sqrt3of2 = sqrt(3) / 2; //sqrt(3)/2
    const float s_PRM      = 19.1;           //(60 * GEAR) / (2 * PI * RW );

    /*
       vars after calculate
    */
    int m_velocity; // velocity of robot
    int m_omega1;
    int m_omega2;
    int m_omega3;

};

Robotino robotino; // global object, cause void setup & loop    :(

Robotino::Robotino() //constructor set all vars to zero
{
  analogWrite(m_pwmEngine1Fovard, 0);
  analogWrite(m_pwmEngine1Back  , 0);
  analogWrite(m_pwmEngine2Fovard, 0);
  analogWrite(m_pwmEngine2Back  , 0);
  analogWrite(m_pwmEngine3Fovard, 0);
  analogWrite(m_pwmEngine3Back  , 0);
  int m_motor1Count = 0;
  int m_motor2Count = 0;
  int m_motor3Count = 0;
  int m_prmEngine1 = 0;
  int m_prmEngine2 = 0;
  int m_prmEngine3 = 0;
  int m_velocity = 0;
  int m_omega1 = 0;
  int m_omega2 = 0;
  int m_omega3 = 0;
}

void Robotino::Motor1InterruptA()
{
  if (digitalRead(m_encoder1PinA) != digitalRead(m_encoder1PinB))
  {
    m_motor1Count--;
  }
  else
  {
    m_motor1Count++;
  }
}

void Motor1InterruptAFunction()
{
  robotino.Motor1InterruptA();
}

void Robotino::Motor1InterruptB()
{
  if (digitalRead(m_encoder1PinA) != digitalRead(m_encoder1PinB))
  {
    m_motor1Count++;
  }
  else
  {
    m_motor1Count--;
  }
}

void Motor1InterruptBFunction()
{
  robotino.Motor1InterruptB();
}

void Robotino::Motor2InterruptA()
{
  if (digitalRead(m_encoder2PinA) != digitalRead(m_encoder2PinB))
  {
    m_motor2Count--;
  }
  else
  {
    m_motor2Count++;
  }
}

void Motor2InterruptAFunction()
{
  robotino.Motor2InterruptA();
}

void Robotino::Motor2InterruptB()
{
  if (digitalRead(m_encoder2PinA) != digitalRead(m_encoder2PinB))
  {
    m_motor2Count++;
  }
  else
  {
    m_motor2Count--;
  }
}

void Motor2InterruptBFunction()
{
  robotino.Motor2InterruptB();
}

void Robotino::Motor3InterruptA()
{
  if (digitalRead(m_encoder3PinA) != digitalRead(m_encoder3PinB))
  {
    m_motor3Count--;
  }
  else
  {
    m_motor3Count++;
  }
}

void Motor3InterruptAFunction()
{
  robotino.Motor3InterruptA();
}

void Robotino::Motor3InterruptB()
{
  if (digitalRead(m_encoder3PinA) != digitalRead(m_encoder3PinB))
  {
    m_motor3Count++;
  }
  else
  {
    m_motor3Count--;
  }
}

void Motor3InterruptBFunction()
{
  robotino.Motor3InterruptB();
}

bool Robotino::WhichDirectonHbridge1() //less then zero -> false
{
  bool isWhichDirection = m_prmEngine1 < 0 ? false : true;
  return isWhichDirection;
}

bool Robotino::WhichDirectonHbridge2() //less then zero -> false
{
  bool isWhichDirection = m_prmEngine2 < 0 ? false : true;
  return isWhichDirection;
}

bool Robotino::WhichDirectonHbridge3() //less then zero -> false
{
  bool isWhichDirection = m_prmEngine3 < 0 ? false : true;
  return isWhichDirection;
}

void Robotino::SetVelocity(float radius, float inTime)  //Set velocity of driving
{
  m_velocity = ((2 * s_PI * radius) / inTime);
}

void Robotino::SetOmega1(float inTime) //set omega1
{
  m_omega1 = ((-m_velocity * s_sqrt3of2 + ((2 * s_PI * s_L) / inTime) / s_RW) * s_PRM);
}

void Robotino::SetOmega2(float inTime) //set omega2
{
  m_omega2 = ((((2 * s_PI * s_L) / (inTime)) / s_RW) * s_PRM);
}

void Robotino::SetOmega3(float inTime) //set omega3
{
  m_omega3 = ((m_velocity * s_sqrt3of2 + ((2 * s_PI * s_L) / inTime) / s_RW) * s_PRM);
}




void setup()
{
  pinMode(m_encoder1PinA, INPUT);
  pinMode(m_encoder1PinB, INPUT);
  pinMode(m_encoder2PinA, INPUT);
  pinMode(m_encoder2PinB, INPUT);
  pinMode(m_encoder3PinA, INPUT);
  pinMode(m_encoder3PinB, INPUT);
  attachInterrupt(m_encoder1PinA, Motor1InterruptAFunction, CHANGE);
  attachInterrupt(m_encoder1PinB, Motor1InterruptAFunction, CHANGE);
  attachInterrupt(m_encoder2PinA, Motor2InterruptBFunction, CHANGE);
  attachInterrupt(m_encoder2PinB, Motor2InterruptBFunction, CHANGE);
  attachInterrupt(m_encoder3PinA, Motor3InterruptAFunction, CHANGE);
  attachInterrupt(m_encoder3PinB, Motor3InterruptBFunction, CHANGE);

  pinMode(m_pwmEngine1Fovard, OUTPUT);
  pinMode(m_pwmEngine1Back  , OUTPUT);
  pinMode(m_pwmEngine2Fovard, OUTPUT);
  pinMode(m_pwmEngine2Back  , OUTPUT);
  pinMode(m_pwmEngine3Fovard, OUTPUT);
  pinMode(m_pwmEngine3Back  , OUTPUT);


}

void loop()
{

}




