#include <CircleMode.h>
#include <RobotinoDUE.h>

#include <PID_v1.h>

/*
   created: 25 nov. 2017
   by Vadim Shorin
   board: arduino due
*/

/*
   =-= (engines)
   <- direction of engines


           1 engine
           <-=-=
              |
              |
             / \
           /     \
         =-=->  =-=->
      2 engine   3 engine

       words in short:
       PRM -> Revolutions per minute
       PWM -> Pulse-width modulation
*/

/*
       3 buttons:
       o - circle mode (left)     o - on/off mode (center)     o - bouncing mode(right)
*/




/*
    encoders (3 items)
*/
const byte s_encoder1PinA     = 53;
const byte s_encoder1PinB     = 52;
const byte s_encoder2PinA     = 51;
const byte s_encoder2PinB     = 50;
const byte s_encoder3PinA     = 49;
const byte s_encoder3PinB     = 48;

/*
    buttons
*/
const byte s_circleMode       = 46;
const byte s_bouncingMode     = 44;

/*
   pwm pins
*/
const byte s_pwmEngine1Fovard = 3;
const byte s_pwmEngine1Back   = 4;
const byte s_pwmEngine2Fovard = 5;
const byte s_pwmEngine2Back   = 6;
const byte s_pwmEngine3Fovard = 5;
const byte s_pwmEngine3Back   = 6;

/*
   parameters of robotino
*/
const float s_L          = 125;            //Distance from robot center to whell center in mm;
const float s_RW        = 80;             //Radius of the wheels in mm.
const float s_sqrt3of2  = 0.86602540;     //sqrt(3)/2
const float s_PRM       = 19.1;           //(60 * GEAR) / (2 * PI * RW ); GEAR == 16
const float s_gain      = 20;
const float s_allTics   = 2000;
const float s_oneMinuteInsec = 60;
//const float s_oneRPMtoPWM  = 17;     // 17 RPM == 1 PWM  without load
const float s_oneRPMtoPWM    = 15;     // 15 RPM == 1 PWM  with load


volatile double motor1Count;
volatile double motor2Count;
volatile double motor3Count;
volatile int pwm1;
volatile int pwm2;
volatile int pwm3;


/*
   prototypes of functions
*/
void ClearCounts();
void ConvertTicsToRPM();
void CalcPWM();
void Motor1InterruptA();
void Motor1InterruptB();
void Motor2InterruptA();
void Motor2InterruptB();
void Motor3InterruptA();
void Motor3InterruptB();


/*
   calc prm motor 1
*/
void Motor1InterruptA()
{
  if (digitalRead(s_encoder1PinA) != digitalRead(s_encoder1PinB))
  {
    motor1Count--;
  }
  else
  {
    motor1Count++;
  }
}

/*
   calc prm motor 1
*/
void Motor1InterruptB()
{
  if (digitalRead(s_encoder1PinA) != digitalRead(s_encoder1PinB))
  {
    motor1Count++;
  }
  else
  {
    motor1Count--;
  }
}

/*
   calc prm motor 2
*/
void Motor2InterruptA()
{
  if (digitalRead(s_encoder2PinA) != digitalRead(s_encoder2PinB))
  {
    motor2Count--;
  }
  else
  {
    motor2Count++;
  }
}

/*
   calc prm motor 2
*/
void Motor2InterruptB()
{
  if (digitalRead(s_encoder2PinA) != digitalRead(s_encoder2PinB))
  {
    motor2Count++;
  }
  else
  {
    motor2Count--;
  }
}

/*
   calc prm motor 3
*/
void Motor3InterruptA()
{
  if (digitalRead(s_encoder3PinA) != digitalRead(s_encoder3PinB))
  {
    motor3Count--;
  }
  else
  {
    motor3Count++;
  }
}

/*
   calc prm motor 3
*/
void Motor3InterruptB()
{
  if (digitalRead(s_encoder3PinA) != digitalRead(s_encoder3PinB))
  {
    motor3Count++;
  }
  else
  {
    motor3Count--;
  }
}

/*
   set all counts of tics in encoders to zero
*/
void ClearCounts()
{
  motor1Count = 0;
  motor2Count = 0;
  motor3Count = 0;
}

/*
   convert all tics in encoders to RPM
*/
void ConvertTicsToRPM()
{
  motor1Count = ((motor1Count * s_oneMinuteInsec) / s_allTics);
  motor2Count = ((motor2Count * s_oneMinuteInsec) / s_allTics);
  motor3Count = ((motor3Count * s_oneMinuteInsec) / s_allTics);
}

void CalcPWM()
{
  pwm1 = robotino.GetOmega1() / s_oneRPMtoPWM;
  pwm2 = robotino.GetOmega2() / s_oneRPMtoPWM;
  pwm3 = robotino.GetOmega3() / s_oneRPMtoPWM;
}







///////////////////////////////////
///////////PID regulator///////////
///////////////////////////////////
/*


  vars for PID regulator


  volatile double Kp = 0.00;
  volatile double Ki = 0.00;
  volatile double Kd = 0.00;

  double Setpoint1,
       Input1,
       Output1,
       SetpointMove1;
  PID pid1(&Input1, &Output1, &Setpoint1, Kp, Ki, Kd, DIRECT);

  double Setpoint2,
       Input2,
       Output2,
       SetpointMove2;
  PID pid2(&Input2, &Output2, &Setpoint2, Kp, Ki, Kd, DIRECT);

  double Setpoint3,
       Input3,
       Output3,
       SetpointMove3;
  PID pid3(&Input3, &Output3, &Setpoint3, Kp, Ki, Kd, DIRECT);

*/

void setup()
{
  Serial.begin(112500);   //TODO del after testing

  pinMode(s_encoder1PinA, INPUT);
  pinMode(s_encoder1PinB, INPUT);
  pinMode(s_encoder2PinA, INPUT);
  pinMode(s_encoder2PinB, INPUT);
  pinMode(s_encoder3PinA, INPUT);
  pinMode(s_encoder3PinB, INPUT);
  attachInterrupt(s_encoder1PinA, Motor1InterruptA, CHANGE);
  attachInterrupt(s_encoder1PinB, Motor1InterruptB, CHANGE);
  attachInterrupt(s_encoder2PinA, Motor2InterruptA, CHANGE);
  attachInterrupt(s_encoder2PinB, Motor2InterruptB, CHANGE);
  attachInterrupt(s_encoder3PinA, Motor3InterruptA, CHANGE);
  attachInterrupt(s_encoder3PinB, Motor3InterruptB, CHANGE);

  pinMode(s_pwmEngine1Fovard, OUTPUT);
  pinMode(s_pwmEngine1Back  , OUTPUT);
  pinMode(s_pwmEngine2Fovard, OUTPUT);
  pinMode(s_pwmEngine2Back  , OUTPUT);
  pinMode(s_pwmEngine3Fovard, OUTPUT);
  pinMode(s_pwmEngine3Back  , OUTPUT);

  /*
     turn off all engines in start of board
  */
  analogWrite(s_pwmEngine1Fovard, 0);
  analogWrite(s_pwmEngine1Back  , 0);
  analogWrite(s_pwmEngine2Fovard, 0);
  analogWrite(s_pwmEngine2Back  , 0);
  analogWrite(s_pwmEngine3Fovard, 0);
  analogWrite(s_pwmEngine3Back  , 0);


  /*
     config PID regulator

    pid1.SetMode(AUTOMATIC);
    pid1.SetOutputLimits(0, 255);
    Setpoint1 = 0;
    SetpointMove1 = 0;


    pid2.SetMode(AUTOMATIC);
    pid2.SetOutputLimits(0, 255);
    Setpoint2 = 0;
    SetpointMove2 = 0;


    pid3.SetMode(AUTOMATIC);
    pid3.SetOutputLimits(0, 255);
    Setpoint3 = 0;
    SetpointMove3 = 0;
  */



  /*
     config hardware
  */
  SetConfiguration();

  Serial.println("READY TO START");    //TODO del after testing
}

void SetConfiguration()
{
  float radius = 318; //cm
  float inTime = 20;  //seconds

  robotino.SetVelocity(radius, inTime);   // ->  ~ 100 mm/s
  robotino.SetOmega1(inTime);             // -> ~ -225 PRM
  robotino.SetOmega2(inTime);             // ->  ~ 187  PRM
  robotino.SetOmega3(inTime);             // ->  ~ 600  PRM
  robotino.WhichDirectonHbridge1();
  robotino.WhichDirectonHbridge2();
  robotino.WhichDirectonHbridge3();
  CalcPWM();
}


void loop()
{
  //testing

  ClearCounts();
  delay(1000);
  ConvertTicsToRPM();

  //engine 1
  if (robotino.GetDirection1() == true)
  {
    analogWrite(s_pwmEngine1Fovard, pwm1);
  }
  else if (robotino.GetDirection1() == false)
  {
    analogWrite(s_pwmEngine1Back, pwm1);
  }

  //engine 2
  if (robotino.GetDirection2() == true)
  {
    analogWrite(s_pwmEngine2Fovard, pwm2);
  }
  else if (robotino.GetDirection2() == false)
  {
    analogWrite(s_pwmEngine2Back, pwm2);
  }

  //engine 3
  if (robotino.GetDirection3() == true)
  {
    analogWrite(s_pwmEngine3Fovard, pwm3);
  }
  else if (robotino.GetDirection3() == false)
  {
    analogWrite(s_pwmEngine3Back, pwm3);
  }

  Serial.print(" count1: ");   Serial.println(motor1Count);
  Serial.print(" count2: ");   Serial.println(motor2Count);
  Serial.print(" count3: ");   Serial.println(motor3Count);
  Serial.print(" velocity: "); Serial.println(robotino.GetVelocity());
  Serial.print(" omega1: ");   Serial.println(robotino.GetOmega1());
  Serial.print(" omega2: ");   Serial.println(robotino.GetOmega2());
  Serial.print(" omega3: ");   Serial.println(robotino.GetOmega3());
  Serial.print(" pwm1: ");     Serial.println(pwm1);
  Serial.print(" pwm2: ");     Serial.println(pwm2);
  Serial.print(" pwm3: ");     Serial.println(pwm3);
  delay(1000);
}





void CircleMode()
{

}

void BouncingMode()
{

}


