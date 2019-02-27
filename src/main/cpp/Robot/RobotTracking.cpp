#include "Robot.h"

#include <iostream>
#include <string>

namespace frc
{
namespace lcchs
{
//gyro reset position
void Robot::gyroResetPos()
{
    if (gyroAngle > 3.5)
    {
        powerTrain.driveRobot(-0.2, 0.2, -0.2, 0);
    }
    if (gyroAngle < -3.5)
    {
        powerTrain.driveRobot(0.2, -0.2, 0.2, 0);
    }
}

void Robot::alignRobot()
{
    auto limelightTable = networkTableInstance.GetTable("limelight-howl");
    bool tv = static_cast<bool>(limelightTable->GetNumber("tv", 0.0));
    double ta = limelightTable->GetNumber("ta", 0.0);
    double tx = limelightTable->GetNumber("tx", 0.0);
    double ty = limelightTable->GetNumber("ty", 0.0);
    double ta0 = limelightTable->GetNumber("ta0", 0.0);
    double ta1 = limelightTable->GetNumber("ta1", 0.0);


    double targetArea = 15;
    double targetX = 0.0;
    double targetY = 11.0;
    double targetAngle = 0;

    double tolerance = 0.85;
    double toleranceArea = 4;

    double toleranceAngle = 0.3;

    double alignSpeedY = 0.35;
    double alignSpeedX = 0.37;

    double gyroRotation = 0;
    double gyroTolerance = 1.5;

    if (gyroAngle > targetAngle + gyroTolerance)
    {
        gyroRotation = -0.25;
    }
    else if (gyroAngle < targetAngle - gyroTolerance)
    {
        gyroRotation = 0.25;
    }

    if (targetArea - ta > 5)
    {
        alignSpeedY = 0.25;
    }

    if (tv)
    {
        if (tx > targetX + tolerance)
        {
            if (ta > targetArea + toleranceArea)
            { //  move back and right
                powerTrain.driveRobot(alignSpeedX, alignSpeedY, gyroRotation);
            }
            else if (ta < targetArea - toleranceArea)
            { //    move forward and right
                powerTrain.driveRobot(alignSpeedX, -alignSpeedY, gyroRotation);
            }
            else
            { // move right
                powerTrain.driveRobot(alignSpeedX, 0, gyroRotation);
            }
        }
        else if (tx < targetX - tolerance)
        {
            if (ta > targetArea + toleranceArea)
            { //  move back+left
                powerTrain.driveRobot(-alignSpeedX, alignSpeedY, gyroRotation);
            }
            else if (ta < targetArea - toleranceArea)
            { // move forward+left
                powerTrain.driveRobot(-alignSpeedX, -alignSpeedY, gyroRotation);
            }
            else
            { //  move left
                powerTrain.driveRobot(-alignSpeedX, 0, gyroRotation);
            }
        }
        else
        {
            if (ta > targetArea + toleranceArea)
            { //  move back
                powerTrain.driveRobot(0, alignSpeedY, gyroRotation);
            }
            else if (ta < targetArea - toleranceArea)
            { //   move forward
                powerTrain.driveRobot(0, -alignSpeedY, gyroRotation);
            }
            else
            {
                powerTrain.driveRobot(0, 0, gyroRotation);
            }
        }
    }
    else
    {
        powerTrain.driveRobot(0, 0, gyroRotation);
    }
}

void Robot::changeCam()
{
    auto limelightTable = networkTableInstance.GetTable("limelight-howl");
    bool camMode = static_cast<bool>(limelightTable->GetNumber("camMode", 0.0));

    if (camMode)
    {
        limelightTable->PutNumber("camMode", 0);
    }
    else
    {
        limelightTable->PutNumber("camMode", 1.0);
    }
}
} // namespace lcchs
} // namespace frc
