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
    // bool tv = static_cast<bool>(limelightTable->GetNumber("tv", 0.0));
    // double ta = limelightTable->GetNumber("ta", 0.0);
    // double tx = limelightTable->GetNumber("tx", 0.0);
    // double ty = limelightTable->GetNumber("ty", 0.0);
    // double ta0 = limelightTable->GetNumber("ta0", 0.0);
    // double ta1 = limelightTable->GetNumber("ta1", 0.0);

    double targetArea = 10.4;
    double targetX = 0.0;
    double targetY = 11.0;
    double targetAngle = 0;

    double tolerance = 0.85;
    double toleranceArea = 4;

    double toleranceAngle = 0.3;

    double alignSpeedY = 0.35;
    double alignSpeedX = 0.45;

    //Rocket Angles
    double rotationSpeed = 0.30;
    double rotationSpeedSlow = 0.20;
    double toleranceRocket = 2.0;
    double rotationSpeedDif;
    double angleDest = findClosestAngle(gyroAngle);
    double angleError = angleDest - gyroAngle;
    double angleKp = 0.04;

    rotationSpeed = angleKp * angleError;

    double alignSpeedDifY;
    double alignSpeedDifX;

    //limelightTable = networkTableInstance.GetTable("limelight");

    if (button8)
    {
        useCam = false;
    }

    // if (liftPosition < -16000)
    // {
    //     tv = false;
    // }

    // tv = false;

    // if (tv && useCam)
    // {
    //     std::cout << ta << "," << tx << "," << ty << "," << std::endl;
    //     if (ta > targetArea + toleranceArea)
    //     { //  move back and right
    //         alignSpeedDifY = alignSpeedY;
    //     }
    //     else if (ta < targetArea - toleranceArea)
    //     { //    move forward and right
    //         alignSpeedDifY = -alignSpeedY;
    //     }
    //     else
    //     { // move right
    //         alignSpeedDifY = 0;
    //     }

    //     if (tx > targetX + tolerance)
    //     {
    //         alignSpeedDifX = alignSpeedX;
    //     }
    //     else if (tx < targetX - tolerance)
    //     {
    //         alignSpeedDifX = -alignSpeedX;
    //     }
    //     else
    //     {
    //         alignSpeedDifX = 0;
    //     }

    //     //slower as gets closer
    //     if (targetArea - ta > 5)
    //     {
    //         alignSpeedDifY = alignSpeedY * 0.714285;
    //     }

    //     if (targetX - tx > 5)
    //     {
    //         alignSpeedDifX = alignSpeedX * 0.8;
    //     }

    //     powerTrain.driveRobot(-alignSpeedDifX, -alignSpeedDifY, 0);
    // }
    // else
    // {
        powerTrain.driveRobot(0, 0, rotationSpeed);
    // }
}

void Robot::wheelDriftFix()
{

    //Fix Mecanum wheel drift when stopping
    double xSpeed = jStick->GetX();
    double ySpeed = jStick->GetY();
    double zSpeed = jStick->GetZ();

    double gyroAtStop;

    double turnSpeed;

    if ((xSpeed < 0.01 && ySpeed < 0.01 && zSpeed < 0.01) && !button3 && gyro.GetRate() < 0.05)
    {
        gyroAtStop = gyroAngle;
    }

    //left turn
    if (gyroAngle + 1.5 > gyroAtStop)
    {
        turnSpeed = -0.15; //moves left fast
    }
    else if (gyroAngle > gyroAtStop)
    {
        turnSpeed = -0.10; //moves left
    }
    //right turn
    else if (gyroAngle - 1.5 < gyroAtStop)
    {
        turnSpeed = 0.15; //moves right fast
    }
    else if (gyroAngle < gyroAtStop)
    {
        turnSpeed = 0.10; //moves right
    }
    else
    {
        powerTrain.driveRobot(0, 0, 0);
    }
    powerTrain.driveRobot(0, 0, turnSpeed);
}

void Robot::changeCam()
{

    //change camera vision state
    bool camMode = static_cast<bool>(limelightTable->GetNumber("camMode", 0.0));

    if (camMode)
    {
        limelightTable->PutNumber("camMode", 0);
    }
    else
    {
        limelightTable->PutNumber("camMode", 1.0);
    }

    // toggle led light

    bool ledMode = static_cast<bool>(limelightTable->GetNumber("ledMode", 0.0));

    if (ledMode)
    {
        limelightTable->PutNumber("ledMode", 1.0);
    }
    else
    {
        limelightTable->PutNumber("ledMode", 0);
    }
}
} // namespace lcchs
} // namespace frc
