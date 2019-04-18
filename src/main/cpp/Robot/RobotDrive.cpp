#include "Robot.h"

#include <iostream>

namespace frc
{
namespace lcchs
{

double findClosestAngle(double num) //targets are in increasing order
{
    double lockAngles[9] = {-180, -151, -90, -29, 0, 29, 90, 151, 180};
    double minDif = 999999;
    int minIndex = 0;

    for (int i = 0; i < 9; i++)
    {
        double Dif = std::abs(lockAngles[i] - num);
        if (Dif < minDif)
        {
            minIndex = i;
            minDif = Dif;
        }
        else
        {
            return lockAngles[minIndex];
        }
    }
    return lockAngles[minIndex];
}

void Robot::alignRobot()
{
    //LIMELIGHT
    bool tv = static_cast<bool>(limelightTable->GetNumber("tv", 0.0));
    double ta = limelightTable->GetNumber("ta", 0.0);
    double tx = limelightTable->GetNumber("tx", 0.0);
    double ty = limelightTable->GetNumber("ty", 0.0);

    double targetArea = 10.4;
    double targetX = 0.0;
    //double targetY = 11.0;
    double targetAngle = 0;

    double tolerance = 0.85;
    double toleranceArea = 4;

    double toleranceAngle = 0.3;

    double DEFAULTSPEED_Y = 0.35;
    double DEFAULTSPEED_X = 0.45;
    double speedXError = tx - targetX;
    double speedX_KP = 0.05;
    double speedYError = ta - targetArea;
    double speedY_KP = 0.05;

    double deltaError_X = speedXError - errorX;
    double deltaX_KD = 0.5;
    double deltaError_Y = speedYError - errorY;
    double deltaY_KD = 0.5;

    //GYRO ANGLES
    double speedZ = 0.30;
    double toleranceRocket = 2.0;
    double angleDest = findClosestAngle(gyroAngle);
    double angleError = angleDest - gyroAngle;
    double angleKp = 0.04;

    speedZ = angleKp * angleError;

    double speedY;
    double speedX;

    std::cout << "cam blocked? " << camBlocked << "\n";
    if (tv && !camBlocked)
    {
        speedX = (speedX_KP * speedXError) + (deltaError_X * deltaX_KD);

        speedY = (speedY_KP * speedYError) + (deltaError_Y * deltaY_KD);

        // std::cout << "delta error X: " << deltaError_X << std::endl;
        // std::cout << "delta error Y: " << deltaError_Y << std::endl;

        // std::cout << "X: " << speedX << std::endl;
        // std::cout << "Y: " << speedY << std::endl;

        // std::cout << "speed X error: " << speedXError << std::endl;
        // std::cout << "speed Y error: " << speedYError << std::endl;

        // if ((speedX < 0.05 && speedY < 0.05) || (speedX > -0.05 && speedY > -0.05))
        // {
        //     powerTrain.driveRobot(0, 0, speedZ);
        // }
        // else
        // {
        //     powerTrain.driveRobot(speedX, speedY, 0);
        // }
        powerTrain.driveRobot(speedX, speedY, speedZ);
    }
    else
    {
        powerTrain.driveRobot(0, 0, speedZ);
    }
    errorX = speedXError;
    errorY = speedYError;
}

void Robot::changeCam()
{

    limelightTable->PutNumber("camMode", 0);

    // toggle led light

    limelightTable->PutNumber("ledMode", 3.0);
}

} // namespace lcchs
} // namespace frc
