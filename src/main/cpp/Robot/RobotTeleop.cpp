
#include "Robot.h"

#include <iostream>
#include <string>

namespace frc
{
namespace lcchs
{
double x = 0;
double y = 0;

bool alignmentEnabled;

void Robot::TeleopInit()
{
    gyroAvgDrift = 0;

    for (int i = 1; i < gyroArraySize; i++)
    {
        gyroAvgDrift += gyroArrayReadings[i] - gyroArrayReadings[i - 1];
    }

    gyroAvgDrift = gyroAvgDrift / (gyroArraySize - 1);

    std::cout << gyroAvgDrift << "\n";
}

void Robot::TeleopPeriodic()
{
    readInput();

    //for testing
    if (button4->Get())
    {
        gyro.Reset();

        gyroAccum = 0;
    }

    operateLift();

    //align robot w/ tracking
    if (button2->Get())
    {
        alignRobot();

        changeCam();

        //alignmentEnabled = true;
    }
    else
    {
        limelightTable->PutNumber("camMode", 1.0);

        limelightTable->PutNumber("ledMode", 0);

        double rotationScalingHatch;
        double rotationScaling;

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

    //robotClimb();

    operateHinges();

    activateRoller();
}
} // namespace lcchs
} // namespace frc
