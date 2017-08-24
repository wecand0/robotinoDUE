#include <math.h>
#include <iostream>

#include "RobotinoPiModel.hpp"

    	const float PI       = 3.14159265359;
    	const float RB       = 0.132;  //Distance from robot center to wheel center in m.
	const float RW       = 80;  //Radius of the wheels in mm.
	const float GEAR     = 16;   //gear.
	const float sqrt3of2 = sqrt(3)/2; //sqrt(3)/2
	const float PRM = 19.1; //(60 * GEAR) / (2 * PI * RW );


	RobotinoPiModel::RobotinoPiModel()
	{
         m_omegaA = 0;
         m_omegaB = 0;
         m_omegaC = 0;
	}



    double RobotinoPiModel::calcCoordinate(double x, double y)
    {
        double alpha = 0.0; //óãîë íàïðàâëåíèÿ ðîáîòà â ãðàäóñàõ
        alpha = atan2(y , x) * 180 / PI;  //ïåðåâîä â óãëû èç ðàäèàí
        return alpha;
    }


    void RobotinoPiModel::setOmegaA(float velocity, float alpha)
    {
        m_omegaA = ((-velocity * cos(alpha) * sqrt3of2 + velocity * sin(alpha) * 0.5) / RW) * PRM;
        std::cout << "\n" <<  m_omegaA << std::endl;
    }



    void RobotinoPiModel::setOmegaB(float velocity, float alpha)
    {
        m_omegaB = (-velocity  * sin(alpha) / RW) * PRM;
        std::cout << m_omegaB << std::endl;
    }



    void RobotinoPiModel::setOmegaC(float velocity, float alpha)
    {
        m_omegaC = ((velocity  * cos(alpha) * sqrt3of2 + velocity * sin(alpha) * 0.5) / RW) * PRM;
        std::cout << m_omegaC << std::endl;
    }



    float RobotinoPiModel::convertValueToSpeedEngineA()    // ÄÎ 500 ÑÌ !!!
     {
        return (fabs(m_omegaA)) * 255 / 400;
     }

     float RobotinoPiModel::convertValueToSpeedEngineB()
     {
        return (fabs(m_omegaB)) * 255 / 400;
     }

     float RobotinoPiModel::convertValueToSpeedEngineC()
     {
        return (fabs(m_omegaC)) * 255 / 400;
     }

     bool RobotinoPiModel::whichDirectonHbridgeA() //less then zero -> false
     {
         bool whichDirection = m_omegaA < 0 ? false : true;
         return whichDirection;
     }

     bool RobotinoPiModel::whichDirectonHbridgeB() //less then zero -> false
     {
         bool whichDirection = m_omegaB < 0 ? false : true;
         return whichDirection;
     }

     bool RobotinoPiModel::whichDirectonHbridgeC() //less then zero -> false
     {
         bool whichDirection = m_omegaC < 0 ? false : true;
         return whichDirection;
     }

