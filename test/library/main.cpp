#include <iostream>
#include <unistd.h>

#include "robotinoDUE.h"
#include "CircleMode.h"

using namespace std;

int main()
{
    RobotinoDUE robot;
    float gain = 16.0;
    robot.ClearAll();
    robot.SetMode(0,1);
    robot.SetRadius(318);
    robot.SetTime(10);


    robot.CirclingTO90();
    robot.WhichDirectonHbridge();

    cout << robot.GetOmega1() * gain << " ";
    cout << robot.GetOmega2() * gain << " ";
    cout << robot.GetOmega3() * gain << " ";
    cout << endl;

    robot.SetVelocityX();
    robot.SetVelocityY();
    robot.CalcOmega1();
    robot.CalcOmega2();
    robot.CalcOmega3();
    robot.WhichDirectonHbridge();

    cout << robot.GetOmega1() * gain << " ";
    cout << robot.GetOmega2() * gain << " ";
    cout << robot.GetOmega3() * gain << " ";

    return 0;
}
