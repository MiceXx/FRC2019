#include "Robot.h"

#include <iostream>
#include <string>

namespace frc
{
namespace lcchs
{

void Robot::alignRobot()
{
    auto limelightTable = networkTableInstance.GetTable("limelight-howl");
    bool tv = static_cast<bool>(limelightTable->GetNumber("tv", 0.0));
    double ta = limelightTable->GetNumber("ta", 0.0);
    double tx = limelightTable->GetNumber("tx", 0.0);
    double ty = limelightTable->GetNumber("ty", 0.0);
    double ta0 = limelightTable->GetNumber("ta0", 0.0);
    double ta1 = limelightTable->GetNumber("ta1", 0.0);

    //ROCKET ANGLES
    double rotationSpeed = 0.23;
    double rotationSpeedSlow = 0.20;
    double toleranceRocket = 2.0;
    double rotationSpeedDif;

    double targetArea = 15;
    double targetX = 0.0;
    double targetY = 11.0;
    double targetAngle = 0;

    double tolerance = 0.85;
    double toleranceArea = 4;

    double toleranceAngle = 0.3;

    double alignSpeedY = 0.35;
    double alignSpeedX = 0.45;

    // double gyroRotation = 0;
    // double gyroTolerance = 1.5;

    // if (gyroAngle > targetAngle + gyroTolerance)
    // {
    //     gyroRotation = -0.25;
    // }
    // else if (gyroAngle < targetAngle - gyroTolerance)
    // {
    //     gyroRotation = 0.25;
    // }

    //ROCKET ANGLES

    //how it was before the changes:
    //RIGHT ROTATION
    if ((gyroAngle > 15 + toleranceRocket && gyroAngle < 29 - toleranceRocket) ||
        (gyroAngle > 59.5 + toleranceRocket && gyroAngle < 90 - toleranceRocket) ||
        (gyroAngle > 120.5 + toleranceRocket && gyroAngle < 151 - toleranceRocket) ||
        (gyroAngle > -59.5 + toleranceRocket && gyroAngle < -29 - toleranceRocket) ||
        (gyroAngle > -120.5 + toleranceRocket && gyroAngle < -90 - toleranceRocket) ||
        (gyroAngle > -180 + toleranceRocket && gyroAngle < -151 - toleranceRocket) ||
        //cargo Angle
        (gyroAngle > -15 + toleranceRocket && gyroAngle < 0 - toleranceRocket))
    {
        // rotationSpeedDif = std::sqrt(rotationSpeed); //positive rotation
        rotationSpeedDif = rotationSpeed;
    }

    //LEFT ROTATION
    else if ((gyroAngle < 59.5 - toleranceRocket && gyroAngle > 29 + toleranceRocket) ||
             (gyroAngle < 120.5 - toleranceRocket && gyroAngle > 90 + toleranceRocket) ||
             (gyroAngle < 180 - toleranceRocket && gyroAngle > 151 + toleranceRocket) ||
             (gyroAngle < -15 - toleranceRocket && gyroAngle > -29 + toleranceRocket) ||
             (gyroAngle < -59.5 - toleranceRocket && gyroAngle > -90 + toleranceRocket) ||
             (gyroAngle < -120.5 - toleranceRocket && gyroAngle > -151 + toleranceRocket) ||
             //Cargo Angle
             (gyroAngle < 15 - toleranceRocket && gyroAngle > 0 + toleranceRocket))
    {
        //rotationSpeedDif = -std::sqrt(rotationSpeed); //negative rotation
        rotationSpeedDif = -rotationSpeed;
    }

    // //RIGHT ROTATION
    // if ((gyroAngle > 30 + toleranceRocket && gyroAngle < 45 - toleranceRocket) ||
    //     (gyroAngle > 75 + toleranceRocket && gyroAngle < 82.5 - toleranceRocket) ||
    //     (gyroAngle > 105 + toleranceRocket && gyroAngle < 112.5 - toleranceRocket) ||
    //     (gyroAngle > -75 + toleranceRocket && gyroAngle < -67.5 - toleranceRocket) ||
    //     (gyroAngle > -105 + toleranceRocket && gyroAngle < -97.5 - toleranceRocket) ||
    //     (gyroAngle > -180 + toleranceRocket && gyroAngle < -150 - toleranceRocket) ||
    //     //cargo Angle
    //     (gyroAngle > -30 + toleranceRocket && gyroAngle < 15 - toleranceRocket))
    // {
    //     rotationSpeedDif = rotationSpeed;
    // }
    // //Slower Rotation RIGHT
    // else if ((gyroAngle > 45 + toleranceRocket && gyroAngle < 60 - toleranceRocket) ||
    //          (gyroAngle > 82.5 + toleranceRocket && gyroAngle < 90 - toleranceRocket) ||
    //          (gyroAngle > 112.5 + toleranceRocket && gyroAngle < 120 - toleranceRocket) ||
    //          (gyroAngle > -67.5 + toleranceRocket && gyroAngle < -60 - toleranceRocket) ||
    //          (gyroAngle > -97.5 + toleranceRocket && gyroAngle < -90 - toleranceRocket) ||
    //          (gyroAngle > -150 + toleranceRocket && gyroAngle < -120 - toleranceRocket) ||
    //          //cargo Angle
    //          (gyroAngle > -15 + toleranceRocket && gyroAngle < 0 - toleranceRocket))
    // {
    //     rotationSpeedDif = rotationSpeedSlow;
    // }

    // //LEFT ROTATION
    // else if ((gyroAngle < 75 - toleranceRocket && gyroAngle > 45 + toleranceRocket) ||
    //          (gyroAngle < 105 - toleranceRocket && gyroAngle > 82.5 + toleranceRocket) ||
    //          (gyroAngle < 180 - toleranceRocket && gyroAngle > 112.5 + toleranceRocket) ||
    //          (gyroAngle < -30 - toleranceRocket && gyroAngle > -67.5 + toleranceRocket) ||
    //          (gyroAngle < -75 - toleranceRocket && gyroAngle > -97.5 + toleranceRocket) ||
    //          (gyroAngle < -105 - toleranceRocket && gyroAngle > -150 + toleranceRocket) ||
    //          //Cargo Angle
    //          (gyroAngle < 30 - toleranceRocket && gyroAngle > 15 + toleranceRocket))
    // {
    //     rotationSpeedDif = -rotationSpeed;
    // }
    // //Slower Rotation LEFT
    // else if ((gyroAngle < 45 - toleranceRocket && gyroAngle > 60 + toleranceRocket) ||
    //          (gyroAngle < 82.5 - toleranceRocket && gyroAngle > 90 + toleranceRocket) ||
    //          (gyroAngle < 112.5 - toleranceRocket && gyroAngle > 120 + toleranceRocket) ||
    //          (gyroAngle < -67.5 - toleranceRocket && gyroAngle > -60 + toleranceRocket) ||
    //          (gyroAngle < -97.5 - toleranceRocket && gyroAngle > -90 + toleranceRocket) ||
    //          (gyroAngle < -150 - toleranceRocket && gyroAngle > -120 + toleranceRocket) ||
    //          //Cargo Angle
    //          (gyroAngle < 15 - toleranceRocket && gyroAngle > 0 + toleranceRocket))
    // {
    //     rotationSpeedDif = -rotationSpeedSlow;
    // }

    double alignSpeedDifY;
    double alignSpeedDifX;

    if (tv)
    {

        if (ta > targetArea + toleranceArea)
        { //  move back and right
            alignSpeedDifY = alignSpeedY;
        }
        else if (ta < targetArea - toleranceArea)
        { //    move forward and right
            alignSpeedDifY = -alignSpeedY;
        }
        else
        { // move right
            alignSpeedDifY = 0;
        }

        if (tx > targetX + tolerance)
        {
            alignSpeedDifX = alignSpeedX;
        }
        else if (tx < targetX - tolerance)
        {
            alignSpeedDifX = -alignSpeedX;
        }
        else
        {
            alignSpeedDifX = 0;
        }

        //slower as gets closer
        if (targetArea - ta > 5)
        {
            alignSpeedDifY = alignSpeedY * 0.714285;
        }

        if (targetX - tx > 5)
        {
            alignSpeedDifX = alignSpeedX * 0.8;
        }

        powerTrain.driveRobot(alignSpeedDifX, alignSpeedDifY, rotationSpeedDif);
    }
    else
    {
        powerTrain.driveRobot(0, 0, rotationSpeedDif);
    }
}

void Robot::wheelDriftFix()
{

    //Fix Mecanum wheel drift when stopping
    double xSpeed = jStick->GetX();
    double ySpeed = jStick->GetY();
    double zSpeed = jStick->GetZ();

    double gyroAtStop;

    double turnSpeed;

    if (xSpeed < 0.01 && ySpeed < 0.01 && zSpeed < 0.01)
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
    auto limelightTable = networkTableInstance.GetTable("limelight-howl");

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
