#include "Robot.h"
#include <iostream>

namespace frc
{
namespace lcchs
{

void Robot::activateRoller()
{
    if (shootCommand > 0.5)
    {
        roller.shootBall();
    }
    else if (captureCommand > 0.5)
    {
        roller.captureBall();
    }
    else
    {

        roller.stopRollers();
    }
}

} //namespace lcchs
} //namespace frc