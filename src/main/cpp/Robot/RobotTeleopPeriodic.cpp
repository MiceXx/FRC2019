
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
        double rotationScalingHatch;
        double rotationScaling;
        // maybe try this:   if(button3 || )...
        if (selectHatch)
        {
            rotationScalingHatch = 0.7;
        }
        else
        {
            rotationScalingHatch = 1;
        }

        rotationScaling = 0.8;

        powerTrain.driveRobot(jStick->GetX(), jStick->GetY(), (jStick->GetZ()) * rotationScalingHatch * rotationScaling);
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
