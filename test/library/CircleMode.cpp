#include "CircleMode.h"
#include "robotinoDUE.h"

CircleMode::CircleMode():
                         m_velocityX(0),
                         m_velocityY(0),
                         m_omega1(0),
                         m_omega2(0),
                         m_omega3(0)
{}


double CircleMode::GetVelocityX()
{
  return m_velocityX;
}

double CircleMode::GetOmega1()
{
  return m_omega1;
}

double CircleMode::GetOmega2()
{
  return m_omega2;
}

double CircleMode::GetOmega3()
{
  return m_omega3;
}


/*
   calc velocity of robot to circle mode
*/
void CircleMode::SetVelocityX()  //Set velocity of driving
{
  m_velocityX = 0.0;
}

/*
   calc velocity of robot to circle mode
*/
void CircleMode::SetVelocityY(float radius, float inTime)  //Set velocity of driving
{
  m_velocityY = ((2 * s_PI * radius) / inTime);
}

/*
   calc omega 1 to circle mode
*/
void CircleMode::SetOmega1(float inTime) //set omega1
{
  m_omega1 = (((1 / s_RW) * (  (-m_velocityY * s_sqrt3of2) + ((2 * s_PI * s_L) / inTime))) * s_PRM) * s_GAIN;
}
/*
   calc omega 2 to circle mode
*/
void CircleMode::SetOmega2(float inTime) //set omega2
{
  m_omega2 = ((((2 * s_PI * s_L) / (inTime)) / s_RW) * s_PRM) * s_GAIN;
}

/*
   calc omega 3 to circle mode
*/
void CircleMode::SetOmega3(float inTime) //set omega3
{
  m_omega3 = (((1 / s_RW) * (  (m_velocityY * s_sqrt3of2) + ((2 * s_PI * s_L) / inTime))) * s_PRM) * s_GAIN;
}
