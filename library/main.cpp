/*
 * testing v1
*/

#include <iostream>

#include "CircleMode.h"
#include "robotinoDUE.h"

int main()
{
    CircleMode circleMode;
    RobotinoDUE robot;

    //сделать задержку выбора режима!!!
    robot.SetMode(true,false);
    robot.SetRadius(1500);
    robot.SetTime(15);

    circleMode.SetVelocityX();
    circleMode.SetVelocityY(318,20);
    circleMode.SetOmega1(20);
    circleMode.SetOmega2(20);
    circleMode.SetOmega3(20);

    robot.SetVelocityX();
    robot.SetVelocityY();
    robot.SetOmega1();
    robot.SetOmega2();
    robot.SetOmega3();

    std::cout << " " << robot.GetOmega1();
    std::cout << " " << robot.GetOmega2();
    std::cout << " " << robot.GetOmega3();

    robot.WhichDirectonHbridge1();
    robot.WhichDirectonHbridge2();
    robot.WhichDirectonHbridge3();
    std::cout << " " << robot.GetDirection1();
    std::cout << " " << robot.GetDirection2();
    std::cout << " " << robot.GetDirection3();


}
