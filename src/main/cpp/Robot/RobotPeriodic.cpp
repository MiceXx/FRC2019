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
    frc::SmartDashboard::PutNumber("Joystick X", jStick->GetX());
    frc::SmartDashboard::PutNumber("Joystick Y", jStick->GetY());
    frc::SmartDashboard::PutNumber("Joystick X Lift", jStick2->GetX());
    frc::SmartDashboard::PutNumber("Joystick Y Lift", jStick2->GetY());

    std::string speedX = std::to_string(jStick->GetX());
    frc::SmartDashboard::PutString("DB/String 0", speedX);

    std::string speedY = std::to_string(jStick->GetY());
    frc::SmartDashboard::PutString("DB/String 1", speedY);

    std::string speedZ = std::to_string(jStick->GetZ());
    frc::SmartDashboard::PutString("DB/String 2", speedZ);

    std::string GyroAngle = std::to_string(gyro.GetAngle());
    frc::SmartDashboard::PutString("DB/String 3", GyroAngle);

    if (button7->Get())
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
    double scaling = frc::SmartDashboard::GetNumber("DB/Slider 0", 0.0) + 1.;
    powerTrain.setScaling(1 / scaling);
    manipulator.setScaling(1 / scaling);
}

} // namespace lcchs
} // namespace frc