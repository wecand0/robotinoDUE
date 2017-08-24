#include <iostream>
#include "RobotinoPiModel.hpp"


#include <math.h>

const float PI = 3.14159265359;

using namespace std;

int main()
{
    RobotinoPiModel object;

    float x = sqrt(3);
    float y = 1;
    float velocity = 500;
    float alpha = 0.0;
    float wheelASpeed;
    float wheelBSpeed;
    float wheelCSpeed;
    bool isWheelAForwardDirection;
    bool isWheelBForwardDirection;
    bool isWheelCForwardDirection;

    alpha = object.calcCoordinate(x,y);

    object.setOmegaA(velocity, alpha  * PI / 180);
    object.setOmegaB(velocity, alpha  * PI / 180);
    object.setOmegaC(velocity, alpha  * PI / 180);

    isWheelAForwardDirection = object.whichDirectonHbridgeA();
    isWheelAForwardDirection = object.whichDirectonHbridgeB();
    isWheelAForwardDirection = object.whichDirectonHbridgeC();

    wheelASpeed = object.convertValueToSpeedEngineA();
    wheelBSpeed = object.convertValueToSpeedEngineB();
    wheelCSpeed = object.convertValueToSpeedEngineC();

    std::cout << "\n Wheel A speed: " << wheelASpeed;
    std::cout << "\n Wheel B speed: " << wheelBSpeed;
    std::cout << "\n Wheel C speed: " << wheelCSpeed;




}
