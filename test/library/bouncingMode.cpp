#include "BouncingMode.h"
#include "robotinoDUE.h"

BouncingMode::BouncingMode():
                         m_velocityX(0),
                         m_velocityY(0),
                         m_omega1(0),
                         m_omega2(0),
                         m_omega3(0)
{}


double BouncingMode::GetVelocityX()
{
  return m_velocityX;
}

double BouncingMode::GetVelocityY()
{
  return m_velocityY;
}

double BouncingMode::GetOmega1()
{
  return m_omega1;
}

double BouncingMode::GetOmega2()
{
  return m_omega2;
}

double BouncingMode::GetOmega3()
{
  return m_omega3;
}


/*
   calc velocity of robot to circle mode
*/
void BouncingMode::SetVelocityX()  //Set velocity of driving
{
  m_velocityX = 0.0;
}

/*
   calc velocity of robot to circle mode
*/
void BouncingMode::SetVelocityY()  //Set velocity of driving
{
  m_velocityY = s_SPEED;
}

/*
   calc omega 1 to circle mode
*/
void BouncingMode::SetOmega1() //set omega1
{
  m_omega1 = ( (((-s_SPEED * s_cos90 * s_sqrt3of2) + (s_SPEED * s_sin90 * 0.5)) / s_RW)  * s_PRM);
}
/*
   calc omega 2 to circle mode
*/
void BouncingMode::SetOmega2() //set omega2
{
  m_omega2 = ( ((-s_SPEED * s_sin90) / s_RW) * s_PRM);
}

/*
   calc omega 3 to circle mode
*/
void BouncingMode::SetOmega3() //set omega3
{
  m_omega3 = ( ((s_SPEED * s_cos90 * s_sqrt3of2  + s_SPEED * s_sin90 * 0.5) / s_RW)  * s_PRM);
}


void BouncingMode::TurnFor90()
{
    m_omega1 = m_omega2 = m_omega3 = s_CIRCLINGSPEED;
}
