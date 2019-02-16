#include "Robot.h"
#include <iostream>

namespace frc
{
namespace lcchs
{

void Robot::activateRoller()
{
    captureCommand = driveStation.getLeftTrigger();
    shootCommand = driveStation.getRightTrigger();

    std::cout << "the trigger was pressed" << shootCommand << std::endl;

    if (shootCommand > 0.5)
    {
        roller.shootBall();
        std::cout << "the ball was shot" << std::endl;
    }
    else if (captureCommand > 0.5)
    {
        roller.captureBall();

        std::cout << "the ball was captured" << std::endl;
    }
    else
    {

        roller.stopRollers();
    }
}

} //namespace lcchs
} //namespace frc