#include "Robot.h"

#include <iostream>
#include <string>

namespace frc
{
namespace lcchs
{

/*void Robot::rotateToAngle45()
{

    double tolerance = 3;
    double rocketAngle = 45;

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
*/

void Robot::rotateToRocketAngles()
{
    double tolerance = 2;

    double rotationSpeed = 0.3;

    //Right Rocket

    //RIGHT ROTATION

    // rotates to 60 from above 60 (right)
    if (gyroAngle > 30 + tolerance && gyroAngle < 60 - tolerance)
    {
        powerTrain.driveRobot(0, 0, rotationSpeed);
    }

    // rotates to 90 from above 90 (right)
    else if (gyroAngle > 75 + tolerance && gyroAngle < 90 - tolerance)
    {
        powerTrain.driveRobot(0, 0, rotationSpeed);
    }

    // rotates to 120 from above 120 (right)
    else if (gyroAngle > 105 + tolerance && gyroAngle < 120 - tolerance)
    {
        powerTrain.driveRobot(0, 0, rotationSpeed);
    }

    //LEFT ROTATION

    // rotates to 60 from below 60 (left)
    else if (gyroAngle < 75 - tolerance && gyroAngle > 60 + tolerance)
    {
        powerTrain.driveRobot(0, 0, -rotationSpeed);
    }

    // rotates to 90 from above 90 (left)
    else if (gyroAngle < 105 - tolerance && gyroAngle > 90 + tolerance)
    {
        powerTrain.driveRobot(0, 0, -rotationSpeed);
    }

    // rotates to 120 from above 120 (left)
    else if (gyroAngle < 180 - tolerance && gyroAngle > 120 + tolerance)
    {
        powerTrain.driveRobot(0, 0, -rotationSpeed);
    }

    //Left Rocket

    //RIGHT ROTATION

    // rotates to -60 from above -60 (right)
    else if (gyroAngle > -75 + tolerance && gyroAngle < -60 - tolerance)
    {
        powerTrain.driveRobot(0, 0, rotationSpeed);
    }

    // rotates to 90 from above 90 (right)
    else if (gyroAngle > -105 + tolerance && gyroAngle < -90 - tolerance)
    {
        powerTrain.driveRobot(0, 0, rotationSpeed);
    }

    // rotates to 120 from above 120 (right)
    else if (gyroAngle > -180 + tolerance && gyroAngle < -120 - tolerance)
    {
        powerTrain.driveRobot(0, 0, rotationSpeed);
    }

    //LEFT ROTATION

    // rotates to 60 from below 60 (left)
    else if (gyroAngle < -30 - tolerance && gyroAngle > -60 + tolerance)
    {
        powerTrain.driveRobot(0, 0, -rotationSpeed);
    }

    // rotates to 90 from above 90 (left)
    else if (gyroAngle < -75 - tolerance && gyroAngle > -90 + tolerance)
    {
        powerTrain.driveRobot(0, 0, -rotationSpeed);
    }

    // rotates to 120 from above 120 (left)
    else if (gyroAngle < -105 - tolerance && gyroAngle > -120 + tolerance)
    {
        powerTrain.driveRobot(0, 0, -rotationSpeed);
    }

    // Cargo Ship

    //rotates right
    else if (gyroAngle < 0 - tolerance && gyroAngle > -30 + tolerance)
    {
        powerTrain.driveRobot(0, 0, rotationSpeed);
    }

    //rotates left
    else if (gyroAngle > 0 + tolerance && gyroAngle < 30 - tolerance)
    {
        powerTrain.driveRobot(0, 0, -rotationSpeed);
    }
    else
    {
        powerTrain.driveRobot(0, 0, 0);
    }
}
} // namespace lcchs
} // namespace frc