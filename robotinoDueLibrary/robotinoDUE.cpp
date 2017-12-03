#include "robotinoDUE.h"

RobotinoDUE::RobotinoDUE():

                          m_velocityX(0),
                          m_velocityY(0),
                          m_omega1(0),
                          m_omega2(0),
                          m_omega3(0),
                          m_direction1(0),
                          m_direction2(0),
                          m_direction3(0),
                          m_circling(0),
                          m_bouncing(0)
{
}



void RobotinoDUE::SetMode(bool circling, bool bouncing)
{
    m_circling = circling;
    m_bouncing = bouncing;
}



bool RobotinoDUE::GetDirection1()
{
  return m_direction1;
}

bool RobotinoDUE::GetDirection2()
{
  return m_direction2;
}

bool RobotinoDUE::GetDirection3()
{
  return m_direction3;
}




/*
   choose the direction of motor 1
*/
void RobotinoDUE::WhichDirectonHbridge1() //less then zero -> false
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
void RobotinoDUE::WhichDirectonHbridge2() //less then zero -> false
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
void RobotinoDUE::WhichDirectonHbridge3() //less then zero -> false
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

void RobotinoDUE::SetRadius(float radius) //cm
{
    m_radusOfCircle = radius;
}

void RobotinoDUE::SetTime(float time)   //seconds
{
    m_timeOfCircle = time;
}



double RobotinoDUE::GetVelocityX()
{
  return m_velocityX = m_circleMode.GetVelocityX();
}

double RobotinoDUE::GetVelocityY()
{
  return m_velocityY = m_circleMode.GetVelocityY();
}

double RobotinoDUE::GetOmega1()
{
    if (m_circling == true)
    {
        return m_circleMode.GetOmega1();
    }
    else if (m_bouncing == true)
    {
        return 0;
    }

}

double RobotinoDUE::GetOmega2()
{
    if (m_circling == true)
    {
        return m_circleMode.GetOmega2();
    }
    else if (m_bouncing == true)
    {
        return 0;
    }
}

double RobotinoDUE::GetOmega3()
{
    if (m_circling == true)
    {
        return m_circleMode.GetOmega3();
    }
    else if (m_bouncing == true)
    {
        return 0;
    }
}




void RobotinoDUE::SetVelocityX()  //Set velocity of driving
{
    if (m_circling == true)
    {
        m_circleMode.SetVelocityX();
    }
    else if (m_bouncing == true)
    {

    }
}

void RobotinoDUE::SetVelocityY()  //Set velocity of driving
{
    if (m_circling == true)
    {
        m_circleMode.SetVelocityY(m_radusOfCircle, m_timeOfCircle);
    }
    else if (m_bouncing == true)
    {

    }
}

void RobotinoDUE::SetOmega1()
{
    if (m_circling == true)
    {
         m_omega1 = m_circleMode.GetOmega1() ;
    }
    else if (m_bouncing == true)
    {

    }
}

void RobotinoDUE::SetOmega2()
{
    if (m_circling == true)
    {
         m_omega2 = m_circleMode.GetOmega2();
    }
    else if (m_bouncing == true)
    {

    }
}

void RobotinoDUE::SetOmega3()
{
    if (m_circling == true)
    {
         m_omega3 = m_circleMode.GetOmega3();
    }
    else if (m_bouncing == true)
    {

    }
}


void RobotinoDUE::CalcOmega1()
{
    if (m_circling == true)
    {
         m_circleMode.SetOmega1(m_timeOfCircle);
    }
    else if (m_bouncing == true)
    {

    }
}

void RobotinoDUE::CalcOmega2()
{
    if (m_circling == true)
    {
         m_circleMode.SetOmega2(m_timeOfCircle);
    }
    else if (m_bouncing == true)
    {

    }
}

void RobotinoDUE::CalcOmega3()
{
    if (m_circling == true)
    {
         m_circleMode.SetOmega3(m_timeOfCircle);
    }
    else if (m_bouncing == true)
    {

    }
}


void RobotinoDUE::ClearAll()
{
      m_velocityX  = 0;
      m_velocityY  = 0;
      m_omega1     = 0;
      m_omega2     = 0;
      m_omega3     = 0;
      m_direction1 = 0;
      m_direction2 = 0;
      m_direction3 = 0;
}


