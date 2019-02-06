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

namespace frc {
    namespace lcchs{
        void Robot::RobotPeriodic() {
            frc::SmartDashboard::PutNumber("Joystick X", jStick->GetX());
            frc::SmartDashboard::PutNumber("Joystick Y", jStick->GetY());
        }
    }
}