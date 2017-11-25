/*
 * created: 25 nov. 2017
 * by Shorin Vadim
 * board: arduino due
 */
 
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

/*
 * encoders (3 items)
 */
const byte s_encoder1PinA     = 53;
const byte s_encoder1PinB     = 52;
const byte s_encoder2PinA     = 51;
const byte s_encoder2PinB     = 50;
const byte s_encoder3PinA     = 49;
const byte s_encoder3PinB     = 48;

/*
 * buttons
 */
const byte s_circleMode       = 46;
const byte s_bouncingMode     = 44;

/*
 * pwm pins
 */
const byte s_pwmEngine1Fovard = 3;
const byte s_pwmEngine1Back   = 4;
const byte s_pwmEngine2Fovard = 5;
const byte s_pwmEngine2Back   = 6;
const byte s_pwmEngine3Fovard = 5;
const byte s_pwmEngine3Back   = 6;

/*
 * parameters of robotino
 */
const float s_PI       = 3.14159265;
const float s_L        = 125;            //Distance from robot center to whell center in mm;
const float s_RW       = 80;             //Radius of the wheels in mm.
const float s_sqrt3of2 = 0.86602540;     //sqrt(3)/2
const float s_PRM      = 19.1;           //(60 * GEAR) / (2 * PI * RW ); GEAR==16
const float s_gain     = 20;

class Robotino
{
  public:
    /*
     * prototypes of methods  
     */
    Robotino();
    void Motor1InterruptA();
    void Motor1InterruptB();
    void Motor2InterruptA();
    void Motor2InterruptB();
    void Motor3InterruptA();
    void Motor3InterruptB();
    void WhichDirectonHbridge1();
    void WhichDirectonHbridge2();
    void WhichDirectonHbridge3();
    void SetVelocity(float radius, float inTime);  //Set velocity of driving
    void SetOmega1(float inTime);                  //set omega1
    void SetOmega2(float inTime);                  //set omega2
    void SetOmega3(float inTime);                  //set omega3

  private:
    /*
       vars after calculate
    */
    volatile double m_motor1Count;
    volatile double m_motor2Count;
    volatile double m_motor3Count;
    volatile int m_velocity; // velocity of robot
    volatile int m_omega1;
    volatile int m_omega2;
    volatile int m_omega3;
    volatile bool m_direction1;
    volatile bool m_direction2;
    volatile bool m_direction3;

};

/*
   create object
*/
Robotino robotino; // global object, cause its arduino.. :(

/*
   //constructor set all vars to zero
*/
Robotino::Robotino():
  m_motor1Count(0),
  m_motor2Count(0),
  m_motor3Count(0),
  m_velocity(0),
  m_omega1(0),
  m_omega2(0),
  m_omega3(0)
{
  /*
   * turn off all engines
   */
  analogWrite(s_pwmEngine1Fovard, 0);
  analogWrite(s_pwmEngine1Back  , 0);
  analogWrite(s_pwmEngine2Fovard, 0);
  analogWrite(s_pwmEngine2Back  , 0);
  analogWrite(s_pwmEngine3Fovard, 0);
  analogWrite(s_pwmEngine3Back  , 0);
  }

/*
   calc prm motor 1
*/
void Robotino::Motor1InterruptA()
{
  if (digitalRead(s_encoder1PinA) != digitalRead(s_encoder1PinB))
  {
    m_motor1Count--;
  }
  else
  {
    m_motor1Count++;
  }
}

/*
   mini hack for class
*/
void Motor1InterruptAFunction()
{
  robotino.Motor1InterruptA();
}

/*
   calc prm motor 1
*/
void Robotino::Motor1InterruptB()
{
  if (digitalRead(s_encoder1PinA) != digitalRead(s_encoder1PinB))
  {
    m_motor1Count++;
  }
  else
  {
    m_motor1Count--;
  }
}

/*
   mini hack for class
*/
void Motor1InterruptBFunction()
{
  robotino.Motor1InterruptB();
}

/*
   calc prm motor 2
*/
void Robotino::Motor2InterruptA()
{
  if (digitalRead(s_encoder2PinA) != digitalRead(s_encoder2PinB))
  {
    m_motor2Count--;
  }
  else
  {
    m_motor2Count++;
  }
}

/*
    mini hack for class
*/
void Motor2InterruptAFunction()
{
  robotino.Motor2InterruptA();
}

/*
   calc prm motor 2
*/
void Robotino::Motor2InterruptB()
{
  if (digitalRead(s_encoder2PinA) != digitalRead(s_encoder2PinB))
  {
    m_motor2Count++;
  }
  else
  {
    m_motor2Count--;
  }
}

/*
    mini hack for class
*/
void Motor2InterruptBFunction()
{
  robotino.Motor2InterruptB();
}

/*
   calc prm motor 3
*/
void Robotino::Motor3InterruptA()
{
  if (digitalRead(s_encoder3PinA) != digitalRead(s_encoder3PinB))
  {
    m_motor3Count--;
  }
  else
  {
    m_motor3Count++;
  }
}

/*
    mini hack for class
*/
void Motor3InterruptAFunction()
{
  robotino.Motor3InterruptA();
}

/*
   calc prm motor 3
*/
void Robotino::Motor3InterruptB()
{
  if (digitalRead(s_encoder3PinA) != digitalRead(s_encoder3PinB))
  {
    m_motor3Count++;
  }
  else
  {
    m_motor3Count--;
  }
}

/*
    mini hack for class
*/
void Motor3InterruptBFunction()
{
  robotino.Motor3InterruptB();
}

/*
   choose the direction of motor 1
*/
void Robotino::WhichDirectonHbridge1() //less then zero -> false
{
  bool isWhichDirection = m_omega1 < 0 ? false : true;
  if (isWhichDirection == true)
  {
    m_direction1 = true;
  }
  else if (isWhichDirection == false)
  {
    m_direction1 = false;
  }
}

/*
   choose the direction of motor 2
*/
void Robotino::WhichDirectonHbridge2() //less then zero -> false
{
  bool isWhichDirection = m_omega2 < 0 ? false : true;
  if (isWhichDirection == true)
  {
    m_direction2 = true;
  }
  else if (isWhichDirection == false)
  {
    m_direction2 = false;
  }
}

/*
   choose the direction of motor 3
*/
void Robotino::WhichDirectonHbridge3() //less then zero -> false
{
  bool isWhichDirection = m_omega3 < 0 ? false : true;
  if (isWhichDirection == true)
  {
    m_direction3 = true;
  }
  else if (isWhichDirection == false)
  {
    m_direction3 = false;
  }
}

/*
   calc velocity of robot
*/
void Robotino::SetVelocity(float radius, float inTime)  //Set velocity of driving
{
  m_velocity = ((2 * s_PI * radius) / inTime);
}

/*
   calc omega 1
*/
void Robotino::SetOmega1(float inTime) //set omega1
{
  m_omega1 = (((1 / s_RW) * (  (-m_velocity * s_sqrt3of2) + ((2 * s_PI * s_L) / inTime))) * s_PRM) * s_gain;
}
/*
   calc omega 2
*/
void Robotino::SetOmega2(float inTime) //set omega2
{
  m_omega2 = ((((2 * s_PI * s_L) / (inTime)) / s_RW) * s_PRM) * s_gain;
}

/*
   calc omega 3
*/
void Robotino::SetOmega3(float inTime) //set omega3
{
  m_omega3 = (((1 / s_RW) * (  (m_velocity * s_sqrt3of2) + ((2 * s_PI * s_L) / inTime))) * s_PRM) * s_gain;
}




void setup()
{
  pinMode(s_encoder1PinA, INPUT);
  pinMode(s_encoder1PinB, INPUT);
  pinMode(s_encoder2PinA, INPUT);
  pinMode(s_encoder2PinB, INPUT);
  pinMode(s_encoder3PinA, INPUT);
  pinMode(s_encoder3PinB, INPUT);
  attachInterrupt(s_encoder1PinA, Motor1InterruptAFunction, CHANGE);
  attachInterrupt(s_encoder1PinB, Motor1InterruptAFunction, CHANGE);
  attachInterrupt(s_encoder2PinA, Motor2InterruptBFunction, CHANGE);
  attachInterrupt(s_encoder2PinB, Motor2InterruptBFunction, CHANGE);
  attachInterrupt(s_encoder3PinA, Motor3InterruptAFunction, CHANGE);
  attachInterrupt(s_encoder3PinB, Motor3InterruptBFunction, CHANGE);

  pinMode(s_pwmEngine1Fovard, OUTPUT);
  pinMode(s_pwmEngine1Back  , OUTPUT);
  pinMode(s_pwmEngine2Fovard, OUTPUT);
  pinMode(s_pwmEngine2Back  , OUTPUT);
  pinMode(s_pwmEngine3Fovard, OUTPUT);
  pinMode(s_pwmEngine3Back  , OUTPUT);

  /*
   * turn off all engines in start of board
   */
  analogWrite(s_pwmEngine1Fovard, 0);
  analogWrite(s_pwmEngine1Back  , 0);
  analogWrite(s_pwmEngine2Fovard, 0);
  analogWrite(s_pwmEngine2Back  , 0);
  analogWrite(s_pwmEngine3Fovard, 0);
  analogWrite(s_pwmEngine3Back  , 0);


}

void loop()
{
  SetConfiguration();
  CalcPWM();

}

void SetConfiguration()
{
  float radius = 318; //cm
  float inTime = 25;  //seconds

  robotino.SetVelocity(radius, inTime);
  robotino.SetOmega1(inTime);
  robotino.SetOmega2(inTime);
  robotino.SetOmega3(inTime);
  robotino.WhichDirectonHbridge1();
  robotino.WhichDirectonHbridge2();
  robotino.WhichDirectonHbridge3();
}

void CalcPWM()
{
  
}

void CircleMode()
{

}

void BouncingMode()
{

}



