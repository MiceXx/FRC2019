
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
    //networking table test
    xEntry.SetDouble(x);
    yEntry.SetDouble(y);
    x += 0.05;
    y += 1.0;

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

    //autonomous teleop

    if (button1->Get())
    {
        gyroResetPos();
        std::cout << "the botton was pressed" << std::endl;
    }

    else if (button4->Get())
    {
        gyro.Reset();
    }

    //if (abs(jStick->GetZ()) > 0.1) {gyro.Reset();}

    //FOR ROCKET ANGLES
    if (button5->Get())
    {
        rotateToAngle45();
    }
    else if (button6->Get())
    {
        rotateToAngle90();
    }
    else if (button7->Get())
    {
        rotateToAngle135();
    }
    else if (button8->Get())
    {
        rotateToAngleNeg45();
    }
    else if (button9->Get())
    {
        rotateToAngleNeg90();
    }
    else if (button10->Get())
    {
        rotateToAngleNeg135();
    }
    //
    //align robot w/ tracking
    else if (button2->Get())
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

    if (driveStation.getXButton())
    {
        wrist.angleForTime(0.3, 2);
    }
    //toothbrush
    operateBrush();

    //roller
    activateRoller();
}
} // namespace lcchs
} // namespace frc
