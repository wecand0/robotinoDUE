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

RobotinoDUE::RobotinoDUE(float raduis, float time):
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
    m_radusOfCircle = raduis;
    m_timeOfCircle  = time;
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
   choose the direction of motor 1,2,3
*/
void RobotinoDUE::WhichDirectonHbridge() //less then zero -> false
{
  bool isWhichDirection1 = m_omega1 < 0 ? false : true;
  if (isWhichDirection1 == true)
  {
    m_direction1 = true;
  }
  else if (isWhichDirection1 == false)
  {
    m_direction1 = false;
  }


  bool isWhichDirection2 = m_omega2 < 0 ? false : true;
  if (isWhichDirection2 == true)
  {
    m_direction2 = true;
  }
  else if (isWhichDirection2 == false)
  {
    m_direction2 = false;
  }



  bool isWhichDirection3 = m_omega3 < 0 ? false : true;
  if (isWhichDirection3 == true)
  {
    m_direction3 = true;
  }
  else if (isWhichDirection3 == false)
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
       return m_bouncingMode.GetOmega1();
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
        return m_bouncingMode.GetOmega2();
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
        return m_bouncingMode.GetOmega3();
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
        m_bouncingMode.SetVelocityX();
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
        m_bouncingMode.SetVelocityY();
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
         m_omega1 = m_bouncingMode.GetOmega1();
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
         m_omega2 = m_bouncingMode.GetOmega2();
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
         m_omega3 = m_bouncingMode.GetOmega3();
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
        m_bouncingMode.SetOmega1();
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
        m_bouncingMode.SetOmega2();
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
        m_bouncingMode.SetOmega3();
    }
}

void RobotinoDUE::CirclingTO90()
{
    m_bouncingMode.TurnFor90();
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


