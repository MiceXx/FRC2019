
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

    if (gyroAngle < -360)
    {
        gyro.Reset();
        //std::cout << "the gyro was reset after -360" << std::endl;
    }
    else if (gyroAngle > 360)
    {
        gyro.Reset();
        //std::cout << "the gyro was reset after 360" << std::endl;
    }
    if (button4->Get())
    {
        gyro.Reset();
    }

    //autonomous teleop

    // if (button1->Get())
    // {
    //     gyroResetPos();
    //     std::cout << "the botton was pressed" << std::endl;
    // }

    //if (abs(jStick->GetZ()) > 0.1) {gyro.Reset();}

    //FOR ROCKET ANGLES
    // if (button5->Get())
    // {
    //     rotateToAngle45();
    // }
    // else if (button6->Get())
    // {
    //     rotateToAngle90();
    // }
    // else if (button7->Get())
    // {
    //     rotateToAngle135();
    // }
    // else if (button8->Get())
    // {
    //     rotateToAngleNeg45();
    // }
    // else if (button9->Get())
    // {
    //     rotateToAngleNeg90();
    // }
    // else if (button10->Get())
    // {
    //     rotateToAngleNeg135();
    // }
    //

    //Rocket angles V2 (Align manually, then press trigger)
    // if (button1->Get())
    // {
    //     rotateToRocketAngles();
    // }

    //align robot w/ tracking
    if (button2->Get())
    {
        alignRobot();
    }
    else
    {
        powerTrain.driveRobot(jStick->GetX(), jStick->GetY(), jStick->GetZ());
    }

    //Lift
    operateLift();

    //hinge
    operateHinges();

    //roller
    activateRoller();
}
} // namespace lcchs
} // namespace frc
