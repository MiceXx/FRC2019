#include "Robot.h"

#include <iostream>
#include <string>

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
    // Get the debug information selection for the PC Dashboard.
    liftDebug = driveStation.getButton(0);
    rollerDebug = driveStation.getButton(1);
    hingeDebug = driveStation.getButton(2);

    frc::SmartDashboard::PutNumber("Joystick X", jStick->GetX());
    frc::SmartDashboard::PutNumber("Joystick Y", jStick->GetY());

    // Drive the PC Dashboard compatible fields.
    if (liftDebug)
    {
        driveStation.setButton(1, false);
        driveStation.setButton(2, false);
    }
    else if (rollerDebug)
    {
        driveStation.setButton(2, false);
        driveStation.setButton(0, false);
    }
    else if (hingeDebug)
    {
        driveStation.setButton(1, false);
        driveStation.setButton(0, false);
    }

    else
    {
        std::string speedX = std::to_string(jStick->GetX());
        frc::SmartDashboard::PutString("DB/String 0", speedX);

        std::string speedY = std::to_string(jStick->GetY());
        frc::SmartDashboard::PutString("DB/String 1", speedY);

        std::string speedZ = std::to_string(jStick->GetZ());
        frc::SmartDashboard::PutString("DB/String 2", speedZ);

        std::string GyroAngle = std::to_string(gyro.GetAngle());
        frc::SmartDashboard::PutString("DB/String 3", GyroAngle);

        frc::SmartDashboard::PutString("DB/String 4", std::to_string(liftLevel));

        frc::SmartDashboard::PutString("DB/String 5", std::to_string(liftPosition));

        frc::SmartDashboard::PutString("DB/String 6", std::to_string(liftVelocity));

        frc::SmartDashboard::PutString("DB/String 7", std::to_string(liftDestination));

        frc::SmartDashboard::PutString("DB/String 8", std::to_string(liftCommand));
    }

    driveStation.setString(4, std::to_string(liftPosition));

    frc::SmartDashboard::PutNumber("Joystick X", jStick->GetX());
    frc::SmartDashboard::PutNumber("Joystick Y", jStick->GetY());

    if (button14->Get())
    {
        double now = Timer().GetFPGATimestamp();
        double debounceTime = 1;
        if (now - lastButtonpress > debounceTime)
        {
            changeCam();
            lastButtonpress = now;
        }
    }

    //Set Scaling
    double scaling = driveStation.getSlider(0);

    if (scaling < 0.)
    {
        scaling = 0.;
    }
    else if (scaling > 5.)
    {
        scaling = 5.;
    }

    driveOutput = 1 / (scaling + 1);
    liftOutput = 1 / (scaling + 1);
    powerTrain.setScaling(driveOutput);
    elevator.setScaling(liftOutput);
}

} // namespace lcchs
} // namespace frc
