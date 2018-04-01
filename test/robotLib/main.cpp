#include <iostream>
#include "robotinoDUE.h"

int main()
{
    RobotinoDUE robot;
    float gain = 16.0;
    robot.ClearAll();
    robot.SetMode(0,1);
    robot.SetRadius(318);
    robot.SetTime(5);
    robot.WhichDirectonHbridge();


    robot.SetVelocityX();
    robot.SetVelocityY();
    robot.CalcOmega1();
    robot.CalcOmega2();
    robot.CalcOmega3();
    robot.WhichDirectonHbridge();

    std::cout << robot.GetOmega1() * gain << " ";
    std::cout << robot.GetOmega2() * gain << " ";
    std::cout << robot.GetOmega3() * gain << " ";

    return 0;
}

