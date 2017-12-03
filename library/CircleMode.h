#ifndef CIRCLEMODE_H
#define CIRCLEMODE_H

/*
 *  class for circle mode
 */

class CircleMode
{
    public:
        CircleMode();
        void SetVelocityX();  //always == 0
        void SetVelocityY(float radius, float inTime);  //Set velocity of driving
        void SetOmega1(float inTime);                   //set omega1
        void SetOmega2(float inTime);                   //set omega2
        void SetOmega3(float inTime);                   //set omega3
        double GetVelocityX();
        double GetVelocityY();
        double GetOmega1();
        double GetOmega2();
        double GetOmega3();

    private:
         double m_velocityX;
         double m_velocityY;
         double m_omega1;
         double m_omega2;
         double m_omega3;

        const double s_PI        = 3.14159265358979;
        const double s_L         = 125.0;            //Distance from robot center to whell center in mm;
        const double s_RW        = 80.0;             //Radius of the wheels in mm.
        const double s_sqrt3of2  = 0.86602540378443;     //sqrt(3)/2
        const double s_PRM       = 19.1;           //(60 * GEAR) / (2 * PI * RW ); GEAR == 16
        const double s_GAIN      = 20.0;
};

#endif // CIRCLEMODE_H
