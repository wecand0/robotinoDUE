/*
 * testing v1
*/

#include <iostream>

#include "robotinoDUE.h"

int main()
{
    Robotino robot;
    robot.SetVelocity(318,20);
    robot.SetOmega1(20);
    robot.SetOmega2(20);
    robot.SetOmega3(20);
    robot.WhichDirectonHbridge1();
    robot.WhichDirectonHbridge2();
    robot.WhichDirectonHbridge3();

    std::cout << robot.GetVelocity();
    std::cout << "  " << robot.GetOmega1();
    std::cout << "  " << robot.GetOmega2();
    std::cout << "  " << robot.GetOmega3();

    std::cout << "  " << robot.GetDirection1();
    std::cout << "  " << robot.GetDirection2();
    std::cout << "  " << robot.GetDirection3();
}
