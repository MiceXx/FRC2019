
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

    //start mechanum stuff

    //if (abs(jStick->GetZ()) > 0.1) {gyro.Reset();}

    else if (button2->Get())
    {
        alignRobot();
    }

    else
    {
        //m_robotDrive.DriveCartesian(jStick->GetX(), -jStick->GetY(), jStick->GetZ());//, gyro.GetAngle());
        powerTrain.driveRobot(jStick->GetX(), jStick->GetY(), jStick->GetZ());
    }

            //Lift
            operateLift();
}
} // namespace lcchs
} // namespace frc
