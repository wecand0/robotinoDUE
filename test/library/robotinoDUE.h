#ifndef ROBOTINODUE_H_INCLUDED
#define ROBOTINODUE_H_INCLUDED

#include "CircleMode.h"
#include "bouncingMode.h"

class RobotinoDUE
{
  public:
    RobotinoDUE();
    RobotinoDUE(float raduis, float time);
    void SetMode(bool circling, bool bouncing);

    void SetVelocityX();                //Set velocity of driving
    void SetVelocityY();                //Set velocity of driving
    void CalcOmega1();                  //Calc omega1
    void CalcOmega2();                  //Calc omega2
    void CalcOmega3();                  //Calc omega3
    void SetOmega1();                   //Set omega1
    void SetOmega2();                  	//Set omega2
    void SetOmega3();                  	//Set omega3
    void SetRadius(float radius); //cm
    void SetTime(float time);    //seconds
    void WhichDirectonHbridge();
    void CirclingTO90();

    double GetVelocityX();
    double GetVelocityY();
    double GetOmega1();
    double GetOmega2();
    double GetOmega3();
    bool GetDirection1();
    bool GetDirection2();
    bool GetDirection3();

    void ClearAll();

  private:
    CircleMode m_circleMode;
    BouncingMode m_bouncingMode;

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
