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
    double gyroAngle = gyro.GetAngle();
    if (gyroAngle > 3.5)
    {
        powerTrain.driveRobot(-0.2, 0.2, -0.25, 0);
    }
    else if (gyroAngle < -3.5)
    {
        powerTrain.driveRobot(0.2, -0.2, 0.25, 0);
    }
}

void Robot::alignRobot()
{
    double gyroAngle = gyro.GetAngle();
    auto limelightTable = networkTableInstance.GetTable("limelight");

    bool tv = static_cast<bool>(limelightTable->GetNumber("tv", 0.0));

    double ta = limelightTable->GetNumber("ta", 0.0);
    double targetArea = 22.5;

    double tx = limelightTable->GetNumber("tx", 0.0);
    double targetX = 0.9;

    double ty = limelightTable->GetNumber("ty", 0.0);
    double targetY = 11;

    double targetAngle = 0;

    double tolerance = 2;
    double toleranceArea = 4.5;

    double moveBackorLeft = 0.2;
    double moveForwardorRight = 0.2;

    double gyroRotation = 0;
    double gyroTolerance = 3;

    if (gyroAngle > targetAngle + gyroTolerance)
    {
        gyroRotation = -0.2;
    }
    else if (gyroAngle < targetAngle - gyroTolerance)
    {
        gyroRotation = 0.2;
    }

    if (tv)
    {

        if (tx > targetX + tolerance)
        {
            if (ta > targetArea + toleranceArea)
            { //  move back and right
                powerTrain.driveRobot(moveForwardorRight, moveBackorLeft, gyroRotation);
            }
            else if (ta < targetArea - toleranceArea)
            { //    move forward and right
                powerTrain.driveRobot(moveForwardorRight, -moveForwardorRight, gyroRotation);
            }
            else
            { // move right
                powerTrain.driveRobot(moveForwardorRight, 0, gyroRotation);
            }
        }
        else if (tx < targetX - tolerance)
        {
            if (ta > targetArea + toleranceArea)
            { //  move back+left
                powerTrain.driveRobot(-moveBackorLeft, moveBackorLeft, gyroRotation);
            }
            else if (ta < targetArea - toleranceArea)
            { // move forward+left
                powerTrain.driveRobot(-moveBackorLeft, -moveForwardorRight, gyroRotation);
            }
            else
            { //  move left
                powerTrain.driveRobot(-moveBackorLeft, 0, gyroRotation);
            }
        }
        else
        {
            if (ta > targetArea + toleranceArea)
            { //  move back
                powerTrain.driveRobot(0, moveBackorLeft, gyroRotation);
            }
            else if (ta < targetArea - toleranceArea)
            { //   move forward
                powerTrain.driveRobot(0, -moveForwardorRight, gyroRotation);
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

    // if (gyroAngle > 1 ){
    //     powerTrain.driveRobot( -0.2, 0.2, -0.6, 0);
    // }
    // else if(gyroAngle < -1 ){
    //     powerTrain.driveRobot( 0.2, -0.2, 0.5, 0);
    //}
}

} // namespace lcchs
} // namespace frc