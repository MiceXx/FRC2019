
#include "Robot.h"

#include <iostream>
#include <string>

namespace frc
{
namespace lcchs
{
double x = 0;
double y = 0;
void Robot::TeleopPeriodic()
{
    readInput();

    //Reset gyro after passing 360 or -360
    // if (gyroAngle < -360)
    // {
    //     gyro.Reset();
    //     //std::cout << "the gyro was reset after -360" << std::endl;
    // }
    // else if (gyroAngle > 360)
    // {
    //     gyro.Reset();
    //     //std::cout << "the gyro was reset after 360" << std::endl;
    // }

    //for testing
    if (button4->Get())
    {
        gyro.Reset();
    }

    //Lift
    operateLift();

    //align robot w/ tracking
    if (button2->Get())
    {
        alignRobot();
    }
    else
    {
        powerTrain.driveRobot(jStick->GetX(), jStick->GetY(), jStick->GetZ());
    }
    //Mecanum wheel drift fix (always on)
    //wheelDriftFix();

    //Robot climb
    //robotClimb();

    //hinge
    operateHinges();

    //roller
    activateRoller();
}
} // namespace lcchs
} // namespace frc
