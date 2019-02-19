#include "Robot.h"

#include <iostream>
#include <string>

namespace frc
{
namespace lcchs
{

void Robot::rotateToAngle45()
{

    double tolerance = 3;
    double rocketAngle = 45;

    // if (gyroAngle != 400)
    // {
    //     rocketAngle = 45;
    // }
    // else if (button6->Get())
    // {
    //     rocketAngle = 90;
    //     std::cout << "the rocket angle was changed to 90" << std::endl;
    // }
    // else if (button7->Get())
    // {
    //     rocketAngle = 135;
    // }
    // else if (button10->Get())
    // {
    //     rocketAngle = -45;
    // }
    // else if (button9->Get())
    // {
    //     rocketAngle = -90;
    // }
    // else if (button8->Get())
    // {
    //     rocketAngle = -135;
    // }
    // else
    // {
    //     rocketAngle = 45;
    // }

    if (gyroAngle != rocketAngle + tolerance)
    {
        if (gyroAngle > rocketAngle + tolerance) //rotate to 45 degrees
        {
            powerTrain.driveRobot(0, 0, -0.4);
        }
        else if (gyroAngle < rocketAngle - tolerance) //rotate to 45 degrees
        {
            powerTrain.driveRobot(0, 0, 0.4);
        }
        else
        {
            powerTrain.driveRobot(0, 0, 0);
        }
    }
}

void Robot::rotateToAngle90()
{

    double tolerance = 3;
    double rocketAngle = 90;

    if (gyroAngle != rocketAngle + tolerance)
    {
        if (gyroAngle > rocketAngle + tolerance) //rotate to 45 degrees
        {
            powerTrain.driveRobot(0, 0, -0.4);
        }
        else if (gyroAngle < rocketAngle - tolerance) //rotate to 45 degrees
        {
            powerTrain.driveRobot(0, 0, 0.4);
        }
        else
        {
            powerTrain.driveRobot(0, 0, 0);
        }
    }
}

void Robot::rotateToAngle135()
{

    double tolerance = 3;
    double rocketAngle = 135;

    if (gyroAngle != rocketAngle + tolerance)
    {
        if (gyroAngle > rocketAngle + tolerance) //rotate to 45 degrees
        {
            powerTrain.driveRobot(0, 0, -0.4);
        }
        else if (gyroAngle < rocketAngle - tolerance) //rotate to 45 degrees
        {
            powerTrain.driveRobot(0, 0, 0.4);
        }
        else
        {
            powerTrain.driveRobot(0, 0, 0);
        }
    }
}

void Robot::rotateToAngleNeg45()
{

    double tolerance = 3;
    double rocketAngle = -45;

    if (gyroAngle != rocketAngle + tolerance)
    {
        if (gyroAngle > rocketAngle + tolerance) //rotate to 45 degrees
        {
            powerTrain.driveRobot(0, 0, -0.4);
        }
        else if (gyroAngle < rocketAngle - tolerance) //rotate to 45 degrees
        {
            powerTrain.driveRobot(0, 0, 0.4);
        }
        else
        {
            powerTrain.driveRobot(0, 0, 0);
        }
    }
}

void Robot::rotateToAngleNeg90()
{

    double tolerance = 3;
    double rocketAngle = -90;

    if (gyroAngle != rocketAngle + tolerance)
    {
        if (gyroAngle > rocketAngle + tolerance) //rotate to 45 degrees
        {
            powerTrain.driveRobot(0, 0, -0.4);
        }
        else if (gyroAngle < rocketAngle - tolerance) //rotate to 45 degrees
        {
            powerTrain.driveRobot(0, 0, 0.4);
        }
        else
        {
            powerTrain.driveRobot(0, 0, 0);
        }
    }
}

void Robot::rotateToAngleNeg135()
{

    double tolerance = 3;
    double rocketAngle = -135;

    if (gyroAngle != rocketAngle + tolerance)
    {
        if (gyroAngle > rocketAngle + tolerance) //rotate to 45 degrees
        {
            powerTrain.driveRobot(0, 0, -0.4);
            std::cout << "the robot will rotate to 45 degrees" << std::endl;
        }
        else if (gyroAngle < rocketAngle - tolerance) //rotate to 45 degrees
        {
            powerTrain.driveRobot(0, 0, 0.4);
        }
        else
        {
            powerTrain.driveRobot(0, 0, 0);
        }
    }
}
} // namespace lcchs
} // namespace frc