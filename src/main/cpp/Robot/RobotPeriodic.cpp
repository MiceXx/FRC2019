#include "Robot.h"

#include <iostream>
#include <string>
#include <cmath>

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */

namespace frc
{
namespace lcchs
{
void Robot::RobotPeriodic()
{


    // Lift Ops
    liftPosition = elevator.getPosition();
    liftVelocity = elevator.getVelocity();
    liftCommand = driveStation.getLeftHandY();
    liftReset = driveStation.getYButton();

    // Roller Ops
    captureCommand = driveStation.getLeftTrigger();
    shootCommand = driveStation.getRightTrigger();

    // Wrist Ops
    wristCommand = driveStation.getRightHandY();

  

    double gyroReading = gyro.GetAngle() / 0.69106781186;

    if (gyroReading > 180)
    {
        gyroAngle = gyroAngle - 360;
    }
    else if (gyroReading < -180)
    {
        gyroAngle = gyroAngle + 360;
    }
    else
    {
        gyroAngle = gyroReading;
    }
}

} // namespace lcchs
} // namespace frc
