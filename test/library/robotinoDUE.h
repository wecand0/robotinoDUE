#ifndef ROBOTINODUE_H_INCLUDED
#define ROBOTINODUE_H_INCLUDED

#include "CircleMode.h"

class RobotinoDUE
{
  public:
    RobotinoDUE();
    void SetMode(bool circling, bool bouncing);
    void SetVelocityX();               //Set velocity of driving
    void SetVelocityY();               //Set velocity of driving
    void SetOmega1();                  //set omega1
    void SetOmega2();                  //set omega2
    void SetOmega3();                  //set omega3
    double GetVelocityX();
    double GetVelocityY();
    double GetOmega1();
    double GetOmega2();
    double GetOmega3();

    void SetRadius(float radius); //cm
    void SetTime(float time);    //seconds

    void WhichDirectonHbridge1();
    void WhichDirectonHbridge2();
    void WhichDirectonHbridge3();
    bool GetDirection1();
    bool GetDirection2();
    bool GetDirection3();

    void ClearAll();

  private:
    CircleMode m_circleMode;

    double m_velocityX;
    double m_velocityY;
    double m_omega1;
    double m_omega2;
    double m_omega3;
    bool m_direction1;
    bool m_direction2;
    bool m_direction3;

    float m_radusOfCircle;
    float m_timeOfCircle;

    bool m_circling;
    bool m_bouncing;
};


#endif // ROBOTINODUE_H_INCLUDED
