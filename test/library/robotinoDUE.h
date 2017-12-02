#ifndef ROBOTINODUE_H_INCLUDED
#define ROBOTINODUE_H_INCLUDED

class Robotino
{
  public:
    Robotino();
    void WhichDirectonHbridge1();
    void WhichDirectonHbridge2();
    void WhichDirectonHbridge3();
    void SetVelocity(float radius, float inTime);  //Set velocity of driving
    void SetOmega1(float inTime);                  //set omega1
    void SetOmega2(float inTime);                  //set omega2
    void SetOmega3(float inTime);                  //set omega3
    double GetVelocity();
    double GetOmega1();
    double GetOmega2();
    double GetOmega3();
    bool GetDirection1();
    bool GetDirection2();
    bool GetDirection3();

  private:
    volatile int m_velocity;
    volatile int m_omega1;
    volatile int m_omega2;
    volatile int m_omega3;
    volatile bool m_direction1;
    volatile bool m_direction2;
    volatile bool m_direction3;

    const double s_PI        = 3.14159265358979;
	const double s_L         = 125.0;            //Distance from robot center to whell center in mm;
	const double s_RW        = 80.0;             //Radius of the wheels in mm.
	const double s_sqrt3of2  = 0.86602540378443;     //sqrt(3)/2
	const double s_PRM       = 19.1;           //(60 * GEAR) / (2 * PI * RW ); GEAR == 16
	const double s_GAIN      = 20.0;
	const double s_ALLTICS   = 2000.0;
	const double s_oneMinuteInsec = 60.0;
	//const double s_oneRPMtoPWM  = 17;     // 17 RPM == 1 PWM  without load
	const double s_oneRPMtoPWM    = 15.0;     // 15 RPM == 1 PWM  with load


};

/*
   create object
*/
Robotino robotino; // global object, cause its arduino.. :(

/*
   //constructor set all vars to zero
*/
Robotino::Robotino():
  m_velocity(0),
  m_omega1(0),
  m_omega2(0),
  m_omega3(0),
  m_direction1(0),
  m_direction2(0),
  m_direction3(0)
{
}



//////////////////////////////////
///////////GET methods////////////
/////////////////////////////////

bool Robotino::GetDirection1()
{
  return m_direction1;
}

bool Robotino::GetDirection2()
{
  return m_direction2;
}

bool Robotino::GetDirection3()
{
  return m_direction3;
}

double Robotino::GetVelocity()
{
  return m_velocity;
}

double Robotino::GetOmega1()
{
  return m_omega1;
}

double Robotino::GetOmega2()
{
  return m_omega2;
}

double Robotino::GetOmega3()
{
  return m_omega3;
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
   calc velocity of robot to circle mode
*/
void Robotino::SetVelocity(float radius, float inTime)  //Set velocity of driving
{
  m_velocity = ((2 * s_PI * radius) / inTime);
}

/*
   calc omega 1 to circle mode
*/
void Robotino::SetOmega1(float inTime) //set omega1
{
  m_omega1 = (((1 / s_RW) * (  (-m_velocity * s_sqrt3of2) + ((2 * s_PI * s_L) / inTime))) * s_PRM) * s_GAIN;
}
/*
   calc omega 2 to circle mode
*/
void Robotino::SetOmega2(float inTime) //set omega2
{
  m_omega2 = ((((2 * s_PI * s_L) / (inTime)) / s_RW) * s_PRM) * s_GAIN;
}

/*
   calc omega 3 to circle mode
*/
void Robotino::SetOmega3(float inTime) //set omega3
{
  m_omega3 = (((1 / s_RW) * (  (m_velocity * s_sqrt3of2) + ((2 * s_PI * s_L) / inTime))) * s_PRM) * s_GAIN;
}

#endif // ROBOTINODUE_H_INCLUDED
