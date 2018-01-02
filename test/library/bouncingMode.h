#ifndef BOUNCINGMODE_H_INCLUDED
#define BOUNCINGMODE_H_INCLUDED


/*
 *  class for buncing mode
 */

class BouncingMode
{
  public:
        BouncingMode();
        void SetVelocityX();  //always == 0
        void SetVelocityY();  //Set velocity of driving
        void SetOmega1();                   //set omega1
        void SetOmega2();                   //set omega2
        void SetOmega3();                   //set omega3
        void TurnFor90();
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

        static const double s_sin90          = 1.0;
        static const double s_cos90          = 0.0;
        static const double s_SPEED          = 200.0;
        static const double s_CIRCLINGSPEED  = 100.0;
        static const double s_PI             = 3.14159265358979;
        static const double s_L              = 125.0;                //Distance from robot center to whell center in mm;
        static const double s_RW             = 80.0;                 //Radius of the wheels in mm.  //80
        static const double s_sqrt3of2       = 0.86602540378443;     //sqrt(3)/2
        static const double s_PRM            = 19.1;                 //(60 * GEAR) / (2 * PI * RW ); GEAR == 16



};


#endif // BOUNCINGMODE_H_INCLUDED
